#pragma once

#include "CoreMinimal.h"
#include "GlobalEnums.h"
#include "DialogueStructs.generated.h"

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
	EDialogueSpecialEvent SpecialEvent;

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
