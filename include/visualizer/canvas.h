#pragma once

#include "cinder/gl/gl.h"

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

 private:

  glm::vec2 top_left_corner_;
  size_t canvas_width_;
  size_t canvas_height_;

  const ci::Color kCanvasColor = "black";
  const ci::Color kTextColor = "black";
  const ci::Font kTextFont = ci::Font("Arial", 24.0f);
  const ci::Font kTitleFont = ci::Font("Arial", 28.0f);

};

}  // namespace visualizer

}  // namespace mazesolver
