#ifndef TGA_HH_
# define TGA_HH_

# include <string>

class image;

void to_tga(const image& im, const std::string& filename);

#endif /* !TGA_HH_ */
