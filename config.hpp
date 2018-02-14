
#pragma once

#include <gflags/gflags.h>

DECLARE_string(cv_images_root);
DECLARE_string(cv_images_group);
DECLARE_string(cv_images_prefix_left);
DECLARE_string(cv_images_prefix_right);
DECLARE_string(cv_images_prefix_groundtruth);
DECLARE_string(cv_images_postfix);

int config_init(int argc, char ** argv);
