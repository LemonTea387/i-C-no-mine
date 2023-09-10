#include "GameScene.hpp"

#include "../Constants.hpp"
#include <SDL_render.h>

GameScene::GameScene(int sizeX, int sizeY) : m_GameBoard(sizeX, sizeY) {}

GameScene::~GameScene() {}

void GameScene::Update(const SDL_Event &event) { m_GameBoard.update(event); }

void GameScene::Render(SDL_Renderer &renderer) {
  SDL_RenderSetViewport(&renderer, &gameboardArea);
  m_GameBoard.render(renderer);
}
