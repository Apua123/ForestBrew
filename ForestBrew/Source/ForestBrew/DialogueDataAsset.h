// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalEnums.h"
#include "DialogueStructs.h"
#include "Engine/DataAsset.h"
#include "DialogueDataAsset.generated.h"



UCLASS()
class FORESTBREW_API UDialogueDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UDialogueDataAsset();
	
	UPROPERTY(BlueprintReadOnly)
	TArray<FDialogueBranch> DialogueBranches;

	UPROPERTY(BlueprintReadOnly)
	TMap<EInvadingVillageType, FDialogueStringArray> VillageSpecificDialogueMapping;

	UPROPERTY(BlueprintReadOnly)
	TMap<FString, int32> DialogueIDMappings;

	UPROPERTY(BlueprintReadOnly)
	TMap<FString, FMultiNPCDialogueBranch> MultiNPCDialogueMapping;

	// For future use
	UPROPERTY(BlueprintReadOnly)
	TMap<EAllegiance, FDialogueStringArray> AllegianceDialogueMapping;

	UPROPERTY(BlueprintReadOnly)
	TMap<EDialogueSpecialEvent, FDialogueStringArray> SpecialEventDialogueMapping;

	void InitializeDialogueData();
	void InitializeDialogueBranches();
	void InitializeVillageSpecificMappings();
	void InitializeDialogueIDMappings();
};
