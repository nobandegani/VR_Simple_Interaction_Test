// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "KobodurCharacter.h"

#include "KobodurPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class KOBODUR_API AKobodurPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay();

	UPROPERTY()
	AKobodurCharacter* CharacterRef1 = nullptr;

	UPROPERTY()
	AKobodurCharacter* CharacterRef2 = nullptr;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void ChangePawn();
};
