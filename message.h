//Файл message.h
#pragma once

#include <string>
#include <fstream>

class Message{
   std::string _text;
   std::string _sender;
   std::string _receiver;
public:
   //Конструкто по умолчанию
   Message();
   //Конструктор с параметрами
   Message(const std::string &text, const std::string &sender, const std::string &rec);
   //Констуктор коипрования
   Message(const Message &other);
   //Деструктор
   ~Message() = default;

   //Оператор присваивания копирования
   Message& operator = (const Message &other);


   //Перегружаем операции >> и <
   friend std::ifstream& operator >>(std::ifstream& is, Message& obj);
   friend std::ostream& operator <<(std::ostream& os, const Message& obj);
};
