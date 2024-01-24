#include <bits/stdc++.h>
using namespace std;

int getSumOfFirstAndLastDigits(string& input) {
    
    int n = input.size();
    int firstDigit = -1, lastDigit = -1;
    
    for(int i = 0; i < n; i++) {
        
        if(isdigit(input[i])) {
            
            if(firstDigit == -1) {
                firstDigit = input[i] - '0';
            }
            
            lastDigit = input[i] - '0';
        }
    }
    
    if(firstDigit == -1 || lastDigit == -1) {
        return -1;
    }
    
    return firstDigit + lastDigit;
}


int main()
{
    string input = "abc1def2ghi";
    
    int result = getSumOfFirstAndLastDigits(input);
    if(result == -1) {
        cout<<"There are no digits in the input string."<<endl;
    } else {
        cout<<"Sum of first and last digits is : "<<result<<endl;
    }
    
    return 0;
}

/*

----------------------------------------------------
                TEST CASES

Test Case 1 : A string with only one digit.

    input = "1"
    expected output : Sum of first and last digits is : 2

Test Case 2 : A string with no digits.

    input = "no digits here"
    expected output : There are no digits in the input string.

Test Case 3 : A string with only digits.

    input = "123456789"
    expected output : Sum of first and last digits is : 10

Test Case 4 : A string with digits and non-digits.

    input = "1a2b3c4d5e6f7g8h9i"
    expected output : Sum of first and last digits is : 10

Test Case 5 : A string with digits at the beginning and end.

    input = "1abc2def3"
    expected output : Sum of first and last digits is : 4

Test Case 6 : A string with digits in the middle.

    input = "abc1def2ghi"
    expected output : Sum of first and last digits is : 3

Test Case 7 : A string with digits and special characters.

    input = "!@#$%^&*()_+123"
    expected output : Sum of first and last digits is : 4

Test Case 8 : A string with only one character.

    input = "a"
    expected output : There are no digits in the input string.

--------------------------------------------------------

*/