#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL_render.h>

class GameObject {
public:
  GameObject();
  ~GameObject();
  virtual void render(SDL_Renderer &renderer) const;
  SDL_Rect getBounds() const { return m_Bounds; };

private:
  SDL_Rect m_Bounds;
  SDL_Texture *m_Texture{nullptr};
  SDL_Rect m_TextureRect;
};

#endif
