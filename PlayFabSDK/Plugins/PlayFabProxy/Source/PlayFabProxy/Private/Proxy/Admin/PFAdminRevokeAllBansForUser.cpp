// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminRevokeAllBansForUser.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminRevokeAllBansForUser::UPFAdminRevokeAllBansForUser(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRevokeAllBansForUserDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminRevokeAllBansForUser* UPFAdminRevokeAllBansForUser::RevokeAllBansForUser(class APlayerController* PlayerController, const FBPAdminRevokeAllBansForUserRequest& InRevokeAllBansForUserRequest)
{
    UPFAdminRevokeAllBansForUser* Proxy = NewObject<UPFAdminRevokeAllBansForUser>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRevokeAllBansForUserRequest;
    
    return Proxy;
}

void UPFAdminRevokeAllBansForUser::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->RevokeAllBansForUser(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminRevokeAllBansForUser::OnSuccessCallback(const PlayFab::AdminModels::FRevokeAllBansForUserResult& Result)
{
    FBPAdminRevokeAllBansForUserResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
