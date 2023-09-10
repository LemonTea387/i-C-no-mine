#include "GameScene.hpp"

#include "../Constants.hpp"
#include <SDL_render.h>

GameScene::GameScene(int sizeX, int sizeY) : m_GameBoard(sizeX, sizeY) {}

GameScene::~GameScene() {}

void GameScene::Update(const SDL_Event &event) {}

void GameScene::Render(SDL_Renderer &renderer) {
  // Center calculation
  SDL_Rect gameboardArea{25, 25, Constants::SCREEN_WIDTH - 50,
                         Constants::SCREEN_HEIGHT - 50};
  SDL_RenderSetViewport(&renderer, &gameboardArea);
  m_GameBoard.render(renderer);
}
