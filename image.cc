#include "image.hh"

image::image(int w, int h)
 : width_(w), height_(h), data_(new pixel[width_ * height_])
{

}
