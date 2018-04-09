// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityAbortFileUploads.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityAbortFileUploads::UPFEntityAbortFileUploads(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FAbortFileUploadsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityAbortFileUploads* UPFEntityAbortFileUploads::AbortFileUploads(class APlayerController* PlayerController, const FBPEntityAbortFileUploadsRequest& InAbortFileUploadsRequest)
{
    UPFEntityAbortFileUploads* Proxy = NewObject<UPFEntityAbortFileUploads>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InAbortFileUploadsRequest;
    
    return Proxy;
}

void UPFEntityAbortFileUploads::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->AbortFileUploads(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityAbortFileUploads::OnSuccessCallback(const PlayFab::EntityModels::FAbortFileUploadsResponse& Result)
{
    FBPEntityAbortFileUploadsResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}