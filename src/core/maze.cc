#include "core/maze.h"

Maze::Maze(const std::vector<std::vector<size_t>>& maze_cells,
           const glm::vec2& start, const glm::vec2& end) {
  current_location_ = start;
  for (size_t i = 0; i < maze_cells.size(); i++) {
    for (size_t j = 0; j < maze_cells[i].size(); j++) {
      glm::vec2 location(i, j);
      float g_cost = glm::distance(location, start);
      float h_cost = glm::distance(location, end);
      Cell cell{location, g_cost, h_cost};
      open_cells_.push_back(cell);
    }
  }
}

void Maze::UpdateSearchLoop() {

}


std::vector<Cell> Maze::GetNeighbors(const Cell& cell) {
  std::vector<Cell> neighbors;
  if (cell.location.x > 0) {

  }
}

std::vector<Cell> Maze::GetClosedCells() const {
  return closed_cells_;
}

