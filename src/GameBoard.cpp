#include "GameBoard.hpp"
#include "Tile.hpp"

GameBoard::GameBoard(int sizeX, int sizeY) : m_Dimension{sizeX, sizeY} {
  // Setup the board
  for (int i = 0; i < sizeX * sizeY; i++) {
    m_Board.push_back(Tile{.hasMine = false, .mineNumber = 0});
  }
}

GameBoard::~GameBoard() {}

void GameBoard::render(SDL_Renderer &renderer) const {}
