// Advent of Code 2021
// Day 1

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int task_one() {
  ifstream fin;
  fin.open("input.txt");

  int current_number, prev_number;
  int count = 0;

  fin >> prev_number;

  while (fin >> current_number) {
    if (current_number > prev_number) {
      count++;
    }
    prev_number = current_number;
  }
  fin.close();
  return count;
}

int task_two() {
  ifstream fin;
  fin.open("input.txt");

  std::vector<int> data;
  int num;
  while (fin >> num) {
    data.push_back(num);
  }
  fin.close();

  int current_total;
  int count = 0;
  int prev_total = data[0] + data[1] + data[2];

  for (int i = 1; i < data.size() - 2; i++) {
    current_total = 0;
    for (int j = 0; j < 3; j++) {
      current_total += data[i + j];
    }

    if (current_total > prev_total) {
      count++;
    }
    prev_total = current_total;
  }
  return count;
}


int main() {
  cout << "result of task one: " << task_one() << endl;
  cout << "result of task two: " << task_two() << endl;
}