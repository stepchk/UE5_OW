// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlashOverlay.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT1_API USlashOverlay : public UUserWidget
{
	GENERATED_BODY()

public: 
	void SetHealthBarPercent(float Percent);
	void SetStaminaBarPercent(float Percent);
	void SetGoldCount(int32 GoldCount);
	void SetSoulsCount(int32 SoulsCount);

private:

	UPROPERTY(meta = (BindWindget))
	class UProgressBar* HealthProgressBar;

	UPROPERTY(meta = (BindWindget))
	class UProgressBar* StaminaProgressBar;

	UPROPERTY(meta = (BindWindget))
	class UTextBlock* GoldCountText;

	UPROPERTY(meta = (BindWindget))
	class UTextBlock* SoulsCountText;

	
};
