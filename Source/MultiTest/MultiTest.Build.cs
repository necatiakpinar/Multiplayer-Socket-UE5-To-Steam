// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class  MultiTest : ModuleRules
{
	public MultiTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "OnlineSubsystemSteam" , "OnlineSubsystem"});
	}
}
