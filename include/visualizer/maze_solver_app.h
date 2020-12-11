#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBase.h"
#include "canvas.h"
#include "core/maze_solver.h"
#include "core/maze_generator.h"

namespace mazesolver {

namespace visualizer {

/**
 * Displays the maze solver and responds to key presses from the user
 */
class MazeSolverApp : public ci::app::App {
 public:
  MazeSolverApp();

  /**
   * Draws the grey background and the maze canvas
   */
  void draw() override;

  /**
   * Updates the solver after each frame
   */
  void update() override;

  const int kMazeHeight = 25;
  const int kMazeWidth = 25;

 private:

  int window_width_;
  const int kXMargin = 50;
  const int kYMargin = 50;
  const float kCellSize = 20;

  MazeGenerator maze_generator_;
  MazeSolver maze_solver_;
  std::vector<std::vector<int>> maze_cells_;
  Canvas canvas_;

  size_t generator_index_ = 0;

  std::string message_;
  const ci::Color kBackgroundColor = "gray";
  const ci::Color kTextColor = "black";
  const ci::Font kFont = ci::Font("Arial", 24.0f);

};

}  // namespace visualizer

}  // namespace mazesolver
