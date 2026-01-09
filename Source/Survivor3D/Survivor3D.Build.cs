// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Survivor3D : ModuleRules
{
	public Survivor3D(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Survivor3D",
			"Survivor3D/Variant_Platforming",
			"Survivor3D/Variant_Platforming/Animation",
			"Survivor3D/Variant_Combat",
			"Survivor3D/Variant_Combat/AI",
			"Survivor3D/Variant_Combat/Animation",
			"Survivor3D/Variant_Combat/Gameplay",
			"Survivor3D/Variant_Combat/Interfaces",
			"Survivor3D/Variant_Combat/UI",
			"Survivor3D/Variant_SideScrolling",
			"Survivor3D/Variant_SideScrolling/AI",
			"Survivor3D/Variant_SideScrolling/Gameplay",
			"Survivor3D/Variant_SideScrolling/Interfaces",
			"Survivor3D/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
