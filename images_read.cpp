
#include "precomp.hpp"

#include "config.hpp"
#include "images.hpp"

using namespace std;
using namespace cv;

void images_read(thread_list<ImageRead> & images_out) {
  tout << "cvRead: begin" << tendl;

  string images_path = FLAGS_images_root + FLAGS_images_group;
  string images_l = FLAGS_images_prefix_left;
  string images_r = FLAGS_images_prefix_right;
  string images_gt = FLAGS_images_prefix_groundtruth;
  string images_format = FLAGS_images_postfix;
  size_t const m = FLAGS_images_size_height, n = FLAGS_images_size_width;
  for (size_t index = FLAGS_images_index_begin;
       index < FLAGS_images_index_end;
       index += FLAGS_images_index_step) {
    stringstream image_count;
    image_count << index;
    string image_index = image_count.str();
    image_index = string(6 - image_index.size(), '0') + image_index;
    Mat l = imread(images_path + images_l + image_index + images_format);
    Mat r = imread(images_path + images_r + image_index + images_format);
    Mat gt = imread(images_path + images_gt + image_index + images_format);
    if (l.empty() || r.empty() || gt.empty()) break;
    if ((l.rows < m) || (r.rows < m) || (gt.rows < m)) break;
    if ((l.cols < n) || (r.cols < n) || (gt.cols < n)) break;

    cvtColor(l, l, CV_RGB2GRAY);
    cvtColor(r, r, CV_RGB2GRAY);
    cvtColor(gt, gt, CV_RGB2GRAY);

    images_out.push_back(ImageRead{index, l(Range(0, m), Range(0, n)),
                                   r(Range(0, m), Range(0, n)),
                                   gt(Range(0, m), Range(0, n))});
  }

  images_out.push_back(ImageRead{(size_t)-1});
  tout << "cvRead: end" << tendl;
  return;
}
