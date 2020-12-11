#include "core/maze_generator.h"

MazeGenerator::MazeGenerator(int height, int width) {
  // Dimensions need to be odd
  height_ = height % 2 == 0 ? height + 1 : height;
  width_ = width % 2 == 0 ? width + 1 : width;

  for (int i = 0; i < height_; i++) {
    std::vector<int> row(width_, kWall);
    cells_.push_back(row);
  }

  // Exit is bottom right corner
  end_cell_ = glm::vec2(height_ - 2, width_ - 1);
}

void MazeGenerator::GenerateMaze() {
  int row = rand() % height_;
  while (row % 2 == 0) {
    row = rand() % height_;
  }

  int col = rand() % width_;
  while (col % 2 == 0) {
    col = rand() % width_;
  }

  // Starting row and column for generator
  cells_[row][col] = kPath;
  path_.emplace_back(row, col);

  RandomDFS(row, col);

  // Mark start and exit as a path
  int start_row = static_cast<int>(kStartCell.x);
  int start_col = static_cast<int>(kStartCell.y);
  cells_[start_row][start_col] = kPath;
  cells_[height_ - 2][width_ - 1] = kPath;

  // Add start and exit to path
  path_.emplace_back(kStartCell.x, kStartCell.y);
  path_.emplace_back(height_ - 2, width_ - 1);
}

void MazeGenerator::RandomDFS(int row, int col) {
  std::vector<int> directions = GetRandomDirections();
  for (int direction : directions) {
    // Move 2 spaces at a time and remove wall between cells
    switch (direction) {
      case 0: // Up
        if (row - 2 > 0 && cells_[row - 2][col] == kWall) {
          cells_[row - 2][col] = kPath;
          cells_[row - 1][col] = kPath;

          path_.emplace_back(row - 1, col);
          path_.emplace_back(row - 2, col);

          RandomDFS(row - 2, col);
        }
        break;
      case 1: // Down
        if (row + 2 < height_ - 1 && cells_[row + 2][col] == kWall) {
          cells_[row + 2][col] = kPath;
          cells_[row + 1][col] = kPath;

          path_.emplace_back(row + 1, col);
          path_.emplace_back(row + 2, col);

          RandomDFS(row + 2, col);
        }
        break;
      case 2: // Left
        if (col - 2 > 0 && cells_[row][col - 2] == kWall) {
          cells_[row][col - 2] = kPath;
          cells_[row][col - 1] = kPath;

          path_.emplace_back(row, col - 1);
          path_.emplace_back(row, col - 2);

          RandomDFS(row, col - 2);
        }
        break;
      case 3: // Right
        if (col + 2 < width_ - 1 && cells_[row][col + 2] == kWall) {
          cells_[row][col + 2] = kPath;
          cells_[row][col + 1] = kPath;

          path_.emplace_back(row, col + 1);
          path_.emplace_back(row, col + 2);

          RandomDFS(row, col + 2);
        }
        break;
    }
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

std::vector<glm::vec2> MazeGenerator::GetGeneratorPath() {
  return path_;
}

std::vector<std::vector<int>> MazeGenerator::GetMazeCells() {
  return cells_;
}

glm::vec2 MazeGenerator::GetStartCell() const {
  return kStartCell;
}

glm::vec2 MazeGenerator::GetEndCell() const {
  return end_cell_;
}

int MazeGenerator::GetMazeHeight() const {
  return height_;
}

int MazeGenerator::GetMazeWidth() const {
  return width_;
}



