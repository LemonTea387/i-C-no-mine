#include "GameBoard.hpp"

#include "Scene/GameScene.hpp"

GameBoard::GameBoard(int sizeX, int sizeY)
    : m_Dimension{sizeX, sizeY},
      m_ActualBoardRect{gameboardArea.x, gameboardArea.y,
                        m_Dimension.first * TILE_SIZE_X,
                        m_Dimension.second * TILE_SIZE_Y} {
  // Setup the board
  for (int i = 0; i < sizeX * sizeY; i++) {
    m_Board.push_back(Tile{false, 0});
  }
}

GameBoard::~GameBoard() {}

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
} // namespace GameBoardUtil
