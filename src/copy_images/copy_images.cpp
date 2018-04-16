
#include <images.hpp>
#include <opencv2/stereo.hpp>

using namespace std;
using namespace cv;

class CopyImages : public Images {
public:
  explicit CopyImages() : Images({ "in" }, { "out" }) {}
  virtual ~CopyImages() { join(); }

private:
  virtual void calculate(size_t index, std::map<std::string, cv::Mat> & images_write, std::map<std::string, cv::Mat> & images_read) {
    tout << "CopyImages: " << index << tendl;
    images_write["out"] = images_read["in"];
  }
};

int main() {
  cout << "copy_images" << endl;

  CopyImages ths;
  for (size_t index = 1; index < (size_t)-1; ++index) {
    string images_index = static_cast<stringstream &>(stringstream() << setw(4) << setfill('0') << index).str();
    ths.process(index, { "./book/L" + images_index + ".png" }, { "./bin/output/OUT" + images_index + ".png" });
    if (!ths) break;
  }

  return 0;
}
