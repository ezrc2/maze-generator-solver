#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBase.h"
#include "canvas.h"
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
   * Draws the grey background and the canvas
   */
  void draw() override;

  /**
   * Updates the simulation after each frame
   */
  void update() override;

  /**
   * Responds to key presses from the user
   *
   * @param event The key that was pressed
   */
  void keyDown(ci::app::KeyEvent event) override;

 private:
  const int kWindowWidth = 1500;
  const int kWindowHeight = 950;
  const int kXMargin = 50;
  const int kYMargin = 50;

  Driver driver_;
  Canvas canvas_;

  const ci::Color kBackgroundColor = "gray";
  const ci::Color kTextColor = "black";
  const ci::Font kFont = ci::Font("Arial", 24.0f);
};

}  // namespace visualizer

}  // namespace mazesolver
