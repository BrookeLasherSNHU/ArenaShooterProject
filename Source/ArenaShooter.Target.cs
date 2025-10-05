// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ArenaShooterTarget : TargetRules
{
	public ArenaShooterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		AdditionalPlugins.AddRange(new string[] { "EnhancedInput" });
		ExtraModuleNames.AddRange( new string[] { "ArenaShooter" } );
	}
}
