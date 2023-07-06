#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(){
  const int N = 4;
  std::vector<int> vec(N);
  std::copy_n(std::istream_iterator<int>(std::cin), N, vec.begin());
  for(const auto i : vec){
    std::cout<<i;
  }
}


