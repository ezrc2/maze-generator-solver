#include <catch2/catch.hpp>

#include <core/driver.h>

const std::vector<std::vector<size_t>> kMazeCells =
    {{0, 0, 0, 0, 0, 0, 0},
     {1, 1, 0, 1, 1, 1, 0},
     {0, 1, 0, 1, 0, 1, 0},
     {0, 1, 1, 1, 0, 1, 0},
     {0, 0, 0, 1, 0, 1, 0},
     {0, 1, 0, 1, 0, 1, 1},
     {0, 0, 0, 0, 0, 0, 0}};

const glm::vec2 kStartCell = {1, 0};
const glm::vec2 kEndCell = {5, 6};
const glm::vec2 kUnreachableCell = {5, 1};

TEST_CASE("Maze is solvable") {
  MazeSolver solver(kMazeCells, kStartCell, kEndCell);
  while (!solver.IsMazeSolved() && !solver.IsMazeUnsolvable()) {
    solver.UpdateSearchLoop();
  }

  REQUIRE(solver.IsMazeSolved());
  REQUIRE_FALSE(solver.IsMazeUnsolvable());
  REQUIRE(solver.GetSolutionPath().size() == 15);
}

TEST_CASE("Maze is unsolvable") {
  MazeSolver solver(kMazeCells, kStartCell, kUnreachableCell);
  while (!solver.IsMazeSolved() && !solver.IsMazeUnsolvable()) {
    solver.UpdateSearchLoop();
  }

  REQUIRE(solver.IsMazeUnsolvable());
  REQUIRE_FALSE(solver.IsMazeSolved());
}

TEST_CASE("Solution G costs") {
  std::vector<float> g_costs =
      {0.0f, 1.0f, 1.4142f, 2.23606f, 2.8284f, 3.60555f, 3.1623f, 3.0f, 4.0f,
       5.0f, 5.099f, 5.3852f, 5.831f, 6.4031f, 7.2111f};

  MazeSolver solver(kMazeCells, kStartCell, kEndCell);
  while (!solver.IsMazeSolved()) {
    solver.UpdateSearchLoop();
  }

  std::vector<Cell*> solution = solver.GetSolutionPath();
  REQUIRE(solution.size() == g_costs.size());

  for (size_t i = 0; i < solution.size(); i++) {
    REQUIRE(g_costs[i] == Approx(solution[i]->g_cost));
  }
}

TEST_CASE("Solution H costs") {
  std::vector<float> h_costs =
      {7.2111f, 6.4031f, 5.831f, 5.3852f, 4.4721f, 3.60555f, 4.2426f, 5.0f,
       4.4721f, 4.1231f, 3.1623f, 2.23607f, 1.4142f, 1.0f, 0.0f};

  MazeSolver solver(kMazeCells, kStartCell, kEndCell);
  while (!solver.IsMazeSolved()) {
    solver.UpdateSearchLoop();
  }

  std::vector<Cell*> solution = solver.GetSolutionPath();
  REQUIRE(solution.size() == h_costs.size());

  for (size_t i = 0; i < solution.size(); i++) {
    REQUIRE(h_costs[i] == Approx(solution[i]->h_cost));
  }
}

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