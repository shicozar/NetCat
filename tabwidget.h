#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QWebEnginePage>

QT_BEGIN_NAMESPACE
class QUrl;
QT_END_NAMESPACE

class WebView;

class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    TabWidget(QWebEngineProfile *profile,QWidget *parent=nullptr);
    WebView *currentWebView() const;

signals:
    void linkHovered(const QString &link);
    void loadProgress(int progress);
    void titleChanged(const QString &title);
    void urlChanged(const QString &url);
    void favIconChanged(const QIcon &icon);
    void webActionEnabled(QWebEnginePage :: WebAction action,bool enabled);

public slots:
    void setUrl(const QUrl &url);
    void nextTab();
    void previousTab();
    void closeTab(int index);
    WebView *createTab();
    WebView *createBackgroundTab();
    void triggerWebPageAction(QWebEnginePage::WebAction action);

private slots:
        void handleCurrentChanged(int index);
        void cloneTab(int index);
        void closeOtherTabs(int index);
        void reloadAllTabs();
        void reloadTab(int index);

private:
    WebView *webView(int index) const;
    void setupView(WebView *webView);

    QWebEngineProfile *m_profile;




};

#endif // TABWIDGET_H
