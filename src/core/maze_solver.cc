#include <iostream>
#include "core/maze_solver.h"

MazeSolver::MazeSolver(const std::vector<std::vector<size_t>>& maze_cells,
                       const glm::vec2& start, const glm::vec2& end) {
  maze_cells_ = maze_cells;
  start_location_ = start;
  end_location_ = end;
  maze_height_ = maze_cells.size();
  maze_width_ = maze_cells[0].size();

  Cell* start_cell = new Cell;
  start_cell->location = start;
  start_cell->g_cost = 0;
  start_cell->h_cost = glm::distance(start, end);
  start_cell->f_cost = start_cell->h_cost;
  open_cells_.push_back(start_cell);
}

void MazeSolver::UpdateSearchLoop() {
  if (open_cells_.empty()) {
    is_unsolvable_ = true;
    return;
  }

  Cell* current = FindLowestFCost();

  open_cells_.erase(std::remove(open_cells_.begin(),
                                open_cells_.end(),
                                current), open_cells_.end());
  closed_cells_.push_back(current);

  if (current->location == end_location_) {
    is_maze_solved_ = true;
    TraceSolutionPath();
    return;
  }

  for (Cell* neighbor : GetNeighbors(*current)) {
    // If neighbor cell is already walked
    if (DoesContainCell(closed_cells_, *neighbor)) {
      continue;
    }
    float new_cost = current->g_cost
        + glm::distance(current->location, neighbor->location);
    if (new_cost < neighbor->g_cost
        || !DoesContainCell(open_cells_, *neighbor)) {
      neighbor->previous = current;
      if (!DoesContainCell(open_cells_, *neighbor)) {
        open_cells_.push_back(neighbor);
      }
    }
  }
}

Cell* MazeSolver::FindLowestFCost() {
  Cell* closest = open_cells_[0];
  for (Cell* cell : open_cells_) {
    if (cell->f_cost <= closest->f_cost && cell->h_cost < closest->h_cost) {
      closest = cell;
    }
  }
  return closest;
}

std::vector<Cell*> MazeSolver::GetNeighbors(const Cell& cell) {
  std::vector<Cell*> neighbors;
  for (float x = -1; x <= 1; x++) {
    for (float y = -1; y <= 1; y++) {
      if (abs(x) == abs(y)) { // No diagonals
        continue;
      }

      float row = x + cell.location.x;
      float col = y + cell.location.y;

      if (row >= 0 && row < maze_height_ && col >= 0 && col < maze_width_
          && maze_cells_[static_cast<size_t>(row)][static_cast<size_t>(col)]
              == 1) {

        Cell* neighbor = new Cell;
        neighbor->location = glm::vec2(row, col);
        neighbor->g_cost = glm::distance(neighbor->location, start_location_);
        neighbor->h_cost = glm::distance(neighbor->location, end_location_);
        neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;
        neighbors.push_back(neighbor);
      }
    }
  }
  return neighbors;
}

void MazeSolver::TraceSolutionPath() {
  if (solution_.empty()) {
    Cell* cell = closed_cells_.back();
    while (cell != nullptr) {
      solution_.push_back(cell);
      cell = cell->previous;
    }
    std::reverse(solution_.begin(), solution_.end());
  }
}

bool MazeSolver::DoesContainCell(const std::vector<Cell*>& cell_list,
                                 const Cell& to_find) {
  for (const Cell* cell : cell_list) {
    if (cell->location == to_find.location) {
      return true;
    }
  }

  return false;
}

bool MazeSolver::IsMazeSolved() {
  return is_maze_solved_;
}

bool MazeSolver::IsMazeUnsolvable() {
  return is_unsolvable_;
}

std::vector<Cell*> MazeSolver::GetClosedCells() const {
  return closed_cells_;
}

std::vector<Cell*> MazeSolver::GetSolutionPath() const {
  return solution_;
}