
#include "precomp.hpp"

#include "config.hpp"
#include "images.hpp"

using namespace std;
using namespace cv;

int main(int argc, char ** argv) {
  cout << "cvMain: Hello OpenCV" << endl;

  config_init(argc, argv);

  thread_list<ImageRead> image_reads;
  thread_list<ImageWrite> images_writes;
  thread th_images_read(images_read, ref(image_reads));
  thread th_images_process(images_process, ref(images_writes), ref(image_reads));
  thread th_images_write(images_write, ref(images_writes));

  th_images_read.join();
  th_images_process.join();
  th_images_write.join();

  return 0;
}
