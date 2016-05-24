// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminDeleteContent.h"

UPFAdminDeleteContent::UPFAdminDeleteContent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FDeleteContentDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminDeleteContent* UPFAdminDeleteContent::DeleteContent(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InKey)
{
	UPFAdminDeleteContent* Proxy = NewObject<UPFAdminDeleteContent>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Key = InKey;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminDeleteContent::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->DeleteContent(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminDeleteContent::OnSuccessCallback(const PlayFab::AdminModels::FBlankResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminDeleteContent::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
