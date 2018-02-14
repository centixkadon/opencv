
#include "precomp.hpp"

// DEFINE_string(cv_images_root, "/home/eelab/All/datasets/dcbgrid/", "images root");
// DEFINE_string(cv_images_group, "book/", "images group");
// DEFINE_string(cv_images_prefix_left, "L", "left images prefix");
// DEFINE_string(cv_images_prefix_right, "R", "right images prefix");
// DEFINE_string(cv_images_prefix_groundtruth, "TR", "groundtruth images prefix");
// DEFINE_string(cv_images_postfix, ".png", "images postfix");
DEFINE_string(cv_images_root, "", "images root");
DEFINE_string(cv_images_group, "", "images group");
DEFINE_string(cv_images_prefix_left, "", "left images prefix");
DEFINE_string(cv_images_prefix_right, "", "right images prefix");
DEFINE_string(cv_images_prefix_groundtruth, "", "groundtruth images prefix");
DEFINE_string(cv_images_postfix, "", "images postfix");

using namespace std;
using namespace google;

int config_init(int argc, char ** argv) {
  SetCommandLineOption("flagfile", "ddrsgm_config.cfg");
  ParseCommandLineFlags(&argc, &argv, true);

  cout << "cvConfig: cv_images_root" << FLAGS_cv_images_root << endl;
  cout << "cvConfig: cv_images_root" << FLAGS_cv_images_group << endl;

  return 0;
}
