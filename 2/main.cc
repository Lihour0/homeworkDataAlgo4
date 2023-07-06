#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

class List {
private:
  std::array<int, 100> element;
  std::size_t size;

  friend std::ostream &operator << (std::ostream &lh, const List& list){
    std::for_each(list.element.begin(), list.element.begin() + list.size, [&](const auto i){lh<< i <<" ";});
    return lh;
  }

public:
  List(): size(0){};

void addItem(int item){
    if(size < element.size()){
      element[size++] = item;
    }

}
void deleteItem(int item){
    auto it = std::find(element.begin(), element.begin() + size, item);
    if(it != element.begin()+size){
      std::move(it + 1, element.begin() + size, it);
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
  k.addItem(1);
  k.addItem(3);
  k.addItem(4);
  k.addItem(2);
  std::cout<< k <<"\n";
  k.deleteItem(2);
  std::cout<< k <<"\n";
  k.updateItem(3,10);
  std::cout<< k <<"\n";
  k.getSearch(10);
  std::cout<< k.getSearch(10);
  std::cout<< k <<"\n";
}
