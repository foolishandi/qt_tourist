//
// Created by Administrator on 2023/8/27.
//
#include <iostream>
#include "my_widget.h"
#include <iostream>
MyWidget::MyWidget(QWidget *parent): QWidget(parent), content_(""), test_("测试关闭") {
    initUi();
    initBind();
}

void MyWidget::initUi() {
    setObjectName("MyWidget");
    //按钮加载图片
    auto *imgBtn = new QPushButton(this);
    imgBtn->setFixedSize(200,100);
    imgBtn->resize(64,64);
    imgBtn->move(200,300);
    imgBtn->setStyleSheet("QPushButton {background-image: url(:/resource/images/test.png)}");
    connect(imgBtn,&QPushButton::clicked,this,[](){
        std::cout<<"cout 444";
        qInfo()<<"click";});

    setLayout(&layout_);
    layout_.addWidget(&test_);
    test_.setObjectName("test");
    layout_.addWidget(imgBtn);
}

void MyWidget::initBind() {
    connect(&test_,&QPushButton::clicked,this,&MyWidget::close);
}