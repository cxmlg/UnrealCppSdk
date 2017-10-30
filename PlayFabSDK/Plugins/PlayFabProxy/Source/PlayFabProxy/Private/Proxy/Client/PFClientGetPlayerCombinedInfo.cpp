// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetPlayerCombinedInfo.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetPlayerCombinedInfo::UPFClientGetPlayerCombinedInfo(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayerCombinedInfoDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetPlayerCombinedInfo* UPFClientGetPlayerCombinedInfo::GetPlayerCombinedInfo(class APlayerController* PlayerController, const FBPClientGetPlayerCombinedInfoRequest& InGetPlayerCombinedInfoRequest)
{
    UPFClientGetPlayerCombinedInfo* Proxy = NewObject<UPFClientGetPlayerCombinedInfo>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayerCombinedInfoRequest;
    
    return Proxy;
}

void UPFClientGetPlayerCombinedInfo::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetPlayerCombinedInfo(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetPlayerCombinedInfo::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayerCombinedInfoResult& Result)
{
    FBPClientGetPlayerCombinedInfoResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}