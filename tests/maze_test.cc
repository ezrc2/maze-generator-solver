#include <catch2/catch.hpp>

#include <core/driver.h>

const std::vector<std::vector<size_t>> kMazeCells =
    {{0, 0, 0, 0, 0, 0, 0},
     {1, 1, 0, 1, 1, 1, 0},
     {0, 1, 0, 1, 0, 1, 0},
     {0, 1, 1, 1, 0, 1, 0},
     {0, 0, 0, 1, 0, 1, 0},
     {0, 1, 1, 1, 0, 1, 1},
     {0, 0, 0, 0, 0, 0, 0}};

const glm::vec2 kStartCell = {1, 0};
const glm::vec2 kEndCell = {5, 6};

TEST_CASE("Solution F costs") {
  std::vector<float> f_costs =
      {7.2111f, 7.4031f, 7.2452f, 7.6212f, 7.3006f, 7.2111f, 7.4049f, 8.0f,
       8.4721f, 9.1231f, 8.2613f, 7.6212f, 7.2452f, 7.4031f, 7.2111f};

  MazeSolver solver(kMazeCells, kStartCell, kEndCell);
  while (!solver.IsMazeSolved()) {
    solver.UpdateSearchLoop();
  }

  std::vector<Cell*> solution = solver.GetSolutionPath();
  REQUIRE(solution.size() == f_costs.size());

  for (size_t i = 0; i < solution.size(); i++) {
    REQUIRE(f_costs[i] == Approx(solution[i]->f_cost));
  }
}