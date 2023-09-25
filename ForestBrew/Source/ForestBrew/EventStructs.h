#pragma once

#include "CoreMinimal.h"
#include "GlobalEnums.h"
#include "EventStructs.generated.h"

USTRUCT(BlueprintType)
struct FEventDetail
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString EventID;

	UPROPERTY(BlueprintReadWrite)
	EEventType EventType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EventPriority;

	UPROPERTY(BlueprintReadWrite)
	float Duration;

	UPROPERTY(BlueprintReadWrite)
	TArray<ETriggerCondition> TriggerConditions;

	UPROPERTY(BlueprintReadWrite)
	TArray<EEventAction> Actions;
};

USTRUCT(BlueprintType)
struct FEventTrigger
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FString TriggerID;

	UPROPERTY(BlueprintReadWrite)
	FString AssociatedEventID;

	//UPROPERTY(BlueprintReadWrite)
	//EGameEventTriggerType TriggerType;

	//UPROPERTY(BlueprintReadWrite)
	//TMap<ETriggerVariableType, FString> TriggerData;
};

USTRUCT(BlueprintType)
struct FEventTriggerArray
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TArray<FEventTrigger> EventTriggers;
};
