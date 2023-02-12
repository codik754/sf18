//Файл main.cpp
#include <iostream>
#include "usersandmessages.h"

int main(){
   //Объект для работы с объектами классов User и Message
   UsersAndMessages um;
  
   //Считываем информацию из файлов
   um.loadUsers();
   um.loadMessages();
   
   std::cout << std::endl;
   //Если не получилось считать информацию о пользователях(вектор пользователей пустой)
   if(um.getAmountUsers() == 0){
      //Добавляем в вектор свои значения
      um.addUser("admin", "ADMIN", "a123");
      um.addUser("user1", "Name1", "123");
      um.addUser("user2", "Name2", "321");
      um.addUser("user3", "Name3", "231");
   }

   //Если не получилось считать сообщения(вектор сообщений пустой)
   if(um.getAmountMessages() == 0){
      //Добавляем в вектор свои значения
      um.addMessage("Welcome user1", "admin", "user1");
      um.addMessage("Hi", "user1", "user2");
      um.addMessage("How are you?", "user2", "admin");
      um.addMessage("Welcome to our chat! You can write messages to each other.", "admin", "all");

   }
   
   //Отображаем информацию
   um.showUsers();
   um.showMessages();
   
   //Сохраняем информацию
   um.saveUsers();
   um.saveMessages();
   
   return 0;
}
