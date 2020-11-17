#pragma once

#include <vector>

#include "cell.h"
#include <glm/glm.hpp>

class MazeSolver {
 public:
  MazeSolver(const std::vector<std::vector<size_t>>& maze_cells,
       const glm::vec2& start, const glm::vec2& end);

  void UpdateSearchLoop();

  bool IsMazeSolved();

  bool IsMazeUnsolvable();

  std::vector<Cell> GetClosedCells() const;

 private:

  std::vector<Cell> GetNeighbors(const Cell& cell);

  bool is_maze_solved_ = false;
  bool is_unsolvable_ = false;
  size_t maze_width_;
  size_t maze_height_;

  std::vector<std::vector<size_t>> maze_cells_;
  std::vector<Cell> open_cells_;
  std::vector<Cell> closed_cells_;

  Cell current_cell_;
  glm::vec2 start_location_;
  glm::vec2 end_location_;
};
