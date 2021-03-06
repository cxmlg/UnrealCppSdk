// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminRevokeInventoryItem.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminRevokeInventoryItem::UPFAdminRevokeInventoryItem(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRevokeInventoryItemDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminRevokeInventoryItem* UPFAdminRevokeInventoryItem::RevokeInventoryItem(class APlayerController* PlayerController, const FBPAdminRevokeInventoryItemRequest& InRevokeInventoryItemRequest)
{
    UPFAdminRevokeInventoryItem* Proxy = NewObject<UPFAdminRevokeInventoryItem>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRevokeInventoryItemRequest;
    
    return Proxy;
}

void UPFAdminRevokeInventoryItem::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->RevokeInventoryItem(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminRevokeInventoryItem::OnSuccessCallback(const PlayFab::AdminModels::FRevokeInventoryResult& Result)
{
    OnSuccess.Broadcast();
}
