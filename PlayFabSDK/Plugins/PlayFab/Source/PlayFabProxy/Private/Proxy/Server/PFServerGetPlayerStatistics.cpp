// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerGetPlayerStatistics.h"

UPFServerGetPlayerStatistics::UPFServerGetPlayerStatistics(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetPlayerStatisticsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetPlayerStatistics* UPFServerGetPlayerStatistics::GetPlayerStatistics(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const TArray<FString>& InStatisticNames, const TArray<FBPServerStatisticNameVersion>& InStatisticNameVersions)
{
	UPFServerGetPlayerStatistics* Proxy = NewObject<UPFServerGetPlayerStatistics>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.StatisticNames = InStatisticNames;
	for (const FBPServerStatisticNameVersion& elem : InStatisticNameVersions)
    {
        Proxy->Request.StatisticNameVersions.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetPlayerStatistics::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetPlayerStatistics(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetPlayerStatisticsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetPlayerStatistics::OnSuccessCallback(const PlayFab::ServerModels::FGetPlayerStatisticsResult& Result)
{
	FBPServerGetPlayerStatisticsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetPlayerStatistics::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetPlayerStatisticsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
