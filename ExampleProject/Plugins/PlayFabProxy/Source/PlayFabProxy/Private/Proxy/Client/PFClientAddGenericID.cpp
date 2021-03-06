// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientAddGenericID.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientAddGenericID::UPFClientAddGenericID(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FAddGenericIDDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientAddGenericID* UPFClientAddGenericID::AddGenericID(class APlayerController* PlayerController, const FBPClientAddGenericIDRequest& InAddGenericIDRequest)
{
    UPFClientAddGenericID* Proxy = NewObject<UPFClientAddGenericID>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InAddGenericIDRequest;
    
    return Proxy;
}

void UPFClientAddGenericID::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->AddGenericID(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientAddGenericID::OnSuccessCallback(const PlayFab::ClientModels::FAddGenericIDResult& Result)
{
    OnSuccess.Broadcast();
}
