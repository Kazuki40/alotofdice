#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;

class shack
{
private:

	unsigned int i;
	unsigned long int sum;
	long double av;
	long double v;
	long double kakuritu;
	long double var;
	unsigned int n;
	unsigned int val[6] = {};
	void write();

public:

	vector<int>value;
	void summary();
	void roll(unsigned int);
	shack();

};

