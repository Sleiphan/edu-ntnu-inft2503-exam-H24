#include <functional>
#include <iostream>
#include <vector>

class Find
{
public:
  std::function<bool(int)> predicate;
  Find(std::function<bool(int)> predicate) : predicate(predicate) {}
};

class Reduce
{
public:
  std::function<int(int, int)> op;
  int initial_value;
  Reduce(std::function<int(int, int)> reduce, int initial_value) : op(reduce), initial_value(initial_value) {}
};

const int *operator|(const std::vector<int> &vec, const Find &pred)
{
  for (const int &i : vec)
    if (pred.predicate(i))
      return &i;

  return (int *)0;
}

const int operator|(const std::vector<int> &vec, const Reduce &reduce)
{
  int previous_val = reduce.initial_value;

  for (const int &i : vec)
    previous_val = reduce.op(previous_val, i);

  return previous_val;
}

int main()
{
  using namespace std;

  // ### The untouchable zone ###
  vector<int> vec = {1, 2, 3};

  cout << *(vec | Find([](int value)
                       { return value > 1; }))
       << endl;
  cout << (vec | Find([](int value)
                      { return value == 5; }))
       << endl;

  cout << (vec | Reduce(
                     [](int previous_value, int current_value)
                     {
                       return previous_value + current_value;
                     },
                     0 /* initial value */))
       << endl;
  cout << (vec | Reduce(
                     [](int previous_value, int current_value)
                     {
                       return previous_value + 2 * current_value;
                     },
                     5 /* initial value */))
       << endl;
  // ### The untouchable zone ###

  return 0;
}