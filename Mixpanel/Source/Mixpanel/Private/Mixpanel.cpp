// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "MixpanelPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FMixpanelModule"


void FMixpanelModule::StartupModule()
{
}

void FMixpanelModule::ShutdownModule()
{

}

void FMixpanelModule::TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttribute>& attributes)
{
	PlatformMixpanelHelper::TrackEvent(eventName, attributes);
}

void FMixpanelModule::SetUserID(const FString& userID)
{
	PlatformMixpanelHelper::SetUserID(userID);
}

void FMixpanelModule::TrackCharge(double charge, const TArray<FAnalyticsEventAttribute>& attributes)
{
	PlatformMixpanelHelper::TrackCharge(charge, attributes);
}

void FMixpanelModule::StoreUserProfileData(const TArray<FAnalyticsEventAttribute>& attributes, const TArray<FAnalyticsEventAttribute>& incrementAttributes)
{
	PlatformMixpanelHelper::StoreUserProfileData(attributes, incrementAttributes);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMixpanelModule, Mixpanel)