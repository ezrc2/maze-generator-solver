#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <cmath>

#include "cell.h"

class MazeSolver {
 public:
  MazeSolver(const std::vector<std::vector<size_t>>& maze_cells,
       const glm::vec2& start, const glm::vec2& end);

  void UpdateSearchLoop();

  std::vector<Cell> GetClosedCells() const;

  std::vector<Cell> GetSolutionPath() const;

  bool IsMazeSolved();

  bool IsMazeUnsolvable();

 private:

  Cell FindLowestFCost();

  std::vector<Cell> GetNeighbors(const Cell& cell);

  bool DoesContainCell(const std::vector<Cell>& cell_list, const Cell& to_find);

  bool is_maze_solved_ = false;
  bool is_unsolvable_ = false;
  size_t maze_width_;
  size_t maze_height_;

  std::vector<std::vector<size_t>> maze_cells_;
  std::vector<Cell> open_cells_;
  std::vector<Cell> closed_cells_;
  std::vector<Cell> solution_;

  Cell current_cell_;
  glm::vec2 start_location_;
  glm::vec2 end_location_;
};
