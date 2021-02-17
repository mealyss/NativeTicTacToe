#include <cassert>

#include "asset_manager.h"

namespace stg
{

void AssetManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;
	bool success = texture.loadFromFile(fileName);
	assert(success);
	m_textures[name] = texture;
}

sf::Texture& AssetManager::getTexture(std::string name)
{
	return m_textures[name];
}

void AssetManager::loadFont(std::string name, std::string fileName)
{
	sf::Font font;
	bool success = font.loadFromFile(fileName);
	assert(success);
	m_fonts[name] = font;
}

sf::Font& AssetManager::getFont(std::string name)
{
	return m_fonts[name];
}

void AssetManager::loadImage(std::string name, std::string fileName)
{
	sf::Image image;
	bool success = image.loadFromFile(fileName);
	assert(success);
	m_images[name] = image;
}

sf::Image& AssetManager::getImage(std::string name)
{
	return m_images[name];
}

}
