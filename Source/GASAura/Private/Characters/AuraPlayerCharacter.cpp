// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraPlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

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
