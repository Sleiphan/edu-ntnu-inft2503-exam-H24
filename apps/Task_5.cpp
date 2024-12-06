#include <iostream>
#include <thread>
#include <vector>

int main()
{
  std::vector<std::thread> threads;
  for (int a = -1; a < 9; ++a)
  {
    threads.emplace_back([b = a + 1]
                         { std::cout << b; });
  }

  for (std::thread &t : threads)
    t.join();

  std::cout << std::endl;
}