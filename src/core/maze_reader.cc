#include <core/maze_reader.h>

namespace mazesolver {

MazeReader::MazeReader() {
  cv::Mat image = cv::imread("images/20x20/maze1.png");
  if (!image.data) {
    throw std::exception("Empty image");
  }

  cv::Mat grayscale;
  cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);

  cv::Mat binary(grayscale.size(), grayscale.type());
  cv::threshold(grayscale, binary, 128, 255, cv::THRESH_BINARY);

  cv::namedWindow("test", cv::WINDOW_AUTOSIZE);
  cv::imshow("test", binary);
  cv::waitKey(0);

  std::vector<std::vector<cv::Point>> contours;
  cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
  if (contours.size() != 2) {
    throw std::exception("Maze should have two openings");
  }

  for (int i = 0; i < binary.rows; i++) {
    std::vector<int> row_cells;
    row_cells.reserve(binary.cols);
    for (int j = 0; j < binary.cols; j++) {
      row_cells.push_back(static_cast<int>(binary.at<float>(i, j)));
    }
    maze_cells_.push_back(row_cells);
  }

}

std::vector<std::vector<int>> MazeReader::GetMazeCells() const {
  return maze_cells_;
}

glm::vec2 MazeReader::GetStartCell() const {
  return start_cell_;
}

glm::vec2 MazeReader::GetEndCell() const {
  return end_cell_;
}

}  // namespace mazesolver