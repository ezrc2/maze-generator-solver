#include <core/maze_reader.h>

namespace mazesolver {

MazeReader::MazeReader() {
  cv::Mat image = cv::imread("images/20x20/maze1.png");
  if (!image.data) {
    throw std::exception("no image");
  }

  cv::Mat grayscale;
  cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);

  cv::Mat binary(grayscale.size(), grayscale.type());
  cv::threshold(grayscale, binary, 100, 255, cv::THRESH_BINARY);

  cv::namedWindow("Output", cv::WINDOW_AUTOSIZE);
  cv::imshow("Output", binary);

  cv::waitKey(0);
}

}  // namespace mazesolver