// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventDataAsset.h"
#include "GlobalEnums.h"
#include "GameFramework/Actor.h"
#include "EventManagerBase.generated.h"

UCLASS()
class FORESTBREW_API AEventManagerBase : public AActor
{
	GENERATED_BODY()
	
public:
	// Initialize Events
	void InitializeEvents();

	// Register and Unregister events
	void RegisterEvent(FEventDetail NewEvent);
	void UnregisterEvent(FName EventName);

	// Trigger Events
	void TriggerEvent(FName EventName);

	// Specific Events
	void StartInvasionEvent();
	void StartWeatherChangeEvent();
	void StartDialogueEvent();
	
	// Sets default values for this actor's properties
	AEventManagerBase();
	
	UPROPERTY(EditDefaultsOnly, Category = "Data")
	UEventDataAsset* EventDataAsset;

	UPROPERTY(BlueprintReadWrite, Category = "Events")
	TMap<FString, FEventTriggerArray> EventTriggerMappings;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Event Initialization
	void InitializeEventFromDataAsset();
	void InitializeEventList();
	
	// Event Data Lists and Maps
	TArray<FEventDetail> EventList;
	TMap<FString, TArray<ETriggerCondition>> EventLookupMap;
	
	// Initialization flag
	bool bIsInitialized = false;

	// Invading Village Type
	EInvadingVillageType InvadingVillageType;
	EInvadingVillageType PreviousInvadingVillageType;
	
	void CheckInitialization();
	TOptional<FEventDetail> FindEventByName(FString EventID);
	FEventTriggerArray* FindTriggersByEventName(FString EventID);
	
};
