// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PxStrm : ModuleRules
{
	public PxStrm(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "RHI", "RenderCore" });
	}
}
