
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "GameJam2021SystemComponent.h"

namespace GameJam2021
{
    void GameJam2021SystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<GameJam2021SystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<GameJam2021SystemComponent>("GameJam2021", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void GameJam2021SystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("GameJam2021Service"));
    }

    void GameJam2021SystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("GameJam2021Service"));
    }

    void GameJam2021SystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void GameJam2021SystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    GameJam2021SystemComponent::GameJam2021SystemComponent()
    {
        if (GameJam2021Interface::Get() == nullptr)
        {
            GameJam2021Interface::Register(this);
        }
    }

    GameJam2021SystemComponent::~GameJam2021SystemComponent()
    {
        if (GameJam2021Interface::Get() == this)
        {
            GameJam2021Interface::Unregister(this);
        }
    }

    void GameJam2021SystemComponent::Init()
    {
    }

    void GameJam2021SystemComponent::Activate()
    {
        GameJam2021RequestBus::Handler::BusConnect();
    }

    void GameJam2021SystemComponent::Deactivate()
    {
        GameJam2021RequestBus::Handler::BusDisconnect();
    }
}
