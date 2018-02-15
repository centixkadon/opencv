
#include "precomp.hpp"

#include "config.hpp"
#include "images.hpp"

using namespace std;
using namespace cv;

void images_process(thread_list<ImageFrame> & images_out, thread_list<ImageFrame> & images_in) {
  tout << "cvProcess: begin" << tendl;

  while (true) {
    ImageFrame frame = images_in.front();
    images_in.pop_front();
    if (frame.index == (size_t)-1) break;
    tout << "cvProcess: " << frame.index << "/" << images_in.size() << tendl;

    images_out.push_back(frame);
  }

  tout << "cvProcess: end" << tendl;
  return;
}
