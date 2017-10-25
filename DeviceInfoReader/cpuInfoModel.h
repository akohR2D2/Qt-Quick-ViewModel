#ifndef CPUINFOMODEL_H
#define CPUINFOMODEL_H

#include <QObject>

class CpuInfoModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString descrProp READ descrProp WRITE setDescrProp NOTIFY descrChanged)
    Q_PROPERTY(QString descrValProp READ descrValProp WRITE setDescrValProp NOTIFY descrValChanged)
public:
    explicit CpuInfoModel(QObject *parent = nullptr);
    CpuInfoModel(const QString &descrProp, const QString &descrValProp, QObject *parent=0);

    QString descrProp() const;
    void setDescrProp(const QString &descrProp);

    QString descrValProp() const;
    void setDescrValProp(const QString &descrValProp);

signals:
    void descrChanged();
    void descrValChanged();

private:
    QString m_descr;
    QString m_descrValue;
};
#endif // CPUINFOMODEL_H
