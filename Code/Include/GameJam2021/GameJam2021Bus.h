
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace GameJam2021
{
    class GameJam2021Requests
    {
    public:
        AZ_RTTI(GameJam2021Requests, "{47b7150b-434d-4c72-bb3e-ed5f2b55d422}");
        virtual ~GameJam2021Requests() = default;
        // Put your public methods here
    };
    
    class GameJam2021BusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using GameJam2021RequestBus = AZ::EBus<GameJam2021Requests, GameJam2021BusTraits>;
    using GameJam2021Interface = AZ::Interface<GameJam2021Requests>;

} // namespace GameJam2021
