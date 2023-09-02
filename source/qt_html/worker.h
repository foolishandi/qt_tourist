//
// Created by Administrator on 2023/9/1.
//

#ifndef QT_TEST_WORKER_H
#define QT_TEST_WORKER_H


#include <QObject>
#include "common.h"

enum WORK_TYPE {
    WORK_DB_QUERY = 0,
    WORK_DB_RUN
};

class Worker : public QObject
{
Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
    void resultReady(const RstData &rstData);

public slots:
    void doWork(const int type, const QString &func, const QString &cmd);

private:


};

#endif //QT_TEST_WORKER_H
