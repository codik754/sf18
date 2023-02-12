//Файл usersandmessages.h
#pragma once

#include <string>
#include <vector>
#include "user.h"
#include "message.h"

class UsersAndMessages{
   std::vector<User> users_;
   std::vector<Message> messages_;
   std::string nameFileForUsers_;
   std::string nameFileForMessages_;
public:
   //Конструктор по умолчанию
   UsersAndMessages();
   //Конструктор с параметрами
   UsersAndMessages(const std::string &nameFileUsers, const std::string &nameFileMessages);
   
   //Получить количество Useroв в векторе
   size_t getAmountUsers() const;
   //Получить количество сообщений в векторе
   size_t getAmountMessages() const;

   //Установить название файла Userов
   void setNameFileForUsers(const std::string &nameFile);
   //Установить название файла сообщений
   void setNameFileForMessages(const std::string &nameFile);

   //Показать всех Userов
   void showUsers() const;
   //Показать все сообщения
   void showMessages() const;
   
   //Добавить usera
   void addUser(const std::string &name, const std::string &login, const std::string& pass);
   //Добавить сообщения
   void addMessage(const std::string &text, const std::string &sender, const std::string& receiver);

   //Сохранить userов в файл
   void saveUsers() const;
   //Сохранить сообщения в файл
   void saveMessages() const;

   //Загрузить данные о пользователях из файла
   void loadUsers();
   //Загрузить сообщения из файла
   void loadMessages();
};
