#include <core/maze_reader.h>

namespace mazesolver {

MazeReader::MazeReader() {
  cv::Mat image = cv::imread("images/20x20/maze1.png", cv::IMREAD_COLOR);
  cv::imshow("test", image);
  cv::waitKey(0);

}

void MazeReader::ReadImage() {

}

}  // namespace mazesolver