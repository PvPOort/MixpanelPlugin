// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MixpanelSDK : ModuleRules
{
    public MixpanelSDK(TargetInfo Target)
    {
        Type = ModuleType.External;

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            string configuration = Target.Configuration == UnrealTargetConfiguration.DebugGame ? "Debug" : "Release";

            PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
                        "Mixpanel",
                        "IOS/MixpanelSDK/" + configuration + "/Mixpanel.embeddedframework.zip"
                    )
                );

            PublicFrameworks.AddRange(
                new string[] {
                    "CoreTelephony",
                    "SystemConfiguration",
                    "UIKit",
                    "Foundation",
                    "CoreGraphics",
                    "Accelerate",
                    "QuartzCore",
                    "CFNetwork",
                    "Security",
                });

            PublicAdditionalLibraries.AddRange(
                        new string[] {
                            "icucore"
                    });
        }
    }
}
