/*givn two string , print all th haratr whih ar in th first string but not in son string.
s1='RITAMBHARA'
S2='TECHNOLOGIES'

S1-S2=R,A,M,B
S2-S1=

US HASHMAP, HASHSET , FREQ ARRAY */

#include <iostream>
#include <string>
#include <unordered_set>

void printDifference(const std::string& s1, const std::string& s2) {
    std::unordered_set<char> set2(s2.begin(), s2.end());
    std::unordered_set<char> seen;

    for (char c : s1) {
        if (set2.find(c) == set2.end() && seen.find(c) == seen.end()) {
            seen.insert(c);
            std::cout << c;
        }
    }
    std::cout << "\n";
}

int main() {
    std::string s1 = "abcdef";
    std::string s2 = "bdfg";
    printDifference(s1, s2); // Output: ace
    return 0;
}