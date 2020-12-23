#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#define N 5
#define DIMENSION 2
using namespace std;

class Input
{
    private:
    
    char struct_element1;
    double struct_element2;
    int* array;

    public:

    Input()
    {
        struct_element1 = 0;
        struct_element2 = 0;
        array = new int[N];
        for (int i = 0; i < N; i++)
            array[i] = 0;
    }
    
     
     Input(char arg1, double arg2, int* arg3)
     {
        struct_element1 = arg1;
        struct_element2 = arg2;
        array = new int[N];
        for (int i = 0; i < N; i++)
        array[i] = arg3[i];

     }

// Copy Constructor:
    Input(const Input& Inputx)
    {
        struct_element1 = Inputx.struct_element1;
        struct_element2 = Inputx.struct_element2;
        for (int i = 0; i < N; i++)
            array[i] = Inputx.array[i];
    }
    
    Input operator=(const Input& Inputx)
    {
            struct_element1 = Inputx.struct_element1;
            struct_element2 = Inputx.struct_element2;
            for (int i = 0; i < N; i++)
                array[i] = Inputx.array[i];

        return *this;
    }


    void print() const
    {   cout << "\nStructure elenent 1: " << struct_element1;
        cout << "\nStructure elenent 2: " << struct_element2;
        cout << "\nNow let's print the array: ";
        for (int i = 0; i < N; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    
    ~Input()
    {
        struct_element1=0;
        struct_element2=0;
        delete[] array;
    }
};

class Output
{
    private:

    char struct_element1;
    double struct_element2;
    int* array;

    public:

    Output()
    {
        struct_element1 = 0;
        struct_element2 = 0;
        array = new int[N];
        for (int i = 0; i < N; i++)
            array[i] = 0;
    }
    
    void build(char arg1, double arg2, int* arg3)
     {
         struct_element1 = arg1;
         struct_element2 = arg2;
         for (int i = 0; i < N; i++)
            array[i] = arg3[i];

     }
     
     Output(char arg1, double arg2, int* arg3)
     {
         build(arg1, arg2, arg3);

     }

// Copy Constructor
    Output(const Output& Outputx)
    {
        struct_element1 = Outputx.struct_element1;
        struct_element2 = Outputx.struct_element2;
        array = new int[N];
        for (int i = 0; i < N; i++)
            array[i] = Outputx.array[i];
    }

    Output operator=(const Output& Outputx)
    {
            struct_element1 = Outputx.struct_element1;
            struct_element2 = Outputx.struct_element2;
            for (int i = 0; i < N; i++)
                array[i] = Outputx.array[i];

        return *this;
    }

   void print() const
    {
        cout << "\nStructure element 1: " << struct_element1;
        cout << "\nStructure element 2: " << struct_element2;
        cout << "\nNow let's print the array: " << endl;
        for (int i = 0; i < N; i++)
            cout << array[i] << " ";
        cout << endl;
    }

    ~Output()
    {
        struct_element1=0;
        struct_element2=0;
        delete[] array;
    }
};

void buildOutput (Output* out)
{
    if (DIMENSION!=0 && out!=0)
    {
        for (int i = 0; i < DIMENSION; ++i){
        int* array = new int[N];
        for (int j = 0; j < N; j++)
            array[j] = j + i;
        out[i].build('a' + i%24, i, array );
        delete []array;
        }
    }
}

void printInput(Input*in)
{
    cout << "\n\n_______INPUT_______\n";
    for (int i = 0; i < DIMENSION&& in+i!=0; i++)
    {
      cout << "Number " << i + 1 << ": "; 
      in[i].print();
    }
    cout << "____________________\n";
}

void printOutput(Output*out)
{
    cout << "\n\n_______OUTPUT_______\n";
    for (int i = 0; i < DIMENSION && out+i!=0; i++)
    {
      cout << "Number " << i + 1 << ": ";
      out[i].print();
    }
    cout << "____________________\n";
}
void write (Output*out, const char* path)
{
    ofstream fout;
    fout.open(path, ios::binary);
    if (fout)
    {
         for (int i = 0; i < DIMENSION && !fout.fail(); ++i)
        {
            fout.write(reinterpret_cast<char*> (&out[i]),
                       sizeof(Output));
        }
        if (fout.fail())
        {
            fout.clear();
        }
        fout.close();
    }
}

void read(Input*in, const char* path)
{
    ifstream fin;
    fin.open(path, ios::binary);

    if (fin)
    {
        for (int i = 0; i < DIMENSION && !fin.fail(); ++i)
        {
            fin.read(reinterpret_cast<char*> (&in[i]),
                       sizeof(Input));
        }
        if (fin.fail())
        {
            fin.clear();
        }
        fin.close();
    }
}