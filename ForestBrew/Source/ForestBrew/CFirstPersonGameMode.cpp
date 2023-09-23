// Fill out your copyright notice in the Description page of Project Settings.


#include "CFirstPersonGameMode.h"
#include "GameStateManager.h"
#include "UObject/ConstructorHelpers.h"


ACFirstPersonGameMode::ACFirstPersonGameMode()
{
	// Set the default pawn class to our Blueprinted character in the file path C:/Git Repository/tiimi2/ForestBrew/Content/FirstPerson/Blueprints/BP_FirstPersonCharacter.uasset
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// Set default game state to our custom GameStateManager class
	GameStateClass = AGameStateManager::StaticClass();
}

void ACFirstPersonGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Get a reference to the GameStateManager
	AGameStateManager* GameStateManager = Cast<AGameStateManager>(GameState);

	// Initialize the game state
	GameStateManager->InitializeGameState();
}

