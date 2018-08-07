#include <iostream>
using namespace std;

int main() 
{
  char byte_arr[12] = {0};
  for (int i = 0; i < 12; ++i) {
    cout << byte_arr[i] << "0";
  }
  cout << "Hello, World!";
  return 0;
}
