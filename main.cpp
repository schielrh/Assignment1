#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

class Sort {
  private:
    int length;
  public:
    void play() {}
    void init_List() {
      cout << "Enter number of elements in list: ";
      cin >> length;
      cout << endl;
      int randomList[length];
      srand((unsigned)time(0));
      for (int x = 0; x < length; x++) {
        randomList[x] = (rand() % (2 * length));
      }
    }
};

class Bubble : public Sort {

};

class Insertion : public Sort {

};

class Head : public Sort {

};

class Merge : public Sort {

};



typedef std::chrono::high_resolution_clock Clock;
int main() {
    auto t1 = Clock::now();
    int length;
    cout << "Enter number of elements in list: ";
    cin >> length;
    cout << endl;
    srand((unsigned)time(0));
    int randomList[length];
    for (int x = 0; x < length; x++) {
      randomList[x] = (rand() % (2 * length));
      cout << randomList[x] << ", ";
    }
    cout << endl;
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
}
