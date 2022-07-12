// Basza. All Rights Reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class BaszaTarget : TargetRules
{
	public BaszaTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Basza" } );
	}
}
