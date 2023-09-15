#include "AssetManager.hpp"
#include "SDL_ttf.h"

#include <iostream>
#include <memory>
#include <vector>

// Anonymous namespace
namespace {
typedef std::pair<int, std::string> AssetFilePair;

/**
 * Define all the file paths to the Fonts
 */
const std::vector<AssetFilePair> fonts = {
    {GameAsset::Font::COMFORTAA,
     "assets/fonts/Comfortaa/static/Comfortaa-SemiBold.ttf"}};
} // namespace

TTF_Font *AssetManager::GetFont(GameAsset::Font t) const {
  return m_Fonts.at(t);
}

AssetManager::AssetManager() {
  // We load all the assets at the start.
  LoadFonts();
}

AssetManager::~AssetManager() {
  // Close all fonts
  for (auto &pair : m_Fonts) {
    TTF_CloseFont(pair.second);
  }
}

void AssetManager::LoadFonts() {
  TTF_Font *font;
  for (const auto &pair : fonts) {
    font = TTF_OpenFont(pair.second.c_str(), 20);
    if (font == nullptr) {
      std::cerr << "Error loading font at " << pair.second << std::endl;
    }
    m_Fonts.insert({(GameAsset::Font)pair.first, font});
  }
}
