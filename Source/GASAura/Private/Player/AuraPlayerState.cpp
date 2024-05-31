// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

AAuraPlayerState::AAuraPlayerState()
{
	// 关联GAS，需要提高刷新频率
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	

	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
