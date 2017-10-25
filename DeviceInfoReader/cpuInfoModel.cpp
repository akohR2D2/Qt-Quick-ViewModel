#include "cpuInfoModel.h"

CpuInfoModel::CpuInfoModel(QObject *parent) : QObject(parent)
{

}

CpuInfoModel::CpuInfoModel(const QString &descrProp, const QString &descrValProp, QObject *parent)
    : QObject(parent), m_descr(descrProp), m_descrValue(descrValProp)
{

}

QString CpuInfoModel::descrProp() const
{
    return m_descr;
}

void CpuInfoModel::setDescrProp(const QString &descrProp)
{
    if (descrProp != m_descr)
    {
        m_descr = descrProp;
        emit descrChanged();
    }
}

QString CpuInfoModel::descrValProp() const
{
    return m_descrValue;
}

void CpuInfoModel::setDescrValProp(const QString &descrValProp)
{
    if (descrValProp != m_descrValue)
    {
        m_descrValue = descrValProp;
        emit descrValChanged();
    }
}
