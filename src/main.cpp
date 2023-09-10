#include <SDL.h>
#include <SDL_error.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#undef main

// Logging
#include <stdio.h>

#include "Constants.hpp"
#include "Scene/GameScene.hpp"

int initSDL(SDL_Window **window);

int main(int argc, char *args[]) {
  // The window we'll be rendering to
  SDL_Window *window = NULL;

  if (initSDL(&window))
    return -1;

  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
    return -1;
  }

  // Game Setup
  GameScene gameScene{10, 10};

  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        quit = true;
      gameScene.Update(e);
    }
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    gameScene.Render(*renderer);
    SDL_RenderPresent(renderer);
  }
  // Destroy window
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();
  return 0;
}

int initSDL(SDL_Window **window) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return -1;
  }
  // Create window
  *window =
      SDL_CreateWindow(Constants::GAME_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, Constants::SCREEN_WIDTH,
                       Constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return -1;
  }

  return 0;
}
