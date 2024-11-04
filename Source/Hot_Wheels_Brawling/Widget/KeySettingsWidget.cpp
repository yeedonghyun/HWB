// Fill out your copyright notice in the Description page of Project Settings.


#include "KeySettingsWidget.h"

void UKeySettingsWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if(KeyToSettings)
    {
        KeyToSettings->OnClicked.AddDynamic(this, &UKeySettingsWidget::KeyToSettingsClicked);
    }
}

void UKeySettingsWidget::KeyToSettingsClicked()
{
    this->RemoveFromParent();

    if (TSubclassOf<UUserWidget> KeyToSettingsClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_SettingWidget.BP_SettingWidget_C'")))
    {
        UUserWidget* KeySettingsWidget = CreateWidget<UUserWidget>(GetWorld(), KeyToSettingsClass);
        if (KeySettingsWidget)
        {
            KeySettingsWidget->AddToViewport();
        }
    }
}
