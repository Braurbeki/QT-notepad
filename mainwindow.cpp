#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Notepad");
    ui->fileList->hide();

    initQMenuBar();

    connect(ui->fileList, &QListWidget::itemDoubleClicked, [=](QListWidgetItem* item) {
        qDebug() << item;
        qDebug() << item->text();
        openChosenFile(item->text());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initQMenuBar()
{
    QMenu* fileMenu = this->menuBar()->addMenu(tr("&File"));

    QAction* openAction = new QAction("Open", this);
    openAction->setShortcuts(QKeySequence::Open);
    connect(openAction, &QAction::triggered, [=](){
        openChosenFile(QFileDialog::getOpenFileName(this));
    });

    QAction* saveAction = new QAction("Save", this);
    saveAction->setShortcuts(QKeySequence::Save);
    connect(saveAction, &QAction::triggered, [=](){
        if(openFile == nullptr)
        {
            openFile = new File(QFileDialog::getOpenFileName(this));
        }

        openFile->save(ui->textEdit->toPlainText());
    });

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
}

void MainWindow::openChosenFile(QString fileName)
{

    if(openFile != nullptr)
    {
        delete openFile;
    }

    openFile = new File(fileName);

    auto fileList = ui->fileList->findItems(openFile->path(), Qt::MatchFlag::MatchCaseSensitive);

    if(ui->fileList->isHidden())
        ui->fileList->show();

    if (fileList.length() == 0)
    {
        ui->fileList->addItem(openFile->path());
    }

    ui->textEdit->setText(openFile->text().c_str());
}
