#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <cmath>
#include <algorithm>

#include "cell.h"

/**
 * Finds the solution path of a maze
 */
class MazeSolver {
 public:

  /**
   * Initializes a MazeSolver object and adds the starting cell to vector of
   * open cells
   *
   * @param maze_cells The maze, represented with 0s and 1s
   * @param start The starting cell's location
   * @param end The end cell's location
   */
  void Initialize(const std::vector<std::vector<int>>& maze_cells,
                  const glm::vec2& start, const glm::vec2& end);

  /**
   * Updates the search loop once and checks if the maze is solved or unsolvable
   */
  void UpdateSearchLoop();

  /**
   * @return true if the maze is solved, otherwise false
   */
  bool IsMazeSolved();

  /**
   * @return true if there is no solution the maze, otherwise false
   */
  bool IsMazeUnsolvable();

  /**
   * @return The vector of closed cells
   */
  std::vector<Cell*> GetClosedCells() const;

  /**
   * @return The vector of cells for the solution to the maze
   */
  std::vector<Cell*> GetSolutionPath() const;

 private:

  /**
   * @return A pointer to the cell with the lowest f cost that hasn't been
   * visited yet
   */
  Cell* FindLowestFCost();

  /**
   * Finds the walkable cells that are adjacent to the input cell
   *
   * @param cell The input cell
   * @return A vector of the neighbors to the cell
   */
  std::vector<Cell*> GetNeighbors(const Cell& cell);

  /**
   * Iterates through the closed cells backwards by calling each cell's previous
   * cell, appending cells into the solution vector. Then, reverses the vector
   * to become a forwards path
   */
  void TraceSolutionPath();

  /**
   * Checks if the vector contains a cell
   *
   * @param cell_list The vector of cells
   * @param to_find The cell to check
   * @return true if the vector contains the target cell, otherwise false
   */
  bool DoesContainCell(const std::vector<Cell*>& cell_list,
                       const Cell& to_find);

  bool is_maze_solved_ = false;
  bool is_unsolvable_ = false;
  size_t maze_width_;
  size_t maze_height_;

  std::vector<std::vector<int>> maze_cells_;
  std::vector<Cell*> open_cells_;
  std::vector<Cell*> closed_cells_;
  std::vector<Cell*> solution_;

  glm::vec2 start_location_;
  glm::vec2 end_location_;
};
