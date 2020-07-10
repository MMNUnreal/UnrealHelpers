#include "MyUE4Project.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Logging/LogMacros.h"
#include "Misc/Paths.h"

void FMyUE4ProjectModule::StartupModule()
{

#if (ENGINE_MINOR_VERSION >= 21)    
	FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping("/Project", ShaderDirectory);
#endif

}

void FMyUE4ProjectModule::ShutdownModule()
{
}

IMPLEMENT_PRIMARY_GAME_MODULE(FMyUE4ProjectModule, MyUE4ProjectName, "MyUE4ProjectName");