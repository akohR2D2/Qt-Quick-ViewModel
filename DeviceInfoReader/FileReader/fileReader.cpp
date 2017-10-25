#include "FileReader/fileReader.h"
#include "FileReader/txtFileReader.h"
#include "cpuInfoModel.h"

using namespace std;

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

QVariantList FileReader::readCpuInfo(string path)
{
    TxtFileReader txtReader;
    map<int, map<string, string>> cpuInfo = txtReader.getCpuInfoFromTxtFile(path);

    QVariantList cpuInfoCollection;

    for (auto const &info: cpuInfo)
    {
        QVariantList* list = new QVariantList();
        for (auto const &i: info.second)
        {
            QString descr = QString::fromStdString(i.first);
            QString descrVal = QString::fromStdString(i.second);
            QObject* cim = (QObject*)new CpuInfoModel(descr, descrVal);

            list->append(QVariant::fromValue(cim));
        }
        cpuInfoCollection.append(QVariant::fromValue(*list));
    }

    return cpuInfoCollection;
}
