// Fill out your copyright notice in the Description page of Project Settings.
#include "Time/TimeLibrary.h"
#include "Kismet/KismetMathLibrary.h"


EDayInWeek UTimeLibrary::GetDayofWeak()
{
	return (EDayInWeek)UKismetMathLibrary::Today().GetDayOfWeek();
}
