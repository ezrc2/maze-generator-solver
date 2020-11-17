#pragma once

#include <vector>

#include "cell.h"
#include <glm/glm.hpp>

class Maze {
 public:
  Maze(const std::vector<std::vector<size_t>>& maze_cells,
       const glm::vec2& start, const glm::vec2& end);

  void UpdateSearchLoop();

  std::vector<Cell> GetNeighbors(const Cell& cell);

  std::vector<Cell> GetClosedCells() const;

 private:

  std::vector<Cell> open_cells_;
  std::vector<Cell> closed_cells_;

  glm::vec2 current_location_;
};
