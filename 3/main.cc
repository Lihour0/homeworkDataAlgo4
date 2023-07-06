#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

class List {
private:
  std::vector<int> element;
  std::size_t size;

  friend std::ostream &operator << (std::ostream &lh, const List& list){
    std::for_each(list.element.begin(), list.element.begin() + list.size, [&](const auto i){lh<< i <<" ";});
    return lh;
  }

public:
  List(): size(0){};
 int getSize(){
    return this->size;
  }

void addItem(int item){
    element.push_back(item);
    ++size;
}
void deleteItem(int item){
    auto it = std::find(element.begin(), element.begin() + size, item);
    if(it != element.begin()+size){
      element.erase(it);
      --size;
    }
}

void updateItem(int oldItem,int item){
    auto it = std::find(element.begin(), element.begin() + size, oldItem);
    if(it != element.begin() + size){
      *it = item;
    }
}

int getSearch(int item){
    auto it = std::find(element.begin(), element.begin() + size, item);
    if(it != element.begin() + size){
        int a =  std::distance(element.begin(),it);
        return a;
    }else {
      return -1;
    }
  }
};
int main(){
  List k;
  k.addItem(10);
  k.addItem(4);
  k.addItem(1023);
  k.addItem(3423);
  std::cout<<k.getSize()<< "\n";
  std::cout<< k <<"\n";
  k.deleteItem(3423);
  std::cout<< k <<"\n";
  k.updateItem(1023,1012312);
  std::cout<< k <<"\n";
  std::cout<<k.getSearch(1012312)<< "\n";
  std::cout<< k <<"\n";
  std::cout<<k.getSize()<< "\n";
}
