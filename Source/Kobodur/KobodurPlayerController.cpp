// Fill out your copyright notice in the Description page of Project Settings.


#include "KobodurPlayerController.h"

#include "KobodurCharacter.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"

void AKobodurPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	// get all player starts
	TSubclassOf<APlayerStart> classToFind;
	classToFind = APlayerStart::StaticClass();
	TArray<AActor*> foundEnemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), classToFind, foundEnemies);

	//spawn characters
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	//get class of character bp
	UObject* SpawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Game/FirstPersonCPP/Blueprints/BP_FirstPersonCharacter.BP_FirstPersonCharacter")));
	UBlueprint* GeneratedBP = Cast<UBlueprint>(SpawnActor);
	
	CharacterRef1 = GetWorld()->SpawnActor<AKobodurCharacter>(GeneratedBP->GeneratedClass, foundEnemies[0]->GetActorLocation(), foundEnemies[0]->GetActorRotation(), SpawnInfo);
	CharacterRef2 = GetWorld()->SpawnActor<AKobodurCharacter>(GeneratedBP->GeneratedClass, foundEnemies[1]->GetActorLocation(), foundEnemies[1]->GetActorRotation(), SpawnInfo);
	
	this->UnPossess();
	this->Possess(CharacterRef1);
}

void AKobodurPlayerController::ChangePawn()
{
	if ( UGameplayStatics::GetPlayerPawn(this, 0) == CharacterRef1 )
	{
		this->Possess(CharacterRef2);
	}else
	{
		this->Possess(CharacterRef1);
	}
}

void AKobodurPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
 
	InputComponent->BindAction("ChangePawn", IE_Pressed, this, &AKobodurPlayerController::ChangePawn);
}



