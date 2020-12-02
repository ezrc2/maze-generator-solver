#pragma once

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "maze_solver.h"

namespace mazesolver {

class MazeReader {
 public:

  MazeReader();

  std::vector<std::vector<int>> GetMazeCells() const;

  glm::vec2 GetStartCell() const;

  glm::vec2 GetEndCell() const;

 private:

  std::vector<std::vector<int>> maze_cells_;

  glm::vec2 start_cell_ = glm::vec2(1, 0);
  glm::vec2 end_cell_ = glm::vec2(19, 20);

  const int kSpaceKeyCode = 32;

};

}  // namespace mazesolver
