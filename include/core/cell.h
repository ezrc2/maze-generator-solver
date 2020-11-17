#pragma once

#include <vector>

class Cell {
 public:
  Cell(size_t g_cost, size_t h_cost, const std::vector<Cell>& neighbors);

  Cell GetNextCell() const;

  size_t GetHCost() const;

  size_t GetFCost() const;

 private:

  size_t g_cost_; // Distance from start cell
  size_t h_cost_; // Distance from end cell
  std::vector<Cell> neighbors_;

};