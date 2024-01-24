#include <bits/stdc++.h>
using namespace std;

string decimalToBase(int decimalNumber, int base) {

    if(decimalNumber == 0) {
        return "0";
    }

    string result = "";
    
    while (decimalNumber > 0) {
        
        int remainder = decimalNumber % base;
        
        if (remainder < 10) {
            result = char(remainder + '0') + result;
        } else {
            result = char(remainder - 10 + 'A') + result;
        }
        
        decimalNumber /= base;
    }
    return result;
}

int main() {
    
    int decimalNumber = 987654321;
    int base = 8;

    if(base == 0) {
        cout<<"Base cannot be zero"<<endl;
    } else {
        cout<<decimalToBase(decimalNumber, base)<<endl;
    }
    
    return 0;
}

/*

----------------------------------------------------
                TEST CASES

Test Case 1 : decimalNumber = 42   base = 2  expected output: 101010

Test Case 2 : decimalNumber = 987654321  base = 8  expected output: 7267464261

Test Case 3 : decimalNumber = 1234   base = 16  expected output: 4D2

Test Case 4 : decimalNumber = 123456789   base = 36  expected output: 21I3V9

Test Case 5 : decimalNumber = 1234   base = 20  expected output: 31E


--------------------------------------------------------

*/