#include <visualizer/canvas.h>

namespace mazesolver {

namespace visualizer {

Canvas::Canvas(const glm::vec2& top_left_corner, float cell_size)
    : top_left_corner_(top_left_corner) {
  cell_size_ = cell_size;
}

void Canvas::DrawMaze(const std::vector<std::vector<int>>& maze_cells) {
  for (size_t i = 0; i < maze_cells.size(); i++) {
    for (size_t j = 0; j < maze_cells[i].size(); j++) {
      glm::vec2 top_left =
          top_left_corner_ + glm::vec2(j * cell_size_, i * cell_size_);
      glm::vec2 bottom_right = top_left + glm::vec2(cell_size_, cell_size_);

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
    glm::vec2 top_left = top_left_corner_ + cell_size_ * cell->location
        * glm::mat2x2(0, 1, 1, 0); // reflect on y = x line
    glm::vec2 bottom_right = top_left + glm::vec2(cell_size_, cell_size_);

    ci::Rectf square(top_left, bottom_right);
    ci::gl::drawSolidRect(square);
  }
}

}  // namespace visualizer

}  // namespace mazesolver
