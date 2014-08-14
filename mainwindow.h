#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void webLoadStarted();
    void webLoadProgress(int progress);
    void webLoadFinished(bool ok);
    void webLinkClicked(const QUrl & url);
    void webSelectionChanged();
    void webStatusBarMessage(const QString & text);
    void webTitleChanged(const QString & title);
    void webUrlChanged(const QUrl & url);
    void actionPlayPause();
    void actionNextTrack();
    void actionPrevTrack();
};

#endif // MAINWINDOW_H
