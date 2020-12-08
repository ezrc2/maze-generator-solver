#include "core/maze_generator.h"

MazeGenerator::MazeGenerator(int height, int width) {
  height_ = height;
  width_ = width;
  for (int i = 0; i < height; i++) {
    std::vector<int> row(width, 0);
    cells_.push_back(row);
  }
}