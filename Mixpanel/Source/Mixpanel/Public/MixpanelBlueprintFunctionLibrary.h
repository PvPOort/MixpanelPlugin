#pragma once

#include "AnalyticsBlueprintLibrary.h"
#include "MixpanelBlueprintFunctionLibrary.generated.h"

UCLASS()
class MIXPANEL_API UMixpanelBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Mixpanel Analytics")
	static void TrackEvent(const FString& eventName, const TArray<FAnalyticsEventAttr>& attributes);

	UFUNCTION(BlueprintCallable, Category = "Mixpanel Analytics")
	static void SetUserID(const FString& userID);

	UFUNCTION(BlueprintCallable, Category = "Mixpanel Analytics")
	static void TrackCharge(float charge, const TArray<FAnalyticsEventAttr>& attributes);

	UFUNCTION(BlueprintCallable, Category = "Mixpanel Analytics")
	static void StoreUserProfileData(const TArray<FAnalyticsEventAttr>& attributes, const TArray<FAnalyticsEventAttr>& incrementAttributes);
};
