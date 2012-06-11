#include <fstream>
#include <stdexcept>

#include "tga.hh"
#include "image.hh"

void to_tga(const image& im, const std::string& filename)
{
  std::ofstream out(filename);

  if (not out.is_open())
    throw std::runtime_error("Can't open file.");

  out.put(0).put(0);
  out.put(2);        /* RGB not compressed */

  out.put(0).put(0);
  out.put(0).put(0);
  out.put(0);

  out.put(0).put(0); /* origin X */
  out.put(0).put(0); /* origin Y */

  out.put((unsigned char)(im.width() & 0x00FF)).put((unsigned char)((im.width() & 0xFF00) / 256));
  out.put((unsigned char)(im.height() & 0x00FF)).put((unsigned char)((im.height() & 0xFF00) / 256));
  out.put(24);       /* 24 bit bitmap */
  out.put(0);

  for (int h = 0; h < im.height(); ++h)
    for (int w = 0; w < im.width(); ++w)
    {
      const pixel& px = im(w, h);
      out.put(px.blue()).put(px.green()).put(px.red());
    }
}
