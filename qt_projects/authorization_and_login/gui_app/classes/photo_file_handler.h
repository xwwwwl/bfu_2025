#ifndef PHOTO_FILE_HANDLER_H
#define PHOTO_FILE_HANDLER_H
#include <QString>
class photo_file_handler
{
public:
    static bool CopyPhoto(QString PhotoPath, QString NewPhotoPath);
    static bool DeletePhoto(QString PhotoPath);
};

#endif // PHOTO_FILE_HANDLER_H
