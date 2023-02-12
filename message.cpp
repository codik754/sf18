//Файл message.cpp
#include "message.h"

//Конструктор по умолчанию
Message::Message() :  _text("UNKNOWN"), _sender("UNKNOWN"), _receiver("UNKNOWN"){}

//Конструктор с параметрами
Message::Message(const std::string &text, const std::string &sender, const std::string &receiver) : _text(text), _sender(sender), _receiver(receiver) {}

//Констуктор коипрования
Message::Message(const Message &other) : _text(other._text), _sender(other._sender), _receiver(other._receiver){}

//Оператор присваивания копирования
Message& Message::operator = (const Message &other){
   //Проверка на самоприсваивание
   if(this == &other){
      return *this;
   }

   _text = other._text;
   _sender = other._sender;
   _receiver = other._receiver;

   return *this;
}

//Перегружаем операции >> и <<
std::ifstream& operator >>(std::ifstream& is, Message& obj){
   is >> obj._sender;
   is >> obj._receiver;
   is.seekg(1, std::ios_base::cur);
   std::getline(is, obj._text);
   return is;
}

std::ostream& operator <<(std::ostream& os, const Message& obj){
   os << obj._sender << " ";
   os << obj._receiver << " ";
   os << obj._text;
   return os;
}

