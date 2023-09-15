#include "Text.hpp"
#include "SDL_surface.h"
#include "SDL_ttf.h"
#include <SDL_render.h>
#include <memory>

Text::Text() {}

Text::Text(std::string str, TTF_Font &font, SDL_Color color) : m_Color{color} {
  SetFont(font);
  SetText(str);
}

Text::~Text() {}

void Text::SetText(const std::string &str) { m_Text = str; }

void Text::SetFont(TTF_Font &font) { m_Font = &font; }

void Text::RenderTexture(SDL_Renderer *renderer) {
  // Free previous texture if available
  if (m_Texture != nullptr) {
    SDL_DestroyTexture(m_Texture.get());
    m_Texture.reset();
  }

  if (m_Font == nullptr) {
    return;
  }

  SDL_Surface *textSurface =
      TTF_RenderText_Solid(m_Font, m_Text.c_str(), m_Color);
  if (textSurface == nullptr) {
    return;
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, textSurface);
  if (texture == nullptr) {
    return;
  }
  m_Texture = std::unique_ptr<SDL_Texture>(texture);

  SDL_FreeSurface(textSurface);
}
