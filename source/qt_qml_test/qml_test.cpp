#include "qml_test.h"
#include "utils.h"
#include <QQuickItem>
#include <QQuickWidget>
#include <QTimer>
QmlTEST::QmlTEST(QWidget *parent) : QDialog(parent) {
  //  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
  setAttribute(Qt::WA_TranslucentBackground);

  qquickWidget_ = new QQuickWidget;
  QUrl source(CommonUtils::getQmlPath("listen.qml"));
  qquickWidget_->setResizeMode(QQuickWidget::SizeRootObjectToView);
  qquickWidget_->setSource(source);
  qquickWidget_->setClearColor(QColor(Qt::transparent));
  QQuickItem *item = qquickWidget_->rootObject();
  connect(item, SIGNAL(sliderMoved(qreal)), this, SLOT(onSliderMoved(qreal)));
  connect(item, SIGNAL(playClicked()), this, SLOT(onPlay()));
  connect(item, SIGNAL(pauseClicked()), this, SLOT(onPause()));
  connect(this, SIGNAL(sigPalyProgress(qreal)), item,
          SIGNAL(updatePlayProgress(qreal)));
  if (item)
    QMetaObject::invokeMethod(item, "setPlayState");

  int inum = 0;
  QTimer *p = new QTimer;
  p->setInterval(10);
  connect(p, &QTimer::timeout, [=]() mutable {
    inum += 10;
    sigPalyProgress(inum);
  });
  p->start();

  layout_.addWidget(qquickWidget_);
  setLayout(&layout_);
}

void QmlTEST::setTitle(const QString &title) {
  QQuickItem *item = qquickWidget_->rootObject();
  if (item)
    QMetaObject::invokeMethod(item, "setTitle", Q_ARG(QVariant, title));
}

void QmlTEST::setTotal(const long v) {
  QQuickItem *item = qquickWidget_->rootObject();
  if (item)
    QMetaObject::invokeMethod(item, "setTotalTime", Q_ARG(long, v));
}

void QmlTEST::setCurValue(const long v) {
  QQuickItem *item = qquickWidget_->rootObject();
  if (item)
    QMetaObject::invokeMethod(item, "setCurTime", Q_ARG(long, v));
}

void QmlTEST::onSliderMoved(qreal v) { qDebug() << "onslidermoved:" << v; }

void QmlTEST::onPlay() { qDebug() << "onPlay"; }

void QmlTEST::onPause() { qDebug() << "onPause"; }
