#include "core/maze_solver.h"

MazeSolver::MazeSolver(const std::vector<std::vector<size_t>>& maze_cells,
                       const glm::vec2& start, const glm::vec2& end) {
  maze_cells_ = maze_cells;
  start_location_ = start;
  end_location_ = end;
  maze_width_ = maze_cells.size();
  maze_height_ = maze_cells[0].size();

  float g_cost = 0;
  float h_cost = glm::distance(start, end);
  Cell current{start, g_cost, h_cost};
  current_cell_ = current;
}

void MazeSolver::UpdateSearchLoop() {
  if (current_cell_.location == end_location_) {
    is_maze_solved_ = true;
    return;
  }

  for (const Cell& cell : GetNeighbors(current_cell_)) {
    // Doesn't contain
    if (std::find(open_cells_.begin(), open_cells_.end(), cell) == open_cells_.end()) {
      open_cells_.push_back(cell);
    }
  }
}

bool MazeSolver::IsMazeSolved() {
  return is_maze_solved_;
}

std::vector<Cell> MazeSolver::GetNeighbors(const Cell& cell) {
  std::vector<Cell> neighbors;
  for (float x = -1; x <= 1; x++) {
    for (float y = -1; y <= 1; y++) {
      if (x == 0 && y == 0) {
        continue;
      }

      float neighbor_x = x + cell.location.x;
      float neighbor_y = y + cell.location.y;

      if (neighbor_x >= 0 && neighbor_x < maze_width_ && neighbor_y >= 0
          && neighbor_y < maze_height_
          && maze_cells_[neighbor_x][neighbor_y] == 1) {

        glm::vec2 location(neighbor_x, neighbor_y);
        float g_cost = glm::distance(location, start_location_);
        float h_cost = glm::distance(location, end_location_);

        Cell neighbor_cell{location, g_cost, h_cost};
        neighbors.push_back(neighbor_cell);
      }
    }
  }
  return neighbors;
}

std::vector<Cell> MazeSolver::GetClosedCells() const {
  return closed_cells_;
}