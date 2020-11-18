#include <iostream>
#include "core/maze_solver.h"

MazeSolver::MazeSolver(const std::vector<std::vector<size_t>>& maze_cells,
                       const glm::vec2& start, const glm::vec2& end) {
  maze_cells_ = maze_cells;
  start_location_ = start;
  end_location_ = end;
  maze_height_ = maze_cells.size();
  maze_width_ = maze_cells[0].size();

  current_cell_.location = start;
  current_cell_.g_cost = 0;
  current_cell_.h_cost = glm::distance(start, end);
  current_cell_.f_cost = current_cell_.h_cost;
  open_cells_.push_back(current_cell_);
}

void MazeSolver::UpdateSearchLoop() {
  if (open_cells_.empty()) {
    is_unsolvable_ = true;
    return;
  }

  current_cell_ = FindLowestFCost();

  // Remove from open and move to closed
  for (size_t i = 0; i < open_cells_.size(); i++) {
    if (open_cells_[i].location == current_cell_.location) {
      open_cells_.erase(open_cells_.begin() + i);
      break;
    }
  }
  closed_cells_.push_back(current_cell_);

  if (current_cell_.location == end_location_) {
    is_maze_solved_ = true;
    if (solution_.empty()) {
      Cell cell = closed_cells_.back();
      while (cell.previous->location != start_location_) {
        solution_.push_back(cell);
        cell.location = cell.previous->location;
        cell.g_cost = cell.previous->g_cost;
        cell.h_cost = cell.previous->h_cost;
        cell.f_cost = cell.previous->f_cost;
        cell.previous = cell.previous->previous;
      }
    }
    return;
  }

  for (Cell& neighbor : GetNeighbors(current_cell_)) {
    // If neighbor cell is already walked
    if (DoesContainCell(closed_cells_, neighbor)) {
      continue;
    }
    float new_cost = current_cell_.g_cost
        + glm::distance(current_cell_.location, neighbor.location);
    if (new_cost < neighbor.f_cost) {
      neighbor.f_cost = new_cost;
      neighbor.previous = &current_cell_;
    }
    if (!DoesContainCell(open_cells_, neighbor)) {
      open_cells_.push_back(neighbor);
    }
  }
}

Cell MazeSolver::FindLowestFCost() {
  Cell closest = open_cells_[0];
  for (const Cell& cell : open_cells_) {
    if (cell.f_cost <= closest.f_cost) {
      closest = cell;
    }
  }
  return closest;
}

std::vector<Cell> MazeSolver::GetNeighbors(const Cell& cell) {
  std::vector<Cell> neighbors;
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

        Cell next;
        next.location = glm::vec2(row, col);
        next.g_cost = glm::distance(next.location, start_location_);
        next.h_cost = glm::distance(next.location, end_location_);
        next.f_cost = next.g_cost + next.h_cost;
        neighbors.push_back(next);
      }
    }
  }
  return neighbors;
}

bool MazeSolver::DoesContainCell(const std::vector<Cell>& cell_list,
                                 const Cell& to_find) {
  for (const Cell& cell : cell_list) {
    if (cell.location == to_find.location) {
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

std::vector<Cell> MazeSolver::GetClosedCells() const {
  return closed_cells_;
}

std::vector<Cell> MazeSolver::GetSolutionPath() const {
  return solution_;
}


