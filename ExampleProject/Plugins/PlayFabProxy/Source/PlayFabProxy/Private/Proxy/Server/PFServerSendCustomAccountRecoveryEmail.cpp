// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerSendCustomAccountRecoveryEmail.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerSendCustomAccountRecoveryEmail::UPFServerSendCustomAccountRecoveryEmail(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FSendCustomAccountRecoveryEmailDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerSendCustomAccountRecoveryEmail* UPFServerSendCustomAccountRecoveryEmail::SendCustomAccountRecoveryEmail(class APlayerController* PlayerController, const FBPServerSendCustomAccountRecoveryEmailRequest& InSendCustomAccountRecoveryEmailRequest)
{
    UPFServerSendCustomAccountRecoveryEmail* Proxy = NewObject<UPFServerSendCustomAccountRecoveryEmail>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSendCustomAccountRecoveryEmailRequest;
    
    return Proxy;
}

void UPFServerSendCustomAccountRecoveryEmail::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->SendCustomAccountRecoveryEmail(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerSendCustomAccountRecoveryEmail::OnSuccessCallback(const PlayFab::ServerModels::FSendCustomAccountRecoveryEmailResult& Result)
{
    OnSuccess.Broadcast();
}