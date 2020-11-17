#include "core/maze_solver.h"

MazeSolver::MazeSolver(const std::vector<std::vector<size_t>>& maze_cells,
                       const glm::vec2& start, const glm::vec2& end) {
  maze_cells_ = maze_cells;
  start_location_ = start;
  end_location_ = end;
  maze_width_ = maze_cells.size();
  maze_height_ = maze_cells[0].size();
  current_cell_ = {start, 0, glm::distance(start, end)};
  open_cells_.push_back(current_cell_);
}

void MazeSolver::UpdateSearchLoop() {
  Cell lowest_f_cost = open_cells_[0];
  for (const Cell& cell : open_cells_) {
    if (cell.f_cost < lowest_f_cost.f_cost) {
      lowest_f_cost = cell;
    }
  }
  current_cell_ = lowest_f_cost;
  closed_cells_.push_back(current_cell_);

  if (open_cells_.empty()) {
    is_unsolvable_ = true;
    return;
  }

  if (current_cell_.location == end_location_) {
    is_maze_solved_ = true;
    return;
  }

  for (size_t i = 0; i < open_cells_.size(); i++) {
    if (&open_cells_[i] == &current_cell_) {
      open_cells_.erase(open_cells_.begin() + i);
      break;
    }
  }
  closed_cells_.push_back(current_cell_);

  for (const Cell& cell : GetNeighbors(current_cell_)) {
    // If neighbor cell is already walked
    if (std::find(closed_cells_.begin(), closed_cells_.end(), cell)
        != closed_cells_.end()) {
      continue;
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