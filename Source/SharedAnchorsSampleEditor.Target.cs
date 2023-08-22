/*
Copyright (c) Meta Platforms, Inc. and affiliates.
All rights reserved.

This source code is licensed under the license found in the
LICENSE file in the root directory of this source tree.
*/

using UnrealBuildTool;
using System.Collections.Generic;

public class SharedAnchorsSampleEditorTarget : TargetRules
{
	public SharedAnchorsSampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange(new string[] { "SharedAnchorsSample" });
	}
}
