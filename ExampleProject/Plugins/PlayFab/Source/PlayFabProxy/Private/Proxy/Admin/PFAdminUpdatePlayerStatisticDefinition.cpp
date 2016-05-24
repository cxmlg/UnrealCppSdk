// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminUpdatePlayerStatisticDefinition.h"

UPFAdminUpdatePlayerStatisticDefinition::UPFAdminUpdatePlayerStatisticDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdatePlayerStatisticDefinitionDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminUpdatePlayerStatisticDefinition* UPFAdminUpdatePlayerStatisticDefinition::UpdatePlayerStatisticDefinition(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InStatisticName)
{
	UPFAdminUpdatePlayerStatisticDefinition* Proxy = NewObject<UPFAdminUpdatePlayerStatisticDefinition>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.StatisticName = InStatisticName;
	
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminUpdatePlayerStatisticDefinition::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->UpdatePlayerStatisticDefinition(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminUpdatePlayerStatisticDefinitionResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminUpdatePlayerStatisticDefinition::OnSuccessCallback(const PlayFab::AdminModels::FUpdatePlayerStatisticDefinitionResult& Result)
{
	FBPAdminUpdatePlayerStatisticDefinitionResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminUpdatePlayerStatisticDefinition::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminUpdatePlayerStatisticDefinitionResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
