//
// Created by Administrator on 2023/9/1.
//

#include <QThread>
#include <QDebug>
#include "worker.h"
#include "common.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::doWork(const int type, const QString &func, const QString &cmd)
{
    qDebug() << "[Worker::doWork]type=" << type << "func=" << func;
    RstData rstData;
    rstData.func = func;
    rstData.retCode = RET_OK;
    rstData.msg = RET_MSG[rstData.retCode];

    if (type == WORK_DB_QUERY)
    {
        if (cmd == "0")
        {
            rstData.retCode = RET_PARAMERR;
            rstData.msg = "用户名或密码错误";
        }
    }
    else if (type == WORK_DB_RUN)
    {

    }
    else
    {
        rstData.retCode = RET_NOWORKTYPE;
        rstData.msg = RET_MSG[rstData.retCode];
    }

    emit resultReady(rstData); // Qt接口
}