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
      glm::vec2 top_left = top_left_corner_ + glm::vec2(j * kCellSize, i * kCellSize);
      glm::vec2 bottom_right = top_left + glm::vec2(kCellSize, kCellSize);
      ci::Rectf square(top_left, bottom_right);
      if (maze_cells[i][j]) {
        ci::gl::color(kBlankColor);
      } else {
        ci::gl::color(kObstacleColor);
      }
      ci::gl::drawSolidRect(square);
    }
  }
}

void Canvas::DrawPath(const std::vector<Cell*>& path) {
  ci::gl::color(kPathColor);
  for (const Cell* cell : path) {
    glm::vec2 top_left = top_left_corner_ + kCellSize * cell->location * glm::mat2x2(0, 1, 1, 0);
    glm::vec2 bottom_right = top_left + glm::vec2(kCellSize, kCellSize);
    ci::Rectf square(top_left, bottom_right);
    ci::gl::drawSolidRect(square);
    //ci::gl::color(ci::Color("red"));
    //ci::gl::drawStringCentered(std::to_string(cell.f_cost),top_left + glm::vec2(25, 25));
  }
}

}  // namespace visualizer

}  // namespace mazesolver
