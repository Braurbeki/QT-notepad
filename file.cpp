#include "file.h"
#include "fstream"
#include "string"

File::File(QString path) : m_path{path.toStdString()}
{

}

std::string File::text()
{
    std::ifstream input(m_path);
    std::string str;

    std::string res;
    while(!input.eof())
    {

        std::getline( input, str );

        res.append(str);
        res.append("\n");
    }
    input.close();
    return res;
}

void File::save(QString data)
{
    m_data = data.toStdString();
    std::ofstream output(m_path);
    output << data.toStdString();
    output.close();
}

QString File::path()
{
    return QString::fromStdString(m_path);
}
