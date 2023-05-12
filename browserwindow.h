#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QWebEnginePage>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QProgressBar;
QT_END_NAMESPACE

class TabWidget;
class Browser;
class WebView;



class BrowserWindow : public QMainWindow
{
    Q_OBJECT

public:
    BrowserWindow(Browser *browser , QWebEngineProfile *profile);
    QSize sizeHint() const override;
    TabWidget *tabWidget() const;
    WebView *webView() const;
    Browser *browser(){return m_browser;}

protected:
    void closeEvent (QCloseEvent *event )override;

private slots:
    void newWindowTriggerd();
    void newIncognitoWindowTriggerd();
    void fileOpenTriggerd();
    void findActionTriggerd();
    void showWindowTriggerd();
    void webViewLoadProgress(int);
    void webViewTitleChanged(const QString &title);
    void webActionEnabledChanged(QWebEnginePage::WebAction *action,bool enabled);

private:
    QMenu *createFileMenu(TabWidget *tabWidget);
    QMenu *createEditMenu();
    QMenu *createViewMenu(QToolBar *toolBar);
    QMenu *createWindowMenu(TabWidget *tabWidget);
    QMenu *createHelpMenu();
    QToolBar *createToolBar();

private:
    Browser *m_browser;
    QWebEngineProfile *m_profile;
    TabWidget *m_tabWidget;
    QProgressBar *m_progressBar;
    QAction *m_historyBackAction;
    QAction *m_historyForwardAction;
    QAction *m_stopAction;
    QAction *m_reloadAction;
    QAction *m_stopReloadAction;
    QLineEdit *m_urlLineEdit;
    QAction *m_favAction;
    QString m_lastSearch;






};
#endif // BROWSERWINDOW_H
