#include<cstdlib>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"Contact.hpp"
#include"Log.hpp"
#include"Board.hpp"

using namespace std;

void Contact::setAO()
{
	a=0;
	o=0;
}
void Contact::condition(float n,float q,string name,string size,Board &bo)
{
	for(int i=0;i<a;i++)
	{
		if(vecLog[i].kind==name)
		{
			if(vecLog[i].quan>=q)
			{		
					vecLog[i].quan-=q;			
					bo.setName(name);
					bo.setSize(size);
					bo.setCub(n);
					o++;
					system("clear");
					cout<<"Заказ выполнен"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;
					vecBoa.push_back(bo);
			}
			else
			{
					system("clear");								
					cout<<"Недостаточно кубов!"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;
			}
		}	
	}
}

void Contact::loadData(string filename)
{
	Log lo;
	Board bo;
	string kind;
	float cub;
	string size;
	ifstream file(filename.c_str());
	if(!file.is_open()){	
		system("clear");
		cout<<"Файл создан"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;
	}	
	else
	{
		file>>a;
		file>>o;
		for(int i=0;i<a;i++)
		{
			file>>lo.kind>>lo.quan;
			vecLog.push_back(lo);
		}
		for(int j=0;j<o;j++)
		{
			file>>kind>>size>>cub;
			bo.setName(kind);
			bo.setSize(size);
			bo.setCub(cub);
			vecBoa.push_back(bo);
		}
		system("clear");
		cout<<"Данные загружены"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;
		file.close();		
	}
}
/*##################################*/
void Contact::addLog(Log &lo)
{
	cin>>lo;
	vecLog.push_back(lo);
	a++;
	system("clear");
	cout<<"Сырьё добавлено"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;
	getchar();
}
/*##################################*/
void Contact::SaveData(string filename,Log &lo,Board &bo)
{
	ofstream file(filename.c_str());
	file<<a<<endl<<o<<endl;
	int i;	
	for(i=0;i<a;i++)
	{
		file<<vecLog[i].kind<<endl<<vecLog[i].quan<<endl;
	}
	for(i=0;i<o;i++)
	{
		file<<vecBoa[i].getName()<<endl<<vecBoa[i].getSize()<<endl<<vecBoa[i].getCub()<<endl;			
	}
	cout<<"Данные сохранены"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;
	file.close();
}
/*##################################*/
void Contact::prosm()
{
	cout<<"1.Просмотреть склад сырья\n2.Просмотреть склад продукции\n"<<endl;
	int i;
	cin>>i;
	system("clear");
	if(i==1)
	{
		if(a!=0){
			for(i=0;i<a;i++){
				cout<<i+1<<"."<<vecLog[i];
			}
		}
		else
			cout<<"Склад пустой"<<endl;
		cout<<"==*=*=*=*=*=**=*==\n"<<endl;
		return;
	}	
	if(i==2)
	{
		if(o!=0){
			for(i=0;i<o;i++){
				cout<<i+1<<"."<<vecBoa[i];
			}	
		}
		else
			cout<<"Склад пустой"<<endl;
	}	
	cout<<"==*=*=*=*=*=**=*==\n"<<endl;
}

/*##################################*/
int Contact::start()
{
	system("clear");
	setAO();
	string filename;
	cout<<"Введите имя: ";
	getline(cin,filename);
	Log log;
	Log &lo=log;
	Board board;
	Board &bo=board;
	loadData(filename);
	for( ; ; )
	{	
		cout<<"1.Просмотреть склады\n2.Добавить сырьё на склад\n3.Произвести\n4.Сохранить\n5.Найти на складах\n6.Удалить со складов"<<endl;
		cout<<"Выбирете действие:";
		int j;
		cin>>j;
		switch(j)
		{
			case(1):system("clear");
					prosm();
					getchar();
					break;
			case(2):system("clear");
					addLog(lo);
					getchar();
					break;
			case(3):system("clear");
					makeBoard(bo);
					getchar();
					break;
			case(4):system("clear");
					SaveData(filename,lo,bo);
					getchar();
					break;
			case(5):system("clear");
					poisk(lo,bo);
					getchar();
					break;
			case(6):system("clear");
					deleteLog(lo,bo);
					getchar();
					break;
			case(0):break;
			default:
					cout<<"Такого пункта нет"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;;	
					break;		
		}
		if(j==0)
				break;
		
	}
}

/*##################################*/

