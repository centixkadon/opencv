
#pragma once

#include <opencv2/opencv.hpp>

#include "thread/list"

struct ImageRead {
  size_t index;
  cv::Mat left, right, groundtruth;
};
struct ImageWrite {
  size_t index;
  cv::Mat disparity, groundtruth;
};

void images_read(std::thread_list<ImageRead> & images_out);
void images_process(std::thread_list<ImageWrite> & images_out, std::thread_list<ImageRead> & images_in);
void images_write(std::thread_list<ImageWrite> & images_in);
