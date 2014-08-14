#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qwebpagefirefox.h"
#include <iostream>
#include <QWebPage>
#include <QWebFrame>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebPageFirefox * ff = new QWebPageFirefox();
    ui->webView->setPage(ff);
    ui->webView->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->settings()->setCSSMediaType("screen");
    connect(ui->webView, SIGNAL(loadStarted()), this, SLOT(webLoadStarted()));
    connect(ui->webView, SIGNAL(loadProgress(int)), this, SLOT(webLoadProgress(int)));
    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(webLoadFinished(bool)));
    connect(ui->webView, SIGNAL(linkClicked(QUrl)), this, SLOT(webLinkClicked(QUrl)));
    connect(ui->webView, SIGNAL(selectionChanged()), this, SLOT(webSelectionChanged()));
    connect(ui->webView, SIGNAL(statusBarMessage(QString)), this, SLOT(webStatusBarMessage(QString)));
    connect(ui->webView, SIGNAL(titleChanged(QString)), this, SLOT(webTitleChanged(QString)));
    connect(ui->webView, SIGNAL(urlChanged(QUrl)), this, SLOT(webUrlChanged(QUrl)));
    ui->webView->load(QUrl("http://play.wimpmusic.com"));
    //ui->webView->load(QUrl("http://www.google.com"));

    QShortcut * shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_Space), this);
    shortcut->setContext(Qt::ApplicationShortcut);
    connect(shortcut, SIGNAL(activated()), this, SLOT(actionPlayPause()));

    shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_N), this);
    shortcut->setContext(Qt::ApplicationShortcut);
    connect(shortcut, SIGNAL(activated()), this, SLOT(actionNextTrack()));

    shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_P), this);
    shortcut->setContext(Qt::ApplicationShortcut);
    connect(shortcut, SIGNAL(activated()), this, SLOT(actionPrevTrack()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::webLoadStarted()
{
    //std::cout << "loadStarted" << std::endl;
}

void MainWindow::webLoadProgress(int progress)
{
    //std::cout << "loadProgress: " << progress << std::endl;
}

void MainWindow::webLoadFinished(bool ok)
{
    //std::cout << "loadFinished " << ok << std::endl;
}

void MainWindow::webLinkClicked(const QUrl &url)
{
    //std::cout << "linkClicked " << url.toDisplayString().toStdString() << std::endl;
}

void MainWindow::webSelectionChanged()
{
    //std::cout << "selectionChanged " << std::endl;
}

void MainWindow::webStatusBarMessage(const QString &text)
{
    //std::cout << "statusBarMessage " << text.toStdString() << std::endl;
}

void MainWindow::webTitleChanged(const QString &title)
{
    setWindowTitle(title);
}

void MainWindow::webUrlChanged(const QUrl &url)
{
    //std::cout << "urlChanged " << url.toDisplayString().toStdString() << std::endl;
}

void MainWindow::actionPlayPause()
{
    ui->webView->page()->mainFrame()->evaluateJavaScript("if($('.play-controls__play').is(':visible')) { $('.play-controls__play').click(); } else { $('.play-controls__pause').click(); }");
    std::cout << "Play/Pause" << std::endl;
}

void MainWindow::actionNextTrack()
{
    std::cout << "Next track" << std::endl;
}

void MainWindow::actionPrevTrack()
{
    std::cout << "Previous track" << std::endl;
}
