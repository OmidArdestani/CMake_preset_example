#include "MainWindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("QtPresetSample");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Example");

    MainWindow window;
    window.show();

    return app.exec();
}
