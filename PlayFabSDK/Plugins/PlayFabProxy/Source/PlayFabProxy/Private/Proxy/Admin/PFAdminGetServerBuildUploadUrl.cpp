// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetServerBuildUploadUrl.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetServerBuildUploadUrl::UPFAdminGetServerBuildUploadUrl(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetServerBuildUploadUrlDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetServerBuildUploadUrl* UPFAdminGetServerBuildUploadUrl::GetServerBuildUploadUrl(class APlayerController* PlayerController, const FBPAdminGetServerBuildUploadURLRequest& InGetServerBuildUploadURLRequest)
{
    UPFAdminGetServerBuildUploadUrl* Proxy = NewObject<UPFAdminGetServerBuildUploadUrl>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetServerBuildUploadURLRequest;
    
    return Proxy;
}

void UPFAdminGetServerBuildUploadUrl::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetServerBuildUploadUrl(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminGetServerBuildUploadUrl::OnSuccessCallback(const PlayFab::AdminModels::FGetServerBuildUploadURLResult& Result)
{
    FBPAdminGetServerBuildUploadURLResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
