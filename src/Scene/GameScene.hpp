#ifndef GAME_SCENE_H 
#define GAME_SCENE_H

#include "../Constants.hpp"
#include "../GameBoard.hpp"
#include "Scene.hpp"
#include <SDL_rect.h>

class GameScene : public Scene {
public:
  GameScene(int sizeX, int sizeY);
  ~GameScene();
  virtual void Update(const SDL_Event &event) override;
  virtual void Render(SDL_Renderer &renderer) override;

private:
  GameBoard m_GameBoard;
};

const SDL_Rect gameboardArea{25, 25, Constants::SCREEN_WIDTH - 50,
                             Constants::SCREEN_HEIGHT - 50};

#endif
