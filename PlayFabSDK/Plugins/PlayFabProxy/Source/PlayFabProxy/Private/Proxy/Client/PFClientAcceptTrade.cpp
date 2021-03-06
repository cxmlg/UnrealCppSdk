// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientAcceptTrade.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientAcceptTrade::UPFClientAcceptTrade(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FAcceptTradeDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientAcceptTrade* UPFClientAcceptTrade::AcceptTrade(class APlayerController* PlayerController, const FBPClientAcceptTradeRequest& InAcceptTradeRequest)
{
    UPFClientAcceptTrade* Proxy = NewObject<UPFClientAcceptTrade>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InAcceptTradeRequest;
    
    return Proxy;
}

void UPFClientAcceptTrade::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->AcceptTrade(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientAcceptTrade::OnSuccessCallback(const PlayFab::ClientModels::FAcceptTradeResponse& Result)
{
    FBPClientAcceptTradeResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
