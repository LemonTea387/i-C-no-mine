#ifndef GAME_SCENE_H 
#define GAME_SCENE_H

#include "../GameBoard.hpp"
#include "Scene.hpp"

class GameScene : public Scene {
public:
  GameScene(int sizeX, int sizeY);
  ~GameScene();
  virtual void Update(const SDL_Event &event) override;
  virtual void Render(SDL_Renderer &renderer) override;

private:
  GameBoard m_GameBoard;
};

#endif
