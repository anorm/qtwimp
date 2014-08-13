#ifndef QWEBPAGEFIREFOX_H
#define QWEBPAGEFIREFOX_H

#include <QWebPage>

class QWebPageFirefox : public QWebPage
{
    Q_OBJECT
public:
    explicit QWebPageFirefox(QObject *parent = 0);
    QString userAgentForUrl(const QUrl &url) const;
    void javaScriptAlert(QWebFrame *originatingFrame, const QString &msg);
    bool javaScriptConfirm(QWebFrame *originatingFrame, const QString &msg);
    void javaScriptConsoleMessage(const QString &message, int lineNumber, const QString &sourceID);
    bool javaScriptPrompt(QWebFrame *originatingFrame, const QString &msg, const QString &defaultValue, QString *result);


signals:

public slots:

};

#endif // QWEBPAGEFIREFOX_H
