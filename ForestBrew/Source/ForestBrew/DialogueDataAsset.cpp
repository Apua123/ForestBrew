// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueDataAsset.h"

UDialogueDataAsset::UDialogueDataAsset()
{
	InitializeDialogueData();
}

void UDialogueDataAsset::InitializeDialogueData()
{
	InitializeDialogueBranches();
	InitializeVillageSpecificMappings();
	InitializeDialogueIDMappings();
}

void UDialogueDataAsset::InitializeDialogueBranches()
{
	// Example Dialogue Branch for FishingVillage
	FDialogueBranch FishingVillageBranch;
	FishingVillageBranch.BranchID = "FishingVillageIntro";
	FishingVillageBranch.DialogueText = "Welcome to the Fishing Village!";
	FishingVillageBranch.IsEnding = false;
	FishingVillageBranch.SpeakerName = EDialogueSpeaker::HumanSettler;
    
	// Adding options to this branch
	FDialogueOption Option1;
	Option1.OptionText = "Thank you!";
	Option1.BranchType = EDialogueBranch::Neutral;
	Option1.OutcomeType = EDialogueOutcome::GainInfo;
	Option1.SpeakerName = EDialogueSpeaker::Player;

	FishingVillageBranch.DialogueOptions.Add(Option1);
	DialogueBranches.Add(FishingVillageBranch);

	// Example Dialogue Branch for TradingVillage
	FDialogueBranch TradingVillageBranch;
	TradingVillageBranch.BranchID = "TradingVillageIntro";
	TradingVillageBranch.DialogueText = "Welcome to the Trading Village!";
	TradingVillageBranch.IsEnding = false;
	TradingVillageBranch.SpeakerName = EDialogueSpeaker::HumanSettler;

	// Adding options to this branch
	FDialogueOption Option2;
	Option2.OptionText = "Thank you!";
	Option2.BranchType = EDialogueBranch::Neutral;
	Option2.OutcomeType = EDialogueOutcome::GainInfo;
	Option2.SpeakerName = EDialogueSpeaker::Player;

	TradingVillageBranch.DialogueOptions.Add(Option2);
	DialogueBranches.Add(TradingVillageBranch);

	// Example Dialogue Branch for HunterVillage
	FDialogueBranch HunterVillageBranch;
	HunterVillageBranch.BranchID = "HunterVillageIntro";
	HunterVillageBranch.DialogueText = "Welcome to the Hunter Village!";
	HunterVillageBranch.IsEnding = false;
	HunterVillageBranch.SpeakerName = EDialogueSpeaker::HumanSettler;

	// Adding options to this branch
	FDialogueOption Option3;
	Option3.OptionText = "Thank you!";
	Option3.BranchType = EDialogueBranch::Neutral;
	Option3.OutcomeType = EDialogueOutcome::GainInfo;
	Option3.SpeakerName = EDialogueSpeaker::Player;

	HunterVillageBranch.DialogueOptions.Add(Option3);
	DialogueBranches.Add(HunterVillageBranch);

	// Example Dialogue Branch for FarmerVillage
	FDialogueBranch FarmerVillageBranch;
	FarmerVillageBranch.BranchID = "FarmerVillageIntro";
	FarmerVillageBranch.DialogueText = "Welcome to the Farmer Village!";
	FarmerVillageBranch.IsEnding = false;
	FarmerVillageBranch.SpeakerName = EDialogueSpeaker::HumanSettler;

	// Adding options to this branch
	FDialogueOption Option4;
	Option4.OptionText = "Thank you!";
	Option4.BranchType = EDialogueBranch::Neutral;
	Option4.OutcomeType = EDialogueOutcome::GainInfo;
	Option4.SpeakerName = EDialogueSpeaker::Player;

	FarmerVillageBranch.DialogueOptions.Add(Option4);
	DialogueBranches.Add(FarmerVillageBranch);
}

void UDialogueDataAsset::InitializeVillageSpecificMappings()
{
	// Populate VillageSpecificDialogueMapping
	FDialogueStringArray FishingVillageDialogue;
	FishingVillageDialogue.StringArray.Add(TEXT("FishingVillageIntro"));
	VillageSpecificDialogueMapping.Add(EInvadingVillageType::FishingVillage, FishingVillageDialogue);

	FDialogueStringArray TradingVillageDialogue;
	TradingVillageDialogue.StringArray.Add(TEXT("TradingVillageIntro"));
	VillageSpecificDialogueMapping.Add(EInvadingVillageType::TradingVillage, TradingVillageDialogue);

	FDialogueStringArray HunterVillageDialogue;
	HunterVillageDialogue.StringArray.Add(TEXT("HunterVillageIntro"));
	VillageSpecificDialogueMapping.Add(EInvadingVillageType::HunterVillage, HunterVillageDialogue);

	FDialogueStringArray FarmerVillageDialogue;
	FarmerVillageDialogue.StringArray.Add(TEXT("FarmerVillageIntro"));
	VillageSpecificDialogueMapping.Add(EInvadingVillageType::FarmerVillage, FarmerVillageDialogue);
}

void UDialogueDataAsset::InitializeDialogueIDMappings()
{
	int32 counter = 0;
	for (const auto& Elem : DialogueBranches)
	{
		DialogueIDMappings.Add(Elem.BranchID, counter++);
	}
}
