
project(copy)

add_executable(cv_${PROJECT_NAME} copy_images.cpp)
target_link_libraries(cv_${PROJECT_NAME} images)
