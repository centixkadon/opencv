
#include "precomp.hpp"

#include "config.hpp"
#include "images.hpp"

using namespace std;
using namespace cv;

void images_write(thread_list<ImageWrite> & images_in) {
  tout << "cvWrite: begin" << tendl;

  while (true) {
    ImageWrite frame = images_in.front();
    images_in.pop_front();
    if (frame.index == (size_t)-1) break;

    stringstream image_count;
    image_count << frame.index;
    string image_index = image_count.str();
    image_index = string(6 - image_index.size(), '0') + image_index;

    imwrite(FLAGS_images_write_path + "SGM" + image_index + FLAGS_images_postfix, frame.disparity);
  }

  tout << "cvWrite: end" << tendl;
  return;
}
