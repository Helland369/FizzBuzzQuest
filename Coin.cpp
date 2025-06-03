#include "Coin.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

FindCoin::FindCoin() {}

FindCoin::~FindCoin() {}

std::string FindCoin::weigh(const std::vector<Coin*>& left, const std::vector<Coin*>& right)
{
  int lw = 0, rw = 0;
  for (auto c : left) lw += c->weight;
  for (auto c : right) rw += c->weight;

  if (lw == rw) return "balanced";
  return (lw > rw) ? "left" : "right";
}    

void FindCoin::find_fake_coin(std::vector<Coin*>& coins)
{
  std::string res1 = weigh({ coins[0], coins[1], coins[2], coins[3] },
                           { coins[4], coins[5], coins[6], coins[7] });

  std::cout << "First weighing: " << res1 << "\n";

  if (res1 == "balanced")
  {
    std::string res2 = weigh({ coins[8], coins[9], coins[10] },
                             { coins[0], coins[1], coins[2] });

    std::cout << "Second weighing: " << res2 << "\n";

    if (res2 == "balanced")
    {
      std::string res3 = weigh({ coins[11] }, { coins[0] });
      std::cout << "Third weighing: " << res3 << "\n";
      std::cout << coins[11]->name << " is fake and " << ((res3 == "left") ? "heavy" : "light") << ".\n";
    }
    else
    {
      std::string res3 = weigh({ coins[8] }, { coins[9] });
      std::cout << "Third weighing: " << res3 << "\n";

      if (res3 == "balanced")
      {
        std::cout << coins[10]->name << " is fake and " << ((res2 == "left") ? "heavy" : "light") << ".\n";
      }
      else if ((res2 == "left" && res3 == "left") || (res2 == "right" && res3 == "right"))
      {
        std::cout << coins[8]->name << " is fake and heavy.\n";
      }
      else
      {
        std::cout << coins[9]->name << " is fake and light.\n";
      }
    }
  }
  else
  {
    std::string res2 = weigh({ coins[0], coins[1], coins[4] },
                             { coins[2], coins[5], coins[8] });

    std::cout << "second weighing: " << res2 << "\n";

    if (res2 == "balanced")
    {
      std::string res3 = weigh({ coins[3] }, { coins[8] });
      std::cout << "Third weighing: " << res3 << "\n";

      if (res3 == "balanced")
      {
        std::string res4 = weigh({ coins[7] }, { coins[8] });
        std::cout << coins[7]->name << " is fake and " << ((res4 == "left") ? "heavy" : "Light") << ".\n";
      }
      else
      {
        std::cout << coins[3]->name << " is fake and " << ((res3 == "left") ? "heavy" : "light") << ".\n";
      }
    }
    else if (res1 == "left")
    {
      if (res2 == "left")
      {
        std::cout << coins[0]->name << " is fake and heavy." << "\n";
      }
      else if (res2 == "right")
      {
        std::cout << coins[5]->name << " is fake and light." << "\n";
      }
      else
      {
        std::string res3 = weigh({ coins[6] }, { coins[8] });
        std::cout << coins[6]->name << " is fake and " << ((res3 == "left") ? "heavy" : "light") << ".\n";
      }
    }
    else
    {
      if (res2 == "right")
      {
        std::cout << coins[0]->name << " is fake and light." << "\n";
      }
      else if (res2 == "left")
      {
        std::cout << coins[5]->name << " is fake and heavy." << "\n";
      }
      else
      {
        std::string res3 = weigh({ coins[6] }, { coins[8] });
        std::cout << coins[6]->name << " is fake and " << ((res3 == "left") ? "light" : "heavy") << ".\n";
      }
    }
  }
}
