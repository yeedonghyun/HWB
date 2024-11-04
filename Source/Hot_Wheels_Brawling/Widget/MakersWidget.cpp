// Fill out your copyright notice in the Description page of Project Settings.


#include "MakersWidget.h"

void UMakersWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (MakersToSettings)
    {
        MakersToSettings->OnClicked.AddDynamic(this, &UMakersWidget::MakersToSettingsClicked);
    }
}

void UMakersWidget::MakersToSettingsClicked()
{
    this->RemoveFromParent();

    if (TSubclassOf<UUserWidget> MakersToSettingsClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_SettingWidget.BP_SettingWidget_C'")))
    {
        UUserWidget* MakersWidget = CreateWidget<UUserWidget>(GetWorld(), MakersToSettingsClass);
        if (MakersWidget)
        {
            MakersWidget->AddToViewport();
        }
    }
}
