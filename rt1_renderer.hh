#ifndef RT1_RENDERER_HH_
# define RT1_RENDERER_HH_

# include "renderer.hh"

class rt1_renderer : public renderer
{
  public:

    virtual void render(const scene& s, image& im);

  private:

};

#endif /* !RT1_RENDERER_HH_ */
