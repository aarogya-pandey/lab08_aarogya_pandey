// lab08 - strFuncs.cpp
// Aarogya Pandey
// June 4th, 2020

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "strFuncs.h"
using namespace std;


/* Precondition: Two valid strings s1 and s2, each containing a mix of alphabets, spaces and punctuations
 * Post condition: Return true if one string is an anagram of the other string. White spaces, punctuations and
 * the case for the letters (upper or lower) should not
 * affect your result. 
 */
bool isAnagram(string s1, string s2) {
  int length1 = s1.length();
  int length2 = s2.length();

  for (int i = 0; i <length1; i++) {
    if (isupper(s1[i]))
      s1[i] = tolower(s1[i]);
  }
  for (int i = 0; i < length2; i++) {
    if (isupper(s2[i]))
      s2[i] = tolower(s2[i]);
  }

  string count1 = "";
  string count2 = "";
  for (int i = 0; i <length1; i++) {
    if (isalpha(s1[i]) && !isspace(s1[i]) && !ispunct(s1[i]))
      count1 = count1 + s1[i];
  }
  for (int i = 0; i <length2; i++) {
    if (isalpha(s2[i]) && !isspace(s2[i]) && !ispunct(s2[i]))
      count2 += s2[i];
  }

  int lengthc1 = count1.length();
  int lengthc2 = count2.length();
  if (lengthc1 != lengthc2) {
    return false;
  }

  sort(count1.begin(), count1.end());
  sort(count2.begin(), count2.end());

  for (int i = 0; i <lengthc1; i++) {
    if (count1[i] != count2[i])
      return false;
  }
  return (count1 == count2);
}

/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 *You should provide a recursive solution*/
bool isPalindrome(const string s1){
  int length = s1.length();
  string count = "";
  for (int i = 0; i < length; i++) {
    if (isalpha(s1[i]) && !isspace(s1[i]) && !ispunct(s1[i]))
      count += s1[i];
  }

  for (int i = 0; i < length; i++) {
    if (isupper(count[i])) {
      count[i] = tolower(count[i]);
    }
  }

  int first = 0;
  int last = count.length() -1;
  if (count.length() == 0)
    return true;
  else if (count[first] != count[last])
    return false;

  for (int i = 0; i < last; i++) {
    if (count[i] != count[last-i])
      return false;
  }
  return true;
}


