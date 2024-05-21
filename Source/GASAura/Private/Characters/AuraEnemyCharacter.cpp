// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraEnemyCharacter.h"

void AAuraEnemyCharacter::HighLightActor()
{
	bHighLighted = true;
}

void AAuraEnemyCharacter::UnHighLightActor()
{
	bHighLighted = false;
}
