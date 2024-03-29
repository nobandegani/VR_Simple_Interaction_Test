// Copyright Epic Games, Inc. All Rights Reserved.

#include "KobodurGameMode.h"
#include "KobodurHUD.h"
#include "KobodurPlayerController.h"
#include "KobodurCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKobodurGameMode::AKobodurGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = NULL;
	
	// use our custom HUD class
	HUDClass = AKobodurHUD::StaticClass();

	PlayerControllerClass = AKobodurPlayerController::StaticClass();
}
