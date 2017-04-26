#include<string>
#include<iostream>
#include"Log.hpp"

using namespace std;

void Log::setLog(string L)
{
 	kind=L;
}
void Log::setQ(float Q)
{
	quan=Q;
}

string Log::getLog()
{
	return kind;
}
float Log::getQ()
{
	return quan;
}

ostream& operator<<(ostream& stream,Log& lo)
{
	stream<<lo.kind<<" "<<lo.quan<<" куб."<<endl;
	return stream;
}
istream& operator>>(istream& stream,Log& lo)
{
	cout<<"Введите название сырья:"<<endl;
	cin.ignore(1,'\n');	
	getline(stream,lo.kind);
	cout<<"Введите количество"<<endl;
	stream>>lo.quan;
	return stream;
}
