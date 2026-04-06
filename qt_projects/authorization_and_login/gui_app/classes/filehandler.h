
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include "QVector"
    class FileHandler
{
public:
    FileHandler();
    QString path_to_data(QString path);
    void create_folder(QString folder_name);
    // проверить существования файла,

};



// class PhotoFileHandler : public FileHandler

#endif // FILEHANDLER_H
