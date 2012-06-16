#ifndef VIEWER_HH
# define VIEWER_HH

class scene;
class renderer;

class viewer
{
  public:

    viewer() { }
    viewer(scene* s, renderer* r)
      : s_(s), r_(r) { }
    virtual ~viewer() { }

    virtual void run(int argc, char* argv[]) = 0;

    scene* s() { return s_; }
    renderer* r() { return r_; }

  protected:

    scene* s_{0};
    renderer* r_{0};
};

#endif // !VIEWER_HH
