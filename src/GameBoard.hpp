#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GameObject.hpp"
#include "Tile.hpp"
#include <vector>

class GameBoard : public GameObject {
  static const int TILE_SIZE_X = 25;
  static const int TILE_SIZE_Y = 25;

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

  virtual void render(SDL_Renderer &renderer) const override;
  virtual void update(const SDL_Event &event) override;

private:
  std::vector<Tile> m_Board;
  std::pair<int, int> m_Dimension;
  SDL_Rect m_ActualBoardRect;
};

namespace GameBoardUtil {
std::pair<int, int> resolveCoordinateToTile(int x, int y, int tileSizeX,
                                            int tileSizeY,
                                            const SDL_Rect &actualBoardRect);
bool withinRange(int x, int y, const SDL_Rect &box);
} // namespace GameBoardUtil

#endif
