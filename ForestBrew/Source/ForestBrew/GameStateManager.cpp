#include "GameStateManager.h"


void AGameStateManager::ChangeAllegiance(EAllegiance NewAllegiance)
{
	CurrentAllegiance = NewAllegiance;
	// Any other logic when allegiance changes
}

void AGameStateManager::AddAllianceEvent(EAllianceEventTriggers NewEvent)
{
	AllianceEventTriggers.Add(NewEvent);
	// Other logic here
}

void AGameStateManager::RemoveAllianceEvent(EAllianceEventTriggers EventToRemove)
{
	AllianceEventTriggers.Remove(EventToRemove);
	// Other logic here
}

bool AGameStateManager::IsAllianceFormed()
{
	return AllianceEventTriggers.Contains(EAllianceEventTriggers::AllianceFormed);
}

void AGameStateManager::UpdateGameStage(EGameStage NewStage)
{
	// TODO: Validate if the stage can be changed
	// TODO: Update the CurrentGameStage
	// TODO: Load new level assets
	// TODO: Set new objectives

	// Validation logic goes here
	
	// Update the CurrentGameStage
	CurrentGameStage = NewStage;
	
	// Trigger delegate
	OnGameStateChangeDelegate.Broadcast(NewStage);

	// Notify observers
	for (IGameStateObserver* Observer : Observers)
	{
		Observer->OnGameStageChanged(NewStage);
	}
}

void AGameStateManager::UpdateNPCStatus(ENPCStatus NewStatus)
{
	// TODO: Validate if the status change is valid
	// TODO: Update the NPC status across the game
	// TODO: Trigger any corresponding events
}

void AGameStateManager::UpdatePlayerStatus(ENPCStatus NewStatus)
{
	// TODO: Validate if the status change is valid
	// TODO: Update the player's HUD or other UI elements
	// TODO: Trigger any corresponding events
}

void AGameStateManager::StartTimedEvent(float Duration, EEventType EventType)
{
	// TODO: Validate EventType and Duration
	// TODO: Start the timer
	// TODO: Execute event logic once timer reaches zero
	// GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &AGameStateManager::YourFunctionName, Duration, false);
}

void AGameStateManager::AdvanceGameStage(EGameStage NewStage)
{
	// TODO: Change the game stage
}

void AGameStateManager::RegisterToSaveLoadManager()
{
	// TODO: Register this class instance to SaveLoadManager
	// TODO: Determine which variables need to be saved/loaded
}

void AGameStateManager::TriggerInvasion()
{
	// TODO: Trigger an invasion
}

void AGameStateManager::HandleVillageEvents()
{
	// TODO: Handle village events
}

void AGameStateManager::HandleAllianceEvents()
{
	// TODO: Handle alliance events
}

void AGameStateManager::SetGameProgressFlag(FString FlagName, bool FlagValue)
{
	// TODO: Set a game progress flag
}

void AGameStateManager::SetEndGameStatus(EEndGameStatus Status)
{
	// TODO: Set the end game status
}

void AGameStateManager::OnGameStateChange()
{
	// Listener method for invoking whenever the game state changes
	// Implement logic that should be universally executed when the game state changes
}

void AGameStateManager::AddObserver(IGameStateObserver* Observer)
{
	if (Observer && !Observers.Contains(Observer))
	{
		Observers.Add(Observer);
	}
}

void AGameStateManager::RemoveObserver(IGameStateObserver* Observer)
{
	Observers.Remove(Observer);
}

void AGameStateManager::InitializeGameState() {
	// Set default values for allegiance and alliance triggers
	CurrentAllegiance = EAllegiance::None;
	
	// Initialize empty array; to be populated based on game events
	AllianceEventTriggers.Empty();

	// Initialize game stage
	CurrentGameStage = EGameStage::Tutorial;  // or whatever default state
	
	// Initialize End Game Status
	EndGameStatus = EEndGameStatus::InProgress;
	
	// TODO: Initialize other subsystems
}

