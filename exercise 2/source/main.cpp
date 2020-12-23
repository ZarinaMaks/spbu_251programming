#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>

class RAID {
    
    private:
    
    int number;
    int length;
    T** buff;
    
    public:
    
    RAID(int k, int n)
    {
        number = k+1;
        length = n;
        T**arr = new T*[number];
        for (int i = 0; i < number; i++) {
            
            arr[i] = new T[length];
            
        }
        
        buff=arr;
        
        for (int j = 0; j < length; j++)
        buff[number-1][j]=0;
        
    }
    
    ~RAID()
    {
        for (int i = 0; i < number; i++)
        {
            delete [] buff[i];
            
        }
        delete [] buff;
    }
    
    void print ()
    {
        if (number == 0) 
        {
        cout << "\nNO DATA.";
        } else {
            
            for (int i = 0; i < number; i++)
            {
                if (i != number - 1) 
                {
                    cout << "\nDisk" << i + 1 << ":" << endl;
                    
                } else {
                    
                    cout << "\nControl sum:" << endl;
                }
                    for (int j = 0; j < length; j++) 
                    {
                        cout << "  " << buff[i][j] << " ";
                    }
                    cout << endl;
            }
            
        }
    }
    
    void read ()
    {
        T x;
        int i=0;
        int j=0;
        
        cout << "\nData:" << endl;
        
        for (int step = 0; step < (number-1)*length; step++ )
        {
            cin >> x;
            buff[i][j]=x;
            j++;
            if ((step+1)%length == 0)
            {
                i++;
                j=0;
                
            }
            
        }
        
    }
    
    void control()
    {
        
        for (int j = 0; j < length; j++) 
        {
            for (int i=0;i<number-1; i++)
            buff[number-1][j] += buff[i][j];
            buff[number-1][j] = buff[number-1][j] % 2;
            
        }
        
    }
    
    void loss (int mistake)
    {
        for (int i = 0; i < length; i++)
        buff[mistake][i] = -1;
        
    }
    
    void recovery (int mistake)
    {
        for (int j = 0; j < length; j++) 
        {
            for (int i = 0; i < number; i++)
            {
                if (i!=mistake) buff[mistake][j]+=buff[i][j];
                
            }
            buff[mistake][j] = (buff[mistake][j]+1) % 2;
            
        }
        
    }
    
};



int main()
{
     srand(time(0));
     int k,n;
     
     cout << "\nNumber of buffers: " << endl;
     cin >> k;
     cout << "\nLength of buffers: " << endl;
     cin >> n;
     
     RAID <int> RAID5(k,n);
     RAID5.read();
     
     RAID5.control();
     RAID5.print();
     
     int mistake = rand() % n;
     
     RAID5.loss(mistake);
     
     cout << "Data of disk " << mistake + 1 << " are lost" << endl;
     RAID5.print();
     RAID5.recovery(mistake);
     RAID5.print();
     
     return 0;
}