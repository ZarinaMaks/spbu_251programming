#include <iostream>
using namespace std;

template <typename T>
class myStack
{
private:
	T* stack;
	int count;

public:

	// Constuctor:
	myStack()
	{
		stack = nullptr;
		count = 0;
	}
	
	myStack(const myStack& st)
	{
		try {
			stack = new T[st.count];

			count = st.count;
			for (int i = 0; i < count; i++)
				stack[i] = st.stack[i];
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;
		}
	}
	
	// Desctuctor:
	~myStack()
	{
		if (count > 0)
			delete[] stack;
	}
	
	
	// push, pop, multipop:
	void push(T item)
	{
		T* tmp;
		try 
		{
			tmp = stack;
			stack = new T[count + 1];
			count++;

			for (int i = 0; i < count - 1; i++)
				stack[i] = tmp[i];
			stack[count - 1] = item;

			if (count > 1)
				delete[] tmp;
		}
		catch (bad_alloc e)
		{
		    //bad_alloc is the type of the object thrown as exceptions by the 
		    //allocation functions to report failure to allocate storage
			cout << e.what() << endl;
		}
	}

	T pop()
	{
		if (count == 0)
			return 0;
		count--;
		return stack[count];
	}
	
	
	T multipop(int k)
	{

		if (count == 0) return 0;
		count = count - k;
		return stack[count];
	}

	T head()
	{
		if (count == 0)
			return 0;
		return stack[count - 1];
	}
	
	// overloading operator=:
	myStack operator=(const myStack& st)
	{
		if (count > 0)
		{
			count = 0;
			delete[] stack;
		}

		try {

			stack = new T[st.count];

			count = st.count;
			for (int i = 0; i < count; i++)
				stack[i] = st.stack[i];
		}
		catch (bad_alloc e)
		{

			cout << e.what() << endl;
		}

		return *this;
	}
	
	// methods:
	int getCount()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	void print()
	{
		T* printSt = stack;

		if (count == 0)
		{
			cout << "Stack is empty." << endl;
		} else {
			for (int i = 0; i < count; i++)
			{
				cout << "Stack[" << i << "] = " << printSt[i] << endl;
			}
		}
	}
};

template <> class myStack <bool>
{
private:
	bool* stack;
	int count;

public:

    // Constructor:
	myStack()
	{
		stack = nullptr;
		count = 0;

	}

	myStack(const myStack& st)
	{
		try
		{
			stack = new bool[st.count];
			count = st.count;
			for (int i = 0; i < count; i++)
			{
				if (st.stack[i] == true)
				{
					stack[i] = true;
				}
				else {
					stack[i] = false;
				}
			}

		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;

		}

	}
	
	// Desctuctor:
	~myStack()
	{
		if (count > 0)
			delete[] stack;

	}
	
	// push, pop, multipop:
	void push(bool item)
	{
		bool* tmp;
		try
		{
			tmp = stack;
			stack = new bool[count + 1];
			count++;

			for (int i = 0; i < count - 1; i++)
				if (tmp[i] == true)
				{
					stack[i] = true;
				}
				else {
					stack[i] = false;
				}

			if (item == true)
			{
				stack[count - 1] = true;
			}
			else {
				stack[count - 1] = false;
			}

			if (count > 1)
				delete[] tmp;

		}

		catch (bad_alloc e)
		{
			cout << e.what() << endl;
		}

	}

	bool head()
	{
		if (count == 0)
		{
			return 0;
		}
		if (stack[count - 1] == true)
		{
			return true;
		}
		else {
			return false;
		}

	}

	bool pop()
	{
		if (count == 0)
		{
			return false;
		}

		count--;
		if (stack[count] == true)
		{
			return true;
		}
		return false;

	}
	
	bool multipop(int k)
	{
		if (count == 0)
			return 0;

		count = count - k;

		return stack[count];

	}
	
	// overloading operator=:
	myStack operator=(const myStack& st)
	{
		if (count > 0)
		{
			count = 0;
			delete[] stack;

		}

		try {
			stack = new bool[st.count];
			count = st.count;

			for (int i = 0; i < count; i++)
			{
				if (st.stack[i] == true)
				{
					stack[i] = true;
				}
				else {
					stack[i] = false;
				}

			}
		}
		catch (bad_alloc e) { cout << e.what() << endl; }

			return *this;

	}
	
	// methods:

	int getCount()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;

	}


	void print()
	{
		bool* printSt = stack;
		
		if (count == 0)
			cout << "Stack is empty." << endl;

		for (int i = 0; i < count; i++)
		{
			cout << "Stack[" << i << "] = ";
			if (printSt[i] == true) cout << "true" << endl;
			else cout << "false" << endl;
		}
	}

};