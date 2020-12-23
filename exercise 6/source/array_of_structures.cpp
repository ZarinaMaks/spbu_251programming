#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct BOOK
{
  char title[100];
  char author[70];
  int year;
  float price;
};

bool Example(const char * filename)
{
  BOOK B[3] = {
    { "Title-01", "Author-01", 2000, 90.25 },
    { "Title-02", "Author-02", 2001, 100.25 },
    { "Title-03", "Author-03", 2002, 110.25 }
  };
  int n = 3;
  BOOK C[3];
  int n2;
  int i;

  // Writing massive of structures
  ofstream outF(filename, ios::out | ios::binary);
  if (!outF) return false;
  // outF - is an example of fole in which from we write

  // writing the value of n
  outF.write((char*)&n, sizeof(int));

  // writing of massive B[] to file wf
  for (i = 0; i < n; i++)
    outF.write((char*)&(B[i]), sizeof(BOOK));
  cout << "Array is written\n" << endl;

  // после завершения работы с файлом его нужно закрыть (обязательно)
  outF.close();

  // Reading massive of structures
  ifstream inF(filename, ios::in | ios::binary);
  // inF - is an example of file in which from we read

  if (!inF) return false;

  cout << "Reading the array...\n";

  // Counting number of written structures
  inF.read((char*)&n2, sizeof(int));

  for (i = 0; i < n2; i++)
    inF.read((char*)&(C[i]), sizeof(BOOK));

  inF.close();

  cout << "Array of Structures:" << endl;
  for (i = 0; i < n2; i++)
  {
    cout << "Book number " << i << "." << endl;
    cout << "Title = " << C[i].title << ", ";
    cout << "Author = " << C[i].author << ", ";
    cout << "Year = " << C[i].year << ", ";
    cout << "Price = " << C[i].price << endl;
  }
}

int main()
{
  Example("file.bin");
  return 0;
}