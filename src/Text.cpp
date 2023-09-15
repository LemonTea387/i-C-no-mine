#include "Text.hpp"
#include <SDL_surface.h>
#include <SDL_ttf.h>
#include <memory>

Text::Text() {}

Text::Text(std::string str, TTF_Font &font, SDL_Color color)
    : m_Color{color}, m_Rendered{false} {
  SetFont(font);
  SetText(str);
}

Text::~Text() {
  // Free previous texture if available
  if (m_Texture != nullptr) {
    SDL_DestroyTexture(m_Texture);
  }
}

void Text::SetText(const std::string &str) {
  m_Text = str;
  m_Rendered = false;
}

void Text::SetFont(TTF_Font &font) { m_Font = &font; }

void Text::RenderTexture(SDL_Renderer *renderer) {
  // Free previous texture if available
  if (m_Texture != nullptr) {
    SDL_DestroyTexture(m_Texture);
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
  m_Texture = texture;
  m_Rendered = true;
  SDL_FreeSurface(textSurface);
}

void Text::Render(SDL_Renderer &renderer, const SDL_Rect &dstRect) {
  if (!m_Rendered)
    RenderTexture(&renderer);

  SDL_RenderCopy(&renderer, m_Texture, NULL, &dstRect);
}
