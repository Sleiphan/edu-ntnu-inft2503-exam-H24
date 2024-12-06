#include <functional>
#include <iostream>
#include <memory>

using namespace std;

class Object
{
public:
  virtual ~Object() {}

  virtual function<double(double)> area_function() const = 0;
};

class Square : public Object
{
public:
  std::function<double(double)> area_function() const override
  {
    return [](double side_length)
    {
      return side_length * side_length;
    };
  }
};

class Circle : public Object
{
public:
  std::function<double(double)> area_function() const override
  {
    return [](double radius)
    {
      return 3.14 * radius * radius;
    };
  }
};
int main()
{

  vector<unique_ptr<Object>> objects;

  objects.emplace_back(new Square());
  objects.emplace_back(new Circle());

  for (auto &object : objects)
    cout << object->area_function()(2.) << endl;
}