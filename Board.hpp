/*!
	\file
	\brief Заголовочный файл с описанием класса  Board 


	Данный файл содержит в себе описания класса  Board, который предназначен для хранения данных продукции
*/


/*! @class  Board
    Класс для производства продукции
*/
#pragma once

class Board {
private:
//!Название сырья,из которого произведена доска
std::string sizeboard;

//!Количество кубов произведённой продукции
float cub;

//!Размер доски
std::string name;
public:
//!Метод,принимающий название сырья,из которого будет произведена доска
//!@param name-параметр,передающий название сырья
void setName(std::string name);

//!Метод,принимающий размер доски
//!@param size-параметр,передающий размер доски
void setSize(std::string size);

//!Метод,принимающий количество кубов проиведённой продукции
//!@param cub-параметр,передающий количество кубов произведённой продукции
void setCub(float cub);

//!Метод,возвращающий название сырья,из которого произведена доска
//!@return name
std::string getName();

//!Метод,возвращающий размер доски
//!@return sizeboard
std::string getSize();

//!Метод,возвращающий количество произведённой продукции 
//!@return cub
float getCub();

//!Перегруженный оператор вывода класса Board
friend std::ostream& operator<<(std::ostream& out,Board& bo);
};