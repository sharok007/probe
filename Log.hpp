/*!
	\file
	\brief Заголовочный файл с описанием класса Log 


	Данный файл содержит в себе описания класса Log, который предназначен для хранения данных сырья
*/


/*! @class Log
    Класс для добавления на склад сырья
*/
#pragma once

class Log {
public:
//!Название сырья
std::string kind;

//!Количество кубов сырья,добавленного на склад
float quan;

//!Метод,принимающий название сырья
//!@param L-параметр,передающий название сырья
void setLog(std::string L);

//!Метод,принимающий количество сырья
//!@param Q-параметр,передающий количество сырья 
void setQ(float Q);

//!Метод,возвращающий название сырья
//!@return kind
std::string getLog();

//!Метод,возвращающий количество сырья
//!@return quan
float getQ();

//!Перегруженный оператор вывода класса Log
friend std:: ostream& operator<<(std::ostream& stream,Log& lo);

//!Перегруженный оператор ввода класса Log
friend std:: istream& operator>>(std::istream& stream,Log& lo);
};
