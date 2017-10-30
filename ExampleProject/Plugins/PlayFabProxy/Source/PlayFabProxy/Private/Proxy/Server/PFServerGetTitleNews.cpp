// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetTitleNews.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetTitleNews::UPFServerGetTitleNews(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetTitleNewsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetTitleNews* UPFServerGetTitleNews::GetTitleNews(class APlayerController* PlayerController, const FBPServerGetTitleNewsRequest& InGetTitleNewsRequest)
{
    UPFServerGetTitleNews* Proxy = NewObject<UPFServerGetTitleNews>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetTitleNewsRequest;
    
    return Proxy;
}

void UPFServerGetTitleNews::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetTitleNews(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerGetTitleNews::OnSuccessCallback(const PlayFab::ServerModels::FGetTitleNewsResult& Result)
{
    FBPServerGetTitleNewsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}