// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CFirstPersonGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FORESTBREW_API ACFirstPersonGameMode : public AGameModeBase
{
	GENERATED_BODY()

	ACFirstPersonGameMode();
	void BeginPlay();
};
