cmake_minimum_required(VERSION 3.19)

project(
  i-c-no-mine
  VERSION 0.1
  DESCRIPTION "Just a minesweeper clone to practice sdl2, not too fancy."
  LANGUAGES CXX
  )

find_package(SDL2 REQUIRED)

add_executable(i-c-no-mine 
  src/main.cpp
  )

include_directories(SDL2::Headers)
target_link_libraries( i-c-no-mine PRIVATE
  SDL2::SDL2)

