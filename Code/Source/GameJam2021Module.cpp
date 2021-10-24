
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "GameJam2021SystemComponent.h"

namespace GameJam2021
{
    class GameJam2021Module
        : public AZ::Module
    {
    public:
        AZ_RTTI(GameJam2021Module, "{d5214946-0e67-4a51-baba-f1b733e22631}", AZ::Module);
        AZ_CLASS_ALLOCATOR(GameJam2021Module, AZ::SystemAllocator, 0);

        GameJam2021Module()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                GameJam2021SystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<GameJam2021SystemComponent>(),
            };
        }
    };
}// namespace GameJam2021

AZ_DECLARE_MODULE_CLASS(Gem_GameJam2021, GameJam2021::GameJam2021Module)
