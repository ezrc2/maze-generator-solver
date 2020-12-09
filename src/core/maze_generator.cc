#include "core/maze_generator.h"

MazeGenerator::MazeGenerator(int height, int width) {
  height_ = height;
  width_ = width;
  for (int i = 0; i < height; i++) {
    std::vector<int> row(width, kWall);
    cells_.push_back(row);
  }
}

void MazeGenerator::GenerateMaze() {
  int row = rand() % height_;
  int col = rand() % width_;
  while (row % 2 == 0) {
    row = rand() % height_;
  }
  while (col % 2 == 0) {
    col = rand() % width_;
  }

  cells_[row][col] = kPath;
  RandomDFS(row, col);
}

void MazeGenerator::RandomDFS(int row, int col) {
  std::vector<int> directions = GetRandomDirections();
  for (int direction : directions) {
    switch (direction) {
      case 0: // Up
        if (row - 2 > 0 && cells_[row - 2][col] == kWall) {
          cells_[row - 2][col] = kPath;
          cells_[row - 1][col] = kPath;
          RandomDFS(row - 2, col);
        }
        break;
      case 1: // Down
        if (row + 2 < height_ - 1 && cells_[row + 2][col] == kWall) {
          cells_[row + 2][col] = kPath;
          cells_[row + 1][col] = kPath;
          RandomDFS(row + 2, col);
        }
        break;
      case 2: // Left
        if (col - 2 > 0 && cells_[row][col - 2] == kWall) {
          cells_[row][col - 2] = kPath;
          cells_[row][col - 1] = kPath;
          RandomDFS(row, col - 2);
        }
        break;
      case 3: // Right
        if (col + 2 < width_ - 1 && cells_[row][col + 2] == kWall) {
          cells_[row][col + 2] = kPath;
          cells_[row][col + 1] = kPath;
          RandomDFS(row, col + 2);
        }
        break;
    }
  }
  // Exit is bottom right corner
  cells_[height_ - 2][width_ - 1] = kPath;
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


