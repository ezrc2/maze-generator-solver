#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <glm/vec2.hpp>
#include <ctime>

/**
 * Generates a maze using randomized depth-first search
 */
class MazeGenerator {
 public:

  /**
   * Initializes the 2D vector of cells
   *
   * @param height The height of the maze
   * @param width The width of the maze
   */
  MazeGenerator(int height, int width);

  /**
   * Chooses a random starting point and generates the maze
   */
  void GenerateMaze();

  /**
   * @return The 2D vector representing the maze
   */
  std::vector<std::vector<int>> GetMazeCells();

  /**
   * @return The coordinates of the starting cell
   */
  glm::vec2 GetStartCell() const;

  /**
   * @return The coordinates of the end cell
   */
  glm::vec2 GetEndCell() const;

 private:

  /**
   * Randomized depth-first search
   *
   * @param row The row of the cell
   * @param col The column of the cell
   */
  void RandomDFS(int row, int col);

  /**
   * Creates a vector of length 4 that represent random directions
   * 0: up, 1: down, 2: left, 3: right
   *
   * @return The vector of random directions
   */
  std::vector<int> GetRandomDirections();

  const int kPath = 1;
  const int kWall = 0;
  const glm::vec2 kStartCell = glm::vec2(1, 0);
  glm::vec2 end_cell_;

  std::vector<std::vector<int>> cells_;
  int height_;
  int width_;

};