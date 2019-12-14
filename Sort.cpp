#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;


class Sort
{
public:
  void bubbleSort(double myArr[], int num);
  void selectionSort(double myArr[], int num);
  void insertionSort(double myArr[], int num);
  void quickSort(double myArr[], int min, int max);
  int partition(double myArr[], int min, int max);
};

void Sort::bubbleSort(double myArr[], int num)
{
  bool finish = true; // check for recursive method
  for(int i = 0; i < num; ++i)
  {
    double temp = 0.0;
    for(int j = i; j < num; ++j)
    {
      if(myArr[j] > myArr[j+1])
      {
        temp = myArr[j+1];
        myArr[j+1] = myArr[j]; // swapping
        myArr[j] = temp;
      }
    }
  }
  for(int i = 0; i < num; ++i) // recursive check
  {
    if(myArr[i] > myArr[i+1])
    {
      finish = false;
      bubbleSort(myArr, num);
    }
  }
}

void Sort::selectionSort(double myArr[], int num)
{
  int i, j, min;
  double temp;
  for(i = 0; i < num-1; i++)
  {
    min = i;
    for(j = i+1; j < num; j++)
    {
      if(myArr[j] < myArr[min])
      {
        min = j;
      }
    }
    if(min!= i)
    {
      temp = myArr[i];
      myArr[i] = myArr[min]; // swapping
      myArr[min] = temp;
    }
  }
}

void Sort::insertionSort(double myArr[], int num)
{
  for(int j = 1; j < num; ++j)
  {
    double temp;
    int k = j;
    while(k>0 && myArr[k-1] >= temp)
    {
      myArr[k] = myArr[k-1];
      --k;
    }
    myArr[k] = temp;
  }
}
int Sort::partition(double myArr[], int min, int max)
{
  double pivot = myArr[max];
  double temp;
  int i = min-1;
  for(int j = min; j < max-1; j++)
  {
    if(myArr[j] < pivot)
    {
      i++;
      temp = myArr[i];
      myArr[j] = myArr[i]; // swapping
      myArr[i] = temp;
    }
  }
  temp = myArr[max];
  myArr[max] = myArr[i]; // swapping
  myArr[i] = temp;

  return i+1;

}
void Sort::quickSort(double myArr[], int min, int max)
{
  if(min < max)
  {
    int i = partition(myArr, min, max);
    quickSort(myArr, min, i-1);
    quickSort(myArr, i+1, max);

  }
}

int main(int argc, char const *argv[])
{
  Sort machine; // class object
  int numElements; // number of doubles to sort
  ifstream inputFile;
  ofstream outputFile;
  string dLine;

  inputFile.open(argv[1]); // open file

  if(inputFile.good())
  {
    string firstLine;
    getline(inputFile, firstLine);
    numElements = stoi(firstLine); // store number of doubles in file
  }
  else
  {
    cout << "unable to open file" << endl;
    return 0;
  }
  // create arrays and necessary variables
  double bubbleArr[numElements];
  double selectArr[numElements];
  double insertArr[numElements];
  double quickArr[numElements];
  double bubbleTime;
  double selectTime;
  double insertTime;
  double quickTime;

  int n = 0;
  while(inputFile >> dLine) // fill arrays
  {
    bubbleArr[n] = stod(dLine);
    selectArr[n] = stod(dLine);
    insertArr[n] = stod(dLine);
    quickArr[n] = stod(dLine);
    n++;
  }

  inputFile.close();

  // run methods and determine clock Time
  // print the times
  clock_t bubbleClock = clock();
  machine.bubbleSort(bubbleArr, numElements);
  clock_t bubbleFinish = clock();
  bubbleTime = double(bubbleFinish - bubbleClock) / CLOCKS_PER_SEC;

  clock_t selectClock = clock();
  machine.selectionSort(selectArr, numElements);
  clock_t selectFinish = clock();
  selectTime = double(selectFinish - selectClock) / CLOCKS_PER_SEC;

  clock_t insertClock = clock();
  machine.bubbleSort(insertArr, numElements);
  clock_t insertFinish = clock();
  insertTime = double(insertFinish - insertClock) / CLOCKS_PER_SEC;

  clock_t quickClock = clock();
  machine.quickSort(quickArr, 0, numElements-1);
  clock_t quickFinish = clock();
  quickTime = double(quickFinish - quickClock) / CLOCKS_PER_SEC;

  cout << "Bubble Sort Time:" << bubbleTime << endl;
  cout << "Select Sort Time:" << selectTime << endl;
  cout << "Insert Sort Time:" << insertTime << endl;
  cout << "Quick Sort Time:" << quickTime << endl;

  return 0;


}
