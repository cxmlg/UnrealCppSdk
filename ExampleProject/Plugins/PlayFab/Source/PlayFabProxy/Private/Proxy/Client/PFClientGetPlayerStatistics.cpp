// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetPlayerStatistics.h"

UPFClientGetPlayerStatistics::UPFClientGetPlayerStatistics(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayerStatisticsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetPlayerStatistics* UPFClientGetPlayerStatistics::GetPlayerStatistics(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FString>& InStatisticNames, const TArray<FBPClientStatisticNameVersion>& InStatisticNameVersions)
{
	UPFClientGetPlayerStatistics* Proxy = NewObject<UPFClientGetPlayerStatistics>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.StatisticNames = InStatisticNames;
	for (const FBPClientStatisticNameVersion& elem : InStatisticNameVersions)
    {
        Proxy->Request.StatisticNameVersions.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetPlayerStatistics::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetPlayerStatistics(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetPlayerStatisticsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetPlayerStatistics::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayerStatisticsResult& Result)
{
	FBPClientGetPlayerStatisticsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetPlayerStatistics::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetPlayerStatisticsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
