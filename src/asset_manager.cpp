#include "asset_manager.h"

namespace stg
{

void AssetManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;
	if (texture.loadFromFile(fileName))
		m_textures[name] = texture;
}

sf::Texture& AssetManager::getTexture(std::string name)
{
	return m_textures[name];
}

void AssetManager::loadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName))
		m_fonts[name] = font;
}

sf::Font& AssetManager::getFont(std::string name)
{
	return m_fonts[name];
}

}
