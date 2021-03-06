// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminCheckLimitedEditionItemAvailability.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminCheckLimitedEditionItemAvailability::UPFAdminCheckLimitedEditionItemAvailability(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FCheckLimitedEditionItemAvailabilityDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminCheckLimitedEditionItemAvailability* UPFAdminCheckLimitedEditionItemAvailability::CheckLimitedEditionItemAvailability(class APlayerController* PlayerController, const FBPAdminCheckLimitedEditionItemAvailabilityRequest& InCheckLimitedEditionItemAvailabilityRequest)
{
    UPFAdminCheckLimitedEditionItemAvailability* Proxy = NewObject<UPFAdminCheckLimitedEditionItemAvailability>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InCheckLimitedEditionItemAvailabilityRequest;
    
    return Proxy;
}

void UPFAdminCheckLimitedEditionItemAvailability::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->CheckLimitedEditionItemAvailability(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminCheckLimitedEditionItemAvailability::OnSuccessCallback(const PlayFab::AdminModels::FCheckLimitedEditionItemAvailabilityResult& Result)
{
    FBPAdminCheckLimitedEditionItemAvailabilityResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
