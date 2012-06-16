#include <QApplication>
#include <QWidget>

#include "qt_viewer.hh"

void qt_viewer::run(int argc, char* argv[])
{

  QApplication app(argc, argv);
  QWidget window;

  window.resize(250, 150);
  window.setWindowTitle("Qt Viewer");
  window.show();

  app.exec();
}
