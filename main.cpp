#include "visual.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Visual window;
    
    window.resize(800, 600);
    window.setWindowTitle("ToDo");
    window.show();
    
    return app.exec();
}
