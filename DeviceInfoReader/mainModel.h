#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>
#include <QVariantList>
#include <qvariant.h>
#include "FileReader/fileReader.h"
#include "cpuInfoModel.h"

class MainModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList cpuInfoModelProp READ cpuInfoModelProp WRITE setCpuInfoModelProp NOTIFY cpuInfoModelChanged)
    Q_PROPERTY(QString headerCpuInfoProp READ headerCpuInfoProp WRITE setheaderCpuInfoProp NOTIFY headerCpuInfoPropChanged)

public:
    explicit MainModel(FileReader *fileReader, QObject *parent = nullptr);
    ~MainModel();

    QVariantList cpuInfoModelProp() const;
    void setCpuInfoModelProp(QVariantList cpuInfoModel);
    QString headerCpuInfoProp() const;
    void setheaderCpuInfoProp(QString str);

    void setCpuInfo(QVariantList *cpuInfo);

signals:
    void cpuInfoModelChanged();
    void headerCpuInfoPropChanged();

public slots:
    void onButtonClicked(QString str);

private:
    QVariantList m_cpuInfoModel;
    QString m_Header;
    FileReader* m_fileReader;
};

#endif // MAINMODEL_H
