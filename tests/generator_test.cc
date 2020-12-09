#pragma once

#include <catch2/catch.hpp>

#include "core/maze_generator.h"

TEST_CASE("Dimensions are odd") {
  MazeGenerator generator(20, 18);

  REQUIRE(generator.GetMazeHeight() == 21);
  REQUIRE(generator.GetMazeWidth() == 19);
}