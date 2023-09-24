// Fill out your copyright notice in the Description page of Project Settings.


#include "EventManagerBase.h"

//#include "EventTriggerContainer.h"


void AEventManagerBase::InitializeEvents()
{
	// Initialize Empty Arrays
	EventList.Empty();

	// Load Pre-defined Events
	FEventDetail InitialEvent;
	InitialEvent.EventID = "Tutorial";
	InitialEvent.EventType = EEventType::Tutorial;
	EventList.Add(InitialEvent);

	// Load Events from Data Asset
	InitializeEventFromDataAsset();
	
	// Initialize Event Lookup Map
	InitializeEventList();

	// Set Initialization Flag
	bIsInitialized = true;
}

void AEventManagerBase::InitializeEventList()
{
	for(const auto& Event : EventList)
	{
		TArray<ETriggerCondition> TriggerList = Event.TriggerConditions;
		EventLookupMap.Add(Event.EventID, TriggerList);
	}
}

void AEventManagerBase::InitializeEventFromDataAsset()
{
	//const FString EventDataAssetPath = TEXT("Path/To/Your/DataAsset");
	//UEventDataAsset* MyEventDataAsset = Cast<UEventDataAsset>(LoadObject<UDataAsset>(nullptr, *EventDataAssetPath));

	if (EventDataAsset)
	{
		// Clear existing event list
		EventList.Empty();

		// Update EventList from DataAsset
		for (auto& Elem : EventDataAsset->EventDetailMap)
		{
			FEventDetail Detail = Elem.Value;
			EventList.Add(Detail);
		}

		// Update EventTriggerMappings from DataAsset
		EventTriggerMappings = EventDataAsset->EventTriggerMappings;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load Event Data Asset."));
	}
}

// Method to register an event
void AEventManagerBase::RegisterEvent(FEventDetail NewEvent)
{
	// Code to register the event
}

// Method to trigger an event
void AEventManagerBase::TriggerEvent(FName EventName)
{
	// Code to trigger the event
}

void AEventManagerBase::StartInvasionEvent()
{
	if (InvadingVillageType == EInvadingVillageType::Random)
	{
		// Random invasion logic here, excluding the previous type of invasion if possible
		TArray<EInvadingVillageType> PossibleTypes = {EInvadingVillageType::FishingVillage, EInvadingVillageType::TradingVillage, EInvadingVillageType::HunterVillage, EInvadingVillageType::FarmerVillage};
		PossibleTypes.Remove(PreviousInvadingVillageType);

		int32 RandomIndex = FMath::RandRange(0, PossibleTypes.Num() - 1);
		InvadingVillageType = PossibleTypes[RandomIndex];
		PreviousInvadingVillageType = InvadingVillageType;
	}
	else
	{
		// Specific type of invasion logic here
	}
}

void AEventManagerBase::StartWeatherChangeEvent()
{
	// Code to start the weather change event
}

void AEventManagerBase::StartDialogueEvent()
{
	// Code to start the dialogue event
}

// Method to un-register an event
void AEventManagerBase::UnregisterEvent(FName EventName)
{
	// Code to un-register the event
}

// Sets default values
AEventManagerBase::AEventManagerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEventManagerBase::BeginPlay()
{
	Super::BeginPlay();

	if (!bIsInitialized)
	{
		InitializeEvents();
	}
	CheckInitialization();
}

// Called every frame
void AEventManagerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEventManagerBase::CheckInitialization()
{
	if(EventList.Num() == 0 || EventTriggerMappings.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Event data was not initialized properly."));
	}
}

TOptional<FEventDetail> AEventManagerBase::FindEventByName(FString EventID)
{
	for (auto& EventDetail : EventList)
	{
		if (EventDetail.EventID == EventID)
		{
			return EventDetail;
		}
	}
	return TOptional<FEventDetail>();
}

FEventTriggerArray* AEventManagerBase::FindTriggersByEventName(FString EventID)
{
	if (EventTriggerMappings.Contains(EventID))
	{
		return &EventTriggerMappings[EventID];
	}
	return nullptr;
}

