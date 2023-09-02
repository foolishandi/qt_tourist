//
// Created by Administrator on 2023/8/27.
//

#ifndef QT_TEST_MY_WIDGET2_H
#define QT_TEST_MY_WIDGET2_H

#include "qt_html/widget.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class MainWidget : public QWidget {
  Q_OBJECT
public:
  explicit MainWidget(QWidget *parent = nullptr);

  ~MainWidget() override = default;

private:
  void initUi();

  void initBind();
  QLabel content_;
  QVBoxLayout layout_;
  QPushButton test_;
  QPushButton qmlTest_;
  QPushButton htmlTest_;
};

#endif // QT_TEST_MY_WIDGET2_H
