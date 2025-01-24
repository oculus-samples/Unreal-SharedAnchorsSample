// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include <functional>

#include "OVRPlatformModels.h"
#include "OVRPlatformOptions.h"

#include "OVRPlatformFunctions.generated.h"

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOvrVoipFilterCallback, TArray<int32>, pcmData, int32, frequency, int32, numChannels);

UCLASS()
/// The UOvrFunctionsBlueprintLibrary class provides a collection of static public member functions that can be used to
/// interact with the Oculus platform. These functions include methods for managing application lifecycle, handling deeplinks,
/// and working with VoIP (Voice over Internet Protocol) connections.
/// See more info about Platform Solutions [here](https://developer.oculus.com/documentation/unreal/ps-platform-intro/).
class OVRPLATFORM_API UOvrFunctionsBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /**
     * Returns information about how the application was started. This function provides details about the launch intent,
     * such as the type of intent field FOvrLaunchDetails::LaunchType and any additional data that was passed along with it.
     * By calling this function, you can gain insight into how your application was launched and take appropriate action based on that information.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|ApplicationLifecycle")
    static FOvrLaunchDetails ApplicationLifecycle_GetLaunchDetails();

    /**
     * Logs if the user successfully deeplinked to a destination. This function takes two parameters: a string tracking ID and a launch result.
     * The tracking ID is used to identify the specific deeplink attempt, while the launch result indicates whether the deeplink was EOvrLaunchResult::Success or not.
     * By logging this information, you can track the effectiveness of your deeplinking efforts and make adjustments as needed.
     * @param TrackingID - The Tracking ID is a unique identifier assigned to each deeplink attempt. It allows developers to track the success or failure of individual deeplink attempts and gain insights into the effectiveness of their deeplinking efforts.
     * @param Result - An enum that indicates the outcome of an attempt to launch this application through a deeplink, including whether the attempt was EOvrLaunchResult::Success or not, and if not, the specific reasons for the failure.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|ApplicationLifecycle")
    static void ApplicationLifecycle_LogDeeplinkResult(FString TrackingID, EOvrLaunchResult Result);

    /** Accepts a VoIP connection from a given user. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_Accept(FOvrId UserID);

    /**
     * Gets whether or not a voice connection is using discontinuous transmission (DTX).
     * Both sides must set to using DTX when their connection is established in order for this
     * to be true. Returns unknown if there is no connection.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrVoipDtxState Voip_GetIsConnectionUsingDtx(FOvrId PeerID);

    /**
     * Gets the current local bitrate used for the connection to the specified user.  This is set
     * by the current client. Returns unknown if there is no connection.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrVoipBitrate Voip_GetLocalBitrate(FOvrId PeerID);

    /**
     * Returns the size of the internal ringbuffer used by the voip system in elements.  This size is the maximum
     * number of elements that can ever be returned by UOvrFunctionsBlueprintLibrary::Voip_GetPCM.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static int64 Voip_GetOutputBufferMaxSize();

    /**
     * Gets all available samples of voice data for the specified peer and
     * copies it into outputBuffer. The voip system will generate data at roughly
     * the rate of 480 samples per 10ms. This function should be called every frame
     * with 50ms (2400 elements) of buffer size to account for frame rate
     * variations. The data format is 16 bit fixed point 48khz mono.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Voip_GetPCM(ovrID senderID, int16_t *outputBuffer, size_t outputBufferNumElements);
     */

    /**
     * Gets all available samples of voice data for the specified peer and
     * copies it into outputBuffer. The voip system will generate data at roughly
     * the rate of 480 samples per 10ms. This function should be called every frame
     * with 50ms (2400 elements) of buffer size to account for frame rate
     * variations. The data format is 32 bit floating point 48khz mono.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Voip_GetPCMFloat(ovrID senderID, float *outputBuffer, size_t outputBufferNumElements);
     */

    /**
     * Returns the current number of audio samples available to read for the specified user.
     * This function is inherently racy; it's possible that more data can be added between a
     * call to this function and a subsequent call to UOvrFunctionsBlueprintLibrary::Voip_GetPCM.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static int64 Voip_GetPCMSize(FOvrId SenderID);

    /**
     * Like UOvrFunctionsBlueprintLibrary::Voip_GetPCM, this function copies available audio samples
     * into a provided buffer, but also stores the timestamp of the first sample
     * in the output parameter 'timestamp'.  This timestamp can be used for
     * synchronization; see UOvrFunctionsBlueprintLibrary::Voip_GetSyncTimestamp for more details.
     * 
     * This function returns a number of samples copied.  Note that it may
     * return early, even if there's more data available, in order to keep the
     * batch of audio samples with a single timestamp small; for example, if
     * there's 30ms worth of audio in the buffer, this function may return
     * 480 samples (10ms) each time it's called.  Therefore, it's recommended
     * to call this as long as there's data in the buffer (i.e. the function
     * returns a non-zero result).
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Voip_GetPCMWithTimestamp(ovrID senderID, int16_t *outputBuffer, size_t outputBufferNumElements, uint32_t *timestamp);
     */

    /**
     * See UOvrFunctionsBlueprintLibrary::Voip_GetPCMWithTimestamp. Uses a 32-bit floating-point data
     * format.
     */
    /*
     * Not exposed to blueprints, call C API directly: size_t ovr_Voip_GetPCMWithTimestampFloat(ovrID senderID, float *outputBuffer, size_t outputBufferNumElements, uint32_t *timestamp);
     */

    /**
     * Gets the current remote bitrate used for the connection to the specified user.  This is set
     * by the client on the other side of the connection.  Returns unknown if there is no connection.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrVoipBitrate Voip_GetRemoteBitrate(FOvrId PeerID);

    /**
     * Returns a timestamp used for synchronizing audio samples sent to the
     * given user with an external data stream.
     * 
     * Timestamps associated with audio frames are implicitly transmitted to
     * remote peers; on the receiving side, they can be obtained by using
     * UOvrFunctionsBlueprintLibrary::Voip_GetPCMWithTimestamp.  UOvrFunctionsBlueprintLibrary::Voip_GetPCMWithTimestamp is used to fetch
     * those timestamps on the sending side -- an application can insert the
     * value returned by this function into each data packet and compare it to
     * the value returned by GetPCMWithTimestamp() on the receiving side in
     * order to determine the ordering of two events (sampling audio and
     * composing a data packet).
     * 
     * Note: the timestamp is generated by an unspecified clock; it's doesn't
     * generally represent wall-clock time.  Use UOvrFunctionsBlueprintLibrary::Voip_GetSyncTimestampDifference
     * to convert the difference between two timestamps to microseconds.
     * 
     * This function assumes that a voice connection to the user already
     * exists; it returns 0 if that isn't the case.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static int32 Voip_GetSyncTimestamp(FOvrId UserID);

    /**
     * Calculates the difference between two sync timestamps, returned by
     * either UOvrFunctionsBlueprintLibrary::Voip_GetSyncTimestamp or UOvrFunctionsBlueprintLibrary::Voip_GetPCMWithTimestamp,
     * and converts it to microseconds.
     * 
     * Return value will be negative if lhs is smaller than rhs, zero if both
     * timestamps are the same, and positive otherwise.  The absolute value of
     * the result is the time in microseconds between two sync timestamps.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static int64 Voip_GetSyncTimestampDifference(int32 Lhs, int32 Rhs);

    /** Returns SystemVoip microphone's mute state. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrVoipMuteState Voip_GetSystemVoipMicrophoneMuted();

    /** Returns SystemVoip status. */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static EOvrSystemVoipStatus Voip_GetSystemVoipStatus();

    /**
     *   This function allows you to set a callback that will be called every time audio data is captured by the microphone.
     *   The callback function must match this signature: void filterCallback(int16_t pcmData[], size_t pcmDataLength, int frequency, int numChannels);
     *   The pcmData param is used for both input and output. pcmDataLength is the size of pcmData in elements. numChannels will be 1 or 2.
     *   If numChannels is 2, then the channel data will be interleaved in pcmData.
     *   Frequency is the input data sample rate in hertz.
     * 
     * 
     * This function can be safely called from any thread.
     */
    /*
     * Not exposed to blueprints, call C API directly: void ovr_Voip_SetMicrophoneFilterCallback(VoipFilterCallback cb);
     */

    /**
     * This function is used to enable or disable the local microphone.  When muted, the microphone will not transmit any audio.
     * Voip connections are unaffected by this state.  New connections can be established or closed whether the microphone is muted or not.
     * This can be used to implement push-to-talk, or a local mute button.  The default state is unmuted.
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_SetMicrophoneMuted(EOvrVoipMuteState State);

    /**
     * The options set for newly created connections to use. Existing connections will continue
     * to use their current settings until they are destroyed and recreated.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_SetNewConnectionOptions(FOvrVoipOptions VoipOptions);

    /**
     * Sets the output sample rate.  Audio data will be resampled as it is placed into the internal ringbuffer.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_SetOutputSampleRate(EOvrVoipSampleRate Rate);

    /**
     * Attempts to establish a VoIP session with the specified user.
     * 
     * A message of type UOvrPlatformSubsystem::OnVoipSystemVoipState() will be posted when the session is
     * established.
     * 
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_Start(FOvrId UserID);

    /**
     * Terminates a VoIP session with the specified user.  Note that a muting
     * functionality should be used to temporarily stop sending audio; restarting
     * a VoIP session after tearing it down may be an expensive operation.
     * 
     * 
     * This function can be safely called from any thread.
     */
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Voip")
    static void Voip_Stop(FOvrId UserID);


    /// Checks if the Oculus Platform SDK has been successfully initialized.
    /// Returns True if the SDK is initialized, otherwise False.
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Platform")
    static bool Platform_IsInitialized();

    /// Retrieves the unique identifier for the currently logged-in user.
    /// Returns The user's ID if logged in, otherwise returns a zero ID indicating no user is logged in.
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Platform")
    static FOvrId Platform_GetLoggedInUserID();

    /// Fetches the locale of the currently logged-in user.
    /// The locale format conforms to BCP47 standards.
    /// Returns The user's locale as a string if available, otherwise an empty string if there's an error or no user is logged in.
    /// More about BCP47 at [here](https://tools.ietf.org/html/bcp47).
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Platform")
    static FString Platform_GetLoggedInUserLocale();

    /// Sets the developer access token used for authenticating API requests.
    /// @param AccessToken The developer access token as a string.
    UFUNCTION(BlueprintCallable, Category = "OvrPlatform|Platform")
    static void Platform_SetDeveloperAccessToken(FString AccessToken);
};
