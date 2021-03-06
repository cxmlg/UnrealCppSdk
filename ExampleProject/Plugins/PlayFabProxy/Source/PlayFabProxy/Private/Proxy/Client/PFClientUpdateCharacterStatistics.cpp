// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientUpdateCharacterStatistics.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientUpdateCharacterStatistics::UPFClientUpdateCharacterStatistics(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FUpdateCharacterStatisticsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientUpdateCharacterStatistics* UPFClientUpdateCharacterStatistics::UpdateCharacterStatistics(class APlayerController* PlayerController, const FBPClientUpdateCharacterStatisticsRequest& InUpdateCharacterStatisticsRequest)
{
    UPFClientUpdateCharacterStatistics* Proxy = NewObject<UPFClientUpdateCharacterStatistics>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateCharacterStatisticsRequest;
    
    return Proxy;
}

void UPFClientUpdateCharacterStatistics::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->UpdateCharacterStatistics(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientUpdateCharacterStatistics::OnSuccessCallback(const PlayFab::ClientModels::FUpdateCharacterStatisticsResult& Result)
{
    OnSuccess.Broadcast();
}
