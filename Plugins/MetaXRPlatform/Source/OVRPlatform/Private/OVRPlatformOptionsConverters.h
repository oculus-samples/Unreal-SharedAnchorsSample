// Copyright (c) Meta Platforms, Inc. and affiliates.

// This file was @generated with LibOVRPlatform/codegen/main. Do not modify it!

#pragma once

// These converters are used to translate options from UE to C during calls to the OVR Platform.

#include "OVRPlatformOptions.h"

struct OVRPLATFORM_API FOvrAbuseReportOptionsConverter
{
    FOvrAbuseReportOptionsConverter(const FOvrAbuseReportOptions& Options):
        Handle(ovr_AbuseReportOptions_Create())
    {
        if (Handle)
        {
            ovr_AbuseReportOptions_SetPreventPeopleChooser(Handle, Options.PreventPeopleChooser);
            ovr_AbuseReportOptions_SetReportType(Handle, ConvertAbuseReportType(Options.ReportType));
        }
    }

    ~FOvrAbuseReportOptionsConverter()
    {
        ovr_AbuseReportOptions_Destroy(Handle);
    }

    operator ovrAbuseReportOptionsHandle() const
    {
        return Handle;
    }

    ovrAbuseReportOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrAdvancedAbuseReportOptionsConverter
{
    FOvrAdvancedAbuseReportOptionsConverter(const FOvrAdvancedAbuseReportOptions& Options):
        Handle(ovr_AdvancedAbuseReportOptions_Create())
    {
        if (Handle)
        {
            for (auto& Pair : Options.DeveloperDefinedContext)
            {
                ovr_AdvancedAbuseReportOptions_SetDeveloperDefinedContextString(Handle, TCHAR_TO_UTF8(*Pair.Key), TCHAR_TO_UTF8(*Pair.Value));
            }
            ovr_AdvancedAbuseReportOptions_SetObjectType(Handle, TCHAR_TO_UTF8(*Options.ObjectType));
            ovr_AdvancedAbuseReportOptions_SetReportType(Handle, ConvertAbuseReportType(Options.ReportType));
            for (size_t Index = 0, TotalIndices = Options.SuggestedUsers.Num(); Index < TotalIndices; ++Index)
            {
                ovr_AdvancedAbuseReportOptions_AddSuggestedUser(Handle, static_cast<ovrID>(Options.SuggestedUsers[Index]));
            }
        }
    }

    ~FOvrAdvancedAbuseReportOptionsConverter()
    {
        ovr_AdvancedAbuseReportOptions_Destroy(Handle);
    }

    operator ovrAdvancedAbuseReportOptionsHandle() const
    {
        return Handle;
    }

    ovrAdvancedAbuseReportOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrApplicationOptionsConverter
{
    FOvrApplicationOptionsConverter(const FOvrApplicationOptions& Options):
        Handle(ovr_ApplicationOptions_Create())
    {
        if (Handle)
        {
            ovr_ApplicationOptions_SetDeeplinkMessage(Handle, TCHAR_TO_UTF8(*Options.DeeplinkMessage));
            ovr_ApplicationOptions_SetDestinationApiName(Handle, TCHAR_TO_UTF8(*Options.DestinationApiName));
            ovr_ApplicationOptions_SetLobbySessionId(Handle, TCHAR_TO_UTF8(*Options.LobbySessionId));
            ovr_ApplicationOptions_SetMatchSessionId(Handle, TCHAR_TO_UTF8(*Options.MatchSessionId));
            ovr_ApplicationOptions_SetRoomId(Handle, static_cast<ovrID>(Options.RoomId));
        }
    }

    ~FOvrApplicationOptionsConverter()
    {
        ovr_ApplicationOptions_Destroy(Handle);
    }

    operator ovrApplicationOptionsHandle() const
    {
        return Handle;
    }

    ovrApplicationOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrAvatarEditorOptionsConverter
{
    FOvrAvatarEditorOptionsConverter(const FOvrAvatarEditorOptions& Options):
        Handle(ovr_AvatarEditorOptions_Create())
    {
        if (Handle)
        {
            ovr_AvatarEditorOptions_SetSourceOverride(Handle, TCHAR_TO_UTF8(*Options.SourceOverride));
        }
    }

    ~FOvrAvatarEditorOptionsConverter()
    {
        ovr_AvatarEditorOptions_Destroy(Handle);
    }

    operator ovrAvatarEditorOptionsHandle() const
    {
        return Handle;
    }

    ovrAvatarEditorOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrChallengeOptionsConverter
{
    FOvrChallengeOptionsConverter(const FOvrChallengeOptions& Options):
        Handle(ovr_ChallengeOptions_Create())
    {
        if (Handle)
        {
            ovr_ChallengeOptions_SetDescription(Handle, TCHAR_TO_UTF8(*Options.Description));
            ovr_ChallengeOptions_SetEndDate(Handle, (unsigned long long) Options.EndDate.ToUnixTimestamp());
            ovr_ChallengeOptions_SetIncludeActiveChallenges(Handle, Options.IncludeActiveChallenges);
            ovr_ChallengeOptions_SetIncludeFutureChallenges(Handle, Options.IncludeFutureChallenges);
            ovr_ChallengeOptions_SetIncludePastChallenges(Handle, Options.IncludePastChallenges);
            ovr_ChallengeOptions_SetLeaderboardName(Handle, TCHAR_TO_UTF8(*Options.LeaderboardName));
            ovr_ChallengeOptions_SetStartDate(Handle, (unsigned long long) Options.StartDate.ToUnixTimestamp());
            ovr_ChallengeOptions_SetTitle(Handle, TCHAR_TO_UTF8(*Options.Title));
            ovr_ChallengeOptions_SetViewerFilter(Handle, ConvertChallengeViewerFilter(Options.ViewerFilter));
            ovr_ChallengeOptions_SetVisibility(Handle, ConvertChallengeVisibility(Options.Visibility));
        }
    }

    ~FOvrChallengeOptionsConverter()
    {
        ovr_ChallengeOptions_Destroy(Handle);
    }

    operator ovrChallengeOptionsHandle() const
    {
        return Handle;
    }

    ovrChallengeOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrGroupPresenceOptionsConverter
{
    FOvrGroupPresenceOptionsConverter(const FOvrGroupPresenceOptions& Options):
        Handle(ovr_GroupPresenceOptions_Create())
    {
        if (Handle)
        {
            ovr_GroupPresenceOptions_SetDeeplinkMessageOverride(Handle, TCHAR_TO_UTF8(*Options.DeeplinkMessageOverride));
            ovr_GroupPresenceOptions_SetDestinationApiName(Handle, TCHAR_TO_UTF8(*Options.DestinationApiName));
            ovr_GroupPresenceOptions_SetIsJoinable(Handle, Options.IsJoinable);
            ovr_GroupPresenceOptions_SetLobbySessionId(Handle, TCHAR_TO_UTF8(*Options.LobbySessionId));
            ovr_GroupPresenceOptions_SetMatchSessionId(Handle, TCHAR_TO_UTF8(*Options.MatchSessionId));
        }
    }

    ~FOvrGroupPresenceOptionsConverter()
    {
        ovr_GroupPresenceOptions_Destroy(Handle);
    }

    operator ovrGroupPresenceOptionsHandle() const
    {
        return Handle;
    }

    ovrGroupPresenceOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrInviteOptionsConverter
{
    FOvrInviteOptionsConverter(const FOvrInviteOptions& Options):
        Handle(ovr_InviteOptions_Create())
    {
        if (Handle)
        {
            for (size_t Index = 0, TotalIndices = Options.SuggestedUsers.Num(); Index < TotalIndices; ++Index)
            {
                ovr_InviteOptions_AddSuggestedUser(Handle, static_cast<ovrID>(Options.SuggestedUsers[Index]));
            }
        }
    }

    ~FOvrInviteOptionsConverter()
    {
        ovr_InviteOptions_Destroy(Handle);
    }

    operator ovrInviteOptionsHandle() const
    {
        return Handle;
    }

    ovrInviteOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrMultiplayerErrorOptionsConverter
{
    FOvrMultiplayerErrorOptionsConverter(const FOvrMultiplayerErrorOptions& Options):
        Handle(ovr_MultiplayerErrorOptions_Create())
    {
        if (Handle)
        {
            ovr_MultiplayerErrorOptions_SetErrorKey(Handle, ConvertMultiplayerErrorErrorKey(Options.ErrorKey));
        }
    }

    ~FOvrMultiplayerErrorOptionsConverter()
    {
        ovr_MultiplayerErrorOptions_Destroy(Handle);
    }

    operator ovrMultiplayerErrorOptionsHandle() const
    {
        return Handle;
    }

    ovrMultiplayerErrorOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrNetSyncOptionsConverter
{
    FOvrNetSyncOptionsConverter(const FOvrNetSyncOptions& Options):
        Handle(ovr_NetSyncOptions_Create())
    {
        if (Handle)
        {
            ovr_NetSyncOptions_SetVoipGroup(Handle, TCHAR_TO_UTF8(*Options.VoipGroup));
            ovr_NetSyncOptions_SetVoipStreamDefault(Handle, ConvertNetSyncVoipStreamMode(Options.VoipStreamDefault));
            ovr_NetSyncOptions_SetZoneId(Handle, TCHAR_TO_UTF8(*Options.ZoneId));
        }
    }

    ~FOvrNetSyncOptionsConverter()
    {
        ovr_NetSyncOptions_Destroy(Handle);
    }

    operator ovrNetSyncOptionsHandle() const
    {
        return Handle;
    }

    ovrNetSyncOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrRichPresenceOptionsConverter
{
    FOvrRichPresenceOptionsConverter(const FOvrRichPresenceOptions& Options):
        Handle(ovr_RichPresenceOptions_Create())
    {
        if (Handle)
        {
            ovr_RichPresenceOptions_SetApiName(Handle, TCHAR_TO_UTF8(*Options.ApiName));
            ovr_RichPresenceOptions_SetDeeplinkMessageOverride(Handle, TCHAR_TO_UTF8(*Options.DeeplinkMessageOverride));
            ovr_RichPresenceOptions_SetIsJoinable(Handle, Options.IsJoinable);
        }
    }

    ~FOvrRichPresenceOptionsConverter()
    {
        ovr_RichPresenceOptions_Destroy(Handle);
    }

    operator ovrRichPresenceOptionsHandle() const
    {
        return Handle;
    }

    ovrRichPresenceOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrRosterOptionsConverter
{
    FOvrRosterOptionsConverter(const FOvrRosterOptions& Options):
        Handle(ovr_RosterOptions_Create())
    {
        if (Handle)
        {
            for (size_t Index = 0, TotalIndices = Options.SuggestedUsers.Num(); Index < TotalIndices; ++Index)
            {
                ovr_RosterOptions_AddSuggestedUser(Handle, static_cast<ovrID>(Options.SuggestedUsers[Index]));
            }
        }
    }

    ~FOvrRosterOptionsConverter()
    {
        ovr_RosterOptions_Destroy(Handle);
    }

    operator ovrRosterOptionsHandle() const
    {
        return Handle;
    }

    ovrRosterOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrUserOptionsConverter
{
    FOvrUserOptionsConverter(const FOvrUserOptions& Options):
        Handle(ovr_UserOptions_Create())
    {
        if (Handle)
        {
            ovr_UserOptions_SetMaxUsers(Handle, static_cast<unsigned int>(Options.MaxUsers));
            for (size_t Index = 0, TotalIndices = Options.ServiceProviders.Num(); Index < TotalIndices; ++Index)
            {
                ovr_UserOptions_AddServiceProvider(Handle, ConvertServiceProvider(Options.ServiceProviders[Index]));
            }
            ovr_UserOptions_SetTimeWindow(Handle, ConvertTimeWindow(Options.TimeWindow));
        }
    }

    ~FOvrUserOptionsConverter()
    {
        ovr_UserOptions_Destroy(Handle);
    }

    operator ovrUserOptionsHandle() const
    {
        return Handle;
    }

    ovrUserOptionsHandle Handle;
};

struct OVRPLATFORM_API FOvrVoipOptionsConverter
{
    FOvrVoipOptionsConverter(const FOvrVoipOptions& Options):
        Handle(ovr_VoipOptions_Create())
    {
        if (Handle)
        {
            ovr_VoipOptions_SetBitrateForNewConnections(Handle, ConvertVoipBitrate(Options.BitrateForNewConnections));
            ovr_VoipOptions_SetCreateNewConnectionUseDtx(Handle, ConvertVoipDtxState(Options.CreateNewConnectionUseDtx));
        }
    }

    ~FOvrVoipOptionsConverter()
    {
        ovr_VoipOptions_Destroy(Handle);
    }

    operator ovrVoipOptionsHandle() const
    {
        return Handle;
    }

    ovrVoipOptionsHandle Handle;
};
