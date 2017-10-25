#include "mainModel.h"

MainModel::MainModel(FileReader* fileReader, QObject *parent) : QObject(parent)
{
    m_fileReader = fileReader;
    m_Header = QString("");
}

MainModel::~MainModel()
{
    delete m_fileReader;
}

QVariantList MainModel::cpuInfoModelProp() const
{
    return m_cpuInfoModel;
}

void MainModel::setCpuInfo(QVariantList *cpuInfo)
{
    m_cpuInfoModel = *cpuInfo;
}

void MainModel::setCpuInfoModelProp(QVariantList cpuInfoModel)
{
    m_cpuInfoModel = cpuInfoModel;
}

QString MainModel::headerCpuInfoProp() const
{
    return m_Header;
}

void MainModel::setheaderCpuInfoProp(QString str)
{
    m_Header = str;
}
void MainModel::onButtonClicked(QString str)
{
    if("cpuInfo" == str)
    {
        setCpuInfoModelProp( m_fileReader->readCpuInfo("/proc/cpuinfo"));
        cpuInfoModelChanged();
        setheaderCpuInfoProp(QString("Readed CPU Info"));
    }
    else if("show...")
    {
        setheaderCpuInfoProp(QString("Create your page..."));
    }

    headerCpuInfoPropChanged();
}
