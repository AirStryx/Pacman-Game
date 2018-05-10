#pragma once
#include "BaseComponent.h"
#include "Transform.h"
#include "Texture2D.h"
#include "ResourceManager.h"
class TextureComponent : public BaseComponent
{
public:
	TextureComponent();
	~TextureComponent();
	void Update(const float deltaTime) override;
	void Render() override;
	void SetTexture(const std::string& filename);
	void SetPosition(float x, float y, float width = 0.f, float height = 0.f);

private:
	dae::Transform mTransform;
	float m_width, m_height;
	bool m_renderWithSize;
	std::shared_ptr<dae::Texture2D> mTexture;
};

