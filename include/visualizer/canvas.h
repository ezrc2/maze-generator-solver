#pragma once

#include "cinder/gl/gl.h"
#include "core/cell.h"

namespace mazesolver {

namespace visualizer {

/**
 * A canvas which will be displayed in the Cinder application
 */
class Canvas {
 public:
  /**
   * Creates a canvas.
   *
   * @param top_left_corner The screen coordinates of the top left corner of
   * the canvas
   * @param cell_size The size of each cell, in pixels
   */
  Canvas(const glm::vec2& top_left_corner, float cell_size);

  /**
   * Draws a square for every cell of the maze. A white cell is walkable, while
   * a black cell is an obstacle/wall
   *
   * @param maze_cells The maze, represented by 0s and 1s
   */
  void DrawMaze(const std::vector<std::vector<int>>& maze_cells);

  /**
   * Draws a square for each cell in the solution path
   *
   * @param path The vector of cells
   */
  void DrawSolverPath(const std::vector<Cell*>& path);

  /**
   * Shows how the maze is generated
   *
   * @param path The path of the generating process
   * @param count The number of cells in the path to draw
   * @param height The height of the maze
   * @param width The width of the maze
   */
  void DrawGeneratorPath(const std::vector<glm::vec2>& path, size_t count,
                         size_t height, size_t width);

 private:

  glm::vec2 top_left_corner_;
  float cell_size_;
  const ci::Color kSearchColor = ci::Color("blue");
  const ci::Color kPathColor = ci::Color("white");
  const ci::Color kWallColor = ci::Color("black");

};

}  // namespace visualizer

}  // namespace mazesolver
