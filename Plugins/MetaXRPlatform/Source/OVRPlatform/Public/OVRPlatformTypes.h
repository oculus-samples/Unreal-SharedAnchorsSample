// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include <memory>

#include "CoreMinimal.h"
#include "OVR_Platform.h"
#include "Misc/CString.h"

#include "OVRPlatformEnums.h"
#include "OVRPlatformTypes.generated.h"

/** UE type corresponding to OVR Platform ::ovrID. It is used to represent an ID in the OVR Platform and provides a convenient way to work with IDs in the OVR Platform within Unreal Engine. */
USTRUCT(BlueprintType, Category = "OvrPlatform|CustomModels|ID")
struct OVRPLATFORM_API FOvrId
{
	GENERATED_USTRUCT_BODY()
	/** This is the default constructor for the FOvrId struct. It initializes the Id member variable to 0.*/
	FOvrId()
		: Id(0) {}
	/** Initializes the Id member variable with the value of the ID parameter. This constructor is useful when you have an existing ovrID value.*/
	FOvrId(ovrID ID)
		: Id(ID) {}
	/** This takes a string parameter and convert the string to an unsigned 64-bit integer, which is then assigned to the Id member variable.*/
	FOvrId(const FString& StrId)
		: Id(FCString::Strtoui64(*StrId, nullptr, 10)) {}

	/** This is an implicit conversion operator that allows a FOvrId object to be converted to an ovrID value. The ovrID type is the native ID type used by the OVR Platform.*/
	operator ovrID() const
	{
		return Id;
	}
	/** This is an equality operator that allows you to compare two FOvrId objects for equality.*/
	bool operator==(const FOvrId& Other)
	{
		return Id == Other.Id;
	}
	/** This is a friend function that provides a hash code for a FOvrId object based on the Id member variable.*/
	friend uint32 GetTypeHash(const FOvrId& Other)
	{
		return GetTypeHash(Other.Id);
	}

private:
	UPROPERTY()
	uint64 Id;
};

/** UE type corresponding to OVR Platform ovrKeyValuePair */
USTRUCT(BlueprintType, Category = "OvrPlatform|CustomModels|Variant")
struct OVRPLATFORM_API FOvrVariant
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "OvrPlatform|CustomModels|Variant|Field")
	EOvrKeyValuePairType Type;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "Type == EOvrVariantType::String", EditConditionHides), Category = "OvrPlatform|CustomModels|Variant|Field")
	FString StringValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "Type == EOvrVariantType::Int", EditConditionHides), Category = "OvrPlatform|CustomModels|Variant|Field")
	int IntValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "Type == EOvrVariantType::Double", EditConditionHides), Category = "OvrPlatform|CustomModels|Variant|Field")
	float FloatValue;

	FOvrVariant()
	{
		Type = EOvrKeyValuePairType::Unknown;
		StringValue = TEXT("");
		IntValue = 0;
		FloatValue = 0.0f;
	}
};

/// Wrapper to manage ::ovrMessageHandle lifetime.
/// Some payloads, like paged arrays, require the message that transports them
/// to outlive the lifetime of their initial handlers, as they get deallocated
/// at the same time.  See OVRPlatformModelsPageRequests.h/.cpp.
class TOvrMessageHandle
{
public:
	/// This is the default constructor for the class. It initializes the Handle member variable to nullptr.
	TOvrMessageHandle()
		: Handle(nullptr)
	{
	}
	/// This is an explicit constructor that takes an ::ovrMessageHandle parameter and initializes the Handle member variable with it.
	explicit TOvrMessageHandle(ovrMessageHandle Handle)
		: Handle(Handle)
	{
	}
	/// This is a destructor that frees the ::ovrMessageHandle pointed to by the Handle member variable.
	~TOvrMessageHandle()
	{
		ovr_FreeMessage(Handle);
		Handle = nullptr;
	}
	/// This is an implicit conversion operator that allows a TOvrMessageHandle object to be converted to an ovrMessageHandle value
	operator ovrMessageHandle() const { return Handle; }

private:
	ovrMessageHandle Handle;
};

typedef std::shared_ptr<TOvrMessageHandle> TOvrMessageHandlePtr;
