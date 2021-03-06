#pragma once

#include <glm/vec2.hpp>

/**
 * Represents a cell in the maze
 */
struct Cell {

  glm::vec2 location;
  float g_cost; // Distance from start cell
  float h_cost; // Distance from end cell
  float f_cost; // g cost + h cost
  Cell* previous = nullptr;

};