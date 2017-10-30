// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetPlayerTrades.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetPlayerTrades::UPFClientGetPlayerTrades(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayerTradesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetPlayerTrades* UPFClientGetPlayerTrades::GetPlayerTrades(class APlayerController* PlayerController, const FBPClientGetPlayerTradesRequest& InGetPlayerTradesRequest)
{
    UPFClientGetPlayerTrades* Proxy = NewObject<UPFClientGetPlayerTrades>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayerTradesRequest;
    
    return Proxy;
}

void UPFClientGetPlayerTrades::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetPlayerTrades(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetPlayerTrades::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayerTradesResponse& Result)
{
    FBPClientGetPlayerTradesResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}