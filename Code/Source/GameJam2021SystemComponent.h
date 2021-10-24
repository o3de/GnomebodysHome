
#pragma once

#include <AzCore/Component/Component.h>

#include <GameJam2021/GameJam2021Bus.h>

namespace GameJam2021
{
    class GameJam2021SystemComponent
        : public AZ::Component
        , protected GameJam2021RequestBus::Handler
    {
    public:
        AZ_COMPONENT(GameJam2021SystemComponent, "{279b3554-e39f-4db3-b47c-5165ceca58ad}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        GameJam2021SystemComponent();
        ~GameJam2021SystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // GameJam2021RequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
