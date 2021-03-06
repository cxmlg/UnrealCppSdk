// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientUnlockContainerInstance.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientUnlockContainerInstance::UPFClientUnlockContainerInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FUnlockContainerInstanceDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientUnlockContainerInstance* UPFClientUnlockContainerInstance::UnlockContainerInstance(class APlayerController* PlayerController, const FBPClientUnlockContainerInstanceRequest& InUnlockContainerInstanceRequest)
{
    UPFClientUnlockContainerInstance* Proxy = NewObject<UPFClientUnlockContainerInstance>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUnlockContainerInstanceRequest;
    
    return Proxy;
}

void UPFClientUnlockContainerInstance::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->UnlockContainerInstance(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientUnlockContainerInstance::OnSuccessCallback(const PlayFab::ClientModels::FUnlockContainerItemResult& Result)
{
    FBPClientUnlockContainerItemResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
