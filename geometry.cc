#include <cmath>

#include "geometry.hh"

std::tuple<bool, point, double> intersection(const ray& r, const sphere& s)
{
  auto res = std::make_tuple(false, point(), 0.);

  const vector& L = s.center() - r.origin();

  const double tca = L * r.dir();

  if (tca <= 0)
    return res;

  const double r2 = s.radius() * s.radius();
  const double d2 = L * L - tca*tca;
  if (d2 > r2)
    return res;

  const double thc = std::sqrt(r2 - d2);
  const double t1 = tca - thc;
  const double t = std::min(t1, tca + thc);

  if (t > 0.1)
  {
    std::get<0>(res) = true;
    std::get<1>(res) = r.origin() + t * r.dir();
    std::get<2>(res) = t;
  }

  return res;
}

std::ostream& operator<<(std::ostream& out, const coordinate& c)
{
  return out << "(" << c.x() << ", "<< c.y() << ", " << c.z() << ")";
}
