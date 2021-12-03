#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>

using namespace std;


int task_one() {
  ifstream fin;
  fin.open("input.txt");

  string binary;
  vector<int> tmp1(12, 0);
  vector<int> tmp2(12, 0);
  while (fin >> binary) {
    for (int i = 0; i < binary.length(); i++) {
      if (binary[i] == '1') {
        tmp1[i]++;
      }
      else {
        tmp2[i]++;
      }
    }
  }
  fin.close();
  string gamma = "";
  string epsilon = "";
  for (int i = 0; i < tmp1.size(); i++) {
    if (tmp1[i] > tmp2[i]) {
      gamma += "1";
      epsilon += "0";
    }
    else {
      gamma += "0";
      epsilon += "1";
    }
  }

  int result = bitset<12>(gamma).to_ulong() * bitset<12>(epsilon).to_ulong();
  return result;
}



int main() {
  cout << "result of task one: " << task_one() << endl;
  return 0;
}