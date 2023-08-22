/*
Copyright (c) Meta Platforms, Inc. and affiliates.
All rights reserved.

This source code is licensed under the license found in the
LICENSE file in the root directory of this source tree.
*/

using UnrealBuildTool;

public class SharedAnchorsSample : ModuleRules
{
	public SharedAnchorsSample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"AndroidPermission",
				"UMG",
				"OculusXRHMD",
				"OculusXRAnchors"
			});

		PrivateDependencyModuleNames.AddRange(new string[]
			{
				"Slate",
				"SlateCore",
				"OnlineSubsystem",
				"OnlineSubsystemOculus"
			});

		if (Target.Platform != UnrealTargetPlatform.Android)
		{
			PrecompileForTargets = PrecompileTargetsType.None;
		}
	}
}
