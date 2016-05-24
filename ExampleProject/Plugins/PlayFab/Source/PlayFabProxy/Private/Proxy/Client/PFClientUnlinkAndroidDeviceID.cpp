// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientUnlinkAndroidDeviceID.h"

UPFClientUnlinkAndroidDeviceID::UPFClientUnlinkAndroidDeviceID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FUnlinkAndroidDeviceIDDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientUnlinkAndroidDeviceID* UPFClientUnlinkAndroidDeviceID::UnlinkAndroidDeviceID(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InAndroidDeviceId)
{
	UPFClientUnlinkAndroidDeviceID* Proxy = NewObject<UPFClientUnlinkAndroidDeviceID>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.AndroidDeviceId = InAndroidDeviceId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientUnlinkAndroidDeviceID::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->UnlinkAndroidDeviceID(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientUnlinkAndroidDeviceID::OnSuccessCallback(const PlayFab::ClientModels::FUnlinkAndroidDeviceIDResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientUnlinkAndroidDeviceID::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
