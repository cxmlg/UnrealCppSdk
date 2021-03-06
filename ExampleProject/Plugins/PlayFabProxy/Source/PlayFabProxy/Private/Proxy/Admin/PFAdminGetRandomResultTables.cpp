// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetRandomResultTables.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetRandomResultTables::UPFAdminGetRandomResultTables(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetRandomResultTablesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetRandomResultTables* UPFAdminGetRandomResultTables::GetRandomResultTables(class APlayerController* PlayerController, const FBPAdminGetRandomResultTablesRequest& InGetRandomResultTablesRequest)
{
    UPFAdminGetRandomResultTables* Proxy = NewObject<UPFAdminGetRandomResultTables>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetRandomResultTablesRequest;
    
    return Proxy;
}

void UPFAdminGetRandomResultTables::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetRandomResultTables(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminGetRandomResultTables::OnSuccessCallback(const PlayFab::AdminModels::FGetRandomResultTablesResult& Result)
{
    FBPAdminGetRandomResultTablesResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
