#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBase.h"
#include "canvas.h"
#include "core/maze_solver.h"
#include "core/driver.h"

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

  const std::vector<std::vector<size_t>> kMazeCells =
      {{1, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
       {1, 0, 1, 0, 1, 0, 0, 1, 1, 1 },
       {1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
       {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
       {1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
       {1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
       {1, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
       {0, 0, 1, 1, 1, 0, 1, 1, 1, 1 },
       {1, 1, 1, 0, 1, 1, 1, 1, 0, 0 }};

  const glm::vec2 kStartCell = {0, 0};
  const glm::vec2 kEndCell = {7, 9};

 private:
  const int kWindowWidth = 1000;
  const int kWindowHeight = 900;
  const int kXMargin = 50;
  const int kYMargin = 50;

  MazeSolver maze_solver_;
  Driver driver_;
  Canvas canvas_;

  std::string message_;
  const ci::Color kBackgroundColor = "gray";
  const ci::Color kTextColor = "black";
  const ci::Font kFont = ci::Font("Arial", 24.0f);
};

}  // namespace visualizer

}  // namespace mazesolver
