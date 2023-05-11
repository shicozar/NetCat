#include "browserwindow.h"
#include "browser.h"

#include <QApplication>
#include <QWebEngineSettings>
#include <QUrl>

QUrl commandLineUrlArgument()
{
    const QStringList args = QCoreApplication::arguments();
    for (const QString &arg : args.mid(1)) {
        if (!arg.startsWith(QLatin1Char('-')))
            return QUrl::fromUserInput(arg);
    }
    return QUrl(QStringLiteral("https://www.google.com"));
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    QUrl url = commandLineUrlArgument();

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(QStringLiteral(":")));
    Browser browser ;
    BrowserWindow *window=browser.createWindow();
    window->tabWidget()->setUrl(url);
    window->show();
    return app.exec();
}
