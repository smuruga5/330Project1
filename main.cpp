//============================================================================
// Name        : CSE330.cpp
// Author      : Sujjanaraj Muruganandam
// Description : CSE 330 Project1 Milestone
//============================================================================


#include <iostream>
#include <fstream>
#include<string>
using namespace std;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(START OF NORMALsearch)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//This helper function is to search for the search_for and print it.
int NORMALsearch(string filename, string search_for)
{
     ifstream file;//Creating a File
     file.open(filename.c_str());
     string line;//Stores the line from the file.

     //Int Variables:
     int count=0;//Counter to keep track of Line
     int offset;//Variable to find the Word and its position
     int size1=search_for.size();//Stores the size of the search_for
     int pos=0;//Stores the position of the search_for.


     while(file)
    {
    getline(file,line);//Function to get Line
    count++;//Counter to keep track of the line number.
    offset=line.find(search_for,0);//Find function that returns the position of the search_for.
    int line_size=line.size();
    int local=0;//Variable to store the location of the previous character found in the same line.

    //forloop for finding the same character that occurs more than once in a file.
    for(int i=0;i<line_size;i++)
    {
    int tell=file.tellg();//tellg function to get the total length of the Line
    pos=offset+1;//Position Variable
    if((offset)!=string::npos)
    {
	cout<< filename<<", "<<count<<", "<<(pos+local)<<", "<< (size1+pos+local)-1<<": "<<search_for<<endl; //Displaying in the required Output Format
	local+=pos+1;
	pos=tell-offset;//To reset the Position
    }
    i+=size1+offset;
    line=line.substr((size1+offset),line.size()-1);
    offset=line.find(search_for,0);
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
    int count=0;//Counter to keep track of Line
    int offset;//Variable to find the Word and its position
    int size1=word.size();
    int pos=0;
    int counter=0;

    while(file)
    {
    getline(file,line);//Function to get Line
    count++;
    offset=line.find(word,0);//Find function that returns the position of the word.
    int tell=file.tellg();//tellg function to get the total length of the Line
    pos=offset+1;//Position Variable
    if((offset)!=string::npos)
    {
    cout<< filename<<", "<<count<<", "<<pos<<", "<< (size1+pos)-1<<": "<<word<<endl; //Displaying in the required Output Format
    pos=tell-offset;//To reset the Position
    counter++;
    }
    }
    file.close();
    return counter;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(END OF STARsearch)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(START OF generate)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//Function to generate the words when the * operator is called.
void generate(string filename,string word)
{
    for(int j=0;j<100;j++)
    {
    int num =STARsearch(filename,word);//If the returned value is not a zero then continue or break
    if(num==0)
    break;
    else
    word+=word;
    }
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(end OF generate)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^MAIN FUNCTION^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
int main(int store_size, char * store[])
{
    string name= store[1];
    int size= name.size();//Size of Word to be searched
    int check=0;
    int i=0;


    for(int h=2;h<store_size;h++)
    {
    	for(int k=0;k<size;k++)//For Loop for finding +
    	   {
    	   if(name.at(k)=='+')
    	   {
    	   NORMALsearch(store[h],name.substr(i,k));
    	   NORMALsearch(store[h],name.substr(k+1,size-1));
    	   i=k;
    	   check++;
    	   }
    	   if(name.at(k)=='\0')
    	   {
    	   NORMALsearch(store[h],name.substr(i,k));
    	   }
    	   }

    	   for(int m=0;m<size;m++)//For Loop for finding Star
    	   {
    	   if (name.at(m)=='*')
    	   {
    	   generate(store[h], name.substr(0,m));
    	   ++check;
    	   }
    	   }

    	   if(check==0)//Check if check=0 and proceed to call search for normal string.
    	   {
    	   NORMALsearch(store[h],name);
    	   }
    }
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^END OF PROGRAM^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//============================================================================
// Name        : CSE330.cpp
// Author      : Sujjanaraj Muruganandam
// Description : CSE 330 Project1 Milestone
//============================================================================


#include <iostream>
#include <fstream>
#include<string>
using namespace std;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(START OF NORMALsearch)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//This helper function is to search for the search_for and print it.
int NORMALsearch(string filename, string search_for)
{
     ifstream file;//Creating a File
     file.open(filename.c_str());
     string line;//Stores the line from the file.

     //Int Variables:
     int count=0;//Counter to keep track of Line
     int offset;//Variable to find the Word and its position
     int size1=search_for.size();//Stores the size of the search_for
     int pos=0;//Stores the position of the search_for.


     while(file)
    {
    getline(file,line);//Function to get Line
    count++;//Counter to keep track of the line number.
    offset=line.find(search_for,0);//Find function that returns the position of the search_for.
    int line_size=line.size();
    int local=0;//Variable to store the location of the previous character found in the same line.

    //forloop for finding the same character that occurs more than once in a file.
    for(int i=0;i<line_size;i++)
    {
    int tell=file.tellg();//tellg function to get the total length of the Line
    pos=offset+1;//Position Variable
    if((offset)!=string::npos)
    {
	cout<< filename<<", "<<count<<", "<<(pos+local)<<", "<< (size1+pos+local)-1<<": "<<search_for<<endl; //Displaying in the required Output Format
	local+=pos+1;
	pos=tell-offset;//To reset the Position
    }
    i+=size1+offset;
    line=line.substr((size1+offset),line.size()-1);
    offset=line.find(search_for,0);
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
    int count=0;//Counter to keep track of Line
    int offset;//Variable to find the Word and its position
    int size1=word.size();
    int pos=0;
    int counter=0;

    while(file)
    {
    getline(file,line);//Function to get Line
    count++;
    offset=line.find(word,0);//Find function that returns the position of the word.
    int tell=file.tellg();//tellg function to get the total length of the Line
    pos=offset+1;//Position Variable
    if((offset)!=string::npos)
    {
    cout<< filename<<", "<<count<<", "<<pos<<", "<< (size1+pos)-1<<": "<<word<<endl; //Displaying in the required Output Format
    pos=tell-offset;//To reset the Position
    counter++;
    }
    }
    file.close();
    return counter;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(END OF STARsearch)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(START OF generate)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//Function to generate the words when the * operator is called.
void generate(string filename,string word)
{
    for(int j=0;j<100;j++)
    {
    int num =STARsearch(filename,word);//If the returned value is not a zero then continue or break
    if(num==0)
    break;
    else
    word+=word;
    }
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$(end OF generate)$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^MAIN FUNCTION^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
int main(int store_size, char * store[])
{
    string name= store[1];
    int size= name.size();//Size of Word to be searched
    int check=0;
    int i=0;


    for(int h=2;h<store_size;h++)
    {
    	for(int k=0;k<size;k++)//For Loop for finding +
    	   {
    	   if(name.at(k)=='+')
    	   {
    	   NORMALsearch(store[h],name.substr(i,k));
    	   NORMALsearch(store[h],name.substr(k+1,size-1));
    	   i=k;
    	   check++;
    	   }
    	   if(name.at(k)=='\0')
    	   {
    	   NORMALsearch(store[h],name.substr(i,k));
    	   }
    	   }

    	   for(int m=0;m<size;m++)//For Loop for finding Star
    	   {
    	   if (name.at(m)=='*')
    	   {
    	   generate(store[h], name.substr(0,m));
    	   ++check;
    	   }
    	   }

    	   if(check==0)//Check if check=0 and proceed to call search for normal string.
    	   {
    	   NORMALsearch(store[h],name);
    	   }
    }
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^END OF PROGRAM^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
