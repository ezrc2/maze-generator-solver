#pragma once

#include "cinder/gl/gl.h"
#include "core/cell.h"

namespace mazesolver {

namespace visualizer {

/**
 * A canvas which will be displayed in the Cinder application and respond to
 * mouse events.
 */
class Canvas {
 public:
  /**
   * Creates a canvas.
   *
   * @param top_left_corner The screen coordinates of the top left corner of
   * the canvas
   * @param canvas_width The width of the canvas, measured in screen pixels
   * @param canvas_height The height of the canvas, measured in
   * screen pixels
   */
  Canvas(const glm::vec2& top_left_corner, size_t canvas_width,
         size_t canvas_height);

  void DrawMaze(const std::vector<std::vector<size_t>>& maze_cells);

  void DrawPath(const std::vector<Cell*>& path);

 private:

  glm::vec2 top_left_corner_;
  size_t canvas_width_;
  size_t canvas_height_;

  const float kCellSize = 50;
  const ci::Color kPathColor = ci::Color("blue");
  const ci::Color kBlankColor = ci::Color("white");
  const ci::Color kObstacleColor = ci::Color("black");

};

}  // namespace visualizer

}  // namespace mazesolver
