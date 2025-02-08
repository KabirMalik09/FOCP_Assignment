#include <iostream>
#include <cstring>  
using namespace std;

int main() {
    char str[100];  
    int i, length, flag = 0;
    int freq[256] = {0};  

    
    cout << "Enter any string: ";
    cin >> str;  

    length = strlen(str);

    
    for (i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            flag = 1;
            break;
        }
    }

    
    if (flag) {
        cout << str << " is NOT a palindrome." << endl;
    } else {
        cout << str << " is a palindrome." << endl;
    }

    
    for (i = 0; i < length; i++) {
        freq[(int)str[i]]++;  
    }

    
    for (i = 0; i < length; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || 
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            str[i] = '*';
        }
    }

    
    cout << "\nCharacter Frequencies:\n";
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << " -: " << freq[i] << endl;
        }
    }

    cout << endl;

    
    cout << "String after replacing vowels with '*' : " << str << endl;

    return 0;
}
