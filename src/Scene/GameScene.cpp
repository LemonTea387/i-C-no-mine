#include "GameScene.hpp"

GameScene::GameScene(int sizeX, int sizeY) : m_GameBoard(sizeX, sizeY) {}

GameScene::~GameScene() {}

void GameScene::Update(const SDL_Event &event) {}

void GameScene::Render(SDL_Renderer &renderer) {}
