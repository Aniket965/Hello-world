// binary.cpp : Binary trees program.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
struct bin {
int nub;
struct bin *l;
struct bin *r;
};
void add(bin ** nood)
{
	int nub;
	cout << "enter nub";
	cin>> nub;
if (*nood==0 )
{
	bin *nu;
	nu = new bin;
	nu->l=0;
	nu->r=0;
	nu->nub=nub;
	*nood=nu;
}
if (nub > (*nood->nub))
	add(*nood->r);
else if (nub< (*nood->nub) )
	add(*nood->l);
else 
	cout<< "duplicate not allowed";
}
void print (bin **nood)
{
	cout <<*nood->nub;
	print(*nood->l);
	print(*nood->r);
}
int _tmain(int argc, _TCHAR* argv[])
{
	bin *nood =0;
	char choice 
	while (1){
	cout << "a: add\n d: del\n p: print\n";
	cin>> choice;
	switch (choice)
	{
a: add(&nood);
		break;
p: print (&nood);
		break;
	}
	}
	return 0;
}


