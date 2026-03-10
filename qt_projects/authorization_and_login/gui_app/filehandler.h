#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include "user_class.h"
#include "QVector"
class FileHandler
{
public:
    FileHandler();
    QVector<QVariant> find_user(QString login, QString filepath);
    QString write_user_info(QStringList All_Lines,  QString filepath);
};

class UserFileHandler : public FileHandler
{
private:
    User user_;
public:
    UserFileHandler(User user);
    QString get_path_to_user_avatar();
    QVector<QString> get_vector_to_user_photo();


};

// class PhotoFileHandler : public FileHandler

#endif // FILEHANDLER_H
