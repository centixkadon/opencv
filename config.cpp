
#include "precomp.hpp"

#include "config.hpp"

using namespace std;
using namespace google;

DECLARE_string(flagfile);

DEFINE_string(cv_images_root, "", "images root");
DEFINE_string(cv_images_group, "", "images group");
DEFINE_string(cv_images_prefix_left, "", "left images prefix");
DEFINE_string(cv_images_prefix_right, "", "right images prefix");
DEFINE_string(cv_images_prefix_groundtruth, "", "groundtruth images prefix");
DEFINE_string(cv_images_postfix, "", "images postfix");

int config_init(int argc, char ** argv) {
  SetCommandLineOption("flagfile", "config.cfg");
  ParseCommandLineFlags(&argc, &argv, true);

  cout << "cvConfig: cv_images_root = " << FLAGS_cv_images_root << endl;
  cout << "cvConfig: cv_images_group= " << FLAGS_cv_images_group << endl;

  return 0;
}
