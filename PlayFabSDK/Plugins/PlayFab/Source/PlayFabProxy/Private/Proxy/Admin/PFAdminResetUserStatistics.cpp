// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminResetUserStatistics.h"

UPFAdminResetUserStatistics::UPFAdminResetUserStatistics(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FResetUserStatisticsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminResetUserStatistics* UPFAdminResetUserStatistics::ResetUserStatistics(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId)
{
	UPFAdminResetUserStatistics* Proxy = NewObject<UPFAdminResetUserStatistics>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminResetUserStatistics::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->ResetUserStatistics(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminResetUserStatistics::OnSuccessCallback(const PlayFab::AdminModels::FResetUserStatisticsResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminResetUserStatistics::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
