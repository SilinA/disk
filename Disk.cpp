#include "Disk.h"
#include <iostream>
#include <vector>

using namespace std;


Disk::Disk(int *G, int *V,int tch)
{
	this-> G = G;
	this-> V = V;
	this-> tch = tch;
}


Disk::~Disk(void)
{
}


void Disk::Res()
{	
	math = new int*[tch];
	int l=0;
	for(int x=0;x<tch; x++)
	{	
		math[x] = new int[tch];

		for(int y=0; y<tch; y++)
		{
			
			if (V[x]<=l) math[x][y]=0;
			else
			{
				if (G[l]==y+1) {math[x][y]=1; l++;}
				else math[x][y]=0;
			}
			cout<<math[x][y]<<" ";
		}
		cout<<endl;
	}
	F = new bool[tch];
	F_ob= new bool[tch];
}


void Disk::T_find(int l)
{
	way.push_back(l);
	for(int k=0; k<tch; k++)
	{
		if ((math[l][k]==1)&&(!chek(k)))
		{
			T_find(k); 
		}
		
	}
	
}

bool Disk::chek(int index)
{
	for(int x=0; x<way.size(); x++)
	{
		if (way[x]==index) return true;
	}
	return false;
}

bool Disk::chek_ob(int index)
{
	for(int x=0; x<way_ob.size(); x++)
	{
		if (way_ob[x]==index) return true;
	}
	return false;
}


void Disk::T_find_ob(int l)
{
	
	way_ob.push_back(l);
	for(int k=0; k<tch; k++)
	{
		if ((math[l][k]==1)&&(!chek_ob(k)))
		{
			T_find_ob(k); 
		}
		
	}
	
}

void Disk::otchet()
{
	T_find();
	for(int x= 0; x<tch; x++)
		F[x]=false;

	for(int x=0; x<way.size(); x++)
		F[way[x]]=true;


    T_find_ob();
	for(int x= 0; x<tch; x++)
		F_ob[x]=false;

	for(int x=0; x<way_ob.size(); x++)
		F_ob[way_ob[x]]=true;

	cout<<endl<<"Максимально-связаные вершины:"<<endl;
	for (int x= 0; x<tch; x++)
		if((F[x]==true)&&(F_ob[x]==true)) cout<<"x"<<x+1<<" ";
	cout<<endl;
	for (int x= 0; x<tch; x++)
		if((F[x]==false)||(F_ob[x]==false)) cout<<"x"<<x+1<<" ";
	
}