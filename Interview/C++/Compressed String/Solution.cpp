/*
Different compression techniques are used in order to reduce the size of the messages sent over the web. An algorithm is designed to compress a given string
by describing the total number of consecutive occurrences of each character next to it. For example, consider the string "abaasass". Group the consecutive
occurrence of each character:
-'a' occurs one time.
-'b' occurs one time.
-'a' occurs two times consecutively.
-'s' occurs one time.
-'a' occurs one time.
-'s' occurs two times consecutively.

If a character only occurs once, it is added to the compressed string. If it occurs consecutive times, the character is added to the string followed by an integer 
representing the number of consecutive occurrences. Thus the compressed form of the string is "aba2sas2".

Function Description:
The function must return the compressed form of the message.
compressedString has the following parameter(s):
    string message: a string

Returns:
    string: the compressed message

Constraints:
    -message[i] in ASCII[a-z]
    -|message| <= 10^5
*/

#include <iostream>
#include <string>
using namespace std;

string compressedString(string message) {
    string result = "";
    if (message.empty()) {
        return result;
    }
    int count = 1;
    for (int i=1; i<message.length(); ++i) {
        if (message[i] == message[i-1]) {
            ++count;
        }
        else {
            result += message[i-1];
            if (count > 1) {
                result += to_string(count);
            }
            count = 1;
        }
    }
    result += message[message.size()-1];
    if (count > 1) {
        result += to_string(count);
    }
    return result;
}

int main() {
    // g++ Solution.cpp -o Solution

    std::string message1 = "aabbccc";
    std::cout << compressedString(message1) << std::endl;

    std::string message2 = "a";
    std::cout << compressedString(message2) << std::endl;
    
    std::string message3 = "abbbbbbbbbbbb";
    std::cout << compressedString(message3) << std::endl;

    std::string message4 = "";
    std::cout << compressedString(message4) << std::endl;

    std::string message5 = "abc";
    std::cout << compressedString(message5) << std::endl;

    std::string message6 = "abbc";
    std::cout << compressedString(message6) << std::endl;
    
    std::string message7 = "abbcdefg";
    std::cout << compressedString(message7) << std::endl;
}
