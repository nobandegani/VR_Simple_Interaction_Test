// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmmoPickup.generated.h"

UCLASS()
class KOBODUR_API AAmmoPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmoPickup();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	USceneComponent* SceneComponent;
	
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite, Category=Mesh)
	UStaticMeshComponent* AmmoPickupMesh;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = Step1, meta = ( DisplayName="Bullets" ))
	int FNumberOfBullets;

	UFUNCTION()
	void AfterPickup();
};
