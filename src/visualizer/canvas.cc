#include <visualizer/canvas.h>

namespace mazesolver {

namespace visualizer {

using glm::vec2;

Canvas::Canvas(const vec2& top_left_corner, size_t canvas_width,
               size_t canvas_height)
    : top_left_corner_(top_left_corner), canvas_width_(canvas_width),
      canvas_height_(canvas_height) {}

}  // namespace visualizer

}  // namespace mazesolver
