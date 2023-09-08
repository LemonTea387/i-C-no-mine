#include "GameBoard.hpp"

GameBoard::GameBoard(int sizeX, int sizeY) : m_Dimension{sizeX, sizeY} {}

GameBoard::~GameBoard() {}

void GameBoard::render(SDL_Renderer &renderer) const {}
