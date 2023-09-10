#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL_render.h>
#include <SDL_events.h>

class GameObject {
public:
  GameObject(){};
  GameObject(SDL_Rect bounds) : m_Bounds{bounds} {};
  virtual ~GameObject(){};
  virtual void render(SDL_Renderer &renderer) const = 0;
  virtual void update(const SDL_Event &event) = 0;
  SDL_Rect getBounds() const { return m_Bounds; };
  void setBounds(SDL_Rect newBounds) { m_Bounds = newBounds; }

protected:
  SDL_Rect m_Bounds;
  SDL_Texture *m_Texture{nullptr};
  SDL_Rect m_TextureRect;
};

#endif
