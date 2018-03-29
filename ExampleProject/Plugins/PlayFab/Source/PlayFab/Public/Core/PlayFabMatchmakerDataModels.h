// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "Core/PlayFabBaseModel.h"

namespace PlayFab
{
namespace MatchmakerModels
{

    struct PLAYFAB_API FAuthUserRequest : public FPlayFabBaseModel
    {
        // Session Ticket provided by the client.
        FString AuthorizationTicket;

        FAuthUserRequest() :
            FPlayFabBaseModel(),
            AuthorizationTicket()
            {}

        FAuthUserRequest(const FAuthUserRequest& src) :
            FPlayFabBaseModel(),
            AuthorizationTicket(src.AuthorizationTicket)
            {}

        FAuthUserRequest(const TSharedPtr<FJsonObject>& obj) : FAuthUserRequest()
        {
            readFromValue(obj);
        }

        ~FAuthUserRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FAuthUserResponse : public FPlayFabBaseModel
    {
        // Boolean indicating if the user has been authorized to use the external match-making service.
        bool Authorized;

        // [optional] PlayFab unique identifier of the account that has been authorized.
        FString PlayFabId;

        FAuthUserResponse() :
            FPlayFabBaseModel(),
            Authorized(false),
            PlayFabId()
            {}

        FAuthUserResponse(const FAuthUserResponse& src) :
            FPlayFabBaseModel(),
            Authorized(src.Authorized),
            PlayFabId(src.PlayFabId)
            {}

        FAuthUserResponse(const TSharedPtr<FJsonObject>& obj) : FAuthUserResponse()
        {
            readFromValue(obj);
        }

        ~FAuthUserResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FDeregisterGameRequest : public FPlayFabBaseModel
    {
        // Unique identifier for the Game Server Instance that is being deregistered.
        FString LobbyId;

        FDeregisterGameRequest() :
            FPlayFabBaseModel(),
            LobbyId()
            {}

        FDeregisterGameRequest(const FDeregisterGameRequest& src) :
            FPlayFabBaseModel(),
            LobbyId(src.LobbyId)
            {}

        FDeregisterGameRequest(const TSharedPtr<FJsonObject>& obj) : FDeregisterGameRequest()
        {
            readFromValue(obj);
        }

        ~FDeregisterGameRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FDeregisterGameResponse : public FPlayFabBaseModel
    {
        FDeregisterGameResponse() :
            FPlayFabBaseModel()
            {}

        FDeregisterGameResponse(const FDeregisterGameResponse& src) :
            FPlayFabBaseModel()
            {}

        FDeregisterGameResponse(const TSharedPtr<FJsonObject>& obj) : FDeregisterGameResponse()
        {
            readFromValue(obj);
        }

        ~FDeregisterGameResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FItemInstance : public FPlayFabBaseModel
    {
        // [optional] Game specific comment associated with this instance when it was added to the user inventory.
        FString Annotation;

        // [optional] Array of unique items that were awarded when this catalog item was purchased.
        TArray<FString> BundleContents;
        /**
         * [optional] Unique identifier for the parent inventory item, as defined in the catalog, for object which were added from a bundle or
         * container.
         */
        FString BundleParent;

        // [optional] Catalog version for the inventory item, when this instance was created.
        FString CatalogVersion;

        // [optional] A set of custom key-value pairs on the inventory item.
        TMap<FString, FString> CustomData;
        // [optional] CatalogItem.DisplayName at the time this item was purchased.
        FString DisplayName;

        // [optional] Timestamp for when this instance will expire.
        Boxed<FDateTime> Expiration;

        // [optional] Class name for the inventory item, as defined in the catalog.
        FString ItemClass;

        // [optional] Unique identifier for the inventory item, as defined in the catalog.
        FString ItemId;

        // [optional] Unique item identifier for this specific instance of the item.
        FString ItemInstanceId;

        // [optional] Timestamp for when this instance was purchased.
        Boxed<FDateTime> PurchaseDate;

        // [optional] Total number of remaining uses, if this is a consumable item.
        Boxed<int32> RemainingUses;

        // [optional] Currency type for the cost of the catalog item.
        FString UnitCurrency;

        // Cost of the catalog item in the given currency.
        uint32 UnitPrice;

        // [optional] The number of uses that were added or removed to this item in this call.
        Boxed<int32> UsesIncrementedBy;

        FItemInstance() :
            FPlayFabBaseModel(),
            Annotation(),
            BundleContents(),
            BundleParent(),
            CatalogVersion(),
            CustomData(),
            DisplayName(),
            Expiration(),
            ItemClass(),
            ItemId(),
            ItemInstanceId(),
            PurchaseDate(),
            RemainingUses(),
            UnitCurrency(),
            UnitPrice(0),
            UsesIncrementedBy()
            {}

        FItemInstance(const FItemInstance& src) :
            FPlayFabBaseModel(),
            Annotation(src.Annotation),
            BundleContents(src.BundleContents),
            BundleParent(src.BundleParent),
            CatalogVersion(src.CatalogVersion),
            CustomData(src.CustomData),
            DisplayName(src.DisplayName),
            Expiration(src.Expiration),
            ItemClass(src.ItemClass),
            ItemId(src.ItemId),
            ItemInstanceId(src.ItemInstanceId),
            PurchaseDate(src.PurchaseDate),
            RemainingUses(src.RemainingUses),
            UnitCurrency(src.UnitCurrency),
            UnitPrice(src.UnitPrice),
            UsesIncrementedBy(src.UsesIncrementedBy)
            {}

        FItemInstance(const TSharedPtr<FJsonObject>& obj) : FItemInstance()
        {
            readFromValue(obj);
        }

        ~FItemInstance();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FPlayerJoinedRequest : public FPlayFabBaseModel
    {
        /**
         * Unique identifier of the Game Server Instance the user is joining. This must be a Game Server Instance started with the
         * Matchmaker/StartGame API.
         */
        FString LobbyId;

        // PlayFab unique identifier for the player joining.
        FString PlayFabId;

        FPlayerJoinedRequest() :
            FPlayFabBaseModel(),
            LobbyId(),
            PlayFabId()
            {}

        FPlayerJoinedRequest(const FPlayerJoinedRequest& src) :
            FPlayFabBaseModel(),
            LobbyId(src.LobbyId),
            PlayFabId(src.PlayFabId)
            {}

        FPlayerJoinedRequest(const TSharedPtr<FJsonObject>& obj) : FPlayerJoinedRequest()
        {
            readFromValue(obj);
        }

        ~FPlayerJoinedRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FPlayerJoinedResponse : public FPlayFabBaseModel
    {
        FPlayerJoinedResponse() :
            FPlayFabBaseModel()
            {}

        FPlayerJoinedResponse(const FPlayerJoinedResponse& src) :
            FPlayFabBaseModel()
            {}

        FPlayerJoinedResponse(const TSharedPtr<FJsonObject>& obj) : FPlayerJoinedResponse()
        {
            readFromValue(obj);
        }

        ~FPlayerJoinedResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FPlayerLeftRequest : public FPlayFabBaseModel
    {
        /**
         * Unique identifier of the Game Server Instance the user is leaving. This must be a Game Server Instance started with the
         * Matchmaker/StartGame API.
         */
        FString LobbyId;

        // PlayFab unique identifier for the player leaving.
        FString PlayFabId;

        FPlayerLeftRequest() :
            FPlayFabBaseModel(),
            LobbyId(),
            PlayFabId()
            {}

        FPlayerLeftRequest(const FPlayerLeftRequest& src) :
            FPlayFabBaseModel(),
            LobbyId(src.LobbyId),
            PlayFabId(src.PlayFabId)
            {}

        FPlayerLeftRequest(const TSharedPtr<FJsonObject>& obj) : FPlayerLeftRequest()
        {
            readFromValue(obj);
        }

        ~FPlayerLeftRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FPlayerLeftResponse : public FPlayFabBaseModel
    {
        FPlayerLeftResponse() :
            FPlayFabBaseModel()
            {}

        FPlayerLeftResponse(const FPlayerLeftResponse& src) :
            FPlayFabBaseModel()
            {}

        FPlayerLeftResponse(const TSharedPtr<FJsonObject>& obj) : FPlayerLeftResponse()
        {
            readFromValue(obj);
        }

        ~FPlayerLeftResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    enum Region
    {
        RegionUSCentral,
        RegionUSEast,
        RegionEUWest,
        RegionSingapore,
        RegionJapan,
        RegionBrazil,
        RegionAustralia
    };

    PLAYFAB_API void writeRegionEnumJSON(Region enumVal, JsonWriter& writer);
    PLAYFAB_API Region readRegionFromValue(const TSharedPtr<FJsonValue>& value);
    PLAYFAB_API Region readRegionFromValue(const FString& value);

    struct PLAYFAB_API FRegisterGameRequest : public FPlayFabBaseModel
    {
        // Unique identifier of the build running on the Game Server Instance.
        FString Build;

        /**
         * Game Mode the Game Server instance is running. Note that this must be defined in the Game Modes tab in the PlayFab Game
         * Manager, along with the Build ID (the same Game Mode can be defined for multiple Build IDs).
         */
        FString GameMode;

        // [optional] Previous lobby id if re-registering an existing game.
        FString LobbyId;

        /**
         * Region in which the Game Server Instance is running. For matchmaking using non-AWS region names, set this to any AWS
         * region and use Tags (below) to specify your custom region.
         */
        Region pfRegion;

        // IPV4 address of the Game Server Instance.
        FString ServerHost;

        // [optional] IPV6 address of the Game Server Instance.
        FString ServerIPV6Address;

        // Port number for communication with the Game Server Instance.
        FString ServerPort;

        // [optional] Tags for the Game Server Instance
        TMap<FString, FString> Tags;
        FRegisterGameRequest() :
            FPlayFabBaseModel(),
            Build(),
            GameMode(),
            LobbyId(),
            pfRegion(),
            ServerHost(),
            ServerIPV6Address(),
            ServerPort(),
            Tags()
            {}

        FRegisterGameRequest(const FRegisterGameRequest& src) :
            FPlayFabBaseModel(),
            Build(src.Build),
            GameMode(src.GameMode),
            LobbyId(src.LobbyId),
            pfRegion(src.pfRegion),
            ServerHost(src.ServerHost),
            ServerIPV6Address(src.ServerIPV6Address),
            ServerPort(src.ServerPort),
            Tags(src.Tags)
            {}

        FRegisterGameRequest(const TSharedPtr<FJsonObject>& obj) : FRegisterGameRequest()
        {
            readFromValue(obj);
        }

        ~FRegisterGameRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FRegisterGameResponse : public FPlayFabBaseModel
    {
        /**
         * [optional] Unique identifier generated for the Game Server Instance that is registered. If LobbyId is specified in request and the
         * game still exists in PlayFab, the LobbyId in request is returned. Otherwise a new lobby id will be returned.
         */
        FString LobbyId;

        FRegisterGameResponse() :
            FPlayFabBaseModel(),
            LobbyId()
            {}

        FRegisterGameResponse(const FRegisterGameResponse& src) :
            FPlayFabBaseModel(),
            LobbyId(src.LobbyId)
            {}

        FRegisterGameResponse(const TSharedPtr<FJsonObject>& obj) : FRegisterGameResponse()
        {
            readFromValue(obj);
        }

        ~FRegisterGameResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FStartGameRequest : public FPlayFabBaseModel
    {
        // Unique identifier of the previously uploaded build executable which is to be started.
        FString Build;

        // [optional] Custom command line argument when starting game server process.
        FString CustomCommandLineData;

        /**
         * HTTP endpoint URL for receiving game status events, if using an external matchmaker. When the game ends, PlayFab will
         * make a POST request to this URL with the X-SecretKey header set to the value of the game's secret and an
         * application/json body of { "EventName": "game_ended", "GameID": "<gameid>" }.
         */
        FString ExternalMatchmakerEventEndpoint;

        // Game mode for this Game Server Instance.
        FString GameMode;

        // Region with which to associate the server, for filtering.
        Region pfRegion;

        FStartGameRequest() :
            FPlayFabBaseModel(),
            Build(),
            CustomCommandLineData(),
            ExternalMatchmakerEventEndpoint(),
            GameMode(),
            pfRegion()
            {}

        FStartGameRequest(const FStartGameRequest& src) :
            FPlayFabBaseModel(),
            Build(src.Build),
            CustomCommandLineData(src.CustomCommandLineData),
            ExternalMatchmakerEventEndpoint(src.ExternalMatchmakerEventEndpoint),
            GameMode(src.GameMode),
            pfRegion(src.pfRegion)
            {}

        FStartGameRequest(const TSharedPtr<FJsonObject>& obj) : FStartGameRequest()
        {
            readFromValue(obj);
        }

        ~FStartGameRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FStartGameResponse : public FPlayFabBaseModel
    {
        // [optional] Unique identifier for the game/lobby in the new Game Server Instance.
        FString GameID;

        // [optional] IPV4 address of the new Game Server Instance.
        FString ServerHostname;

        // [optional] IPV6 address of the new Game Server Instance.
        FString ServerIPV6Address;

        // Port number for communication with the Game Server Instance.
        uint32 ServerPort;

        FStartGameResponse() :
            FPlayFabBaseModel(),
            GameID(),
            ServerHostname(),
            ServerIPV6Address(),
            ServerPort(0)
            {}

        FStartGameResponse(const FStartGameResponse& src) :
            FPlayFabBaseModel(),
            GameID(src.GameID),
            ServerHostname(src.ServerHostname),
            ServerIPV6Address(src.ServerIPV6Address),
            ServerPort(src.ServerPort)
            {}

        FStartGameResponse(const TSharedPtr<FJsonObject>& obj) : FStartGameResponse()
        {
            readFromValue(obj);
        }

        ~FStartGameResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FUserInfoRequest : public FPlayFabBaseModel
    {
        /**
         * Minimum catalog version for which data is requested (filters the results to only contain inventory items which have a
         * catalog version of this or higher).
         */
        int32 MinCatalogVersion;

        // PlayFab unique identifier of the user whose information is being requested.
        FString PlayFabId;

        FUserInfoRequest() :
            FPlayFabBaseModel(),
            MinCatalogVersion(0),
            PlayFabId()
            {}

        FUserInfoRequest(const FUserInfoRequest& src) :
            FPlayFabBaseModel(),
            MinCatalogVersion(src.MinCatalogVersion),
            PlayFabId(src.PlayFabId)
            {}

        FUserInfoRequest(const TSharedPtr<FJsonObject>& obj) : FUserInfoRequest()
        {
            readFromValue(obj);
        }

        ~FUserInfoRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FVirtualCurrencyRechargeTime : public FPlayFabBaseModel
    {
        /**
         * Maximum value to which the regenerating currency will automatically increment. Note that it can exceed this value
         * through use of the AddUserVirtualCurrency API call. However, it will not regenerate automatically until it has fallen
         * below this value.
         */
        int32 RechargeMax;

        // Server timestamp in UTC indicating the next time the virtual currency will be incremented.
        FDateTime RechargeTime;

        // Time remaining (in seconds) before the next recharge increment of the virtual currency.
        int32 SecondsToRecharge;

        FVirtualCurrencyRechargeTime() :
            FPlayFabBaseModel(),
            RechargeMax(0),
            RechargeTime(0),
            SecondsToRecharge(0)
            {}

        FVirtualCurrencyRechargeTime(const FVirtualCurrencyRechargeTime& src) :
            FPlayFabBaseModel(),
            RechargeMax(src.RechargeMax),
            RechargeTime(src.RechargeTime),
            SecondsToRecharge(src.SecondsToRecharge)
            {}

        FVirtualCurrencyRechargeTime(const TSharedPtr<FJsonObject>& obj) : FVirtualCurrencyRechargeTime()
        {
            readFromValue(obj);
        }

        ~FVirtualCurrencyRechargeTime();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFAB_API FUserInfoResponse : public FPlayFabBaseModel
    {
        // [optional] Array of inventory items in the user's current inventory.
        TArray<FItemInstance> Inventory;
        // Boolean indicating whether the user is a developer.
        bool IsDeveloper;

        // [optional] PlayFab unique identifier of the user whose information was requested.
        FString PlayFabId;

        // [optional] Steam unique identifier, if the user has an associated Steam account.
        FString SteamId;

        // [optional] Title specific display name, if set.
        FString TitleDisplayName;

        // [optional] PlayFab unique user name.
        FString Username;

        // [optional] Array of virtual currency balance(s) belonging to the user.
        TMap<FString, int32> VirtualCurrency;
        // [optional] Array of remaining times and timestamps for virtual currencies.
        TMap<FString, FVirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;
        FUserInfoResponse() :
            FPlayFabBaseModel(),
            Inventory(),
            IsDeveloper(false),
            PlayFabId(),
            SteamId(),
            TitleDisplayName(),
            Username(),
            VirtualCurrency(),
            VirtualCurrencyRechargeTimes()
            {}

        FUserInfoResponse(const FUserInfoResponse& src) :
            FPlayFabBaseModel(),
            Inventory(src.Inventory),
            IsDeveloper(src.IsDeveloper),
            PlayFabId(src.PlayFabId),
            SteamId(src.SteamId),
            TitleDisplayName(src.TitleDisplayName),
            Username(src.Username),
            VirtualCurrency(src.VirtualCurrency),
            VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

        FUserInfoResponse(const TSharedPtr<FJsonObject>& obj) : FUserInfoResponse()
        {
            readFromValue(obj);
        }

        ~FUserInfoResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

}
}
