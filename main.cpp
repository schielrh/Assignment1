#include <iostream>
#include <chrono>
#include <ctime>
#include <list>
#define MAX_ELEMENTS 25000
using namespace std;

//sort class creates an array with random numbers
class Sort {
  private:
    int length;
  public:
    virtual void play() = 0;

    void init_Array(int arr[]) {
      srand((unsigned)time(0));
      for (int x = 0; x < length; x++) {
        arr[x] = rand() % (2 * length);
        cout << arr[x] << endl;
      }
    }
    //getLength asks the user to select the number of elements for the list
    void getLength() {
      do {
      cout << "Enter number of elements in list (between 10 and 25000)";
      cin >> length;
      cout << endl;
      } while (length < 10 || length > 25000);
    }

    int ReturnLength() {
      return length;
    }
    //this function displays the sorted array
    void displayArray(int arr[]) {
        int n = ReturnLength();
        cout << "---SORTED ARRAY---" << endl;
        for (int i=0; i<n; ++i)
          cout << arr[i] << endl;
      }
};

// https://www.softwaretestinghelp.com/bubble-sort/
class Bubble : public Sort {
  public:
    void play() {
      cout << "---Bubble Play---" << endl;
      getLength();
      int l = ReturnLength();
      int arr[l];
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
      getLength();
      int l = ReturnLength();
      int arr[l];
      init_Array(arr);
      int hold[1] = {0};
      int i = 0;
      /*main algorithm for insertion*/
      while( arr[i+1] < arr[i] ){
          swap(hold[0], arr[i]); //moves val to hold, and hold to index i's pos.
          ///FIX: swap(arr[i-1].swap(hold); // swaps the hold with index i - 1's pos
          //hold.swap(arr[i]); // swaps hold with index i's pos. Should have 0 in hold again.
          if (i == 1){
              break;
          }
      }
  }
};

class Merge : public Sort {
  public:
    void merge(int arr[], int left, int middle, int right) {
      int i, j, k, nl, nr;
      //size of left and right sub-arrays
      nl = middle-left+1; 
      nr = right-middle;
      int leftArr[nl], rightArr[nr];
      //fill left and right sub-arrays
      for(i = 0; i<nl; i++)
        leftArr[i] = arr[left+i];
      for(j = 0; j<nr; j++)
        rightArr[j] = arr[middle+1+j];
      i = 0; j = 0; k = left;
      //marge temp arrays to real array
      while(i < nl && j<nr) {
        if(leftArr[i] <= rightArr[j]) {
          arr[k] = leftArr[i];
          i++;
        }
        else {
          arr[k] = rightArr[j];
          j++;
        }
        k++;
      }
      while(i<nl) {       //extra element in left array
        arr[k] = leftArr[i];
        i++; k++;
      }
      while(j<nr) {     //extra element in right array
        arr[k] = rightArr[j];
        j++; k++;
      }
    }

    void mergeSort(int arr[], int left, int right) {
      int m;
      if(left < right) {
        int m = left+(right-left)/2;
        // Sort first and second arrays
        mergeSort(arr, left, m);
        mergeSort(arr, m+1, right);
        merge(arr, left, m, right);
      }
    }

    void play() {
      cout << "---Merge Play---" << endl;
      getLength();
      int l = ReturnLength();
      int arr[l];
      init_Array(arr);
      mergeSort(arr, 0, l - 1);
      displayArray(arr);
  }
};

class Quick : public Sort {
  public:
    void play() {
      cout << "---Quick Play---" << endl;
      getLength();
      int l = ReturnLength();
      int arr[l];
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
      getLength();
      int l = ReturnLength();
      int arr[l];
      init_Array(arr);
      /*void heapify(int arr[], int n, int root) {
          int largest = root; // root is the largest element
          int l = 2*root + 1; // left = 2*root + 1
          int r = 2*root + 2; // right = 2*root + 2
  
          // If left child is larger than root
          if (l < n && arr[l] > arr[largest])
            largest = l;
  
          // If right child is larger than largest so far
            if (r < n && arr[r] > arr[largest])
              largest = r;
  
          // If largest is not root
          if (largest != root) {
            //swap root and largest
            swap(arr[root], arr[largest]);
  
            // Recursively heapify the sub-tree
            heapify(arr, n, largest);
          }
        }
  
      // implementing heap sort
      void heapSort(int arr[], int n) {
        // build heap
        for (int i = n / 2 - 1; i >= 0; i--)
          heapify(arr, n, i);
  
        // extracting elements from heap one by one
        for (int i=n-1; i>=0; i--) {
          // Move current root to end
          swap(arr[0], arr[i]);
  
          // again call max heapify on the reduced heap
          heapify(arr, i, 0);
        }
      } */
    }
};

class Counting : public Sort {
  public:
    void play() {
      cout << "---Count Play---" << endl;
      getLength();
      int l = ReturnLength();
      int arr[l];
      init_Array(arr);
      int max = arr[1];

      for(int i = 2; i<=l; i++) {
          if(arr[i] > max)
            max = arr[i];
      } //the max element from the array

      int output[l+1];
      int count[max+1];     //create count array (max+1 number of elements)
      
      for(int i = 0; i<=max; i++)
        count[i] = 0;     //initialize count array to all zero
  
      for(int i = 1; i <=l; i++) 
        count[arr[i]] += 1;     //increase number count in count array.
      cout << endl;
      for(int i = 1; i<=max; i++)
        count[i] += count[i-1];     //find cumulative frequency
      cout << endl;
      for(int i = l; i>=0; i--) {
        output[count[arr[i]]] = arr[i];
        count[arr[i]] -= 1; //decrease count for same numbers
      }
      cout << "---SORTED ARRAY---" << endl;
      for(int i = 1; i<=l; i++) {
        arr[i] = output[i]; //store output array to main array
        cout << arr[i] << endl;
      }
    }
};

class Radix : public Sort {
  public:
    void play() {
      cout << "---Radix Play---" << endl;
      getLength();
      int l = ReturnLength();
      int arr[l];
      init_Array(arr);
    }
};

/* PART 3, LINKED LIST OF STUDENTS 
-
-
-
-
-
*/

struct StudentData {
  string Firstname;
  string Lastname;
  int Mnumber;
};

class Students : public Sort {
  private:
    struct Node {
        StudentData data;
        Node *Next;
    };
    Node *head;
    Node *tail;
  public:
    void play() {
      cout << "Student Play" << endl;
      getLength();
      int l = ReturnLength();
      int x = 0;
      while (x < l) {
        Node *temp = new Node;
        StudentData student;
        cout << "Enter student Firstname" << endl;
        cin >> student.Firstname;
        cout << "Enter student Lastname" << endl;
        cin >> student.Lastname;
        cout << "Enter Student M number (WITHOUT THE M)" << endl;
        cin >> student.Mnumber;
        temp->data = student;
        temp->Next = NULL;
        if (head == NULL) {
          head = temp;
          tail = temp;
          tail->Next = NULL;
        }
        else {
          tail -> Next = NULL;
          tail = temp;
        }
        x += 1;
      }
    }
};

typedef std::chrono::high_resolution_clock Clock;
int main() {
    auto t1 = Clock::now();
    Sort *bptr;
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
    else if (decision == 7) {
      Radix r;
      bptr = &r;
    }
    else {
      Students s;
      bptr = &s;
    }
    bptr->play();
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
}
