//============================================================================
// Name        : Parralell.cpp
// Author      : Sujjanaraj Muruganandam
// Description : CSE 330 Project1 Final Serial Program
//============================================================================


#include <iostream>
#include <fstream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int NORMALsearch(string filename, string search_for)
{
	ifstream file;//Creating a File
	file.open(filename.c_str());
	string line;//Stores the line from the file.

	//Int Variables:
	int count = 0;//Counter to keep track of Line
	int offset;//Variable to find the Word and its position
	int size1 = search_for.size();//Stores the size of the search_for
	int pos = 0;//Stores the position of the search_for.


	while (file)
	{
		getline(file, line);//Function to get Line
		count++;//Counter to keep track of the line number.
		offset = line.find(search_for, 0);//Find function that returns the position of the search_for.
		int line_size = line.size();
		int local = 0;//Variable to store the location of the previous character found in the same line.

		//forloop for finding the same character that occurs more than once in a file.
		for (int i = 0; i < line_size; i++)
		{
			int tell = file.tellg();//tellg function to get the total length of the Line
			pos = offset + 1;//Position Variable
			if ((offset) != string::npos)
			{
				cout << filename << ", " << count << ", " << (pos) << ", " << (size1 + pos) - 1 << ": " << search_for << endl; //Displaying in the required Output Format
				local += pos + 1;
			}
			i += size1 + offset;
			offset = line.find(search_for,local);

		}
	}
	file.close();
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(END OF NORMALsearch)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(START OF STARsearch)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//This function is to finding the word if the * operator is present in the input.
int STARsearch(string filename, string word)
{
	ifstream file;//Creating a File
	file.open(filename.c_str());
	string line;
	int count = 0;//Counter to keep track of Line
	int offset;//Variable to find the Word and its position
	int size1 = word.size();
	int pos = 0;
	int counter = 0;
	int local = 0;


	while (file)
	{
		getline(file, line);//Function to get Line
		count++;//Counter to keep track of the line number.
		offset = line.find(word, 0);//Find function that returns the position of the search_for.
		int line_size = line.size();
		int local = 0;//Variable to store the location of the previous character found in the same line.

		//forloop for finding the same character that occurs more than once in a file.
		for (int i = 0; i < line_size; i++)
		{
			int tell = file.tellg();//tellg function to get the total length of the Line
			pos = offset + 1;//Position Variable
			if ((offset) != string::npos)
			{
				cout << filename << ", " << count << ", " << (pos) << ", " << (size1 + pos) - 1 << ": " << word << endl; //Displaying in the required Output Format
				local += pos + 1;
				counter++;
			}
			i += size1 + offset;
			offset = line.find(word, local);

		}
	}
	file.close();
	return counter;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(END OF STARsearch)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(START OF generate)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//Function to generate the words when the * operator is called.
void generate(string filename, string word)
{
	int num = 1;
	for (int j = 0; num!=0; j++)
	{
		      num = STARsearch(filename, word);//If the returned value is not a zero then continue or break
			word += word;
	}
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(end OF generate)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(START OF generate2)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void generate2(string filename, string word1, string word2)
{
	int i = 0;
	int c = 0;
	string sub;
	int size = word1.size();
	int num = 1;
	string f3;
	string f4;
	string n;
	string f1;
	string temp;
	int z = 0;


	for (int f = 0; f < word1.size(); f++)
	{
		c++;
		if (word1.at(f) == '+')
		{
		    f1 = word1.substr(i,c-1);
			c = 0;
			i = f + 1;
			for (int u = 0; u < word2.size(); u++)
			{
				if (word2.at(u) == '*')
				{
					z++;
					n=word2.substr(1);
					temp = n;
					f3 += f1+n;
					generate(filename,f3);
					generate(filename,n);
					n += f1;
				}
			}
			if (z == 0)
			{
				temp = word2;
				NORMALsearch(filename, (f1+temp));
			}
		}
		if ((f + 1) == size)
		{
			f3 = (word1.substr(i,c)) + temp;
			generate(filename,f3);
		}
	}

	for (int e = 0; e < word1.size(); e++)
	{
		if (word1.at(e) == '*')
		{
			string s = word1.substr(1);
			generate(filename,s);
			for (int h = 0; h < word2.size(); h++)
			{
				if (word2.at(h) == '*')
				{
					string d = word1.substr(1);
					generate(filename,d);
					break;

				}
			}
		}
	}
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(end OF generate2)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(START OF Process)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void process(string filename, string word)
{
	int count = 0;
	string f;

	for (int i = 0; i < word.size(); i++)
	{
		if (word.at(i) == '*')
		{
			generate(filename,word.substr(0,i));
		}
	}
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(end OF Process)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


int main(int store_size, char * store[])
{
	string name = store[1];
	int size = name.size();//Size of Word to be searched
	int check = 0;
	int i = 0;
	int c = 0;


		for (int h = 2; h < store_size; h++)
		{
			for (int n = 0; n < size; n++)//For Loop for finding (
			{
				if (name.at(n)=='(')
				{
					for (int j = n; j < size; j++)
					{
						if (name.at(j) == ')')
						{
							process(store[h], name.substr(n+1,j-1));
							generate2(store[h], name.substr(n+1, j-1), name.substr(j+1, size));
						}
					}
				}

			}


			for (int k = 0; k < size; k++)//For Loop for finding +
			{
				c++;
				if (name.at(k) == '+')
				{
					NORMALsearch(store[h], name.substr(i, c-1));
					c = 0;
					i = k+1;
					check++;
				}
				if ((k+1) == size)
				{
					NORMALsearch(store[h], name.substr(i, c));
					check++;
				}
			}

			for (int m = 0; m < size; m++)//For Loop for finding Star
			{
				if (name.at(m) == '*')
				{
					generate(store[h], name.substr(0, m));
					++check;
				}
			}

			if (check == 0)//Check if check=0 and proceed to call search for normal string.
			{
				NORMALsearch(store[h], name);
			}
		}
}
