#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mapagrafico.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QGridLayout *layout = 0);
    ~MainWindow();

private:

};

#endif // MAINWINDOW_H
