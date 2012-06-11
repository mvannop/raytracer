#ifndef IMAGE_HH_
# define IMAGE_HH_

# include <memory>

class pixel
{
  public:

    pixel() : pixel(0, 0, 0) { }
    pixel(unsigned char r, unsigned char g, unsigned char b) : red_(r), green_(g), blue_(b) { }

    unsigned char red() const { return red_; }
    unsigned char green() const { return green_; }
    unsigned char blue() const { return blue_; }

    unsigned char& red() { return red_; }
    unsigned char& green() { return green_; }
    unsigned char& blue() { return blue_; }

  private:

    unsigned char red_;
    unsigned char green_;
    unsigned char blue_;
};

class image
{
  public:

    image(int w, int h);

    int height() const { return height_; }
    int width() const { return width_; }

    pixel& operator()(int w, int h) { return data_[w + h * width_]; }
    const pixel& operator()(int w, int h) const { return data_[w + h * width_]; }

  private:

    int width_;
    int height_;
    std::unique_ptr<pixel[]> data_;
};

#endif /* !IMAGE_HH_ */
