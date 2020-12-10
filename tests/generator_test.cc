#pragma once

#include <catch2/catch.hpp>

#include "core/maze_generator.h"

TEST_CASE("Dimensions are odd") {
  MazeGenerator generator(20, 18);

  REQUIRE(generator.GetMazeHeight() == 21);
  REQUIRE(generator.GetMazeWidth() == 19);
}

TEST_CASE("Start and end cells are paths") {
  MazeGenerator generator(11, 11);
  generator.GenerateMaze();
  std::vector<std::vector<int>> cells = generator.GetMazeCells();

  REQUIRE(cells[1][0] == 1);
  REQUIRE(cells[9][10] == 1);
}

TEST_CASE("Borders are walls") {
  MazeGenerator generator(11, 11);
  generator.GenerateMaze();
  std::vector<std::vector<int>> cells = generator.GetMazeCells();

  for (size_t i = 0; i < cells[0].size(); i++) {
    REQUIRE(cells[0][i] == 0);
    REQUIRE(cells[cells.size() - 1][i] == 0);
  }

  for (size_t i = 0; i < cells.size(); i++) {
    if (i == 1) {
      continue;
    }
    REQUIRE(cells[i][0] == 0);
  }

  for (size_t i = 0; i < cells.size(); i++) {
    if (i == cells.size() - 2) {
      continue;
    }
    REQUIRE(cells[i][cells.size() - 1] == 0);
  }
}