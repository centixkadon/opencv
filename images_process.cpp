
#include "precomp.hpp"

#include "config.hpp"
#include "images.hpp"

using namespace std;
using namespace cv;

void images_process(thread_list<ImageWrite> & images_out, thread_list<ImageRead> & images_in) {
  tout << "cvProcess: begin" << tendl;

  size_t const m = FLAGS_images_size_height, n = FLAGS_images_size_width;
  while (true) {
    ImageRead frame = images_in.front();
    images_in.pop_front();
    if (frame.index == (size_t)-1) break;
    tout << "cvProcess: " << frame.index << "/" << images_in.size() << tendl;

    pixel_t * l = new pixel_t[m * n];
    pixel_t * r = new pixel_t[m * n];
    for (size_t i = 0; i < m; ++i)
      for (size_t j = 0; j < n; ++j) {
        l[i * n + j] = frame.left.at<uint8_t>(i, j);
        r[i * n + j] = frame.right.at<uint8_t>(i, j);
      }

    pixel_t * d = new pixel_t[m * n];
    // Computation

    // Mat disparity(m, n, CV_8UC1, d);
    delete[] l, r, d;

    // Evaluation

    images_out.push_back(ImageWrite{frame.index, frame.groundtruth, frame.groundtruth});
  }

  images_out.push_back(ImageWrite{(size_t)-1});
  tout << "cvProcess: end" << tendl;
  return;
}
