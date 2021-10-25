#include "CsvReader.h"

CsvReader::CsvReader(std::string path)
{
    //para la lectura del csv 
    setlocale(LC_ALL, "spanish");
    content = "";
    cursor = 0;

    std::ifstream file(path);

    std::string data;
    while (std::getline(file, data))
        content += data + ",";
    file.close();
}
// content = "155,cindaquil,2"
bool CsvReader::Read(std::string& data)
{
    data = "";

    if (cursor >= content.length())
        return false;

    while (true)
    {
        if (cursor >= content.length())
            return true;
        if (content[cursor] == ',') {
            cursor++;
            return true;
        }
        data += content[cursor];
        cursor++;
    }
}