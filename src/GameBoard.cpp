#include "GameBoard.hpp"

#include "Scene/GameScene.hpp"
#include <cstdlib> /* rand */
#include <stdlib.h> /* srand */
#include <time.h>   /* time */

GameBoard::GameBoard(int sizeX, int sizeY)
    : m_Dimension{sizeX, sizeY},
      m_ActualBoardRect{gameboardArea.x, gameboardArea.y,
                        m_Dimension.first * TILE_SIZE_X,
                        m_Dimension.second * TILE_SIZE_Y},
      gameEnded{false} {
  // Setup the board
  for (int i = 0; i < sizeX * sizeY; i++) {
    m_Board.push_back(Tile{false, false, 0});
  }

  // Scatter Mines
  placeMines(m_Board.size() / 5);
}

GameBoard::~GameBoard() {}

void GameBoard::reset() {
  for (auto &tile : m_Board) {
    tile.revealed = false;
    tile.hasMine = false;
    tile.mineNumber = 0;
  }
  // Scatter Mines
  placeMines(m_Board.size() / 5);
  gameEnded = false;
}

void GameBoard::placeMines(int numMines) {
  srand(time(NULL));
  int minesPlaced = 0;
  while (minesPlaced < numMines) {
    // 1) Select a random tile
    // 2) Place Mine if possible, if not, continue placing
    // 3) Increment number of neighbouring tiles
    // 4) Profit?
    int i = std::rand() % m_Board.size();
    if (m_Board[i].hasMine)
      continue;

    m_Board[i].hasMine = true;
    minesPlaced++;
    incrementNeighbours(i % m_Dimension.first, i / m_Dimension.first);
  }
}

void GameBoard::incrementNeighbours(int x, int y) {
  // 1) Iterate through the 8 closest neighbours and increment their numbers
  int i = 0;
  int sizeX = m_Dimension.first;
  int sizeY = m_Dimension.second;
  i = GameBoardUtil::translateCoordinate(x - 1, y - 1, sizeX, sizeY);
  if (i >= 0)
    m_Board[i].mineNumber += 1;
  i = GameBoardUtil::translateCoordinate(x, y - 1, sizeX, sizeY);
  if (i >= 0)
    m_Board[i].mineNumber += 1;
  i = GameBoardUtil::translateCoordinate(x + 1, y - 1, sizeX, sizeY);
  if (i >= 0)
    m_Board[i].mineNumber += 1;
  i = GameBoardUtil::translateCoordinate(x - 1, y, sizeX, sizeY);
  if (i >= 0)
    m_Board[i].mineNumber += 1;
  i = GameBoardUtil::translateCoordinate(x + 1, y, sizeX, sizeY);
  if (i >= 0)
    m_Board[i].mineNumber += 1;
  i = GameBoardUtil::translateCoordinate(x - 1, y + 1, sizeX, sizeY);
  if (i >= 0)
    m_Board[i].mineNumber += 1;
  i = GameBoardUtil::translateCoordinate(x, y + 1, sizeX, sizeY);
  if (i >= 0)
    m_Board[i].mineNumber += 1;
  i = GameBoardUtil::translateCoordinate(x + 1, y + 1, sizeX, sizeY);
  if (i >= 0)
    m_Board[i].mineNumber += 1;
}

void GameBoard::render(SDL_Renderer &renderer) const {
  SDL_Rect tileRect{0, 0, TILE_SIZE_X, TILE_SIZE_Y};
  for (int i = 0; i < m_Board.size(); i++) {
    tileRect.x = (i % m_Dimension.first) * TILE_SIZE_X;
    tileRect.y = (i / m_Dimension.first) * TILE_SIZE_Y;
    auto &tile = m_Board[i];
    if (tile.revealed) {
      SDL_SetRenderDrawColor(&renderer, 224, 224, 224, 255);
    } else {
      SDL_SetRenderDrawColor(&renderer, 128, 128, 128, 255);
    }
    SDL_RenderFillRect(&renderer, &tileRect);
    SDL_SetRenderDrawColor(&renderer, 32, 32, 32, 255);
    SDL_RenderDrawRect(&renderer, &tileRect);
  }
}

void GameBoard::update(const SDL_Event &event) {
  if (!(event.type == SDL_MOUSEBUTTONUP)) {
    return;
  }
  if (!GameBoardUtil::withinRange(event.button.x, event.button.y,
                                  m_ActualBoardRect)) {
    return;
  }

  auto tileCoord = GameBoardUtil::resolveCoordinateToTile(
      event.button.x, event.button.y, TILE_SIZE_X, TILE_SIZE_Y,
      m_ActualBoardRect);
  // y * DimX + x
  auto &tile = m_Board[tileCoord.second * m_Dimension.first + tileCoord.first];

  // Different cases of the tile
  if (tile.hasMine) {
    gameEnded = true;
    return;
  }
  tile.revealed = true;
}

namespace GameBoardUtil {
std::pair<int, int> resolveCoordinateToTile(int x, int y, int tileSizeX,
                                            int tileSizeY,
                                            const SDL_Rect &actualBoardRect) {
  return std::pair<int, int>{(x - actualBoardRect.x) / tileSizeX,
                             (y - actualBoardRect.y) / tileSizeY};
}

bool withinRange(int x, int y, const SDL_Rect &box) {
  return x >= box.x && x <= box.x + box.w && y >= box.y && y <= box.y + box.h;
}

int translateCoordinate(int x, int y, int sizeX, int sizeY) {
  // Gives negative index if it's invalid.
  if ((x < 0 || y < 0) || (x >= sizeX || y >= sizeY)) {
    return -1;
  }
  return y * sizeX + x;
}

} // namespace GameBoardUtil
