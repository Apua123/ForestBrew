// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueManager.h"


UDialogueManager::UDialogueManager() :
	DialogueOptions(),
	CurrentSpeaker(EDialogueSpeaker::None),
	MultiNPCSpeakers(),
	VillageBasedDialogues()
{
	if(!bIsInitialized)
	{
		// Initialize here
		// TODO: Initialize the DialogueAssets
		static ConstructorHelpers::FObjectFinder<UDialogueDataAsset> ElderSageTreeDialogueAsset(TEXT("Path/To/ElderSageTreeDialogueAsset"));
		if (ElderSageTreeDialogueAsset.Succeeded()) {
			DialogueAssets.Add("ElderSageTree", ElderSageTreeDialogueAsset.Object);
		}

		// Set initialization flag
		bIsInitialized = true;
	}
}

UDialogueDataAsset* UDialogueManager::FetchDialogue(FName DialogueID) {
	return DialogueAssets.Contains(DialogueID) ? DialogueAssets[DialogueID] : nullptr;
}

void UDialogueManager::InitializeDialogue(EDialogueSpeaker NPCSpeaker)
{
	switch (NPCSpeaker)
	{
	case EDialogueSpeaker::ElderSageTree:
		CurrentDialogue = ElderSageTreeDialogue;
		break;
	case EDialogueSpeaker::ForestDenizen:
		CurrentDialogue = ForestDenizenDialogue;
		break;
	case EDialogueSpeaker::HumanSettler:
		CurrentDialogue = HumanSettlerDialogue;
		break;
	default:
		CurrentDialogue = nullptr;
		break;
	}

	// Start dialogue, UI updates, etc.
}

void UDialogueManager::LoadDialogue(const FString& DialogueID)
{
	// Check the cache first
	if (CachedDialogueBranches.Contains(DialogueID))
	{
		// Load from cache
	}
	else
	{
		// Load dialogue data from the asset
		/*FDialogueBranch* dialogueBranch = DialogueDataAsset->DialogueIDMappings.Find(DialogueID);
		if(dialogueBranch)
		{
			// Cache it
			CacheDialogueBranch(DialogueID);
            
			// Load the branch
			LoadDialogueBranch(*dialogueBranch);
		}*/
	}
}

void UDialogueManager::CacheDialogueBranch(FString branchId)
{
	// Cache the dialogue branch
}

void UDialogueManager::LoadDialogueOptions(const FDialogueBranch& DialogueBranch)
{
	// Handle dialogue options logic
	// ...
}

void UDialogueManager::LoadDialogueBranch(const FDialogueBranch& DialogueBranch)
{
	// Handle dialogue branch logic
	// ...
}

void UDialogueManager::StartDialogue(EDialogueSpeaker NPC_Speaker)
{
	CurrentSpeaker = NPC_Speaker;
	//LoadDialogue(NPC_Speaker);

	// Continue with logic to display first dialogue
}

void UDialogueManager::BranchDialogue(EPlayerResponse response)
{
	// Logic to change dialogue based on player response
}

void UDialogueManager::ChooseDialogueOption(int32 Index)
{
	if (Index < 0 || Index >= DialogueOptions.Num())
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid dialogue option index."));
		return;
	}
	if (Index >= 0 && Index < DialogueOptions.Num())
	{
		FDialogueOption ChosenOption = DialogueOptions[Index];
		ExecuteDialogueOutcome(ChosenOption.OutcomeType);
		// Other logic here
	}
}

void UDialogueManager::ExecuteDialogueOutcome(EDialogueOutcome ChosenOutcome)
{
	switch(ChosenOutcome)
	{
	case EDialogueOutcome::None:
		break;
	case EDialogueOutcome::GainRecipe:
		break;
	case EDialogueOutcome::GainInfo:
		break;
	case EDialogueOutcome::ChangeAllegiance:
		break;
	case EDialogueOutcome::ChangeWeather:
		break;
	case EDialogueOutcome::ChangeTimeOfDay:
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("Invalid dialogue outcome"));
		break;
	}
}

void UDialogueManager::LoadDialogueBranch(EDialogueBranch BranchType)
{
	// Store previous Dialogue Options in case new ones aren't found
	TArray<FDialogueOption> prevDialogueOptions = DialogueOptions;
    
	// Clear previous Dialogue Options
	DialogueOptions.Empty();
    
	// Search in DialogueDataAsset for relevant dialogue options
	for (auto& Branch : DialogueAsset->DialogueBranches)
	{
		/*if (Branch.BranchType == BranchType) // TODO fix type mismatch
		{
			DialogueOptions = Branch.DialogueOptions;
			return; // Found the correct branch, exit the function
		}*/
	}

	// If this line is reached, no matching branch was found
	DialogueOptions = prevDialogueOptions; // Revert to previous options
}

void UDialogueManager::SetDialogueTiming(float ShowTime, float PauseTime, float InitialDelayTime)
{
	DialogueShowTime = ShowTime;
	DialoguePauseTime = PauseTime;
	InitialDialogueDelayTime = InitialDelayTime;
	// Implement any logic that should trigger when timing is set.
}

void UDialogueManager::ShowNextDialogueLine()
{
	if (bIsFirstLine)
	{
		FTimerHandle InitialDelayHandle;
		GetWorld()->GetTimerManager().SetTimer(InitialDelayHandle, [this]()
		{
			DisplayNextDialogueLine();
		}, InitialDialogueDelayTime, false);

		bIsFirstLine = false;
	}
	else
	{
		DisplayNextDialogueLine();
	}
}

void UDialogueManager::ShowDialogueLine()
{
	// Your code to display the dialogue line
}

void UDialogueManager::HideDialogueLine()
{
	GetWorld()->GetTimerManager().SetTimer(PauseDialogueTimerHandle, [this]()
	{
		ShowNextDialogueLine();
	}, DialoguePauseTime, false);
}

void UDialogueManager::DisplayNextDialogueLine()
{
	ShowDialogueLine();

	GetWorld()->GetTimerManager().SetTimer(ShowDialogueTimerHandle, [this]()
	{
		HideDialogueLine();
	}, DialogueShowTime, false);
}

// ------------------


// Stubbed out for future use

void UDialogueManager::RegisterDialogueEvents()
{
	// Register any delegates or custom events you've defined.
}

void UDialogueManager::UnregisterDialogueEvents()
{
	// Unregister any delegates or custom events you've registered.
}

void UDialogueManager::LoadVillageSpecificDialogue(EInvadingVillageType VillageType)
{
	// Logic here
}
