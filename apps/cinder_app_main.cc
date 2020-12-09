#include <visualizer/maze_solver_app.h>

using mazesolver::visualizer::MazeSolverApp;

void prepareSettings(MazeSolverApp::Settings* settings) {
  settings->setResizable(false);
  settings->setWindowPos(500, 100);
  srand(static_cast<unsigned int>(time(nullptr)));
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(MazeSolverApp, ci::app::RendererGl, prepareSettings);
