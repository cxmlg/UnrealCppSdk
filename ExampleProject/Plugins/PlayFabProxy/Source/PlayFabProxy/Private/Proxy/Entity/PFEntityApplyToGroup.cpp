// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityApplyToGroup.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityApplyToGroup::UPFEntityApplyToGroup(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FApplyToGroupDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityApplyToGroup* UPFEntityApplyToGroup::ApplyToGroup(class APlayerController* PlayerController, const FBPEntityApplyToGroupRequest& InApplyToGroupRequest)
{
    UPFEntityApplyToGroup* Proxy = NewObject<UPFEntityApplyToGroup>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InApplyToGroupRequest;
    
    return Proxy;
}

void UPFEntityApplyToGroup::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->ApplyToGroup(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityApplyToGroup::OnSuccessCallback(const PlayFab::EntityModels::FApplyToGroupResponse& Result)
{
    FBPEntityApplyToGroupResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
