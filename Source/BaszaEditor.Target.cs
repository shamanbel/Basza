// Basza. All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class BaszaEditorTarget : TargetRules
{
	public BaszaEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Basza" } );
	}
}
