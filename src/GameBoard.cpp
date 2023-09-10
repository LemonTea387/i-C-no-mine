#include "GameBoard.hpp"
#include "Tile.hpp"
#include <SDL_render.h>

GameBoard::GameBoard(int sizeX, int sizeY) : m_Dimension{sizeX, sizeY} {
  // Setup the board
  for (int i = 0; i < sizeX * sizeY; i++) {
    m_Board.push_back(Tile{false, 0});
  }
}

GameBoard::~GameBoard() {}

void GameBoard::render(SDL_Renderer &renderer) const {
  SDL_Rect tileRect{0, 0, TILE_SIZE_X, TILE_SIZE_Y};
  SDL_SetRenderDrawColor(&renderer, 160, 160, 160, 255);
  for (int i = 0; i < m_Board.size(); i++) {
    tileRect.x = (i % m_Dimension.first) * TILE_SIZE_X;
    tileRect.y = (i / m_Dimension.second) * TILE_SIZE_Y;
    SDL_RenderDrawRect(&renderer, &tileRect);
  }
}

void GameBoard::update(const SDL_Event &event) {}
