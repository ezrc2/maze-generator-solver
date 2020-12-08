#include <core/maze_reader.h>

namespace mazesolver {

void MazeReader::CaptureWebcamImage() {
  cv::VideoCapture camera(0);
  if (!camera.isOpened()) {
    throw std::exception("Cannot open camera");
  }

  cv::Mat frame;
  while (camera.read(frame)) {
    cv::putText(frame, "Press space key to capture", cv::Point(5, 20),
                cv::FONT_HERSHEY_PLAIN, 1.0, kGreen);
    cv::imshow("Camera", frame);

    if (cv::waitKey(1) == kSpaceKeyCode) {
      maze_image_ = frame;
      break;
    }
  }
}

void MazeReader::UploadImage(const std::string& image_path) {
  cv::Mat image = cv::imread(image_path);
  if (!image.data) {
    throw std::exception("Empty image");
  }
  maze_image_ = image;
}

void MazeReader::ConvertImage() {
  cv::Mat grayscale;
  cv::cvtColor(maze_image_, grayscale, cv::COLOR_BGR2GRAY);

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
  end_cell_ = glm::vec2(maze_cells_.size() - 2, maze_cells_[0].size() - 1);
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