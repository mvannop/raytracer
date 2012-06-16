#include <iostream>

#include "scene.hh"
#include "rt1_renderer.hh"
#include "image.hh"
#include "tga.hh"
#include "qt_viewer.hh"

int main(int argc, char* argv[])
{
  scene s(640, 480);

  s.add_light({{0, 240, -100}, 1, 1, 1});
  s.add_light({{640, 240, -10000}, 0.6, 0.7, 1});
  //s.add_light({{0, 0, -1000}, 1, 1, 1});

  s.add_sphere({{0.5, 1, 1, 0}, {233, 290, 0}, 100});
  s.add_sphere({{0.5, 0, 1, 1}, {407, 290, 0}, 100});
  s.add_sphere({{0.5, 1, 0, 1}, {320, 140, 0}, 100});

  image out(s.width(), s.height());

  rt1_renderer rt1;
  rt1.render(s, out);

  to_tga(out, "out.tga");

  qt_viewer qt(&s, &rt1);
  qt.run(argc, argv);
}
