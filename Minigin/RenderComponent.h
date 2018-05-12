#pragma once
#include "BaseComponent.h"
class RenderComponent : public BaseComponent
{
public:
	RenderComponent();
	virtual ~RenderComponent();
	void Update(const float deltaTime) override;
	void Render() override;
};

