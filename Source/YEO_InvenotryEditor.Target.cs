// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class YEO_InvenotryEditorTarget : TargetRules
{
	public YEO_InvenotryEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("YEO_Invenotry");
	}
}
