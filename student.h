#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
#include"subjects.h"
using namespace std;
class student
{
public:
	int age;
	int grade;
	string name;
	subject* subjects;
	student()
	{
		age = grade = 0;
		name = " ";
		subjects = new subject[4];
	}
	student(int age, int grade, string name, float arabicscore, float englishscore, float mathsscore, float sciencescore)
	{
		this->age = age;
		this->grade = grade;
		this->name = name;
		subjects = new subject[4]{
			{"arabic",100,50,arabicscore},
			{"english",100,50,englishscore},
			{"maths",100,50,mathsscore},
			{"science",100,50,sciencescore},

		};
	}

	~student()
	{
		delete[] subjects;
	}
	void read(ifstream& in)
	{
		in >> age;
		in >> grade;
		int size;
		in >> size;
		char c;
		in.read(&c, 1);
		char* temp = new char[size + 1];
		in.read(temp, size);
		temp[size] = '\0';
		name = temp;
		delete[]temp;
		for (int i = 0; i < 4; i++)
		{
			subjects[i].read(in);
		}

	}
	void write(ofstream& out)
	{
		out << age << endl;
		out << grade << endl;
		out << name << endl;
		for (int i = 0; i < 4; i++)
		{
			subjects[i].write(out);
		}


	}


	float gettotalpercentage()
	{
		return ((subjects[0].score + subjects[1].score + subjects[2].score + subjects[3].score) * 100) / 400.0f;
	}








};




