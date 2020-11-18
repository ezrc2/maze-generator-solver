#pragma once

#include <vector>
#include <glm/vec2.hpp>

struct Cell {

  glm::vec2 location;
  float g_cost; // Distance from start cell
  float h_cost; // Distance from end cell
  float f_cost;
  Cell* previous;

};