#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qwebpagefirefox.h"
#include <iostream>
#include <QWebPage>
#include <QWebFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebPageFirefox * ff = new QWebPageFirefox();
    ui->webView->setPage(ff);
    ui->webView->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    connect(ui->webView, SIGNAL(loadStarted()), this, SLOT(webLoadStarted()));
    connect(ui->webView, SIGNAL(loadProgress(int)), this, SLOT(webLoadProgress(int)));
    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(webLoadFinished(bool)));
    connect(ui->webView, SIGNAL(linkClicked(QUrl)), this, SLOT(webLinkClicked(QUrl)));
    connect(ui->webView, SIGNAL(selectionChanged()), this, SLOT(webSelectionChanged()));
    connect(ui->webView, SIGNAL(statusBarMessage(QString)), this, SLOT(webStatusBarMessage(QString)));
    connect(ui->webView, SIGNAL(titleChanged(QString)), this, SLOT(webTitleChanged(QString)));
    connect(ui->webView, SIGNAL(urlChanged(QUrl)), this, SLOT(webUrlChanged(QUrl)));
    ui->webView->load(QUrl("http://play.wimpmusic.com"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::webLoadStarted()
{
    std::cout << "loadStarted" << std::endl;
}

void MainWindow::webLoadProgress(int progress)
{
    std::cout << "loadProgress: " << progress << std::endl;
}

void MainWindow::webLoadFinished(bool ok)
{
    std::cout << "loadFinished " << ok << std::endl;
    //std::cout << ui->webView->page()->mainFrame()->toHtml().toStdString() << std::endl;
}

void MainWindow::webLinkClicked(const QUrl &url)
{
    std::cout << "linkClicked " << url.toDisplayString().toStdString() << std::endl;
}

void MainWindow::webSelectionChanged()
{
    std::cout << "selectionChanged " << std::endl;
}

void MainWindow::webStatusBarMessage(const QString &text)
{
    std::cout << "statusBarMessage " << text.toStdString() << std::endl;
}

void MainWindow::webTitleChanged(const QString &title)
{
    setWindowTitle(title);
}

void MainWindow::webUrlChanged(const QUrl &url)
{
    std::cout << "urlChanged " << url.toDisplayString().toStdString() << std::endl;
}
