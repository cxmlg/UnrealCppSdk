// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetTime.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetTime::UPFServerGetTime(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetTimeDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetTime* UPFServerGetTime::GetTime(class APlayerController* PlayerController)
{
    UPFServerGetTime* Proxy = NewObject<UPFServerGetTime>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    
    return Proxy;
}

void UPFServerGetTime::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetTime(SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetTime::OnSuccessCallback(const PlayFab::ServerModels::FGetTimeResult& Result)
{
    FBPServerGetTimeResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
