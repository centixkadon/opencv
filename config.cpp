
#include "precomp.hpp"

#include "config.hpp"

using namespace std;
using namespace google;

DECLARE_string(flagfile);

DEFINE_string(images_root, "", "images root");
DEFINE_string(images_group, "", "images group");
DEFINE_string(images_prefix_left, "", "left images prefix");
DEFINE_string(images_prefix_right, "", "right images prefix");
DEFINE_string(images_prefix_groundtruth, "", "groundtruth images prefix");
DEFINE_string(images_postfix, "", "images postfix");
DEFINE_string(images_write_path, "./bin/output/", "images write path");

DEFINE_uint64(images_index_begin, 0, "images index begin");
DEFINE_uint64(images_index_end, -1, "images index end");
DEFINE_uint64(images_index_step, 1, "images index step");

DEFINE_uint64(images_size_width, 400, "images size height");
DEFINE_uint64(images_size_height, 300, "images size height");
DEFINE_uint32(images_disparity_min, 0, "images disparity min");
DEFINE_uint32(images_disparity_max, 64, "images disparity max");

DEFINE_uint32(window_scale, 4, "window scale [window_size = window_scale * 2 + 1]");

int config_init(int argc, char ** argv) {
  SetCommandLineOption("flagfile", "config.cfg");
  ParseCommandLineFlags(&argc, &argv, true);

  cout << "cvConfig: images_path = " << (FLAGS_images_root + FLAGS_images_group) << endl;

  return 0;
}
