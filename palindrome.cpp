#include <iostream>
using namespace std;

int substring(const string& str, int j, int k) {
  int count = 0;
  for (;j >= 0 && k < str.length(); --j, ++k) {
    if (str[j] != str[k]) {      
      break;
    } 
    cout << str.substr(j, k - j + 1) << endl;
    ++count;
  }
  return count;
}

int all_palindrome(const string& str) {
  int count = 0;
  for (int i = 0; i < str.length(); ++i) {    
    count += substring(str, i - 1, i + 1);
    count += substring(str, i, i + 1);
  }
  cout<<"Total no of Palindroms"<<endl;
  return  count;
}

int main() {
  string str;
  cout<<"Enter your Input"<<endl;
  cin>>str;

  cout << "Total palindrome substrings: \n"  << all_palindrome(str) << endl;
}