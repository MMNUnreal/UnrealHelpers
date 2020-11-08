// Copyright Mirren MN

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "AudioUtilities.generated.h"

/**
 *  Functions to be used from within the editor to assist with audio pipeline.
 *  Should move to one plugin so all and future useful functionality is together
 */
UCLASS()
class WISEPLAYG_API UAudioUtilities : public UAssetActionUtility
{
	GENERATED_BODY()

public:
	/** Return all objects of given type from given path **/
	template<typename T>
	void GetObjectsOfClass(TArray<T*>& OutArray, const FName PathIn)
	{
		FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		TArray<FAssetData> AssetData;
		FARFilter Filter;
		Filter.ClassNames.Add(T::StaticClass()->GetFName());
		Filter.PackagePaths.Add(PathIn);
		AssetRegistryModule.Get().GetAssets(Filter, AssetData);

		for (int i = 0; i < AssetData.Num(); i++) {
			T* Object = Cast<T>(AssetData[i].GetAsset());
			OutArray.Add(Object);
		}
	}
	

	UFUNCTION(BlueprintCallable, Category="SDAudioUtilities")
	TArray<FString> GetAllMaterialObjectsAsStrings(const FName FolderPath);

	UFUNCTION(BlueprintCallable, Category = "SDAudioUtilities")
	static bool SaveStringsToFile(UPARAM(ref) const TArray<FString>& StringArrayIn, const FString& FileNameIn);

};
