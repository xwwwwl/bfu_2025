#ifndef FUNC_H
#define FUNC_H
#include <QDir>

QString find_path(QDir current_filepath, QString new_path);
QString encoder(QString password, int key);
bool password_check(QString password, QString alphabet);
#endif // FUNC_H
