#pragma once

#include <vector>
#include <random>
#include <algorithm>

class MazeGenerator {

 public:

  MazeGenerator(int height, int width);

  std::vector<std::vector<int>> GetMazeCells();

 private:

  std::vector<int> GetRandomDirections();

  std::vector<std::vector<int>> cells_;
  int height_;
  int width_;

};