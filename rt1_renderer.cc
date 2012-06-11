#include <cmath>
#include <iostream>
#include <cassert>
#include <tuple>
#include <limits>

#include "rt1_renderer.hh"
#include "scene.hh"
#include "image.hh"
#include "geometry.hh"
#include "chrono.hh"


void rt1_renderer::render(const scene& s, image& im)
{
  chrono ch;

  for (int y = 0; y < s.height(); ++y)
    for (int x = 0; x < s.width(); ++x)
    {
      double coef{1};
      double r = 0, g = 0, b = 0;
      int level{0};

      ray vr{ {double(x), double(y), -1000}, {0, 0, 1} };

      do
      {
	std::tuple<bool, point, double> isect{false,{}, std::numeric_limits<double>::infinity()};
	sphere sp;
	for (const auto& cur_sp : s.spheres())
	{
	  std::tuple<bool, point, double>&& i = std::move(intersection(vr, cur_sp));
	  if (std::get<0>(i) and std::get<2>(i) < std::get<2>(isect))
	  {
	    isect = i;
	    sp = cur_sp;
	  }
	}

	if (not std::get<0>(isect))
	  break;

	const point& ipt = std::get<1>(isect);

	vector n = ipt - sp.center();
	double tmp = 1/std::sqrt(n*n);
	n = tmp * n;

	for (const auto& l : s.lights())
	{
	  vector lv = l.pos() - ipt;

	  if (n * lv > 0)
	  {
	    const double t = std::sqrt(lv * lv);

	    ray sr{ ipt, lv / t};

	    bool in_shadow = false;

	    for (const auto& sh : s.spheres())
	    {
	      std::tuple<bool, point, double>&& i = std::move(intersection(sr, sh));
	      if (std::get<0>(i))
	      {
		in_shadow = true;
		break;
	      }
	    }

	    if (not in_shadow)
	    {
	      const double lambert = (sr.dir() * n) * coef;
	      r += lambert * l.r() * sp.r();
	      g += lambert * l.g() * sp.g();
	      b += lambert * l.b() * sp.b();
	    }
	  }
	}

	coef *= sp.ref();
	const double reflect = 2. * (vr.dir() * n);
	vr.origin() = ipt;
	vr.dir() = vr.dir() - (reflect * n);
	++level;

      } while (coef > 0. and level < 10);

      im(x, y) = pixel(std::min(255., r * 255), std::min(255., g * 255.), std::min(255., b * 255));
    }

  std::cout << "Render time: " << ch.cur_duration() / 1000. << "ms" << std::endl;
}
