// @copyright SKH

using UnrealBuildTool;
using System.Collections.Generic;

public class ObstacleAssaultTarget : TargetRules
{
	public ObstacleAssaultTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "ObstacleAssault" } );
	}
}
