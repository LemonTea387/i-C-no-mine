cmake_minimum_required(VERSION 3.19)

project(
  i-c-no-mine
  VERSION 0.1
  DESCRIPTION "Just a minesweeper clone to practice sdl2, not too fancy."
  LANGUAGES CXX
  )

include(FetchContent)

# sdl2
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL
    GIT_TAG         release-2.28.3
    GIT_PROGRESS    TRUE
)

# sdl2_image
FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL_image
    GIT_TAG         release-2.6.3
    GIT_PROGRESS    TRUE
)
set(SDL2IMAGE_SAMPLES OFF)
set(SDL2IMAGE_INSTALL OFF)

# sdl2_ttf
FetchContent_Declare(
    SDL2_ttf
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL_ttf
    GIT_TAG         release-2.20.2
    GIT_PROGRESS    TRUE
)
set(SDL2TTF_SAMPLES OFF)
set(SDL2TTF_INSTALL OFF)
FetchContent_MakeAvailable(SDL2 SDL2_image SDL2_ttf)

add_executable(i-c-no-mine 
  src/main.cpp
  src/GameBoard.cpp
  src/Scene/Scene.cpp
  src/Scene/GameScene.cpp
  src/Text.cpp
  src/AssetManager.cpp
  )
target_link_libraries( i-c-no-mine PRIVATE
  SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)
