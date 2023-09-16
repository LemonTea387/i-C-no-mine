#ifndef TILE_H
#define TILE_H

#include <stdint.h>
typedef struct {
  bool hasMine;
  bool revealed;
  bool mark;
  uint8_t mineNumber;
} Tile;

#endif
