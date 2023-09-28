// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueDataAsset.h"
#include "DialogueStructs.h"
#include "GlobalEnums.h"
#include "UObject/NoExportTypes.h"
#include "DialogueManager.generated.h"

UCLASS()
class FORESTBREW_API UDialogueManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TArray<FDialogueOption> DialogueOptions;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	EDialogueSpeaker CurrentSpeaker;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TArray<EDialogueSpeaker> MultiNPCSpeakers;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TMap<EInvadingVillageType, FDialogueStringArray> VillageBasedDialogues;
	
	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TArray<FString> DialogueLines;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	UDialogueDataAsset* DialogueAsset;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	TMap<FName, UDialogueDataAsset*> DialogueAssets;

	UPROPERTY(BlueprintReadOnly, Category = "Dialogue")
	UDialogueDataAsset* CurrentDialogue;

	// Initialiation flag
	bool bIsInitialized = false;
	// Dialogue line flag
	bool bIsFirstLine = true;

	// Dialogue timing
	float DialogueShowTime = 0.0f;
	float DialoguePauseTime = 0.0f;
	float InitialDialogueDelayTime = 0.0f;

	// Dialogue timers
	FTimerHandle ShowDialogueTimerHandle;
	FTimerHandle PauseDialogueTimerHandle;

	// Dialogue cache
	TMap<FString, FDialogueBranch> CachedDialogueBranches;

	// NPC Dialogue Assets
	UPROPERTY(EditDefaultsOnly, Category = "Dialogue")
	UDialogueDataAsset* ElderSageTreeDialogue;

	UPROPERTY(EditDefaultsOnly, Category = "Dialogue")
	UDialogueDataAsset* ForestDenizenDialogue;

	UPROPERTY(EditDefaultsOnly, Category = "Dialogue")
	UDialogueDataAsset* HumanSettlerDialogue;
	
	UDialogueManager();
	
	UDialogueDataAsset* FetchDialogue(FName DialogueID);
	void InitializeDialogue(EDialogueSpeaker NPCSpeaker);
	void LoadDialogue(const FString& DialogueID);
	void CacheDialogueBranch(FString branchId);
	void LoadDialogueOptions(const FDialogueBranch& DialogueBranch);
	void LoadDialogueBranch(const FDialogueBranch& DialogueBranch);
	void StartDialogue(EDialogueSpeaker NPC_Speaker);
	void BranchDialogue(EPlayerResponse response);
	void ChooseDialogueOption(int32 Index);
	void ExecuteDialogueOutcome(EDialogueOutcome ChosenOutcome);
	void LoadDialogueBranch(EDialogueBranch BranchType);
	void SetDialogueTiming(float ShowTime, float PauseTime, float InitialDelayTime);
	void ShowNextDialogueLine();
	void ShowDialogueLine();
	void HideDialogueLine();
	void DisplayNextDialogueLine();

	// For future use
	void RegisterDialogueEvents();
	void UnregisterDialogueEvents();
	void LoadVillageSpecificDialogue(EInvadingVillageType VillageType);
};
