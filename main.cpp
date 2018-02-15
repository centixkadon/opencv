
#include "precomp.hpp"

#include "config.hpp"
#include "images.hpp"

using namespace std;
using namespace cv;

int main(int argc, char ** argv) {
  cout << "cvMain: Hello OpenCV" << endl;

  config_init(argc, argv);

  thread_list<ImageFrame> images_pipe1, images_pipe2;
  thread th_images_read(images_read, ref(images_pipe1));
  thread th_images_process(images_process, ref(images_pipe2), ref(images_pipe1));

  th_images_read.join();
  th_images_process.join();

  return 0;
}
