#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameObject.hpp"
#include "Text.hpp"
#include "Tile.hpp"
#include <vector>

class GameBoard : public GameObject {
  static const int TILE_SIZE_X = 25;
  static const int TILE_SIZE_Y = 25;

public:
  bool gameEnded;
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
  void reset();

  virtual void render(SDL_Renderer &renderer) override;
  virtual void update(const SDL_Event &event) override;

private:
  std::vector<Text> m_Texts;
  std::vector<Tile> m_Board;
  std::pair<int, int> m_Dimension;
  SDL_Rect m_ActualBoardRect;
  void placeMines(int numMines);
  void incrementNeighbours(int x, int y);
  void revealAdjacentEmptyNeighbours(int x, int y);
};

namespace GameBoardUtil {
std::pair<int, int> resolveCoordinateToTile(int x, int y, int tileSizeX,
                                            int tileSizeY,
                                            const SDL_Rect &actualBoardRect);
bool withinRange(int x, int y, const SDL_Rect &box);
int translateCoordinate(int x, int y, int sizeX, int sizeY);
} // namespace GameBoardUtil
#endif
