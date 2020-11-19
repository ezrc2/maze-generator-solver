#include <visualizer/maze_solver_app.h>

namespace mazesolver {

namespace visualizer {

MazeSolverApp::MazeSolverApp()
    : driver_(), maze_solver_(kMazeCells, kStartCell, kEndCell),
      canvas_(glm::vec2(kXMargin, kYMargin), 0, 0) {
  ci::app::setWindowSize(kWindowWidth, kWindowHeight);
}

void MazeSolverApp::draw() {
  ci::gl::clear(kBackgroundColor);
  ci::gl::drawStringCentered(message_,
                             glm::vec2(kWindowWidth / 2, kXMargin / 3),
                             kTextColor,
                             kFont);
  canvas_.DrawMaze(kMazeCells);

  if (maze_solver_.IsMazeSolved()) {
    setFrameRate(40);
    canvas_.DrawPath(maze_solver_.GetSolutionPath());
  } else {
    canvas_.DrawPath(maze_solver_.GetClosedCells());
  }
}

void MazeSolverApp::update() {
  if (!maze_solver_.IsMazeSolved() && !maze_solver_.IsMazeUnsolvable()) {
    maze_solver_.UpdateSearchLoop();
    message_ = "Solving maze...";
  } else if (maze_solver_.IsMazeSolved()) {
    message_ = "Maze solved";
  } else {
    message_ = "Maze is unsolvable";
  }
}

}  // namespace visualizer

}  // namespace mazesolver
