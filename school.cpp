#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
#include"subjects.h"
#include"student.h"
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int count;
	in >> count;
	student* students = new student[count];
	for (int i = 0; i < count; i++)
	{
		students[i].read(in);
	}
	for (int i = 0; i < count; i++)
	{

		out << students[i].name << " with age " << students[i].age << " has get " << students[i].gettotalpercentage() << " percentage" << endl;
	
	}
	delete[] students;
	return 0;
}