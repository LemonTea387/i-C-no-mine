#include "GameBoard.hpp"

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
    tileRect.y = (i / m_Dimension.first) * TILE_SIZE_Y;
    SDL_RenderDrawRect(&renderer, &tileRect);
  }
}

void GameBoard::update(const SDL_Event &event) {
  if (event.type == SDL_MOUSEBUTTONUP) {
  }
}

namespace GameBoardUtil {
bool withinRange(int x, int y, SDL_Rect box) {
  return x >= box.x && x <= box.x + box.w && y >= box.y && y <= box.y + box.h;
}
} // namespace GameBoardUtil
