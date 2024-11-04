// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingWidget.h"

void USettingWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (SettingGoBack)
    {
        SettingGoBack->OnClicked.AddDynamic(this, &USettingWidget::SettingGoBackClicked);
    }

    if (KeySettingsButton)
    {
        KeySettingsButton->OnClicked.AddDynamic(this, &USettingWidget::KeySettingsButtonClicked);
    }

    if (MakersButton)
    {
        MakersButton->OnClicked.AddDynamic(this, &USettingWidget::MakersButtonClicked);
    }
}

void USettingWidget::SettingGoBackClicked()
{
    if (TSubclassOf<UUserWidget> SettingGoBackClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_MainPage.BP_MainPage_C'")))
    {
        UUserWidget* BackToMain = CreateWidget<UUserWidget>(GetWorld(), SettingGoBackClass);
        if (BackToMain)
        {
            BackToMain->AddToViewport();
        }
    }
}

void USettingWidget::KeySettingsButtonClicked()
{
    if (TSubclassOf<UUserWidget> KeySettingsButtonClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_KeySettings.BP_KeySettings_C'")))
    {
        UUserWidget* GoToKeySettings = CreateWidget<UUserWidget>(GetWorld(), KeySettingsButtonClass);
        if (GoToKeySettings)
        {
            GoToKeySettings->AddToViewport();
        }
    }
        

}

void USettingWidget::MakersButtonClicked()
{
    if (TSubclassOf<UUserWidget> MakersButtonClickedClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/TreadMill/BluePrints/Widget/BP_Makers.BP_Makers_C'")))
    {
        UUserWidget* GoToMakers = CreateWidget<UUserWidget>(GetWorld(), MakersButtonClickedClass);
        if (GoToMakers)
        {
            GoToMakers->AddToViewport();
        }
    }
}
