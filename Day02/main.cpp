// Advent of Code 2021
// Day 2

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int task_one() {
  ifstream fin;
  fin.open("input.txt");

  string command;
  int value;
  int forward = 0;
  int depth = 0;

  while (fin >> command >> value) {
    if (command == "forward") {
      forward += value;
    } 
    else if (command == "down") {
      depth += value;
    }
    else {
      depth -= value;
    }
  }
  fin.close();
  int result = forward * depth;
  return result;
}

int task_two() {
  ifstream fin;
  fin.open("input.txt");

  string command;
  int value;
  int forward = 0;
  int depth = 0;
  int aim = 0;

  while (fin >> command >> value) {
    if (command == "forward") {
      forward += value;
      depth += aim * value;
    }
    else if (command == "down") {
      aim += value;
    }
    else {
      aim -= value;
    }
  }
  fin.close();
  int result = forward * depth;
  return result;
}


int main() {
  cout << "result of task one: " << task_one() << endl;
  cout << "result of task two: " << task_two() << endl;

  return 0;
}