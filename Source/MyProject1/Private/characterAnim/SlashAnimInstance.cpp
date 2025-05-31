// Fill out your copyright notice in the Description page of Project Settings.


#include "characterAnim/SlashAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void USlashAnimInstance::NativeInitializeAnimation()
{	
	Super::NativeInitializeAnimation();

	MyCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
	if (MyCharacter)
	{
		MyCharacterMovement = MyCharacter->GetCharacterMovement();
	}
	
}

void USlashAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (MyCharacterMovement)
	{
		
		GroundSpeed =  UKismetMathLibrary::VSizeXY(MyCharacterMovement->Velocity);
		IsFalling = MyCharacterMovement->IsFalling();
		CharacterState = MyCharacter->GetCharacterState();
	}
}	
