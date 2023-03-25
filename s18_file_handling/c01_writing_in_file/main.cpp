#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ofstream ofs("Newfile.txt", ios::trunc);
    
    ofs << "Name \t Age \t Subject" << endl;
    ofs << "Bryan \t";
    ofs << 26;
    ofs << "\t Mechanics" << endl;

    ofs.close();
}