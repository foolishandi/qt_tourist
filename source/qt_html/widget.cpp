#pragma warning(disable : 4819)
#include "widget.h"
#include <QStackedLayout>
#include <QWebChannel>
#include <QWebEngineView>
WidgetDialog::WidgetDialog(QWidget *parent)
    : QDialog(parent)

{
  setObjectName("WidgetDialog");
  qWebEngineView_ = new QWebEngineView(this);
  QHBoxLayout *layout = new QHBoxLayout;
  // 定义交互类，通过channel与html交互
  QWebChannel *channel = new QWebChannel(this);
  channel->registerObject(QStringLiteral("core"), &mCore);
  qWebEngineView_->page()->setWebChannel(channel);

  //    加载页面
  qWebEngineView_->load(QUrl("qrc:/index.html"));
  //    qWebEngineView_->load(QUrl("https://www.baidu.com"));
  layout->addWidget(qWebEngineView_);
  setLayout(layout);
}

void WidgetDialog::showNow() { show(); }
