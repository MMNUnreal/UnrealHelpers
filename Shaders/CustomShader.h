#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

//Class name: MyUE4ProjectNameModule

//To use custom HLSL shader code you need to use custom startup module in UE4

class FMyUE4ProjectModule
	/* only IModuleInterface necessary if not hosting gamemode in this module */
	: public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
