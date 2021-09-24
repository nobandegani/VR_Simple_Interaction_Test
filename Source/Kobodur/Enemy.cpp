// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
	:SceneComponent(nullptr),
	EnemypMesh(nullptr),
	FHealth(100.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//create defauly scene component
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("scene component"));
	RootComponent = SceneComponent;
	
	// Create a mesh component that will be used for viewing the ammo pickup
	EnemypMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Enemy Mesh"));
	EnemypMesh->SetupAttachment(SceneComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::TakeRandomDamage(int min, int max)
{
	int RndDamage = FMath::FRandRange( min, max);
	if ( (FHealth - RndDamage) <= 0 )
	{
		FHealth = 0;
		Destroy();
	}else
	{
		FHealth -= RndDamage;
	}
}

