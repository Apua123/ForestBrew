// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyNativeCharacter.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"


UCLASS(Blueprintable)
class FORESTBREW_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
};
