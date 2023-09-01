
//
// Created by Administrator on 2023/9/1.
//
#pragma warning (disable:4819)
#ifndef QT_TEST_CORE_H
#define QT_TEST_CORE_H
#include <QWidget>
#include <QObject>
#include <QThread>
#include "common.h"

class Core : public QObject
{
Q_OBJECT

public:
    explicit Core(QObject *parent = nullptr);
    ~Core()
    {
        mWorkerThread.quit();
        mWorkerThread.wait();
    }

    // 定义供html页面调用的函数时，需要加上Q_INVOKABLE，否则html页面会找不到定义的函数
    Q_INVOKABLE void handleCmd(const QString &func, const QStringList &keys,
                               const QStringList &values);

signals:
    void operate(const int type, const QString &func, const QString &cmd);
    void operateResult(const QString &result);

public slots:
    void handleResults(const RstData &rstData);


private:
    QThread mWorkerThread;
};


#endif //QT_TEST_CORE_H
