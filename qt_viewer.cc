#include <QApplication>
#include <QWidget>
#include <QImage>
#include <QLabel>

#include "qt_viewer.hh"
#include "scene.hh"
#include "image.hh"
#include "renderer.hh"

void qt_viewer::run(int argc, char* argv[])
{

  QApplication app(argc, argv);
  QWidget window;

  const int w = s_->width();
  const int h = s_->height();

  window.resize(w, h);
  window.setWindowTitle("Qt Viewer");
  window.show();

  image out(w, h);
  r_->render(*s_, out);

  QImage qim(w, h, QImage::Format_RGB32);

  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
    {
      const auto& p = out(x, y);
      qim.setPixel(x, y, qRgb(p.red(), p.green(), p.blue()));
    }

  QLabel* l = new QLabel(&window);
  l->setPixmap(QPixmap::fromImage(qim));
  l->show();

  app.exec();
}
