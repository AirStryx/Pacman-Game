#include "MiniginPCH.h"
#include "TextComponent.h"
#include "Renderer.h"


TextComponent::TextComponent(std::shared_ptr<dae::GameObject> go)
	:BaseComponent(Types::TEXT, go)
	, mNeedsUpdate(false)
{
}


TextComponent::~TextComponent()
{
}
void TextComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
	if (mNeedsUpdate)
	{
		const auto surf = TTF_RenderText_Blended(mFont->GetFont(), mText.c_str(), m_Color);
		if (surf == nullptr) {
			std::stringstream ss; ss << "Render text failed: " << SDL_GetError();
			throw std::runtime_error(ss.str().c_str());
		}
		auto texture = SDL_CreateTextureFromSurface(dae::Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) {
			std::stringstream ss; ss << "Create text texture from surface failed: " << SDL_GetError();
			throw std::runtime_error(ss.str().c_str());
		}
		SDL_FreeSurface(surf);
		mTexture = std::make_shared<dae::Texture2D>(texture);
	}
}

void TextComponent::LateUpdate(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void TextComponent::Render()
{
	if (mTexture != nullptr)
	{
		const auto pos = mTransform.GetPosition();
		dae::Renderer::GetInstance().RenderTexture(*mTexture, pos.x, pos.y);
	}

}

void TextComponent::SetText(const std::string& text)
{
	mText = text;
	mNeedsUpdate = true;
}

void TextComponent::SetPosition(float x, float y)
{
	mTransform.SetPosition(x, y, 0.0f);
}

void TextComponent::SetFont(std::shared_ptr<dae::Font> font)
{
	mFont = font;
	mNeedsUpdate = true;
}

void TextComponent::SetColor(SDL_Color col)
{
	m_Color = col;
	mNeedsUpdate = true;
}
