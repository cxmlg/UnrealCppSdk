// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetUserReadOnlyData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetUserReadOnlyData::UPFServerGetUserReadOnlyData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetUserReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetUserReadOnlyData* UPFServerGetUserReadOnlyData::GetUserReadOnlyData(class APlayerController* PlayerController, const FBPServerGetUserDataRequest& InGetUserDataRequest)
{
    UPFServerGetUserReadOnlyData* Proxy = NewObject<UPFServerGetUserReadOnlyData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserDataRequest;
    
    return Proxy;
}

void UPFServerGetUserReadOnlyData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetUserReadOnlyData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetUserReadOnlyData::OnSuccessCallback(const PlayFab::ServerModels::FGetUserDataResult& Result)
{
    FBPServerGetUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
