#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "Renderer.h"


TextureComponent::TextureComponent()
	:BaseComponent(Types::TEXTURE)
	, m_renderWithSize(false)
{
}


TextureComponent::~TextureComponent()
{
}
void TextureComponent::Update(const float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void TextureComponent::Render()
{
	if (mTexture != nullptr)
	{
		auto pos = mTransform.GetPosition();
		if (!m_renderWithSize)
		{
			dae::Renderer::GetInstance().RenderTexture(*mTexture, pos.x, pos.y);
		}
		else
		{
			dae::Renderer::GetInstance().RenderTexture(*mTexture, pos.x, pos.y, m_width, m_height);
		}
	}
	
}

void TextureComponent::SetTexture(const std::string & filename)
{
	mTexture = dae::ResourceManager::GetInstance().LoadTexture(filename);
}

void TextureComponent::SetPosition(float x, float y, float width, float height)
{
	mTransform.SetPosition(x, y, 0.0f);
	if (width > 0 && height > 0)
	{
		m_width = width;
		m_height = height;
		m_renderWithSize = true;
	}
	else
	{
		m_renderWithSize = false;
	}
}
