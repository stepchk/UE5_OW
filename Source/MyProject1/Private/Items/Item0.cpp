 // Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item0.h"
#include "MyProject1/DebugMacros.h"
#include "Components/SphereComponent.h"
#include "MyCharacter.h"
#include "NiagaraComponent.h"

// Sets default values
AItem0::AItem0()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh Component"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());

	EmbersEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Embers"));
	EmbersEffect->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItem0::BeginPlay()
{
	Super::BeginPlay();


	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem0::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem0::OnSphereEndOverlap);
}

float AItem0::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem0::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem0::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	 
	 AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
	 if (MyCharacter) 
	 { 
		 MyCharacter->SetOverlappingItem(this);
	 }
}

void AItem0::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
	if (MyCharacter)
	{
		MyCharacter->SetOverlappingItem(nullptr);
	}

}

// Called every frame
void AItem0::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	if (ItemState == EItemState::EIS_Hovering)
	{
		AddActorWorldOffset(FVector(0.f, 0.f, TransformedSin()));
	}

	
	
	
}
