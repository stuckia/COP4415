// C++ program to check for balanced brackets.

#include <bits/stdc++.h>
using namespace std;

// Function to check if brackets are balanced
int areBracketsBalanced(string expr) {
  // Declare a stack to hold the previous brackets.
  stack<char> temp;
  // track working index of last added bracket
  int index = 0;
  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] != '(' && expr[i] != ')' && expr[i] != '{' && expr[i] != '}' &&
        expr[i] != '[' && expr[i] != ']') {
      // if not a bracket, skip to next iteration
      continue;
    } else if (expr[0] == ')' || expr[0] == '}' || expr[0] == ']' ||
               expr.length() == 1) {
      // size of one character or starting with closed bracket immediately means
      // it fails push ensures that "success" condition will not trigger
      temp.push(expr[i]);
      break;
    } else if ((temp.top() == '(' && expr[i] == ')') ||
               (temp.top() == '{' && expr[i] == '}') ||
               (temp.top() == '[' && expr[i] == ']')) {
      // If we found any complete pair of bracket
      // then pop
      temp.pop();
    } else {
      index = i;
      temp.push(expr[i]);
    }
  }
  if (temp.empty()) {
    // If stack is empty return true
    return 0;
  }
  return index + 1;
}

// Driver code
int main() {
  string expr = "{[";

  // Function call
  if (areBracketsBalanced(expr) == 0)
    cout << "Success" << endl;
  else
    cout << areBracketsBalanced(expr) << endl;
  return 0;
}
