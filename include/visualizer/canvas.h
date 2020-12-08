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
   * Draws a square for each cell in the path
   *
   * @param path The vector of cells
   */
  void DrawPath(const std::vector<Cell*>& path);

 private:

  glm::vec2 top_left_corner_;
  float cell_size_;
  const ci::Color kPathColor = ci::Color("blue");
  const ci::Color kBlankColor = ci::Color("white");
  const ci::Color kObstacleColor = ci::Color("black");

};

}  // namespace visualizer

}  // namespace mazesolver
