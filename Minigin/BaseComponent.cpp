#include "MiniginPCH.h"
#include "BaseComponent.h"
//test

BaseComponent::BaseComponent(Types type, std::shared_ptr<dae::GameObject> go)
	:m_type(type)
	,m_GO(go)
{
}


BaseComponent::~BaseComponent()
{
}
