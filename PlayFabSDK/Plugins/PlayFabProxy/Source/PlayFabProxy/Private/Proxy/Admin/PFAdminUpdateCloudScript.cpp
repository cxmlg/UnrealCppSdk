// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminUpdateCloudScript.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminUpdateCloudScript::UPFAdminUpdateCloudScript(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateCloudScriptDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminUpdateCloudScript* UPFAdminUpdateCloudScript::UpdateCloudScript(class APlayerController* PlayerController, const FBPAdminUpdateCloudScriptRequest& InUpdateCloudScriptRequest)
{
    UPFAdminUpdateCloudScript* Proxy = NewObject<UPFAdminUpdateCloudScript>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateCloudScriptRequest;
    
    return Proxy;
}

void UPFAdminUpdateCloudScript::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->UpdateCloudScript(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminUpdateCloudScript::OnSuccessCallback(const PlayFab::AdminModels::FUpdateCloudScriptResult& Result)
{
    FBPAdminUpdateCloudScriptResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
