// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerDeleteUsers.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerDeleteUsers::UPFServerDeleteUsers(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FDeleteUsersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerDeleteUsers* UPFServerDeleteUsers::DeleteUsers(class APlayerController* PlayerController, const FBPServerDeleteUsersRequest& InDeleteUsersRequest)
{
    UPFServerDeleteUsers* Proxy = NewObject<UPFServerDeleteUsers>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeleteUsersRequest;
    
    return Proxy;
}

void UPFServerDeleteUsers::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->DeleteUsers(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerDeleteUsers::OnSuccessCallback(const PlayFab::ServerModels::FDeleteUsersResult& Result)
{
    OnSuccess.Broadcast();
}
