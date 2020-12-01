// Copyright Mirren MN

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AudioBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class WISEPLAYG_API UAudioBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Will interpolate the audio listener between the current and target position at the given interp speed **/
	UFUNCTION(BlueprintCallable, Category = "Audio")
	static void InterpolateListenerPositions(UObject* WorldContextObject, UPARAM(ref) const FVector& CurrentPositionIn, UPARAM(ref) const FVector& TargetPositionIn, const float InterpSpeedIn, FVector& NewListenerPosOut);
	
};
