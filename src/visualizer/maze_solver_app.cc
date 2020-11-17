#include <visualizer/maze_solver_app.h>

namespace mazesolver {

namespace visualizer {

MazeSolverApp::MazeSolverApp()
    :
      canvas_(glm::vec2(kXMargin, kYMargin), 0, 0) {
  ci::app::setWindowSize(kWindowWidth, kWindowHeight);
}

void MazeSolverApp::draw() {
  ci::gl::clear(kBackgroundColor);
}

void MazeSolverApp::update() {

}

void MazeSolverApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {

  }
}

}  // namespace visualizer

}  // namespace mazesolver
