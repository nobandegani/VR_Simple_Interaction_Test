// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "KobodurHUD.generated.h"

UCLASS()
class AKobodurHUD : public AHUD
{
	GENERATED_BODY()

public:
	AKobodurHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

