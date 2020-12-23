#include<iostream>
#include<iomanip>

using namespace std;

class queue
{
    private:
    int *q;
    int max, front, rear, count;
    
    public:
    
    class FULL{};  //for exception handling
    class EMPTY{}; //for exception handling
    
    queue(int);
    
    void enqueue(int);
    int dequeue(void);
    void display(void);

};

queue::queue(int m)
{
    q = new int[m];
    
    rear = 0;
    front = 0;
    count = 0;
    max = m;

}

void queue::enqueue(int item)
{
    if(count < max)
    {
        front = front%max;
        q[front++] = item;
        count++;
        
    } else {
        throw FULL();
    }

}

int queue::dequeue(void)
{
    if(count > 0)
    {
        count--;
        rear = rear %max;
        return q[rear++];
        
    } else {
    throw EMPTY();
    }

}

void queue::display(void)
{
    if(count > 0) {
    for(int i = 0, j = front; i < count; i++, j++) { cout << "|" << q[j%max] << "|"; } 
    } else {
        throw EMPTY();
    }

}
