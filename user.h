//Файл user.h
#pragma once

#include <string>
#include <fstream>

class User{
   std::string _name;
   std::string _login;
   std::string _pass;
public:
   //Конструкто по умолчанию
   User();
   //Конструктор с параметрами
   User(const std::string &name, const std::string &login, const std::string &pass);
   //Констуктор коипрования
   User(const User &other);
   //Деструктор
   ~User() = default;

   //Оператор присваивания копирования
   User& operator = (const User &other);
   
   //Перегружаем операции >> и <<
   friend std::ifstream& operator >>(std::ifstream& is, User& obj);
   friend std::ostream& operator <<(std::ostream& os, const User& obj);
};
