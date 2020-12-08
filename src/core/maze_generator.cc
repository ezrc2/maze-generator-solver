#include "core/maze_generator.h"

MazeGenerator::MazeGenerator(int height, int width) {
  height_ = height;
  width_ = width;
  for (int i = 0; i < height; i++) {
    std::vector<int> row(width, 0);
    cells_.push_back(row);
  }
}

std::vector<int> MazeGenerator::GetRandomDirections() {
  std::vector<int> directions;
  directions.reserve(4);
  for (int i = 0; i < 4; i++) {
    directions.push_back(i);
  }
  std::shuffle(directions.begin(), directions.end(), std::random_device());
  return directions;
}

std::vector<std::vector<int>> MazeGenerator::GetMazeCells() {
  return cells_;
}


