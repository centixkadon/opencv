
#pragma once

#include <gflags/gflags.h>

DECLARE_string(images_root);
DECLARE_string(images_group);
DECLARE_string(images_prefix_left);
DECLARE_string(images_prefix_right);
DECLARE_string(images_prefix_groundtruth);
DECLARE_string(images_postfix);
DECLARE_string(images_write_path);

DECLARE_uint64(images_index_begin);
DECLARE_uint64(images_index_end);
DECLARE_uint64(images_index_step);
DECLARE_uint64(images_index_length);

DECLARE_uint64(images_size_width);
DECLARE_uint64(images_size_height);
DECLARE_uint32(images_disparity_min);
DECLARE_uint32(images_disparity_max);

DECLARE_uint32(window_scale);

typedef uint8_t pixel_t;
typedef uint8_t disparity_t;
typedef uint16_t cost_t;

int config_init(int argc, char ** argv);
