#pragma once

#include <vector>
#include <algorithm>

class MazeGenerator {

 public:

  MazeGenerator(int height, int width);

  std::vector<std::vector<int>> cells_;
  int height_;
  int width_;

};