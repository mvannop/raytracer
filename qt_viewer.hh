#ifndef QT_VIEWER_HH
# define QT_VIEWER_HH

# include "viewer.hh"

class qt_viewer : public viewer
{
  public:

    qt_viewer() { }
    explicit qt_viewer(scene* s, renderer* r)
      : viewer(s, r) { }
    virtual ~qt_viewer() { }

    virtual void run(int argc, char* argv[]);

  private:
};

#endif // !QT_VIEWER_HH

