#pragma once
#include "BaseComponent.h"
class RenderComponent : public BaseComponent
{
public:
	RenderComponent();
	~RenderComponent();
	void Update(const float deltaTime) override;
	void LateUpdate(const float deltaTime) override;
	void Render() override;
};

