// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerUpdatePlayerStatistics.h"

UPFServerUpdatePlayerStatistics::UPFServerUpdatePlayerStatistics(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdatePlayerStatisticsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerUpdatePlayerStatistics* UPFServerUpdatePlayerStatistics::UpdatePlayerStatistics(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const TArray<FBPServerStatisticUpdate>& InStatistics)
{
	UPFServerUpdatePlayerStatistics* Proxy = NewObject<UPFServerUpdatePlayerStatistics>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	for (const FBPServerStatisticUpdate& elem : InStatistics)
    {
        Proxy->Request.Statistics.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerUpdatePlayerStatistics::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->UpdatePlayerStatistics(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerUpdatePlayerStatistics::OnSuccessCallback(const PlayFab::ServerModels::FUpdatePlayerStatisticsResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFServerUpdatePlayerStatistics::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}