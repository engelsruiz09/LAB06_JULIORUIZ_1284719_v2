#pragma once
#include <iostream>
#include <string>
#include <locale>
#include <fstream>


class CsvReader
{
private:
    int cursor;
    std::string content;
public:
    CsvReader(std::string path);//la ruta del archivo
    bool Read(std::string &data);
};

