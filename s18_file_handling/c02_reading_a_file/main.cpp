#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream ifs;
    ifs.open("../c01_writing_in_file/Newfile.txt");

    if(ifs)/*ifs.is_open()*/ 
    {
        cout << "File is opened" << endl;
    }

    string header;
    string name;
    string age;
    string subject;

    ifs >> header >> name >> age >> subject;

    ifs.close();

    cout << header << " " << name << " " << age<< endl;
    cout << subject;
}