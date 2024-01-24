#include <bits/stdc++.h>
using namespace std;

string sumOfTwoLargeNumbers(string num1, string num2) {
    
    num1.erase(0, min(num1.find_first_not_of('0'), num1.size()-1));
    num2.erase(0, min(num2.find_first_not_of('0'), num2.size()-1));

    int i = num1.size() - 1;
    int j = num2.size() - 1;
    
    int carry = 0;
    string result = "";
    
    while(i>=0 || j>=0 || carry){
        
        long sum = 0;
        
        if(i >= 0){
            sum += (num1[i] - '0');
            i--;
        }
        
        if(j >= 0){
            sum += (num2[j] - '0');
            j--;
        }
        
        sum += carry; 
        
        carry = sum / 10;
        
        sum = sum % 10;
        
        result =  result + to_string(sum);
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}


int main()
{
    string num1 = "abc1def2ghi";
    string num2 = "Asdfjasf";
    
    string result = sumOfTwoLargeNumbers(num1, num2);
    
    cout<<result<<endl;
    
    return 0;
}


/*

----------------------------------------------------
                TEST CASES

Test Case 1 :

    num1 = "12345678901234567890123456789012345678901234567890"
    num2 = "98765432109876543210987654321098765432109876543210"
    expected output : 111111111011111111101111111110111111111011111111100

Test Case 2: 

    num1 = "98765432109876543210987654321098765432109876543210"; 
	num2 = "0"; 
    expected output : 98765432109876543210987654321098765432109876543210

Test Case 3 :  

    num1 = "0"
    num2 = "0"
    expected output : 0

Test Case 4: 

    num1 = "000003456789012345678901234567890"
    num2 = "004321098765432109876543210"
    expected output : 3461110111111111011111111100

--------------------------------------------------------

*/
