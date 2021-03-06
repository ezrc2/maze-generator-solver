# Maze Generator and Solver

Uses a recursive implementation of randomized depth-first search to generate and A* search algorithm to solve.

<img src="https://github.com/ezrc2/maze-generator-solver/blob/main/maze-demo.gif" width="500" height="500" />

## Installation

For Windows, you will  need to install [MS Build Tools](https://my.visualstudio.com/Downloads?q=visual%20studio%202015&wt.mc_id=o~msft~vscom~older-downloads) (Visual Studio Community 2015 Update 3) with Common Tools for Visual C++ 2015. If using [CLion](https://www.jetbrains.com/clion/download/#section=windows), go to Settings > Build, Execution, Deployment > Toolchains and select Visual Studio 14.0 as the environment.

## Libraries

[Cinder (v0.9.2)](https://libcinder.org/download)

[Catch2](https://github.com/catchorg/Catch2)

**Setup**

1. Open the ~/Cinder folder in your IDE and run the program to build it (only needs to be done once). 

2. Create a folder called "my-projects" in the ~/Cinder folder.

3. Download this repository into "my-projects" and open the program.

## How to Use

Run the program to show the maze generation and solving process. You can adjust the height and width parameters in the maze_solver_app header file.

## References

[A* Search Algorithm](https://www.geeksforgeeks.org/a-search-algorithm/)

[Maze Generation Algorithms](https://en.wikipedia.org/wiki/Maze_generation_algorithm)
