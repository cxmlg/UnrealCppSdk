// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntitySetProfilePolicy.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntitySetProfilePolicy::UPFEntitySetProfilePolicy(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FSetProfilePolicyDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntitySetProfilePolicy* UPFEntitySetProfilePolicy::SetProfilePolicy(class APlayerController* PlayerController, const FBPEntitySetEntityProfilePolicyRequest& InSetEntityProfilePolicyRequest)
{
    UPFEntitySetProfilePolicy* Proxy = NewObject<UPFEntitySetProfilePolicy>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSetEntityProfilePolicyRequest;
    
    return Proxy;
}

void UPFEntitySetProfilePolicy::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->SetProfilePolicy(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntitySetProfilePolicy::OnSuccessCallback(const PlayFab::EntityModels::FSetEntityProfilePolicyResponse& Result)
{
    FBPEntitySetEntityProfilePolicyResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
