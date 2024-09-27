#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Create a class to handle the Longest Common Substring calculation and display
class LongestCommonSubstring {
private:
    string str1, str2;  // Two input strings
    vector<vector<int>> lookupTable;  // 2D lookup table
    string longestSubstring;  // Longest common substring
    int maxLength;  // Length of the longest common substring

public:
    // Constructor to initialize the strings
    LongestCommonSubstring(string s1, string s2) : str1(s1), str2(s2), maxLength(0) {
        // Initialize the lookup table with zeros
        lookupTable.resize(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    }

    // Function to calculate the longest common substring
    void calculateLCS() {
        int rowIndex = 0, colIndex = 0;

        for (int i = 1; i <= str1.length(); ++i) {
            for (int j = 1; j <= str2.length(); ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1;

                    if (lookupTable[i][j] > maxLength) {
                        maxLength = lookupTable[i][j];
                        rowIndex = i;
                        colIndex = j;
                    }
                } else {
                    lookupTable[i][j] = 0;
                }
            }
        }

        // Extract the longest common substring from str1 using the indices
        longestSubstring = str1.substr(rowIndex - maxLength, maxLength);
    }

    // Function to display the lookup table
    void displayLookupTable() {
        cout << "Lookup Table:" << endl;
        cout << "   ";
        for (int j = 0; j <= str2.length(); ++j) {
            if (j == 0)
                cout << "  ";
            else
                cout << str2[j - 1] << " ";
        }
        cout << endl;

        for (int i = 0; i <= str1.length(); ++i) {
            if (i == 0)
                cout << "  ";
            else
                cout << str1[i - 1] << " ";
            
            for (int j = 0; j <= str2.length(); ++j) {
                cout << lookupTable[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to display the result
    void displayResult() {
        cout << "Longest Common Substring: " << longestSubstring << endl;
        cout << "Length of Longest Common Substring: " << maxLength << endl;
    }
};

// Main function
int main() {
    string str1, str2;

    // Input two strings
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    // Create an object of the LongestCommonSubstring class
    LongestCommonSubstring lcs(str1, str2);

    // Calculate the longest common substring
    lcs.calculateLCS();

    // Display the lookup table
    lcs.displayLookupTable();

    // Display the result
    lcs.displayResult();

    return 0;
}
