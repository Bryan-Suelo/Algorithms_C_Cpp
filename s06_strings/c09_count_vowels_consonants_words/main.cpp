#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "How Many Words";
    int vowels = 0, consonants = 0, words = 0;

    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == 'A' | str[i] == 'E' | str[i] == 'I' | str[i] == 'O' | str[i] == 'U' |
        str[i] == 'a' | str[i] == 'e' | str[i] == 'i' | str[i] == 'o' | str[i] == 'u'){
            vowels++;
        }
        else if (str[i] == ' '){
            words++;
        }
        else{
            consonants++;
        }
    }

    cout << "Vowels " << vowels << endl;
    cout << "Consonants " << consonants << endl;
    cout << "Words " << words+1 << endl;

    return 0;

}