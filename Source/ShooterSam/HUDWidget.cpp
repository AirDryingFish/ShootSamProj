// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"

void UHUDWidget::SetHPBarPercent(float HealthPercent)
{
	HealthPercent = FMath::Clamp(HealthPercent, 0.0f, 1.0f);
	if (HealthPercent >= 0.0f && HealthPercent <= 1.0f)
	{
		HPBar->SetPercent(HealthPercent);
	}
}
