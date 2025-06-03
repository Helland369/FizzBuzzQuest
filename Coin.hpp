#include <string>
#include <vector>


struct Coin
{
  std::string name;
  int weight;
};   

class FindCoin
{
public:
  FindCoin();
  ~FindCoin();

  std::string weigh(const std::vector<Coin*>& left, const std::vector<Coin*>& right);

  void find_fake_coin(std::vector<Coin*>& coins);
};

