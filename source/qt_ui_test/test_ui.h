//
// Created by Administrator on 2023/8/28.
//
#pragma warning(disable : 4819)
#ifndef QT_TEST_TEST_UI_H
#define QT_TEST_TEST_UI_H
#include "../mainWidget.h"
#include "1.h" //必须添加 "ui_类名.h" 头文件
#include <QDialog>
class testUi : public QDialog, public Ui::Form {
  Q_OBJECT // 添加 Q_OBJECT宏，为ui类提供信号槽机制
      public : testUi(MainWidget *pWidget) {
    setupUi(this); // ui类的构造函数中必须包含启动函数，可将代码与界面关联起来。
  }
  ~testUi() override = default;
};
#endif // QT_TEST_TEST_UI_H
