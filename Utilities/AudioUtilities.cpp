// Copyright Mirren MN


#include "AudioUtilities.h"
#include "Materials/Material.h"
#include "AssetRegistryModule.h"
#include "Containers/UnrealString.h"
#include "Misc/FileHelper.h"

TArray<FString> UAudioUtilities::GetAllMaterialObjectsAsStrings(const FName FolderPath)
{
	TArray<UMaterial*> AllMaterials;
	TArray<FString> MaterialStrings;
	GetObjectsOfClass<UMaterial>(AllMaterials, FolderPath);

	for (const auto& material : AllMaterials)
	{
		MaterialStrings.AddUnique(material->GetFName().ToString());
	}

	return MaterialStrings;
}

/** Save array of string names of assets to a txt file which can be convertes to csv **/
/** Need to iterate on the file not save over, find way of comparing with previous list what is new. Or what isn't included in wwise switches **/
bool UAudioUtilities::SaveStringsToFile(UPARAM(ref) const TArray<FString>& StringArrayIn, const FString& FileNameIn)
{
	FString csvString = "";
	for(const auto& string : StringArrayIn)
	{
		csvString.Append(string + ",");
		
	}

	return FFileHelper::SaveStringToFile(csvString, *(FPaths::ProjectDir() + FileNameIn));
}
