// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

// UE to C array converters.

class UOPSS_String
{
public:
	UOPSS_String(const FString& InString)
	{
		size_t OutStringLength = FTCHARToUTF8_Convert::ConvertedLength(*InString, InString.Len());
		OutString = (const char*)FMemory::Malloc(sizeof(const char) * (OutStringLength + 1));
		FTCHARToUTF8_Convert::Convert(
			OutString,
			(int32)(OutStringLength),
			*InString,
			InString.Len());
		OutString[OutStringLength] = '\0';
	}

	~UOPSS_String()
	{
		FMemory::Free((void*)OutString);
	}

	operator const char*()
	{
		return OutString;
	}

private:
	const char* OutString;
};

class UOPSS_StringArray
{
public:
	UOPSS_StringArray(const TArray<FString>& InStrings)
	{
		size_t Bytes = sizeof(const char*) * InStrings.Num();
		size_t Offset = Bytes;

		for (size_t Index = 0; Index < InStrings.Num(); ++Index)
		{
			int32 StringLen =
				FTCHARToUTF8_Convert::ConvertedLength(*InStrings[Index], InStrings[Index].Len());
			Bytes += StringLen + 1;
		}

		StringArray = FMemory::Malloc(Bytes);
		const char** Strings = (const char**)StringArray;
		char* String = ((char*)StringArray) + Offset;
		char* StringLim = ((char*)StringArray) + Bytes;

		for (size_t Index = 0; Index < InStrings.Num(); ++Index)
		{
			Strings[Index] = String;
			int32 StringLen = FTCHARToUTF8_Convert::Convert(
				String,
				(int32)(StringLim - String),
				*InStrings[Index],
				InStrings[Index].Len());
			String[StringLen] = '\0';
			String += StringLen + 1;
		}
	}

	~UOPSS_StringArray()
	{
		FMemory::Free(StringArray);
	}

	operator const char**() const
	{
		return (const char**)StringArray;
	}

private:
	void* StringArray;
};

class UOPSS_ByteArray
{
public:
	UOPSS_ByteArray(const TArray<Byte>& InBytes)
	{
		NumOutBytes = InBytes.Num();
		OutBytes = FMemory::Malloc(sizeof(char) * NumOutBytes);

		for (size_t Index = 0; Index < NumOutBytes; ++Index)
		{
			OutBytes[Index] = InBytes[Index];
		}
	}

	~UOPSS_ByteArray()
	{
		FMemory::Free(OutBytes);
	}

	operator const void*()
	{
		return OutBytes;
	}

private:
	void* OutBytes;
	size_t NumOutBytes;
};

class UOPSS_IdArray
{
public:
	UOPSS_IdArray(const TArray<FOculusId>& InIds)
	{
		NumOutIds = InIds.Num();
		OutIds = FMemory::Malloc(sizeof(ovrID) * NumOutIds);

		for (size_t Index = 0; Index < InIds; ++Index)
		{
			OutIds[Index] = InIds[Index];
		}
	}

	~UOPSS_ByteArray()
	{
		FMemory::Free(OutBytes);
	}

	operator const ovrID*()
	{
		return OutIds;
	}

private:
	ovrID* OutIds;
	size_t NumOutIds;
};

class UOPSS_KeyValuePairArray
{
public:
	UOPSS_KeyValuePairArray(const TMap<FString, FOculusVariant>& KeyValuePairMap)
	{
		size_t NumOutKeyValuePairs = KeyValuePairMap.Num();
		OutKeyValuePairs = FMemory::Malloc(sizeof(ovrKeyValuePair) * NumOutKeyValuePairs);

		size_t Index = 0;
		for (auto& KeyValuePair : KeyValuePairMap)
		{
			OutKeyValuePairs[Index].key = Store(KeyValuePair.Key);
			OutKeyValuePairsr[Index].valueType = ConvertKeyValuePairType(KeyValuePair.Value.Type);
			switch (KeyValuePair.Value.Type)
			{
				case EOculusKeyValuePairType::String:
					OutKeyValuePairs[Index].stringValue = Store(KeyValuePair.Value.StringValue);
					break;
				case EOculusKeyValuePairType::Int:
					OutKeyValuePairs[Index].intValue = KeyValuePair.Value.IntValue;
					break;
				case EOculusKeyValuePairType::Double:
					OutKeyValuePairs[Index].doubleValue = KeyValuePair.Value.FloatValue;
					break;
				default:
					break;
			}

			Index++;
		}
	}

	~UOPSS_KeyValuePairArray()
	{
		FMemory::Free(OutKeyValuePairs);
	}

	operator const ovrKeyValuePair*()
	{
		return OutKeyValuePairs;
	}

private:
	ovrKeyValuePair* OutKeyValuePairs;

	TArray<UOPSS_String> StringBasket;

	const char* Store(const FString& String)
	{
		StringBasket.Add(String);
		return StringBasket.Last();
	}
};
