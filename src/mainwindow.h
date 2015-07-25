#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "QtMultimedia/QMediaPlayer"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_PlayButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_AudioSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    bool is_started;
};

#endif // MAINWINDOW_H
