
#include "precomp.hpp"

#include "config.hpp"
#include "images.hpp"

using namespace std;
using namespace cv;

void images_read(thread_list<ImageFrame> & images_out) {
  tout << "cvRead: begin" << tendl;

  string images_path = FLAGS_cv_images_root + FLAGS_cv_images_group;
  string images_l = FLAGS_cv_images_prefix_left;
  string images_r = FLAGS_cv_images_prefix_right;
  string images_gt = FLAGS_cv_images_prefix_groundtruth;
  string images_format = FLAGS_cv_images_postfix;
  for (size_t i = 0; i < (size_t)-1; ++i) {
    stringstream image_count;
    image_count << i;
    string image_i = image_count.str();
    image_i = string(6 - image_i.size(), '0') + image_i;
    Mat l = imread(images_path + images_l + image_i + images_format);
    Mat r = imread(images_path + images_r + image_i + images_format);
    Mat gt = imread(images_path + images_gt + image_i + images_format);
    // if (l.empty() || r.empty() || gt.empty()) break;
    tout << "cvRead: " << images_path << image_i << tendl;

    images_out.push_back(ImageFrame{i, l, r, gt});
  }

  images_out.push_back(ImageFrame{(size_t)-1});

  tout << "cvRead: end" << tendl;
  return;
}
