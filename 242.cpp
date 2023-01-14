#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

// Given std::string, return unordered map
// of unique characters, with character key
// representing character count in string
unordered_map<char, int> string_to_unordered_map(string s) {
    unordered_map<char, int> dictionary;
    bool character_is_present;
    for(int i = 0; i < s.size(); i++) {
        character_is_present = dictionary.count(s[i]);
        if(character_is_present) {
            dictionary[s[i]] = dictionary[s[i]] + 1;
        } else {
            dictionary.insert({s[i], 1});
        }
    }
    return(dictionary);
}

bool is_anagram(string s, string t) {
    // Confirm strings are same length
    if(s.size() != t.size()) {
        return false;
    }

    // Check for identical set of characters between
    // the two strings by loading the characters of one
    // into a dictionary, then confirming each character
    // comprising the other string is present in the dictionary.
    // Use a hash table for constant time dictionary functions  
    unordered_map<char, int> dictionary = string_to_unordered_map(s);

    // Confirm that each character in 2nd string is present in
    // dictionary (hash table) of 1st string
    bool character_is_present;
    for(int i = 0; i < t.size(); i++) {
        std::cout << t[i];
        character_is_present = dictionary.count(t[i]);
        if(!character_is_present) {
            return false;
        } else {
            dictionary[t[i]] = dictionary[t[i]] - 1;
            if(dictionary[t[i]] == 0) {
                dictionary.erase(t[i]);
            }
        }
        std::cout << std::endl;
    }
    return true;
}

int main(void) {
    std::string s = "rat";
    std::string t = "car";
    bool anagram = is_anagram(s, t);
    std::cout << "Is anagram: " << anagram << std::endl;
}