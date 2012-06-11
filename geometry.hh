#ifndef GEOMETRY_HH_
# define GEOMETRY_HH_

# include <tuple>
# include <ostream>

class coordinate
{
  public:

    coordinate() { }
    coordinate(double x, double y, double z) : x_(x), y_(y), z_(z) { }

    double x() const { return x_; }
    double y() const { return y_; }
    double z() const { return z_; }

    double& x() { return x_; }
    double& y() { return y_; }
    double& z() { return z_; }

    coordinate& operator+=(const coordinate& rhs);
    coordinate& operator-=(const coordinate& rhs);
    coordinate& operator*=(double rhs);
    coordinate& operator/=(double rhs);

    bool operator!=(const coordinate& rhs) const { return x_ != rhs.x_ or y_ != rhs.y_ or z_ != rhs.z_; }

  protected:

    double x_ = 0;
    double y_ = 0;
    double z_ = 0;
};

coordinate operator-(const coordinate& lhs, const coordinate& rhs);
coordinate operator+(const coordinate& lhs, const coordinate& rhs);
coordinate operator*(double lhs, const coordinate& rhs);
inline coordinate operator*(const coordinate& lhs, double rhs) { return rhs * lhs; }
coordinate operator/(const coordinate& lhs, double rhs);

std::ostream& operator<<(std::ostream& out, const coordinate& c);

class point : public coordinate
{
  public:

    point() { }
    point(double x, double y, double z) : coordinate(x, y, z) { }
    point(const coordinate& c) : coordinate(c) { }
};

class vector : public coordinate
{
  public:

    vector() { }
    vector(double x, double y, double z) : coordinate(x, y, z) { }
    vector(const coordinate& c) : coordinate(c) { }

    double operator*(const vector& v) const
    {
      double res = 0;

      res += x_ * v.x_;
      res += y_ * v.y_;
      res += z_ * v.z_;

      return res;
    }
};

class ray
{
  public:

    ray(const point& p, const vector& dir)
      : origin_(p), dir_(dir) { }

    const point& origin() const { return origin_; }
    const vector& dir() const { return dir_; }

    point& origin() { return origin_; }
    vector& dir() { return dir_; }

  private:

    point origin_;
    vector dir_;
};

class material
{
  public:

    material() { }
    material(double rf, double r, double g, double b)
      : ref_(rf), r_(r), g_(g), b_(b) { }

    virtual ~material() { }

    double ref() const { return ref_; }
    double r() const { return r_; }
    double g() const { return g_; }
    double b() const { return b_; }

  private:

    double ref_{0};
    double r_{0};
    double g_{0};
    double b_{0};
};

class sphere : public material
{
  public:

    sphere() { }
    sphere(const point& c, double r) : material(), center_(c), radius_(r) { }
    sphere(const material& m, const point& c, double r) : material(m), center_(c), radius_(r) { }

    const point& center() const { return center_; }
    double radius() const { return radius_; }

    bool operator!=(const sphere& rhs) { return center_ != rhs.center_ or radius_ != rhs.radius_; }

  private:

    point center_{0, 0, 0};
    double radius_{0};
};


std::tuple<bool, point, double> intersection(const ray& r, const sphere& s);
inline std::tuple<bool, point, double> intersection(const sphere& s, const ray& r) { return std::move(intersection(r, s)); }

# include "geometry.hxx"

#endif /* !GEOMETRY_HH_ */
