//
// Created by Administrator on 2023/9/1.
//
#pragma warning (disable:4819)
#ifndef QT_TEST_WIDGET_H
#define QT_TEST_WIDGET_H

#include <QWebEngineView>
#include <QDialog>
#include <QHBoxLayout>
#include "core.h"

class WidgetDialog : public QDialog
{
Q_OBJECT
public:
    explicit WidgetDialog(QWidget *parent = nullptr);
    ~WidgetDialog() override=default;
    void showNow();
private:
    QWebEngineView* qWebEngineView_;
    Core mCore; // 定义全局的，否则程序运行会出错，js里面也找不到Core里面定义的函数
};


#endif //QT_TEST_WIDGET_H
