//
// Created by Administrator on 2023/9/1.
//

#include "core.h"
#include "widget.h"
#include <QWebChannel>
#include <QFileDialog>
#include <QDebug>
#include "worker.h"

Core::Core(QObject *parent) : QObject(parent)
{
    Worker *worker = new Worker;
    worker->moveToThread(&mWorkerThread);
    connect(&mWorkerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &Core::operate, worker, &Worker::doWork);
    connect(worker, &Worker::resultReady, this, &Core::handleResults); // Qt接口
    mWorkerThread.start();
}

void Core::handleCmd(const QString &func, const QStringList &keys, const QStringList &values)
{
    qDebug() << func << keys << values;
    QString cmd = "0";
    if (func == "selectFile")
    {
        QFileDialog dialog;
        QString fileName = dialog.getOpenFileName(NULL,
                                                  tr("selectFile"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
    }
    else if (func == "selectDir")
    {
        QFileDialog dialog;
        dialog.setFileMode(QFileDialog::Directory);
        QString fileName = dialog.getOpenFileName(NULL,
                                                  tr("selectDir"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
    }
    else
    {
        RstData rstData;
        if (keys.size() != values.size() || values.size() != 2)
        {
            rstData.retCode = RET_PARAMERR;
            rstData.msg = RET_MSG[rstData.retCode];
            emit operateResult(MyCommon::GetJsonData(rstData));
            return;
        }

        if (values[0] == "admin" && values[1] == "admin")
        {
            cmd = "1";
        }
    }

    emit operate(WORK_DB_QUERY, func, cmd);
}

void Core::handleResults(const RstData &rstData)
{
    qDebug() << "[handleResults]result.size()=" << rstData.func << ","
             << rstData.retCode << "," << rstData.msg;

    emit operateResult(MyCommon::GetJsonData(rstData));
}