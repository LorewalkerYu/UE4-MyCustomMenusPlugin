// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TimeLibrary.generated.h"

UENUM(BlueprintType)
enum class EDayInWeek : uint8
{
	Monday = 0,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};
/**
 * 
 */
UCLASS()
class MYCUSTOMWIDGET_API UTimeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "TimeLibrary")
		static EDayInWeek GetDayofWeak();
};
