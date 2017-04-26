#include<string>
#include<iostream> 
#include"Board.hpp"

using namespace std;

void Board::setName(string n)
{
	name=n;
}
void Board::setSize(string size)
{
	sizeboard=size;
}
void Board::setCub(float c)
{
	cub=c;
}

string Board::getName()
{
	return name;
}
string Board::getSize()
{
	return sizeboard;
}
float Board::getCub()
{
	return cub;
}

ostream& operator<<(ostream& out,Board& bo)
{
	out<<bo.name<<" "<<bo.sizeboard<<" "<<bo.cub<<" куб."<<endl;
	return out;
}


