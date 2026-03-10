#include "func.h"
#include "logger.hpp"

QString find_path(QDir current_filepath, QString new_path){
    QString current_filepath_str = current_filepath.absolutePath();
    int pos = current_filepath_str.indexOf("authorization_and_login");
    QString main_folder_path = current_filepath_str.left(pos+QString("authorization_and_login").length());
    QString filepath = QDir(main_folder_path).filePath(new_path);
    return filepath;
}

QString encoder(QString password, int key){
    QString new_password="";
    int new_key = qAbs(key)%74+1;

    for (int i=0; i<password.length(); i++){
        int letter_int=password[i].toLatin1();
        char new_symbol=' ';
        if (letter_int+new_key>'z'){
            int x = letter_int+new_key-'z';
            new_symbol= static_cast<char>('0'-1+x);
        }
        else{
            new_symbol= static_cast<char>(letter_int+new_key);
        }
        new_password=new_password+new_symbol;
    }
    return new_password;
}
