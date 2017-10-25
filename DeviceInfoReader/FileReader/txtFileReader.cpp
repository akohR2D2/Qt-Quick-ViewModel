#include "txtFileReader.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace  std;

TxtFileReader::TxtFileReader()
{

}

TxtFileReader::~TxtFileReader()
{

}

map<int, map<string, string>> TxtFileReader::getCpuInfoFromTxtFile(string path)
{
    if(path == lastPath) return cpuInfo;

    try{
        string textLine;
        ifstream fileReader(path);
        if (fileReader.is_open())
        {
            int processorNr = -1;

            while ( getline (fileReader,textLine) )
            {
                if(!textLine.compare("")) continue;

                textLine.erase(remove(textLine.begin(), textLine.end(), '\t'), textLine.end());
                int pos = textLine.find_first_of(':');

                string key = textLine.substr(0, pos);
                string value = textLine.substr(pos+2);

                if(key == "processor")
                {
                    processorNr = stoi(value);
                }
                if(processorNr != -1)
                {
                    cpuInfo[processorNr][key] = value;
                }
            }
            fileReader.close();
        }
        else
        {
            cout << "Unable to open file";
        }
    }
    catch(exception ex)
    {
        map<int, map<string, string>> ret;
        return ret;
    }


    lastPath = path;

    return cpuInfo;
}
