// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueManager.h"

UDialogueManager::UDialogueManager() :
	DialogueOptions(),
	CurrentSpeaker(EDialogueSpeaker::None),
	MultiNPCSpeakers(),
	VillageBasedDialogues()
{
	// Initialization code here
}

void UDialogueManager::LoadDialogue(EDialogueSpeaker NPC_Speaker)
{
	// Code to populate DialogueOptions
}

void UDialogueManager::StartDialogue(EDialogueSpeaker NPC_Speaker)
{
	CurrentSpeaker = NPC_Speaker;
	LoadDialogue(NPC_Speaker);

	// Continue with logic to display first dialogue
}

void UDialogueManager::ChooseDialogueOption(int32 Index)
{
	// Logic here
}

void UDialogueManager::ExecuteDialogueOutcome(EDialogueSpecialEvent SpecialEvent)
{
	switch(SpecialEvent)
	{
	case EDialogueSpecialEvent::None:
		break;
	default: break;

		// Handle other special events
	}
}

void UDialogueManager::LoadDialogueBranch()
{
	// Logic here
}


// ------------------


// Stubbed out for future use

void UDialogueManager::RegisterDialogueEvents()
{
	// Dynamic binding code here
}

void UDialogueManager::UnregisterDialogueEvents()
{
	// Dynamic unbinding code here
}

void UDialogueManager::HandleSpecialEvent(EDialogueSpecialEvent SpecialEvent)
{
	// Implement event handling logic
}

void UDialogueManager::SetDialogueTiming(float InitialDelay, TArray<float> AdditionalPauses)
{
	// Logic here
}

void UDialogueManager::LoadVillageSpecificDialogue(EInvadingVillageType VillageType)
{
	// Logic here
}
