/*
Copyright (c) Meta Platforms, Inc. and affiliates.
All rights reserved.

This source code is licensed under the license found in the
LICENSE file in the root directory of this source tree.
*/

using UnrealBuildTool;
using System.Collections.Generic;

public class SharedAnchorsSampleTarget : TargetRules
{
	public SharedAnchorsSampleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange(new string[] { "SharedAnchorsSample" });
	}
}
