#include <iostream>

using namespace std;

public:
    void search()
    {

    }
int main(int argc, string argv[])
{
    fstream file;//Creating a file
    file.open(argv[2]);//Opening the file

    //Check for correct input format in the Command Line
    if(argc!=3)
    {
        cout<<"Usage: search.exe <text> <filename>\n";
        return -1;
    }

    //Check is the file contains anything
    if(!file)
    {
        cout<<"Failed to open file";
        return 0;
    }

    string sent;//String for storing the line
    string sent2;//String for storing the second string if Union is present
    int count=1;//Variable to keep track of the line count

    while(getline(file, sent))
    {
        for(int i=0;i<sent.length();i++)
        {
            if(sent.at(i)==argv[1].at(0))
            {

                for(int j=0;j<argv[1].length();j++}
                {
                if(argv[1].at(j)=="+")
                {
                  sent2=argv[1].substr(j+1,argv[1].length()-1);

                }
                if(sent.at(j)==argv[1].at(j))
                {
                    cout<<argv[2]<<", "<<count<<", "<<i<<", "<<j<<": "<<argv[1]<<endl;
                }
                }
            }
        }

    }



}
