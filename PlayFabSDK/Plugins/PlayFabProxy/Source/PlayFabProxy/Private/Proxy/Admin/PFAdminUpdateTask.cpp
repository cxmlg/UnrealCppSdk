// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminUpdateTask.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminUpdateTask::UPFAdminUpdateTask(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateTaskDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminUpdateTask* UPFAdminUpdateTask::UpdateTask(class APlayerController* PlayerController, const FBPAdminUpdateTaskRequest& InUpdateTaskRequest)
{
    UPFAdminUpdateTask* Proxy = NewObject<UPFAdminUpdateTask>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateTaskRequest;
    
    return Proxy;
}

void UPFAdminUpdateTask::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->UpdateTask(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminUpdateTask::OnSuccessCallback(const PlayFab::AdminModels::FEmptyResult& Result)
{
    OnSuccess.Broadcast();
}