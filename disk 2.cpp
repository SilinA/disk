#include <iostream>
#include <float.h>
#include <conio.h> 
#include "Disk.h"
using namespace std;



int main()
{setlocale(LC_ALL,"Russian");
	int reb, tch;
	int *G,*V;

cout<<"������������ ������ �2 ������� �19"<<endl;

for(;;)
{	
	cout<<"������� ���������� ������ ����� �������:";
	cin>>reb;
	if((reb<1)||(reb>50)) cout<<"!!!������������ ����!!!"<<endl;
	else break;
}

G = new int[reb];

cout<<"������� ������ G:"<<endl;
for(int x=0; x<reb; x++)
	cin>>G[x];

for(;;)
{
cout<<"������� ���������� ���e�:";
	cin>>tch;
	if((tch<1)||(tch>50)) cout<<"!!!������������ ����!!!"<<endl;
	else break;
}


V= new int[tch];
cout<<"������� ������ V:"<<endl;
for(int x=0; x<tch; x++)
	cin>>V[x];

Disk d(G,V,tch);
d.Res();
d.otchet();
cin>>reb;
}