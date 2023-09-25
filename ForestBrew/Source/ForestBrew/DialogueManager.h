// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalEnums.h"
#include "DialogueStructs.h"
#include "UObject/NoExportTypes.h"
#include "DialogueManager.generated.h"

UCLASS()
class FORESTBREW_API UDialogueManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UDialogueManager();
	
	UPROPERTY(BlueprintReadOnly)
	TArray<FString> DialogueOptions;

	UPROPERTY(BlueprintReadOnly)
	EDialogueSpeaker CurrentSpeaker;

	UPROPERTY(BlueprintReadOnly)
	TArray<EDialogueSpeaker> MultiNPCSpeakers;

	UPROPERTY(BlueprintReadOnly)
	TMap<EInvadingVillageType, FDialogueStringArray> VillageBasedDialogues;
	
	void StartDialogue(EDialogueSpeaker NPC_Speaker);
	void ChooseDialogueOption(int32 Index);
	void ExecuteDialogueOutcome(EDialogueSpecialEvent SpecialEvent);
	void LoadDialogueBranch();

	// For future use
	void RegisterDialogueEvents();
	void UnregisterDialogueEvents();
	void HandleSpecialEvent(EDialogueSpecialEvent SpecialEvent);
	void SetDialogueTiming(float InitialDelay, TArray<float> AdditionalPauses);
	void LoadVillageSpecificDialogue(EInvadingVillageType VillageType);
};
