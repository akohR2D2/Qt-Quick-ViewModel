#ifndef TXTFILEREADER_HPP
#define TXTFILEREADER_HPP

#include <QObject>
#include <map>
#include <algorithm>

class TxtFileReader
{
public:

    TxtFileReader();
    ~TxtFileReader();


    std::map<int, std::map<std::string, std::string> > getCpuInfoFromTxtFile(std::string path);

private:
    std::map<int, std::map<std::string, std::string>> cpuInfo ;
    std::string lastPath;
};

#endif // TXTFILEREADER_HPP
