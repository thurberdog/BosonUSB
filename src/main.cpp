#include "mainapplication.hpp"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MainApplication * mainApplication = new MainApplication();
    mainApplication->init(argc,argv);
    return a.exec();
}
