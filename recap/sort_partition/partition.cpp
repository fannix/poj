/*
 * =====================================================================================
 *
 *       Filename:  partition.cpp
 *
 *    Description:  Sort a char array. We require the lower case char appear before space char and upper case char
 *    and the space chars appear before the upper chars.
 *
 *        Version:  1.0
 *        Created:  2011年04月14日 19时09分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

void print(char * s){
  cout << s << endl;
}
void swap(char *s, int left, int right){
  int temp = s[right];
  s[right] = s[left];
  s[left] = temp;
}

// Two runs of partition algorithm.
void sort(char * s){
  if (s == NULL)
    return;

  int len = strlen(s);
  int left = 0;
  int right = 0;

  // The logic is a little awkward heere. Please see the sort2 for
  // a cleaner one.
  for (; right < len; right++){
    if (islower(s[left]))
        left++;
    else if (islower(s[right])){
        swap(s, left++, right);
    }
  }

  right = left;

  for (; right < len; right++){
    if (isspace(s[left]))
        left++;
    else if (isspace(s[right])){
        swap(s, left++, right);
    }
  }
}

// Only one run of partition algorithm.
void sort2(char * s){

  if (s == NULL)
    return;
  int len = strlen(s);

  int left = 0;
  int middle = 0;
  int right = 0;
  for (; right < len; right++){
    if (isupper(s[right]))
      continue;
    else if (isspace(s[right]))
      swap(s, middle++, right);
    else{
      swap(s, middle, right);
      swap(s, left, middle);
      middle++;
      left++;
    }
  }

}


int main(){
  char s[100] = "AAAaaa   ";
  sort2(s);
  print(s);
  char s2[100] = "A A A a a a";
  sort2(s2);
  print(s2);
  char s3[100] = "aa A a A A";
  sort2(s3);
  print(s3);
  return 0;
}
