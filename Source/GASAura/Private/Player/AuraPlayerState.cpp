// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	// 关联GAS，需要提高刷新频率
	NetUpdateFrequency = 100.f;
}
