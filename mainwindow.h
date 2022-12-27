#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "file.h"
#include "QListWidget"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    File* openFile{nullptr};
    QList<File*> openFiles;

private:
    void initQMenuBar();
    void connectFileList();
    void openChosenFile(QString fileName);
    void openChosenFile(QListWidgetItem* item);
};
#endif // MAINWINDOW_H
