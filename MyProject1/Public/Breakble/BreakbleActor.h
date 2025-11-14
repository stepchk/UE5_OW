// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "BreakbleActor.generated.h"

class UGeometryCollectionComponent;

UCLASS()
class MYPROJECT1_API ABreakbleActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	
	ABreakbleActor();
	
	virtual void Tick(float DeltaTime) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* Capsule;

private:	
	
	
	UPROPERTY(EditAnywhere,Category = "Breakble Properties")
	TArray<TSubclassOf<class ATreasure>> TreasureClasses;
	
	bool bBroken = false;

};
