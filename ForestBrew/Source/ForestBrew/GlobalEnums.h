#pragma once

UENUM(BlueprintType)
enum class EGameStage : uint8
{
	Intro,
	Tutorial,
	EarlyGame,
	MidGame,
	LateGame,
	EndGame
};

UENUM(BlueprintType)
enum class EAllegiance : uint8
{
	None,
	ForestDenizen,
	Settler,
};

UENUM(BlueprintType)
enum class EEndGameStatus : uint8
{
	InProgress,
	ForestDenizenWin,
	SettlerWin,
};

UENUM(BlueprintType)
enum class ENPCStatus : uint8
{
	Idle,
	Patrolling,
	Chasing,
	Attacking,
	Interacting,
	Sleeping
};

UENUM(BlueprintType)
enum class EInvadingVillageType : uint8
{
	FishingVillage,
	TradingVillage,
	HunterVillage,
	FarmerVillage,
	Random,
};

UENUM(BlueprintType)
enum class EAllianceEventTriggers : uint8
{
	AllianceFormed,
	AllianceBroken,
};

UENUM(BlueprintType)
enum class EQuestState : uint8
{
	NotStarted,
	InProgress,
	Completed,
	Failed,
};

UENUM(BlueprintType)
enum class EQuestType : uint8
{
	MainQuest,
	SideQuest,
	Tutorial,
	AllianceQuest,
	CraftingQuest,
	InvasionQuest,
};

UENUM(BlueprintType)
enum class EDependencyType : uint8
{
	Predecessor,
	Optional,
	ChoiceBased,
};

UENUM(BlueprintType)
enum class EEndingType : uint8
{
	NeutralEnding,
	ForestAllianceEnding,
	SettlerAllianceEnding,
};

UENUM(BlueprintType)
enum class EDialogueBranch : uint8
{
	Neutral,
	SideWithForestDenizen,
	SideWithSettler,
	EndGameChoice,
	SpecialEvent
};

UENUM(BlueprintType)
enum class EDialogueOutcome : uint8
{
	GainRecipe,
	GainInfo,
	ChangeAllegiance,
};

UENUM(BlueprintType)
enum class EDialogueSpeaker : uint8
{
	None,
	Player,
	NPC1,
	NPC2,
};

UENUM(BlueprintType)
enum class EDialogueSpecialEvent : uint8
{
	None,
	ChangeWeather,
	ChangeTimeOfDay,
	ChangeAllegiance,
};

UENUM(BlueprintType)
enum class EEventType : uint8
{
	Tutorial,
	Invasion,
	Dialogue,
	Quest,
	Misc,
	WeatherChange,
	SleepCycle,
};

UENUM(BlueprintType)
enum class ETriggerCondition : uint8
{
	None,
	TimeOfDay,
	PlayerLocation,
	Allegiance,
	QuestStatus,
	TimeBased, 
	PlayerAction,   
	Environment     
};

UENUM(BlueprintType)
enum class EEventAction : uint8
{
	StartDialogue,
	StartQuest,
	UpdateHUD,
	ChangeWeather,
};
