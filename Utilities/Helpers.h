// BY RAMA

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class AUDIODEMO_API Helpers
{
public:
	Helpers();

	class UTextUtil {
	public:

		/** Gets corresponding enum value given the enum to search and the string name**/
		template <typename EnumType>
		static FORCEINLINE EnumType GetEnumValueFromString(const FString& EnumName, const FString& String)
		{
			UEnum* Enum = FindObject<UEnum>(ANY_PACKAGE, *EnumName, true);
			if (!Enum)
			{
				return EnumType(0);
			}
			return (EnumType)Enum->GetIndexByName(FName(*String));
		}

		/** Gets corresponding string value of a given enum **/
		template<typename TEnum>
		static FORCEINLINE FString GetEnumValueAsString(const FString& Name, TEnum Value)
		{
			const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
			if (!enumPtr)
			{
				return FString("Invalid");
			}
			return enumPtr->GetValueByName((int64)Value).ToString();
		}
	};


	~Helpers();
};
