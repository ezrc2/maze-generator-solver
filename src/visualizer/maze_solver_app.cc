#include <visualizer/maze_solver_app.h>

namespace mazesolver {

namespace visualizer {

MazeSolverApp::MazeSolverApp()
    : maze_generator_(kMazeHeight, kMazeWidth), maze_solver_(),
      canvas_(glm::vec2(kXMargin, kYMargin), kCellSize) {

  maze_generator_.GenerateMaze();
  maze_cells_ = maze_generator_.GetMazeCells();
  maze_solver_.Initialize(maze_cells_,
                          maze_generator_.GetStartCell(),
                          maze_generator_.GetEndCell());

  window_width_ =
      static_cast<int>(maze_cells_[0].size() * kCellSize) + kXMargin * 2;
  int window_height =
      static_cast<int>(maze_cells_.size() * kCellSize) + kYMargin * 2;
  ci::app::setWindowSize(window_width_, window_height);
}

void MazeSolverApp::draw() {
  ci::gl::clear(kBackgroundColor);
  ci::gl::drawStringCentered(message_,
                             glm::vec2(window_width_ / 2, kYMargin / 3),
                             kTextColor,
                             kFont);

  if (generator_index_ < maze_generator_.GetGeneratorPath().size()) {
    canvas_.DrawGeneratorPath(maze_generator_.GetGeneratorPath(),
                              generator_index_,
                              maze_generator_.GetMazeHeight(),
                              maze_generator_.GetMazeWidth());
  } else {
    canvas_.DrawMaze(maze_cells_);
    if (maze_solver_.IsMazeSolved()) {
      canvas_.DrawSolverPath(maze_solver_.GetSolutionPath());
    } else {
      canvas_.DrawSolverPath(maze_solver_.GetClosedCells());
    }
  }
}

void MazeSolverApp::update() {
  if (generator_index_ < maze_generator_.GetGeneratorPath().size()) {
    message_ = "Generating maze...";
    generator_index_++;
  } else {
    if (!maze_solver_.IsMazeSolved() && !maze_solver_.IsMazeUnsolvable()) {
      maze_solver_.UpdateSearchLoop();
      message_ = "Solving maze...";
    } else if (maze_solver_.IsMazeSolved()) {
      message_ = "Maze solved";
    } else {
      message_ = "Maze is unsolvable";
    }
  }
}

}  // namespace visualizer

}  // namespace mazesolver
