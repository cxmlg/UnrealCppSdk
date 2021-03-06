// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminModifyServerBuild.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminModifyServerBuild::UPFAdminModifyServerBuild(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FModifyServerBuildDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminModifyServerBuild* UPFAdminModifyServerBuild::ModifyServerBuild(class APlayerController* PlayerController, const FBPAdminModifyServerBuildRequest& InModifyServerBuildRequest)
{
    UPFAdminModifyServerBuild* Proxy = NewObject<UPFAdminModifyServerBuild>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InModifyServerBuildRequest;
    
    return Proxy;
}

void UPFAdminModifyServerBuild::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->ModifyServerBuild(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminModifyServerBuild::OnSuccessCallback(const PlayFab::AdminModels::FModifyServerBuildResult& Result)
{
    FBPAdminModifyServerBuildResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
