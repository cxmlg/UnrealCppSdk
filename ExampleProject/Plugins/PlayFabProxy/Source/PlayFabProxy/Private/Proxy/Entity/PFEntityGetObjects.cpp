// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityGetObjects.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityGetObjects::UPFEntityGetObjects(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FGetObjectsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityGetObjects* UPFEntityGetObjects::GetObjects(class APlayerController* PlayerController, const FBPEntityGetObjectsRequest& InGetObjectsRequest)
{
    UPFEntityGetObjects* Proxy = NewObject<UPFEntityGetObjects>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetObjectsRequest;
    
    return Proxy;
}

void UPFEntityGetObjects::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->GetObjects(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityGetObjects::OnSuccessCallback(const PlayFab::EntityModels::FGetObjectsResponse& Result)
{
    FBPEntityGetObjectsResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
