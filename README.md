# i-C-no-mine
Just a minesweeper clone to practice sdl2, not too fancy.

## Building
```
cmake -DCMAKE_INSTALL_PREFIX="[SDL_PATH]\cmake;[SDL_image_PATH]\cmake" -B .\build
```
If you're on MinGW + clangd
```
cmake -DCMAKE_INSTALL_PREFIX="[SDL_PATH]\cmake;[SDL_image_PATH]\cmake" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -G Ninja -B .\build
```
