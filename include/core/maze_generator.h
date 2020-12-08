#pragma once

#include <vector>
#include <random>
#include <algorithm>

class MazeGenerator {

 public:

  MazeGenerator(int height, int width);

  void GenerateMaze();

  std::vector<std::vector<int>> GetMazeCells();

 private:

  void RandomDFS(int row, int col);

  std::vector<int> GetRandomDirections();

  std::vector<std::vector<int>> cells_;
  int height_;
  int width_;

};