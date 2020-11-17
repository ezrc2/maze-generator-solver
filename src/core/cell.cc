#include <core/cell.h>

Cell::Cell(size_t g_cost, size_t h_cost, const std::vector<Cell>& neighbors) {
  g_cost_ = g_cost;
  h_cost_ = h_cost;
  neighbors_ = neighbors;
}

Cell Cell::GetNextCell() const {
  Cell next = neighbors_[0];
  for (const Cell& cell : neighbors_) {
    if (cell.GetFCost() < GetFCost()) {
      next = cell;
    }
  }
  return next;
}

size_t Cell::GetHCost() const {
  return h_cost_;
}

size_t Cell::GetFCost() const {
  return g_cost_ + h_cost_;
}

