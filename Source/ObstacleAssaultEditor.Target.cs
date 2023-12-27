// @copyright SKH

using UnrealBuildTool;
using System.Collections.Generic;

public class ObstacleAssaultEditorTarget : TargetRules
{
	public ObstacleAssaultEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "ObstacleAssault" } );
	}
}
