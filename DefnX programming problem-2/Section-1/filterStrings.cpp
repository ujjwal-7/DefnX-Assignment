#include<bits/stdc++.h>
using namespace std;

vector<string> filterStrings(vector<string>& inputList, string& matchString) {
    
    unordered_set<char> matchSet(matchString.begin(), matchString.end());
    vector<string> resultList;

    for (string& word : inputList) {
        
        bool containsMatch = false;
        
        for (char ch : word) {
            
            if (matchSet.count(ch) > 0) {
                
                containsMatch = true;
                break;
            }
        }

        if (!containsMatch) {
            resultList.push_back(word);
        }
    }

    return resultList;
}

int main() {
    
    vector<string> argument1 = {"this", "place", "is", "an", "island"};
    string argument2 = "";
    
    vector<string> result = filterStrings(argument1, argument2);
    
    cout<<"[";
    for (string& word : result) {
        
        cout<<word<<" ";

    }
    cout<<"]";
    

    return 0;
}
/*

----------------------------------------------------
                TEST CASES

Test Case 1 : Test case with no matching characters

    Argument 1: {"this", "place", "is", an", "island"}
    Argument 2: "xyz"
    Expected output: [this place is an island ]

Test Case 2 : Test case with one matching character

    Argument 1: {"this", "place", "is", "an", "island"}
    Argument 2: "s"
    Expected output: [place an ]
    
Test Case 3 : Test case with multiple matching characters

    Argument 1: {"this", "place", "is", "an", "island"}
    Argument 2: "is"
    Expected output: [place an ]


Test Case 4 : Test case with empty list of strings:

    Argument 1: {}
    Argument 2: "xyz"
    Expected output: []

Test Case 5 : Test case with empty string to match against:

    Argument 1: {"this", "place", "is", "an", "island"}
    Argument 2: ""
    Expected output: [this place is an island ]

--------------------------------------------------------

*/
