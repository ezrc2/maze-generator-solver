#include <core/maze_reader.h>

namespace mazesolver {

MazeReader::MazeReader() {
  cv::VideoCapture camera(0);
  if (!camera.isOpened()) {
    throw std::exception("Cannot open camera");
  }

  cv::Mat frame;
  while (camera.read(frame)) {
    cv::flip(frame, frame, 1);
    cv::imshow("Camera", frame);
    if (cv::waitKey(1) == kSpaceKeyCode) {
      camera >> frame;
      break;
    }
  }


  cv::Mat image = cv::imread("images/20x20/maze1.png");
  if (!image.data) {
    throw std::exception("Empty image");
  }

  cv::Mat grayscale;
  cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);

  cv::Mat binary(grayscale.size(), grayscale.type());
  cv::threshold(grayscale, binary, 100, 255, cv::THRESH_BINARY);

  int cell_pixels = 10;
  for (int i = 0; i < binary.rows; i += cell_pixels) {
    std::vector<int> row_cells;
    for (int j = 0; j < binary.cols; j += cell_pixels) {
      int cell = static_cast<int>(binary.at<uchar>(i, j));
      row_cells.push_back(cell == 0 ? 0 : 1);
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