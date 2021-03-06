// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetPlayerSegments.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetPlayerSegments::UPFServerGetPlayerSegments(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetPlayerSegmentsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetPlayerSegments* UPFServerGetPlayerSegments::GetPlayerSegments(class APlayerController* PlayerController, const FBPServerGetPlayersSegmentsRequest& InGetPlayersSegmentsRequest)
{
    UPFServerGetPlayerSegments* Proxy = NewObject<UPFServerGetPlayerSegments>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayersSegmentsRequest;
    
    return Proxy;
}

void UPFServerGetPlayerSegments::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetPlayerSegments(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetPlayerSegments::OnSuccessCallback(const PlayFab::ServerModels::FGetPlayerSegmentsResult& Result)
{
    FBPServerGetPlayerSegmentsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
