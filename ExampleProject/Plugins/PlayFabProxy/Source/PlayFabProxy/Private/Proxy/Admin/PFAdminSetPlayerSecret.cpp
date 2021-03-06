// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminSetPlayerSecret.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminSetPlayerSecret::UPFAdminSetPlayerSecret(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FSetPlayerSecretDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminSetPlayerSecret* UPFAdminSetPlayerSecret::SetPlayerSecret(class APlayerController* PlayerController, const FBPAdminSetPlayerSecretRequest& InSetPlayerSecretRequest)
{
    UPFAdminSetPlayerSecret* Proxy = NewObject<UPFAdminSetPlayerSecret>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSetPlayerSecretRequest;
    
    return Proxy;
}

void UPFAdminSetPlayerSecret::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->SetPlayerSecret(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminSetPlayerSecret::OnSuccessCallback(const PlayFab::AdminModels::FSetPlayerSecretResult& Result)
{
    OnSuccess.Broadcast();
}
