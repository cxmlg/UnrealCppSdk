// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientWriteTitleEvent.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientWriteTitleEvent::UPFClientWriteTitleEvent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FWriteTitleEventDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientWriteTitleEvent* UPFClientWriteTitleEvent::WriteTitleEvent(class APlayerController* PlayerController, const FBPClientWriteTitleEventRequest& InWriteTitleEventRequest)
{
    UPFClientWriteTitleEvent* Proxy = NewObject<UPFClientWriteTitleEvent>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InWriteTitleEventRequest;
    
    return Proxy;
}

void UPFClientWriteTitleEvent::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->WriteTitleEvent(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientWriteTitleEvent::OnSuccessCallback(const PlayFab::ClientModels::FWriteEventResponse& Result)
{
    FBPClientWriteEventResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
