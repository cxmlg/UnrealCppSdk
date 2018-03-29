// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityAddMembers.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityAddMembers::UPFEntityAddMembers(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FAddMembersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityAddMembers* UPFEntityAddMembers::AddMembers(class APlayerController* PlayerController, const FBPEntityAddMembersRequest& InAddMembersRequest)
{
    UPFEntityAddMembers* Proxy = NewObject<UPFEntityAddMembers>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InAddMembersRequest;
    
    return Proxy;
}

void UPFEntityAddMembers::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->AddMembers(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityAddMembers::OnSuccessCallback(const PlayFab::EntityModels::FEmptyResult& Result)
{
    OnSuccess.Broadcast();
}
