#include <iostream>

class Fahrenheit
{
public:
  static double to_kelvin(double value)
  {
    return (value - 32) / 1.8 + 273.15;
  }
};

class Celsius
{
public:
  static double to_kelvin(double value)
  {
    return value + 273.15;
  }
};

class Kelvin
{
public:
  static double to_kelvin(double value)
  {
    return value;
  }
};

template <class T>
class Temperature
{
public:
  double kelvin;

  Temperature(double value)
  {
    kelvin = T::to_kelvin(value);
  }

  friend std::ostream &operator<<(std::ostream &os, const Temperature<T> &temperature)
  {
    os << temperature.kelvin << " K (kelvins)";
    return os;
  }
};

int main()
{
  std::cout << Temperature<Fahrenheit>(10.4) << std::endl;
  std::cout << Temperature<Celsius>(10.4) << std::endl;
  std::cout << Temperature<Kelvin>(10.4) << std::endl;
}