#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Tile.hpp"
#include <memory>

class GameBoard {
public:
  GameBoard(int sizeX, int sizeY);
  ~GameBoard();
  /**
   * We don't want a gameboard to be copy-able, since it makes no sense to do
   * it.
   */
  GameBoard(GameBoard const &) = delete;

  /**
   * Deletes the assignment operator. Similarly to the copy constructor, we
   * don't want to be able to assign it to another.
   */
  void operator=(const GameBoard &) = delete;

private:
  std::unique_ptr<Tile> m_Board;
};

#endif
