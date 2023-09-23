#pragma once

#include "CoreMinimal.h"
#include "GlobalEnums.h"
#include "GameFramework/GameStateBase.h"
#include "GameStateManager.generated.h"


// Declare a class for the Observer Interface
UINTERFACE(BlueprintType)
class UGameStateObserver : public UInterface
{
	GENERATED_BODY()
};

class IGameStateObserver
{
	GENERATED_BODY()

public:
	virtual void OnGameStageChanged(EGameStage NewStage) = 0;
};

UCLASS()
class FORESTBREW_API AGameStateManager : public AGameStateBase
{
	GENERATED_BODY()

public:
	// Declare a delegate for GameState changes
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStateChangeSignature, EGameStage, NewGameStage);

	// Methods to add and remove observers
	void AddObserver(IGameStateObserver* Observer);
	void RemoveObserver(IGameStateObserver* Observer);
	
	UPROPERTY(BlueprintAssignable)
	FOnGameStateChangeSignature OnGameStateChangeDelegate;
	
	UPROPERTY(BlueprintReadWrite, Category="Game State")
	EAllegiance CurrentAllegiance;

	UPROPERTY(BlueprintReadWrite, Category="Game State")
	TArray<EAllianceEventTriggers> AllianceEventTriggers;

	UPROPERTY(BlueprintReadWrite, Category="Game State")
	EGameStage CurrentGameStage;

	UPROPERTY(BlueprintReadWrite, Category="Game State")
	TMap<FString, bool> GameProgressFlags;

	UPROPERTY(BlueprintReadWrite, Category="Game State")
	EEndGameStatus EndGameStatus;
	
	UFUNCTION(BlueprintCallable, Category="Game State")
	void InitializeGameState();

	UFUNCTION(BlueprintCallable, Category="Game State")
	void OnGameStateChange();
	
	UFUNCTION(BlueprintCallable, Category="Game State")
	void ChangeAllegiance(EAllegiance NewAllegiance);

	UFUNCTION(BlueprintCallable, Category="Game State")
	void AddAllianceEvent(EAllianceEventTriggers NewEvent);

	UFUNCTION(BlueprintCallable, Category="Game State")
	void RemoveAllianceEvent(EAllianceEventTriggers EventToRemove);

	UFUNCTION(BlueprintCallable, Category="Game State")
	bool IsAllianceFormed();

	UFUNCTION(BlueprintCallable, Category="Game State")
	void UpdateGameStage(EGameStage NewStage);

	UFUNCTION(BlueprintCallable, Category="Game State")
	void UpdateNPCStatus(ENPCStatus NewStatus);

	UFUNCTION(BlueprintCallable, Category="Game State")
	void UpdatePlayerStatus(ENPCStatus NewStatus);

	UFUNCTION(BlueprintCallable, Category="Game State")
	void StartTimedEvent(float Duration, EEventType EventType);

	UFUNCTION(BlueprintCallable, Category="Game State")
	void AdvanceGameStage(EGameStage NewStage);

	UFUNCTION(BlueprintCallable, Category="Game State")
	void RegisterToSaveLoadManager();

	UFUNCTION(BlueprintCallable, Category="Game State")
	void TriggerInvasion();

	UFUNCTION(BlueprintCallable, Category="Game State")
	void HandleVillageEvents();

	UFUNCTION(BlueprintCallable, Category="Game State")
	void HandleAllianceEvents();

	UFUNCTION(BlueprintCallable, Category="Game State")
	void SetGameProgressFlag(FString FlagName, bool FlagValue);

	UFUNCTION(BlueprintCallable, Category="Game State")
	void SetEndGameStatus(EEndGameStatus Status);

private:
	TArray<IGameStateObserver*> Observers;
};
