#ifndef RENDERER_HH_
# define RENDERER_HH_

class scene;
class image;

class renderer
{
  public:

    virtual ~renderer() { }

    virtual void render(const scene& s, image& im) = 0;

  private:

};

#endif /* !RENDERER_HH_ */
