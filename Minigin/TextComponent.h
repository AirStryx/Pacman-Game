#pragma once
#include "BaseComponent.h"
#include "Transform.h"
#include "Texture2D.h"
#include "ResourceManager.h"
#include "Font.h"
class TextComponent : public BaseComponent
{
public:
	TextComponent();
	virtual ~TextComponent();
	void Update(const float deltaTime) override;
	void Render() override;
	void SetText(const std::string& text);
	void SetPosition(float x, float y);
	void SetFont(std::shared_ptr<dae::Font> font);

private:
	bool mNeedsUpdate;
	std::string mText;
	dae::Transform mTransform;
	std::shared_ptr<dae::Font> mFont;
	std::shared_ptr<dae::Texture2D> mTexture;
};

