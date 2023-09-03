#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Tile.hpp"
#include <memory>

class GameBoard {
public:
  GameBoard(int sizeX, int sizeY);
  ~GameBoard();
private:
  std::unique_ptr<Tile> m_Board;
};

#endif
