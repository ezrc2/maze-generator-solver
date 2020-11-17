#include <visualizer/canvas.h>

namespace mazesolver {

namespace visualizer {

Canvas::Canvas(const glm::vec2& top_left_corner, size_t canvas_width,
               size_t canvas_height)
    : top_left_corner_(top_left_corner), canvas_width_(canvas_width),
      canvas_height_(canvas_height) {}

void Canvas::DrawMaze(const std::vector<std::vector<size_t>>& maze_cells) {
  for (size_t i = 0; i < maze_cells.size(); i++) {
    for (size_t j = 0; j < maze_cells[i].size(); j++) {
      glm::vec2 top_left = top_left_corner_ + glm::vec2(0, i * kCellSize);
      glm::vec2 bottom_right = top_left + glm::vec2(kCellSize, kCellSize);
      ci::Rectf square(top_left, bottom_right);
      if (maze_cells[i][j]) {
        ci::gl::color(kObstacleColor);
      } else {
        ci::gl::color(kBlankColor);
      }
      ci::gl::drawSolidRect(square);
    }
  }
}

void Canvas::DrawPath() {

}

}  // namespace visualizer

}  // namespace mazesolver
