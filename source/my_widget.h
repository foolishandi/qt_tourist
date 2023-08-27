//
// Created by Administrator on 2023/8/27.
//

#ifndef QT_TEST_MY_WIDGET2_H
#define QT_TEST_MY_WIDGET2_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>
class MyWidget : public QWidget {
Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

    ~MyWidget() override = default;

private:
    void initUi();

    void initBind();
    QLabel content_;
    QHBoxLayout layout_;
    QPushButton test_;
};


#endif //QT_TEST_MY_WIDGET2_H
