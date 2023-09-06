#ifndef SCENE_H
#define SCENE_H

#include <SDL_events.h>
#include <SDL_render.h>
class Scene {
public:
  virtual void Update(const SDL_Event &event) = 0;
  virtual void Render(SDL_Renderer &renderer) = 0;
  Scene();
  ~Scene();
};

#endif
