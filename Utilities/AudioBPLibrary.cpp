// Copyright Mirren MN


#include "AudioBPLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void UAudioBPLibrary::InterpolateListenerPositions(UObject* WorldContextObject, UPARAM(ref) const FVector& CurrentPositionIn, UPARAM(ref) const FVector& TargetPositionIn, const float InterpSpeedIn, FVector& NewListenerPosOut)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	if(World != nullptr)
	{
		auto* PlayerController = World->GetFirstPlayerController();

		if(PlayerController != nullptr)
		{
			FVector NewListenerPosition = FMath::VInterpTo(CurrentPositionIn, TargetPositionIn, World->GetDeltaSeconds(), InterpSpeedIn);
			PlayerController->SetAudioListenerOverride(NULL, NewListenerPosition, FRotator::ZeroRotator);
			NewListenerPosOut = NewListenerPosition;
		}
	}
}

