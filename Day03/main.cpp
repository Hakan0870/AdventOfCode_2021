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

int task_two() {
  ifstream fin;
  fin.open("input.txt");

  string binary;
  string gamma = "";
  string epsilon = "";
  vector<string> inputs;
  vector<string> vector1;
  vector<string> vector2;

  while (fin >> binary) {
    inputs.push_back(binary);
  }
  size_t length = binary.size();

  vector1 = vector2 = inputs;
  int a, b;
  char flag;

  for (int i = 0; i < length; i++) {
    if (vector1.size() == 1) {
      break;
    }

    a = 0;
    b = 0;
    for (int j = 0; j < vector1.size(); j++) {
      if (vector1[j][i] == '1') {
        a++;
      }
      else {
        b++;
      }
    }
    if (a >= b) {
      flag = '1';
    }
    else {
      flag = '0';
    }

    vector<string> tmp1_vector;
    for (int j = 0; j < vector1.size(); j++) {
      if (vector1[j][i] == flag) {
        tmp1_vector.push_back(vector1[j]);
      }
    }
    vector1 = tmp1_vector;
  }

  for (int i = 0; i < length; i++) {
    if (vector2.size() == 1) {
      break;
    }

    a = 0;
    b = 0;
    for (int j = 0; j < vector2.size(); j++) {
      if (vector2[j][i] == '1') {
        a++;
      }
      else {
        b++;
      }
    }
    if (a < b) {
      flag = '1';
    }
    else {
      flag = '0';
    }

    vector<string> tmp2_vector;
    for (int j = 0; j < vector2.size(); j++) {
      if (vector2[j][i] == flag) {
        tmp2_vector.push_back(vector2[j]);
      }
    }
    vector2 = tmp2_vector;
  }

  int result = bitset<12>(vector1[0]).to_ulong() * bitset<12>(vector2[0]).to_ulong();
  return result;
}



int main() {
  cout << "result of task one: " << task_one() << endl;
  cout << "result of task two: " << task_two() << endl;

  return 0;
}