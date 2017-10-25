#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include "cpuInfoModel.h"
#include <QVariant>
#include <QVariantList>

class FileReader
{
public:
    FileReader();
    ~FileReader();

    QVariantList readCpuInfo(std::string path);
};

#endif // FILEREADER_H
