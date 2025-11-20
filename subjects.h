#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
#include<ostream>
using namespace std;
class subject
{
public:
	string name;
	int maxscore;
	int successscore;
	float score;
	subject()
	{
		name = " ";
		maxscore = successscore = score = 0;
	}
	subject(string n, int maxscore, int successscore, float score)
	{
		name = n;
		this->maxscore = maxscore;
		this->successscore = successscore;
		this->score = score;

	}
	void read(ifstream& in)
	{
		int size;
		in >> size;
		char c;
		in.read(&c, 1);
		char *temp = new char[size + 1];
		in.read(temp, size);
		temp[size] = '\0';
		name = temp;
		delete[]temp;
		in >> maxscore;
		in >> successscore;
		in >> score;
	}
	void write(ofstream& out)
	{
		out << name << endl;
		out << maxscore << endl;
		out << successscore<<endl;
		out << score << endl;

	}

};




