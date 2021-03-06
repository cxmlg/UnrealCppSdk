// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientUnlinkIOSDeviceID.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientUnlinkIOSDeviceID::UPFClientUnlinkIOSDeviceID(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FUnlinkIOSDeviceIDDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientUnlinkIOSDeviceID* UPFClientUnlinkIOSDeviceID::UnlinkIOSDeviceID(class APlayerController* PlayerController, const FBPClientUnlinkIOSDeviceIDRequest& InUnlinkIOSDeviceIDRequest)
{
    UPFClientUnlinkIOSDeviceID* Proxy = NewObject<UPFClientUnlinkIOSDeviceID>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUnlinkIOSDeviceIDRequest;
    
    return Proxy;
}

void UPFClientUnlinkIOSDeviceID::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->UnlinkIOSDeviceID(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientUnlinkIOSDeviceID::OnSuccessCallback(const PlayFab::ClientModels::FUnlinkIOSDeviceIDResult& Result)
{
    OnSuccess.Broadcast();
}
