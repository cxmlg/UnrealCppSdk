// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetUserPublisherReadOnlyData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetUserPublisherReadOnlyData::UPFClientGetUserPublisherReadOnlyData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetUserPublisherReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetUserPublisherReadOnlyData* UPFClientGetUserPublisherReadOnlyData::GetUserPublisherReadOnlyData(class APlayerController* PlayerController, const FBPClientGetUserDataRequest& InGetUserDataRequest)
{
    UPFClientGetUserPublisherReadOnlyData* Proxy = NewObject<UPFClientGetUserPublisherReadOnlyData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserDataRequest;
    
    return Proxy;
}

void UPFClientGetUserPublisherReadOnlyData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetUserPublisherReadOnlyData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientGetUserPublisherReadOnlyData::OnSuccessCallback(const PlayFab::ClientModels::FGetUserDataResult& Result)
{
    FBPClientGetUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
