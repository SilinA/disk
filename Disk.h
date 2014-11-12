#pragma once
#include <vector>
class Disk
{
public:
	int **math;
	int *G;
	int *V;
	int *T_p;
	int *T_m;
	int tch;
	std::vector<int> way;
	std::vector<int> way_ob;
	bool *F;
	bool *F_ob;
	Disk(int*G, int*V, int tch);
	~Disk(void);
	void Res();
	void T_find(int l=3);
	void T_find_ob(int l=3);
	void otchet();
	bool chek(int index);
	bool chek_ob(int index);
};

