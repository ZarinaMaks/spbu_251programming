#include "ExceptionQueue.h"

int main()
{ 
    int item, size;
    int choice = 0;
    
    cout << "\nEnter the size of the queue: ";
    cin >> size;
    queue q(size);
    
    cout << "\nQueue Operations using Exception Handling";
    cout << "\n\n\t MENU:\n 1.ADD ITEM\n 2.DELETE ITEM\n 3.PRINT QUEUE\n 4.CLOSE PROGRAM";
    cout << "\nEnter your choice: ";
    cin >> choice;
    
    do
    {
        switch(choice)
        {
            case 1:
            
            cout<<"\nEnter the item to insert in to the queue: ";
            cin >> item;
            
            try
            {
                q.enqueue(item);
            }
                catch(queue::FULL)
                {
                    
                    cout << "\n ANSWER: Queue is Full.\n";
                    
                }
                break;
                
            case 2:
            try
            {
                cout << "\n ANSWER: Removed " << q.dequeue() << " from the Queue.";
            }
            
            catch(queue::EMPTY) //EMPTY object is caught
            {
                cout << "\n ANSWER: Queue is Empty\n";
            }
            break;
        
        case 3:
        
        cout << "\n ANSWER: Queue is ";
        try
        {
            q.display();
        }
        catch(queue::EMPTY)
        {
            cout << "Empty.\n";
        }
        break;
        
        case 4:
        exit(0);
            
        }
        
        cout << "\nEnter your choice: ";
        cin >> choice;
        
    } while (choice < 5);
    
    return 0;

}