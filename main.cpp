#include "Coin.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int returnFunction(int input);
void fizzBuzz(int input);

int main(int argc, char* argv[])
{
  FindCoin fc;
  std::cout << returnFunction(-10) << "\n";
  std::cout << returnFunction(0) << "\n";
  std::cout << returnFunction(10) << "\n";

  fizzBuzz(3);
  fizzBuzz(15);

  std::vector<Coin> coins;
  for (size_t i = 1; i <= 12; i++)
  {
    coins.push_back({"M" + std::to_string(i), 10});
  }

  int fakeIndex = 6;
  bool isHeavy = false;
  coins[fakeIndex].weight = isHeavy ? 11 : 9;

  std::vector<Coin*> coin_ptr;
  for (size_t i = 0; i < coins.size(); i++)
  {
    coin_ptr.push_back(&coins[i]);
  }
  
  fc.find_fake_coin(coin_ptr);

  return 0;
}

int returnFunction(int input)
{
  return (input > 0) - (input < 0);
}

void fizzBuzz(int input)
{
  std::stringstream ss;
  ss<< input;
  std::string str = ss.str();
  for (size_t i = 0; i < str.size(); i++)
  {
    if (str[i] == '3')
    {
      std::cout << "Fizz" << "\n";
    }
    else if (str[i]== '5')
    {
      std::cout << "Buzz" << "\n";
    }
  }

  if (input % 3 == 0 && input % 5 == 0)
  {
    std::cout << "FizzBuzz" << "\n";
  }
  else if (input % 5 == 0)
  {
      std::cout << "Buzz" << "\n";
  }
  else if (input % 3 == 0)
  {
      std::cout << "Fizz" << "\n";
  }
}    
