// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class KOBODUR_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	USceneComponent* SceneComponent;
	
	/** Enemy Mesh*/
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite, Category=Mesh)
	UStaticMeshComponent* EnemypMesh;

	UPROPERTY( BlueprintReadOnly, Category = Step4, meta = ( DisplayName="Health" ))
	float FHealth;

	UFUNCTION()
	void TakeRandomDamage(int min, int max);
};
