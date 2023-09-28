#pragma once

#include "CoreMinimal.h"
#include "DialogueStructs.generated.h"

UENUM(BlueprintType)
enum class EDialogueBranch : uint8
{
	None,
	Neutral,
	SideWithForestDenizen,
	SideWithSettler,
	EndGameChoice,
	SpecialEvent
};

UENUM(BlueprintType)
enum class EDialogueOutcome : uint8
{
	None,
	GainRecipe,
	GainInfo,
	ChangeAllegiance,
	ChangeWeather,
	ChangeTimeOfDay,
};

UENUM(BlueprintType)
enum class EDialogueSpeaker : uint8
{
	None,
	Player,
	ElderSageTree,
	ForestDenizen,
	HumanSettler
};

UENUM(BlueprintType)
enum class EDialogueTimingType : uint8
{
	ShowForXSeconds,
	PauseBeforeNextLine
};

UENUM(BlueprintType)
enum class EPlayerResponse : uint8
{
	Response1,
	Response2,
	Response3,
};

USTRUCT(BlueprintType)
struct FDialogueOption
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FString OptionText;

	UPROPERTY(BlueprintReadWrite)
	EDialogueBranch BranchType;
	
	UPROPERTY(BlueprintReadWrite)
	EDialogueOutcome OutcomeType;

	UPROPERTY(BlueprintReadWrite)
	EDialogueSpeaker SpeakerName;

	UPROPERTY(BlueprintReadWrite)
	float ShowForSeconds;

	UPROPERTY(BlueprintReadWrite)
	float PauseBeforeNext;
};

USTRUCT(BlueprintType)
struct FDialogueBranch
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FString BranchID;

	UPROPERTY(BlueprintReadWrite)
	FString DialogueText;

	UPROPERTY(BlueprintReadWrite)
	bool IsEnding;

	UPROPERTY(BlueprintReadWrite)
	TArray<FDialogueOption> DialogueOptions;
	
	UPROPERTY(BlueprintReadWrite)
	float InitialDelay;

	UPROPERTY(BlueprintReadWrite)
	TArray<float> AdditionalPauses;

	UPROPERTY(BlueprintReadWrite)
	EDialogueSpeaker SpeakerName;
};

USTRUCT(BlueprintType)
struct FMultiNPCDialogueBranch
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString BranchID;

	UPROPERTY(BlueprintReadWrite)
	TArray<FString> DialogueText;

	UPROPERTY(BlueprintReadWrite)
	TArray<FDialogueOption> DialogueOptions;

	UPROPERTY(BlueprintReadWrite)
	TArray<EDialogueSpeaker> SpeakerNames;
};

// Encapsulate the array of strings in a struct because TMap doesn't support TArray as a value
USTRUCT(BlueprintType)
struct FDialogueStringArray
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TArray<FString> StringArray;
};
