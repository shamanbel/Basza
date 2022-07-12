// Basza. All Rights Reserved

using UnrealBuildTool;

public class Basza : ModuleRules
{
	public Basza(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {});

		PublicIncludePaths.AddRange(new string[] 
		{
			"Bazsa/Public/Player",
			"Bazsa/Public/Weapon",
			"Bazsa/Public/Components",
			"Bazsa/Public/PickUp",
			"Bazsa/Public/Enemy"

		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
