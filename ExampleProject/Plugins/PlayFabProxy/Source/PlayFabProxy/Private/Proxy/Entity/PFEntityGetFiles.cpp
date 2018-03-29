// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityGetFiles.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityGetFiles::UPFEntityGetFiles(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FGetFilesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityGetFiles* UPFEntityGetFiles::GetFiles(class APlayerController* PlayerController, const FBPEntityGetFilesRequest& InGetFilesRequest)
{
    UPFEntityGetFiles* Proxy = NewObject<UPFEntityGetFiles>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetFilesRequest;
    
    return Proxy;
}

void UPFEntityGetFiles::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->GetFiles(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityGetFiles::OnSuccessCallback(const PlayFab::EntityModels::FGetFilesResponse& Result)
{
    FBPEntityGetFilesResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
