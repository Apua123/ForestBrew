#pragma once

#include "CoreMinimal.h"
#include "EventStructs.h"
#include "Engine/DataAsset.h"
#include "EventDataAsset.generated.h"

UCLASS(BlueprintType)
class FORESTBREW_API UEventDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	TMap<FString, FEventDetail> EventDetailMap;

	UPROPERTY(BlueprintReadWrite)
	TMap<FString, FEventTrigger> GlobalTriggerMap;
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> RelatedNPCs;

	UPROPERTY(BlueprintReadWrite)
	TArray<FString> RelatedItems;

	UPROPERTY(BlueprintReadWrite)
	TArray<FString> RelatedQuests;

	UPROPERTY(BlueprintReadWrite)
	TMap<FString, FEventTriggerArray> EventTriggerMappings;
};
