// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientUpdatePlayerStatistics.h"

UPFClientUpdatePlayerStatistics::UPFClientUpdatePlayerStatistics(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FUpdatePlayerStatisticsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientUpdatePlayerStatistics* UPFClientUpdatePlayerStatistics::UpdatePlayerStatistics(UObject* WorldContextObject, class APlayerController* PlayerController , const TArray<FBPClientStatisticUpdate>& InStatistics)
{
	UPFClientUpdatePlayerStatistics* Proxy = NewObject<UPFClientUpdatePlayerStatistics>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	for (const FBPClientStatisticUpdate& elem : InStatistics)
    {
        Proxy->Request.Statistics.Add(elem.Data);
    }

	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientUpdatePlayerStatistics::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->UpdatePlayerStatistics(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientUpdatePlayerStatistics::OnSuccessCallback(const PlayFab::ClientModels::FUpdatePlayerStatisticsResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientUpdatePlayerStatistics::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