void Contact::makeBoard(Board &bo)
{
	cout<<"Введите название сырья:"<<endl;
	string k;
	cin.ignore(1,'\n');
	getline(cin,k);
	float q,s;
	int flag;
		for(int i=0;i<a;i++)
		{
			if(k==vecLog[i].kind)
				flag=1;
		}
		if(flag==1)
		{
			int j;
			system("clear");
			cout<<"1.50x150\n2.50x200\n3.150x150\n4.25x150\n5.Другой размер\nВыберите размер:";			
			cin>>j;
			switch(j)
						{
							case(1):cout<<"Введите количество:";								
									cin>>q;
									s=q;
									q=q*3;
									condition(s,q,k,"50x150",bo);
									break;
							case(2):cout<<"Введите количество:";								
									cin>>q;
									s=q;
									q=q*3;
									condition(s,q,k,"50x200",bo);
									break;	
							case(3):cout<<"Введите количество:";								
									cin>>q;
									s=q;
									q=q*4;
									condition(s,q,k,"150x150",bo);
									break;
							case(4):cout<<"Введите количество:";								
									cin>>q;
									s=q;
									condition(s,q,k,"25x150",bo);
									break;
							case(5):cout<<"Введите размер:"<<endl;
								string size;
								cin.ignore(1,'\n');
								getline(cin,size);
								cout<<"Введите количество:"<<endl;
								cin>>q;
								s=q;
								q=q*3;
								condition(s,q,k,size,bo);	
								break;				
						}	
				}
			else
			cout<<"Такого сырья нет на складе"<<endl;
}

/*##################################*/
void Contact::deleteLog(Log &lo,Board &bo)
{
	string name1;
	int i;
	cout<<"1.Удалить сырьё\n2.Удалить продукцию\nВыбирите дейтсвие:";
	cin>>i;	
	if(i==1)
	{
		cout<<"Введите название сырья:";
		cin.ignore(1,'\n');
		getline(cin,name1);
		int flag,n;
			for(i=0;i<a;i++){
				if(name1==vecLog[i].kind){
						flag=1;
						n=i;
				}
			}
			if(flag==1)
			{
					vecLog.erase(vecLog.begin()+n);
					system("clear");
					cout<<"Сырьё удалено"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;
					a--;
			}
				else{
					system("clear");
					cout<<"Сырьё не найдено"<<endl<<"==*=*=*=*=*=**=*==\n";	
				}	
		return;
	}
	if(i==2)
	{
		cout<<"Введите номер заказа:";
		int j;
		cin>>j;
		j--;
		if(j<0 || j>o){
				system("clear");			
				cout<<"Заказа с таким номером нет"<<"==*=*=*=*=*=**=*==\n"<<endl;
				return;
		}	
		else{
			for(i=j;i<o;i++){
					vecBoa.erase(vecBoa.begin()+i);
					system("clear");
					cout<<"Продукция удалена"<<endl<<"==*=*=*=*=*=**=*==\n"<<endl;
					o--;
			}	
		}
	}
}

/*##################################*/
void Contact::poisk(Log &lo,Board &bo)
{
	int i;
	string n;
	float q;
	cout<<"1.Найти сырьё по названию\n2.Найти сырьё по количеству\n3.Найти продукцию по названию\n";
	cout<<"4.Найти продукцию по размру\n5.Найти продукцию по количеству"<<endl;
	cin>>i;
	system("clear");
	switch(i)
		{
			case(1):cout<<"Введите название:"<<endl;
					cin.ignore(1,'\n');
					getline(cin,n);
					break;
			case(2):cout<<"Введите количество:"<<endl;
					cin>>q;
					break;
			case(3):cout<<"Введите название:"<<endl;
					cin.ignore(1,'\n');
					getline(cin,n);
					break;			
			case(4):cout<<"Введите размер:"<<endl;
					cin.ignore(1,'\n');
					getline(cin,n);
					break;
			case(5):cout<<"Введите количество:"<<endl;
					cin>>q;
					break;
		}
	int j;
	system("clear");
	for(j=0;j<a;j++){
			switch(i)
				{
					case(1):if(n==vecLog[j].kind)
										cout<<vecLog[j]<<"==*=*=*=*=*=**=*==\n"<<endl;
							break;
					case(2):if(q==vecLog[j].quan)
									 	cout<<vecLog[j]<<"==*=*=*=*=*=**=*==\n"<<endl;
							break;
				}
		}
	for(j=0;j<o;j++){
			switch(i)
			{
					case(3):if(n==vecBoa[j].getName())
										cout<<vecBoa[j]<<"==*=*=*=*=*=**=*==\n"<<endl;
							break;
 					case(4):if(n==vecBoa[j].getSize())
										cout<<vecBoa[j]<<"==*=*=*=*=*=**=*==\n"<<endl;
							break;
					case(5):if(q==vecBoa[j].getCub())
										cout<<vecBoa[j]<<"==*=*=*=*=*=**=*==\n"<<endl;
							break;                            
			}	
	}
}
