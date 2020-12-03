#pragma once

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "maze_solver.h"

namespace mazesolver {

/**
 * Uses OpenCV to read in a picture of a maze, either through the webcam or
 * uploaded by file path.
 */
class MazeReader {
 public:

  /**
   * Uses the webcam to take a picture of a maze
   */
  void CaptureWebcamImage();

  /**
   * Uploads an image given the image's file path
   *
   * @param image_path The image's file path
   */
  void UploadImage(const std::string& image_path);

  /**
   * Converts the image into a 2D vector
   */
  void ConvertImage();

  /**
   * @return A 2D vector representing the maze
   */
  std::vector<std::vector<int>> GetMazeCells() const;

  /**
   * @return The coordinates of the starting cell
   */
  glm::vec2 GetStartCell() const;

  /**
   * @return The coordinates of the end cell
   */
  glm::vec2 GetEndCell() const;

 private:

  cv::Mat maze_image_;
  std::vector<std::vector<int>> maze_cells_;

  glm::vec2 start_cell_ = glm::vec2(1, 0);
  glm::vec2 end_cell_;

  const int kSpaceKeyCode = 32;

};

}  // namespace mazesolver
