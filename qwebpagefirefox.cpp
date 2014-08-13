#include "qwebpagefirefox.h"
#include <iostream>

using namespace std;

QWebPageFirefox::QWebPageFirefox(QObject *parent) :
    QWebPage(parent)
{
}

QString QWebPageFirefox::userAgentForUrl(const QUrl &url) const
{
    return "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1985.125 Safari/537.36";
    //return "Mozilla/5.0 (X11; Linux x86_64; rv:28.0) Gecko/20100101 Firefox/28.0";
    //return "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:8.0) Gecko/20100101 Firefox/8.0";
}

void QWebPageFirefox::javaScriptAlert(QWebFrame *originatingFrame, const QString &msg)
{
    cout << "JS alert: " << msg.toStdString() << endl;
}

bool QWebPageFirefox::javaScriptConfirm(QWebFrame *originatingFrame, const QString &msg)
{
    cout << "JS confirm: " << msg.toStdString() << endl;
    return true;
}

void QWebPageFirefox::javaScriptConsoleMessage(const QString &message, int lineNumber, const QString &sourceID)
{
    cout << "JS " << sourceID.toStdString() << ":" << lineNumber << ": " << message.toStdString() << endl;
}

bool QWebPageFirefox::javaScriptPrompt(QWebFrame *originatingFrame, const QString &msg, const QString &defaultValue, QString *result)
{
    cout << "JS prompt: " << msg.toStdString() << endl;
    return true;
}
