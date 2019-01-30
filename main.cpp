#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[])
{
    ifstream file;
    string line;
    int count;
    int offset;
    file.open(argv[2]);
    while(file)
    {

    getline(file,line);
    count++;
    if((offset=line.find(argv[1],0))!=string::npos)
    {
       cout<< argv[2]<<", "<<file.tellg()<<", "<<count<<": "<<argv[1]<<endl;
    }
    //cout<<line<<endl;

    }

    cout << "You have entered " << argc
         << " arguments:" << "\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    return 0;
}
