#ifndef FILE_H
#define FILE_H
#include<iostream>
#include<QString>

class File
{
private:
    std::string m_data;
    std::string m_path;
private:
    std::string read_data();

public:
    File(QString path);
    std::string text();
    void save(QString data);
    QString path();
};

#endif // FILE_H
