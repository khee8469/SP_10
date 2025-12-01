// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SP_10 : ModuleRules
{
	public SP_10(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",

			"UMG",
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        PublicIncludePaths.AddRange(new string[] { "SP_10" });
    }
}
