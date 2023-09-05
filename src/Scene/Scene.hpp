#ifndef SCENE_H
#define SCENE_H

#include <SDL_events.h>
class Scene {
public:
  virtual void Update(const SDL_Event &event) = 0;
  virtual void Render() = 0;
  Scene();
  ~Scene();
};

#endif
