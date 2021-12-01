// Advent of Code 2021
// Day 1

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int task_one() {
  std::ifstream fin;
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


int main() {
  cout << "result of task one: " << task_one() << endl;


}