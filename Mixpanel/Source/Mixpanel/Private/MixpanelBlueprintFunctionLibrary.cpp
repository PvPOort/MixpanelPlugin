#include "MixpanelPrivatePCH.h"
#include "MixpanelBlueprintFunctionLibrary.h"
#include "Mixpanel.h"

DEFINE_LOG_CATEGORY_STATIC(LogMixpanelAnalytics, Log, All);

void UMixpanelBlueprintFunctionLibrary::TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttr>& attributes)
{
	FMixpanelModule *mixpanelModule = &FMixpanelModule::Get();
	if (mixpanelModule)
	{
		TArray<FAnalyticsEventAttribute> convertedAttributes;

		for (int32 i = 0; i < attributes.Num(); i++)
		{
			convertedAttributes.Add(FAnalyticsEventAttribute(attributes[i].Name, attributes[i].Value));
		}

		mixpanelModule->TrackEvent(eventName, convertedAttributes);
	}
	else
	{
		UE_LOG(LogMixpanelAnalytics, Warning, TEXT("UMixpanelBlueprintFunctionLibrary::TrackEvent: mixpanel module is NULL"));
	}
}

void UMixpanelBlueprintFunctionLibrary::SetUserID(const FString& userID)
{
	FMixpanelModule *mixpanelModule = &FMixpanelModule::Get();
	if (mixpanelModule)
	{
		mixpanelModule->SetUserID(userID);
	}
	else
	{
		UE_LOG(LogMixpanelAnalytics, Warning, TEXT("UMixpanelBlueprintFunctionLibrary::SetUserID: mixpanel module is NULL"));
	}
}

void UMixpanelBlueprintFunctionLibrary::TrackCharge(float charge, const TArray<FAnalyticsEventAttr>& attributes)
{
	FMixpanelModule *mixpanelModule = &FMixpanelModule::Get();
	if (mixpanelModule)
	{
		TArray<FAnalyticsEventAttribute> convertedAttributes;

		for (int32 i = 0; i < attributes.Num(); i++)
		{
			convertedAttributes.Add(FAnalyticsEventAttribute(attributes[i].Name, attributes[i].Value));
		}

		mixpanelModule->TrackCharge(charge, convertedAttributes);
	}
	else
	{
		UE_LOG(LogMixpanelAnalytics, Warning, TEXT("UMixpanelBlueprintFunctionLibrary::TrackCharge: mixpanel module is NULL"));
	}
}

void UMixpanelBlueprintFunctionLibrary::StoreUserProfileData(const TArray<FAnalyticsEventAttr>& attributes, const TArray<FAnalyticsEventAttr>& incrementAttributes)
{
	FMixpanelModule *mixpanelModule = &FMixpanelModule::Get();
	if (mixpanelModule)
	{
		TArray<FAnalyticsEventAttribute> convertedAttributes;
		TArray<FAnalyticsEventAttribute> convertedIncrementAttributes;

		for (int32 i = 0; i < attributes.Num(); i++)
		{
			convertedAttributes.Add(FAnalyticsEventAttribute(attributes[i].Name, attributes[i].Value));
		}

		for (int32 i = 0; i < incrementAttributes.Num(); i++)
		{
			convertedIncrementAttributes.Add(FAnalyticsEventAttribute(incrementAttributes[i].Name, incrementAttributes[i].Value));
		}

		mixpanelModule->StoreUserProfileData(convertedAttributes, convertedIncrementAttributes);
	}
	else
	{
		UE_LOG(LogMixpanelAnalytics, Warning, TEXT("UMixpanelBlueprintFunctionLibrary::StoreUserProfileData: mixpanel module is NULL"));
	}
}


