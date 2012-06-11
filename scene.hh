#ifndef SCENE_HH_
# define SCENE_HH_

# include <deque>

# include "geometry.hh"

class light
{
  public:

    light() { }
    light(const point& p, double r, double g, double b)
      : pos_(p), r_(r), g_(g), b_(b) { }

    const point& pos() const { return pos_; }
    double r() const { return r_; }
    double g() const { return g_; }
    double b() const { return b_; }

  private:

    point pos_{0,0,0};
    double r_{0};
    double g_{0};
    double b_{0};
};

class scene
{
  public:

    template <typename Geometry>
      using list_t = std::deque<Geometry>;

    typedef list_t<sphere> sphere_list_t;
    typedef list_t<light> light_list_t;

    scene();
    scene(int w, int h);

    void height(int h) { height_ = h; }
    void width(int w) { width_ = w; }

    int height() const { return height_; }
    int width() const { return width_; }

    void add_sphere(const sphere& s) { spheres_.push_back(s); }
    const sphere_list_t& spheres() const { return spheres_; }

    void add_light(const light& s) { lights_.push_back(s); }
    const light_list_t& lights() const { return lights_; }

  private:

    int width_;
    int height_;

    sphere_list_t spheres_;
    light_list_t lights_;
};

#endif /* !SCENE_HH_ */
