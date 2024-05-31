// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerState.h"
#include "Player/AuraPlayerState.h"

AAuraPlayerCharacter::AAuraPlayerCharacter()
{
	// 角色朝向运动方向
	GetCharacterMovement()->bOrientRotationToMovement = true;	
	// 转身速率
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	// QT：约束到平面上？？
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// 不使用控制器旋转
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
}

void AAuraPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Server
	InitAbilityActorInfo();
}

void AAuraPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Client
	InitAbilityActorInfo();
}

void AAuraPlayerCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
