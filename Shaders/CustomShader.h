#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

//Class name: MyUE4ProjectNameModule

class FMyUE4ProjectModule
	/* only IModuleInterface necessary if not hosting gamemode in this module */
	: public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
