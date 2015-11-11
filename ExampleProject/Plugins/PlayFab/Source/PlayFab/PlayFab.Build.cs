// Some copyright should be here...

using UnrealBuildTool;

public class PlayFab : ModuleRules
{
	public PlayFab(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"PlayFab/Public"
				
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"PlayFab/Private",
				
				// ... add other private include paths required here ...
			}
			);


        PublicIncludePathModuleNames.AddRange(new string[] { "Json" });

        PublicDependencyModuleNames.AddRange(
            new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"InputCore",
                    "Settings",
					"HTTP",
                    "Json",
                    "OnlineSubsystemUtils"
				}
        );
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
				// ... add any modules that your module loads dynamically here ...
			}
			);

        if (UEBuildConfiguration.bBuildEditor == true)
        {

            PublicDependencyModuleNames.AddRange(
                new string[] 
					{
						"UnrealEd", 
					}
            );

        }
	}
}
