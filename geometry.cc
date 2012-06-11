#include <cmath>

#include "geometry.hh"

 bool hitSphere(const ray &r, const sphere &s, double &t)
 {
    vector dist = s.center() - r.origin();
    float B = r.dir() * dist;
    float D = B*B - dist * dist + s.radius() * s.radius();
    if (D < 0.0f)
        return false;
    float t0 = B - std::sqrt(D);
    float t1 = B + std::sqrt(D);
    bool retvalue = false; 
    if ((t0 > 0.1f) && (t0 < t))
    {
        t = t0;
        retvalue = true;
    }
    if ((t1 > 0.1f) && (t1 < t))
    {
        t = t1;
        retvalue = true;
    }
    return retvalue;
 }

#if 0
std::tuple<bool, point, double> intersection(const ray& r, const sphere& s)
{
  auto res = std::make_tuple(false, point(), 2000.);

  if (hitSphere(r, s, std::get<2>(res)))
  {
    std::get<0>(res) = true;
    std::get<1>(res) = r.origin() + std::get<2>(res) * r.dir();
  }

  return res;
}

std::tuple<bool, point, double> intersection(const ray& r, const sphere& s)
{
  auto res = std::make_tuple(false, point(), 0);

  const vector& f = (r.origin() - s.center());
  const double a = r.dir() * r.dir();
  const double b = 2 * (r.dir() * f);
  const double c = f * f - s.radius() * s.radius();

  double delta = b*b - 4*a*c;

  if (delta >= 0)
  {
    delta = std::sqrt(delta);
    std::get<0>(res) = true;

    const double x0 = ((-b + delta) / (2 * a));
    const double x1 = ((-b - delta) / (2 * a));

    if (x0 < x1)
    {
      std::get<1>(res) = r.origin() + r.dir() * x0;
      std::get<2>(res) = x0;
    }
    else
    {
      std::get<1>(res) = r.origin() + r.dir() * x1;
      std::get<2>(res) = x1;
    }
  }

  return res;
}
#endif
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
