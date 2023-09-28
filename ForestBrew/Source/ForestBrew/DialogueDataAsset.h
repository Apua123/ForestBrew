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
	
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TArray<FDialogueBranch> DialogueBranches;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TMap<EInvadingVillageType, FDialogueStringArray> VillageSpecificDialogueMapping;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TMap<FString, int32> DialogueIDMappings;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TMap<FString, FMultiNPCDialogueBranch> MultiNPCDialogueMapping;
	
	// For future use
	UPROPERTY(BlueprintReadOnly)
	TMap<EAllegiance, FDialogueStringArray> AllegianceDialogueMapping;
	
	void InitializeDialogueData();
	void InitializeDialogueBranches();
	void InitializeVillageSpecificMappings();
	void InitializeDialogueIDMappings();
};
