#include <visualizer/maze_solver_app.h>

namespace mazesolver {

namespace visualizer {

MazeSolverApp::MazeSolverApp()
    : maze_reader_(), maze_solver_(), canvas_(glm::vec2(kXMargin, kYMargin)) {

  maze_reader_.UploadImage("images/20x20/maze1.png");
  maze_reader_.ConvertImage();

  maze_cells_ = maze_reader_.GetMazeCells();
  maze_solver_.Initialize(maze_cells_,
                          maze_reader_.GetStartCell(),
                          maze_reader_.GetEndCell());

  window_width_ = static_cast<int>(maze_cells_.size()) * 10 + kXMargin * 2;
  int window_height = static_cast<int>(maze_cells_.size()) * 10 + kYMargin * 2;
  ci::app::setWindowSize(window_width_, window_height);
}

void MazeSolverApp::draw() {
  ci::gl::clear(kBackgroundColor);
  ci::gl::drawStringCentered(message_,
                             glm::vec2(window_width_ / 2, kYMargin / 3),
                             kTextColor,
                             kFont);
  canvas_.DrawMaze(maze_reader_.GetMazeCells());

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
