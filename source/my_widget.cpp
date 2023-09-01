//
// Created by Administrator on 2023/8/27.
//
#include <iostream>
#include "my_widget.h"
#include "qt_ui_test/test_ui.h"
#include "qt_qml_test/qml_test.h"
#include "../utils/utils.h"
#include "qt_html/widget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent), content_(""), test_("测试ui弹窗"), qmlTest_{"qml dialog test"},
                                      htmlTest_("html test") {
    initUi();
    initBind();
}

void MyWidget::initUi() {
    setFixedWidth(64);
    setObjectName("MyWidget");
    //按钮加载图片
    auto *imgBtn = new QPushButton(this);
    imgBtn->resize(64, 64);
    imgBtn->setStyleSheet(QString("QPushButton {border-image: url(%1)}").arg(CommonUtils::getImagesPath("button.png")));
    connect(imgBtn, &QPushButton::clicked, this, []() {
        qInfo() << "image click";
    });

//    ui文件弹窗测试
    layout_.addWidget(&test_);
    test_.setObjectName("test");
    layout_.addWidget(imgBtn);
//    qml测试
    layout_.addWidget(&qmlTest_);
    connect(&qmlTest_, &QPushButton::clicked, this, [this] {
        auto qmlDialog = new QmlTEST(this);
        qmlDialog->show();
    });
// html 测试
    layout_.addWidget(&htmlTest_);
    connect(&htmlTest_, &QPushButton::clicked, this, [this] {
        WidgetDialog *dialog=new WidgetDialog();
        dialog->showNow();
    });
    setLayout(&layout_);

}

void MyWidget::initBind() {
    connect(&test_, &QPushButton::clicked, [this] {
        testUi *p = new testUi(this);
        p->show();
    });
}