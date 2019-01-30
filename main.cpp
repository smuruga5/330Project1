/*
----------------------------------------------------------------------------------
Author Name: Sujjanaraj Muruganandam
Project    : CSE 330 Project1 Milestone
----------------------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[])
{
    ifstream file;//Creating a File
    string line;//String to read the input from File Line by Line
    int count;//Counter to keep track of Line
    int offset;//Variable to find the Word and its position
    int size=(sizeof argv[1]/8)-1;//Size of Word to be searched
    file.open(argv[2]);

    while(file)
    {
    getline(file,line);//Function to get Line

    count++;

    offset=line.find(argv[1],0);//Find function that returns the position of the word.

    int tell=file.tellg();//tellg function to get the total length of the Line

    int pos=offset;//Position Variable

    if((offset)!=string::npos)
    {
       cout<< argv[2]<<", "<<count<<", "<<offset<<", "<< (offset+size)<<": "<<argv[1]<<endl; //Displaying in the required Output Format

       pos=tell-offset; //To reset the Position
    }
    }
    return 0;
}
