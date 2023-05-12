#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QIcon>
#include <QWebEngineView>
#include <QWebEnginePage>



class WebView : public QWebEngineView
{
public:
    WebView(QWidget *parent=nullptr);
    void setPage(QWebEnginePage *page);
    QIcon favIcon() const;
    int loadProgress()const;
    bool isWebActionEnabled(QWebEnginePage::WebAction webAction) const;

protected:
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;

signals:
    void webActionEnabledChanged(QWebEnginePage::WebAction webAction, bool enabled);
    void favIconChanged(const QIcon &icon);


private:
    void createWebActionTrigger(QWebEnginePage *page, QWebEnginePage::WebAction);

private:
    int m_loadProgress;

};

#endif // WEBVIEW_H
