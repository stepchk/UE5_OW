// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Engine/SkeletalMesh.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);

	SetRootComponent(Capsule);

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Bird Mesh"));
	BirdMesh->SetupAttachment(GetRootComponent());
	
	

	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	CameraArm->SetupAttachment(GetRootComponent());
	CameraArm->TargetArmLength = 300.f;

	ViewCamera0 = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	ViewCamera0-> SetupAttachment(CameraArm);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABird::MoveForward(float Value)
{
	if (Controller && (Value != 0.f))
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
	}
	
}

void ABird::Turn(float Value)
{
	AddControllerYawInput(Value);

}

void ABird::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ABird::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ABird::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ABird::LookUp);
}

