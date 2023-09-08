#ifndef TILE_H
#define TILE_H

#include <stdint.h>
typedef struct {
  bool hasMine;
  uint8_t mineNumber;
} Tile;

#endif
