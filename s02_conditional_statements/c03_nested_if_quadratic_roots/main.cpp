#include<iostream>
#include<cmath>
using namespace std;

/* 
    Find nature of quadratic roots
*/

void roots(float a, float b, float c){
    float d, r1, r2;

    d = b * b - 4 * a * c;

    if (d == 0){
        cout<< "Roots are real and equal " <<endl;
        cout<< "r1 and r2: "<< -b / (2 * a);
    }
    else if (d > 0){
        cout<< "Roots are real and unequal" <<endl;
        cout<< "r1: " << (-b + sqrt(d)) / (2 * a) << endl;
        cout<< "r2: " << (-b - sqrt(d)) / (2 * a) << endl;
    }
    else{
        cout<< "Imaginary" <<endl;
    }
}

int main(){
    float a,b,c;

    cout<< "Enter a,b and c" <<endl;
    cin>> a>> b>> c;

    roots(a, b, c);

    return 0;
}