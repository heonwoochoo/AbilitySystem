// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AbilitySystem : ModuleRules
{
	public AbilitySystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });

		PublicIncludePaths.Add("AbilitySystem/");

        PublicDependencyModuleNames.AddRange(new string[] { 
		"GameplayAbilities",
		"GameplayTags",
		"GameplayTasks"
		});
    }
}
