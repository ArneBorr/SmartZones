// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GW_SmartZones : ModuleRules
{
	public GW_SmartZones(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
