#include<iostream>
using namespace std;

/* 
    Display grades for student marks
*/
void display_grades(int m1, int m2, int m3){
    int total;
    float avg;

    total = m1 + m2 + m3;
    avg = total / 3.0;

    if (avg >= 60){
        cout<< 'A' <<endl;
    }
    else if (avg >= 35 && avg < 60){
        cout<< 'B' <<endl;
    }
    else{
        cout<< 'C' <<endl;
    }
}

int main(){
    int m1,m2,m3;

    cout<< "Enter marks of 3 subjects: " <<endl;
    cin>>m1>> m2>> m3;
    display_grades(m1, m2, m3);

    return 0;
}