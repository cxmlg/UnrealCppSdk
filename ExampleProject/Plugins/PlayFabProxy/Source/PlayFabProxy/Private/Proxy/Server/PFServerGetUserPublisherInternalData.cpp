// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetUserPublisherInternalData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetUserPublisherInternalData::UPFServerGetUserPublisherInternalData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetUserPublisherInternalDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetUserPublisherInternalData* UPFServerGetUserPublisherInternalData::GetUserPublisherInternalData(class APlayerController* PlayerController, const FBPServerGetUserDataRequest& InGetUserDataRequest)
{
    UPFServerGetUserPublisherInternalData* Proxy = NewObject<UPFServerGetUserPublisherInternalData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserDataRequest;
    
    return Proxy;
}

void UPFServerGetUserPublisherInternalData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetUserPublisherInternalData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetUserPublisherInternalData::OnSuccessCallback(const PlayFab::ServerModels::FGetUserDataResult& Result)
{
    FBPServerGetUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
