//Файл user.cpp
#include "user.h"

//Конструктор по умолчанию
User::User() :  _name("UNKNOWN"), _login("UNKNOWN"), _pass("UNKNOWN"){}

//Конструктор с параметрами
User::User(const std::string &name, const std::string &login, const std::string &pass) : _name(name), _login(login), _pass(pass) {}

//Констуктор коипрования
User::User(const User &other) : _name(other._name), _login(other._login), _pass(other._pass){}

//Оператор присваивания копирования
User& User::operator = (const User &other){
   //Проверка на самоприсваивание
   if(this == &other){
      return *this;
   }

   _name = other._name;
   _login = other._login;
   _pass = other._pass;

   return *this;
}

//Перегружаем операции >> и <
std::ifstream& operator >>(std::ifstream& is, User& obj){
   is >> obj._name;
   is >> obj._login;
   is >> obj._pass;
   return is;
}

std::ostream& operator <<(std::ostream& os, const User& obj){
   os << obj._name << " ";
   os << obj._login << " ";
   os << obj._pass;
   return os;
}

