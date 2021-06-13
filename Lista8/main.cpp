#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QMessageBox::information(&w, "Informacja",
                             "Ten program reaguje na kliknięcia myszką <br>"
                             "Ctrl + Scroll zmniejszasz kółka<br>"
                             "Ctrl + Z usuwasz ostatnie kółko");
    return a.exec();
}
