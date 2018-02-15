
#pragma once

#include <opencv2/opencv.hpp>

#include "thread/list"

struct ImageFrame {
  size_t index;
  cv::Mat left, right, groundtruth;
};

void images_read(std::thread_list<ImageFrame> & images_out);
void images_process(std::thread_list<ImageFrame> & images_out, std::thread_list<ImageFrame> & images_in);
void images_write(std::thread_list<ImageFrame> & images_in);
