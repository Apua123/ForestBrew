// Fill out your copyright notice in the Description page of Project Settings.


#include "CFirstPersonGameMode.h"
#include "GameStateManager.h"
#include "CustomPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "DialogueAssetManager.h"


ACFirstPersonGameMode::ACFirstPersonGameMode()
{
	// Set the default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));

	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// Set default game state to our custom GameStateManager class
	GameStateClass = AGameStateManager::StaticClass();

	// Set default player controller to our blueprinted BP_CustomPlayerController class (which is a child of ACustomPlayerController)
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/FirstPerson/Blueprints/BP_CustomPlayerController"));

	if (PlayerControllerBPClass.Class != nullptr)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void ACFirstPersonGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Get a reference to the GameStateManager
	AGameStateManager* GameStateManager = Cast<AGameStateManager>(GameState);

	// Initialize the game state
	GameStateManager->InitializeGameState();

}

