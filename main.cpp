#include <iostream>
#include <chrono>
#include <ctime>
#include <list>
#define MAX_ELEMENTS 25000
using namespace std;

class Sort {
  private:
    int length;
    int randomArr[MAX_ELEMENTS];
  public:
    void play() {cout << "Hello";}
    void init_Array(int randomArr[]) {
      do {
      cout << "Enter number of elements in list (between 10 and 25000)";
      cin >> length;
      cout << endl;
      } while (length <= 10 and length >= 25000);
      srand((unsigned)time(0));
      for (int x = 0; x < length; x++) {
        randomArr[x] = (rand() % (2 * length));
        cout << randomArr[x] << endl;
      }
    }
};

// https://www.softwaretestinghelp.com/bubble-sort/
class Bubble : public Sort {
  public:
    void play() {
      cout << "---Bubble Play---" << endl;
      int arr[MAX_ELEMENTS];
      init_Array(arr);
    /*bool swapped = false;
      for ()
      */
  }
};
/// Notes: Compare [i] to [i+1], if i+1 > i keep in same position
/// if i+1 < i, shift index down,move i+1 to temp, move [i] to i+1.
///Keep running until selected > previous.
class Insertion : public Sort {
  public:
    void play() {
      cout << "---Insertion Play---" << endl;
      int arr[MAX_ELEMENTS];
      init_Array(arr);
      int hold[1] = {0};
      int i = 0;
      /*main algorithm for insertion*/
      while( arr[i+1] < arr[i] ){
          swap(hold[0], arr[i]); //moves val to hold, and hold to index i's pos.
          ///FIX: swap(arr[i-1].swap(hold); // swaps the hold with index i - 1's pos
          hold.swap(arr[i]); // swaps hold with index i's pos. Should have 0 in hold again.
          if (i == 1){
              break;
          }
      }
  }
};

class Merge : public Sort {
  public:
    void play() {
      cout << "---Merge Play---" << endl;
      int arr[MAX_ELEMENTS];
      init_Array(arr);
  }
};

class Quick : public Sort {
  public:
    void play() {
      cout << "---Quick Play---" << endl;
      int arr[MAX_ELEMENTS];
      init_Array(arr);
      /*int pivot;
      int midpoint = ql.size() / 2;
      int low = 0;
      int high = ql.size() - 1;
      bool done = false;
      while(!done) {
        while (low < midpoint) {
          low += 1;
        }
        while (high > midpoint) {
          high -= 1;
        }
        if (high >= low) {
          done = true;
        }
      }*/
    }
    /*void algorithm() {

    }*/
};

class Heap : public Sort {
  public:
    void play() {
      cout << "---Heap Play---" << endl;
      int arr[MAX_ELEMENTS];
      init_Array(arr);
    }
};

class Counting : public Sort {
  public:
    void play() {
      cout << "---Count Play---" << endl;
      int arr[MAX_ELEMENTS];
      init_Array(arr);
    }
};

class Radix : public Sort {
  public:
    void play() {
      cout << "---Radix Play---" << endl;
      int arr[MAX_ELEMENTS];
      init_Array(arr);
    }
};



typedef std::chrono::high_resolution_clock Clock;
int main() {
    auto t1 = Clock::now();
    Sort *bptr = new Sort;
    cout << "Enter the type of sorting algorithm you want to use" << endl;
    cout << "1: Bubble, 2: Insertion, 3: Merge, 4: Quick, 5: Heap, 6: Counting, 7: Radix" << endl;
    int decision;
    cin >> decision;
    if (decision == 1) {
      Bubble b;
      bptr = &b;
    }
    else if (decision == 2) {
      Insertion i;
      bptr = &i;
    }

    else if (decision == 3) {
      Merge m;
      bptr = &m;
    }

    else if (decision == 4) {
      Quick q;
      bptr = &q;
    }

    else if (decision == 5) {
      Heap h;
      bptr = &h;
    }

    else if (decision == 6) {
      cout << "6";
      Counting c;
      bptr = &c;
    }

    else {
      Radix r;
      bptr = &r;
    }
    bptr->play();
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
}
