// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoPickup.h"

// Sets default values
AAmmoPickup::AAmmoPickup()
	: SceneComponent(nullptr),
	AmmoPickupMesh(nullptr),
	FNumberOfBullets(50)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create defauly scene component
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("scene component"));
	RootComponent = SceneComponent;
	
	// Create a mesh component that will be used for viewing the ammo pickup
	AmmoPickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AmmoPickupMesh"));
	AmmoPickupMesh->SetupAttachment(SceneComponent);
	AmmoPickupMesh->SetCollisionObjectType(ECC_Pawn);
	AmmoPickupMesh->SetCollisionProfileName("OverlapAll");
}

// Called when the game starts or when spawned
void AAmmoPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmoPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmmoPickup::AfterPickup()
{
	this->Destroy();
}

