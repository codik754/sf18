//Файл usersandmessages.cpp
#include "usersandmessages.h"
#include <iostream>
#include <fstream>
#include <filesystem>

//Конструктор по умолчанию
UsersAndMessages::UsersAndMessages() : users_(), messages_(), nameFileForUsers_("users.txt"), nameFileForMessages_("messages.txt") {}

//Конструктор с параметрами
UsersAndMessages::UsersAndMessages(const std::string &nameFileUsers, const std::string &nameFileMessages) : users_(), messages_(), nameFileForUsers_(nameFileUsers), nameFileForMessages_(nameFileMessages) {}

//Установить название файла Userов
void UsersAndMessages::setNameFileForUsers(const std::string &nameFile){
   nameFileForUsers_ = nameFile;   
}

//Установить название файла сообщений
void UsersAndMessages::setNameFileForMessages(const std::string &nameFile){
   nameFileForMessages_ = nameFile;
}

//Получить количество Useroв в векторе
size_t UsersAndMessages::getAmountUsers() const{
   return users_.size();
}
   
//Получить количество сообщений в векторе
size_t UsersAndMessages::getAmountMessages() const{
   return messages_.size();
}

//Показать всех Userов
void UsersAndMessages::showUsers() const{
  std::cout << "Users: " << std::endl;
  for(const auto &user : users_){
      std::cout << user << std::endl;
  }
  std::cout << std::endl;
}

//Показать все сообщения
void UsersAndMessages::showMessages() const{
  std::cout << "Messages: " << std::endl;
  for(const auto &m : messages_){
      std::cout << m << std::endl;
  }
  std::cout << std::endl;
}

//Добавить usera
void UsersAndMessages::addUser(const std::string &name, const std::string &login, const std::string& pass){
   users_.emplace_back(name, login, pass);
}

//Добавить сообщения
void UsersAndMessages::addMessage(const std::string &text, const std::string &sender, const std::string& receiver){
   messages_.emplace_back(text, sender, receiver);
}

//Сохранить userов в файл
void UsersAndMessages::saveUsers() const{
   //Открываем файл
   std::ofstream file(nameFileForUsers_, std::ios::trunc);

   //Если файл не создан по каким-то причинам
   if(!file.is_open()){
      std::cout << "I can't open the file " << nameFileForUsers_  << " for the record!" << std::endl;
      return;
   }
   
   //Записываем данные 
   for(const auto &user : users_){
      file << user << std::endl;
   }

   //Закрываем файл
   file.close();
   
   //Устанавливаем права для файла
   std::filesystem::permissions(nameFileForUsers_, std::filesystem::perms::owner_read | std::filesystem::perms::owner_write);
}

//Сохранить сообщения в файл
void UsersAndMessages::saveMessages() const{
   //Открываем файл
   std::ofstream file(nameFileForMessages_, std::ios::trunc);

   //Если файл не создан по каким-то причинам
   if(!file.is_open()){
      std::cout << "I can't open the file " << nameFileForMessages_  << " for the record!" << std::endl;
      return;
   }
   
   //Записываем данные 
   for(const auto & m: messages_){
      file << m << std::endl;
   }

   //Закрываем файл
   file.close();

   //Устанавливаем права для файла
   std::filesystem::permissions(nameFileForMessages_, std::filesystem::perms::owner_read | std::filesystem::perms::owner_write);
}

//Загрузить данные о пользователях из файла
void UsersAndMessages::loadUsers(){
   //Открываем файл
   std::ifstream file(nameFileForUsers_);

   //Если файл не открыт по каки-то причинам
   if(!file.is_open()){
      std::cout << "I can't open the file " << nameFileForUsers_  << " for the reading!" << std::endl;
      //Если файла нет, выведим сообщение
      if(!std::filesystem::exists(nameFileForUsers_)){
         std::cout << "File " << nameFileForUsers_  << " does not exist!" << std::endl;
      }

      return;
   }
   
   //Считываем данные
   User tempUser;
   while(file >> tempUser){
      users_.emplace_back(tempUser);
   }

   //Зарываем файл
   file.close();
}
   
//Загрузить сообщения из файла
void UsersAndMessages::loadMessages(){
   //Открываем файл
   std::ifstream file(nameFileForMessages_);

   //Если файл не открыт по каки-то причинам
   if(!file.is_open()){
      std::cout << "I can't open the file " << nameFileForMessages_  << " for the reading!" << std::endl;
      
      //Если файла нет, выведим сообщение
      if(!std::filesystem::exists(nameFileForMessages_)){
         std::cout << "File " << nameFileForMessages_  << " does not exist!" << std::endl;
      }

      return;
   }
   
   //Считываем данные
   Message tempMessage;
   while(file >> tempMessage){
      messages_.emplace_back(tempMessage);
   }

   //Зарываем файл
   file.close();
}

