#include <iostream>
#include <string>
using namespace std;

/*
	This program implements stack operations using a singly linked list and templates,
	and also demonstrates it's uses through operating on the list's items,
	as well as through recursive sorting and reversal of different types of elements.
*/

// Node structure for Linked List
template<class T>
struct node
{
	node<T>* next;
	T data;
};

// Class implements stack operations using singly linked list
template<class T>
class LinkedList
{
public:
	int top = -1;
	node<T>* first;
	node<T>* last;
	LinkedList<T>()
	{
		first = NULL;
		last = NULL;
	}
	
	// Pushes data to top of stack
	void push(T data)
	{
		if (!first)
		{
			first = new node<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		}
		else
		{
			if (last == first)
			{
				last = new node<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			}
			else
			{
				node<T>* insdata = new node<T>;
				insdata->data = data;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
		}
	}
	
	// Pops last data from stack
	T pop()
	{
		if (!first)
			cout << "List empty." << endl;
		else if (first == last)
		{
			node<T> tempData;
			tempData = *last;
			first = NULL;
			last = NULL;
			return tempData.data;
		}
		else
		{
			node<T>* curr = this->first;
			node<T>* temp;
			node<T> tempData;
			while (curr->next != last)
			{
				curr = curr->next;
			}
			temp = last;
			tempData = *last;
			last = curr;
			free(temp);
			return tempData.data;
		}
		return NULL;
	}
	
	// Returns top element in stack
	T peek()
	{
		return last->data;
	}
	
	// Displays all list data
	void display()
	{
		if (!first)
			cout << "No list data." << endl;
		else if (last != first)
		{
			node<T>* temp = this->first;
			while (temp != last)
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
		cout << last->data << endl;
	}
	
	// Returns true if list is empty
	bool empty()
	{
		bool status = false;
		if (!first)
			status = true;
		return status;
	}

	// Returns count of list items
	int count()
	{
		node<T>* curr = this->first;
		int num = 0;
		if (!first)
			return 0;
		else if (first == last)
			return 1;
		else
		{
			while (curr != last)
			{
				num++;
				curr = curr->next;
			}
			num++;
		}
		return num;
	}

	// Take user input to populate list
	void input(int num)
	{
		T input;
		for (int i = 0; i < num; i++)
		{
			cout << "Enter variable #" << (i + 1) << ":" << endl;
			cin >> input;
			this->push(input);
		}
	}

	// Multiply list elements
	void multiplyList()
	{
		while (this->count() >= 2)
		{
			T temp, temp2;
			temp = this->pop();
			temp2 = this->pop();
			this->push(temp * temp2);
		}
	}

	// Subtract list elements
	void additionList()
	{
		while (this->count() >= 2)
		{
			T temp, temp2;
			temp = this->pop();
			temp2 = this->pop();
			this->push(temp + temp2);
		}
	}
	
	// Insert sorted item in list
	void sortedInsert(T topData)
	{
		// Base case
		if (this->empty() || topData > this->peek())
		{
			this->push(topData);
			return;
		}
		int top = this->pop();
		sortedInsert(topData);
		this->push(top);
	}

	// Sort list using recursive sort
	void sortStack()
	{
		if (this->empty())
		{
			return;
		}
		T top = this->pop();
		sortStack();
		sortedInsert(top);
	}
};

LinkedList<int> revInt;
LinkedList<char> revString;
LinkedList<char> sortchar;
LinkedList<int> sortint;
LinkedList<double> sortdouble;


///// *** 1 - Performs subtraction or multiplication on diferent types of stack elements *** /////

void operationsList()
{
	string flush;
	char type;
	char op;
	int num;
	// Take user input for type
	cout << "What type of variable will be entered? Enter (C) Character, (I) Integer, or (D) Double:" << endl;
	cin >> type;
    while (type != 'I' && type != 'i' && type != 'D' && type != 'd' && type != 'C' && type != 'c')
	{
		 cout << "Invalid option entered, enter a valid variable type. Enter (I) Integer, (D) Double, or (C) Character:" << endl;
		 cin >> type;
	}
	   
	   // Take user input for number of variables
        	cout << "How many elements will be entered:" << endl;
        	cin >> num;
        	while (num < 5 || num >= 10)
        	{
        		cout << "Invalid amount entered, enter a valid amount (5-10):" << endl;
        		cin >> num;
        	}
        	

	if((type == 'C') || (type == 'c'))
	{
	    	// Character type
	    LinkedList<char> list;
	    cout << "Enter " << num << " elements of chosen type..." << endl;
		list.input(num);
		cout << "Original List:" << endl;
		list.display();
	}
	else
	{
	        // Take user input for operation
	        cout << "Enter operation to be completed ( + or * ):" << endl;
        	cin >> op;
        	while (op != '+' && op != '*')
        	{
        		cout << "Invalid option entered, enter a valid operation to be completed ( + or * ):" << endl;
        		cin >> op;
        	}

        	// Integer type
        	if (type == 'I' || type == 'i')
        	{
        		LinkedList<int> list;
        		cout << "Enter " << num << " elements of chosen type..." << endl;
        		list.input(num);
        		cout << "Original List:" << endl;
        		list.display();
        		if (op == '*')
        			list.multiplyList();
        		else
        			list.additionList();
        		cout << "Result:" << endl;
        		list.display();
        	}

        	// Double type
        	else 
        	{
        		LinkedList<double> list;
        		cout << "Enter " << num << " elements of chosen type..." << endl;
        		list.input(num);
        		cout << "Original List:" << endl;
        		list.display();
        		if (op == '*')
        			list.multiplyList();
        		else
        			list.additionList();
        		cout << "Result:" << endl;
        		list.display();
        	}
    }

}

///// *** 1 - Sort charecters, integers and doubles on the stack using linked list and recursion *** /////

void recursiveSortList()
{
    char type;
    int num;
	cout << "What type of variable will be entered? Enter (C) Character, (I) Integer, or (D) Double:" << endl;
	cin >> type;
    while (type != 'I' && type != 'i' && type != 'D' && type != 'd' && type != 'C' && type != 'c')
	{
		 cout << "Invalid option entered, enter a valid variable type. Enter (I) Integer, (D) Double, or (C) Character:" << endl;
		 cin >> type;
	}
	   
	// Take user input for number of variables
    cout << "How many elements will be entered to sort:" << endl;
    cin >> num;
    while (num < 5 || num >= 10)
    {
        cout << "Invalid amount entered, enter a valid amount (5-10):" << endl;
        cin >> num;
    }
    if (type=='c' || type=='C')
    {
	    cout << "Enter "<<num<< "chosen type of elements to be sorted..." << endl;
	    sortchar.input(num);
	    cout << "Unsorted List:" << endl;
	    sortchar.display();
	    sortchar.sortStack();
    	cout << "Sorted List:" << endl;
	    sortchar.display();
    }
    else if(type=='i' || type=='I')
    {
        sortint.input(7);
	    cout << "Unsorted List:" << endl;
	    sortint.display();
	    sortint.sortStack();
    	cout << "Sorted List:" << endl;
	    sortint.display();
    }
    else 
    {
        sortdouble.input(7);
    	cout << "Unsorted List:" << endl;
	    sortdouble.display();
    	sortdouble.sortStack();
    	cout << "Sorted List:" << endl;
	    sortdouble.display();
    }
}

///// *** 2 - Reverses strings and integers using linked list and recursion *** /////

// insert digits into stack using recursion
void reverseInt(int num)
{
	if (num / 10 == 0)
	{
		revInt.push(num);
	}
	else
	{
		revInt.push(num % 10);
		reverseInt(num / 10);
	}
}

void reverseString(string str)
{
	
	
	
	if (str.length() == 1)
	{
		revString.push(str[0]);
	}
	else
	{
		revString.push(str[str.length() - 1]);
		str.pop_back();
		reverseString(str);
	}
}

// Reverse the string and integer
void reverseLists()
{
	string str;
	int num;
	int c;
	int reverse=0;
	int i=1;
	cout<<"enter your choic to reverse 1.String 2.Integer \n";
	cin>>c;
	switch(c)
	{
	   case 1:
	        cout << "Enter a string to reverse:" << endl;
	        cin >> str;
	        reverseString(str);
	        cout << "Reversed String:" << endl;
	        for(i=str.length()-1;i>=0;i--)
	        {
	            str[i]=revString.pop();
	            
	        }
	        cout<<str;
	        break;
	   case 2:
	    	cout << "Enter an integer to reverse:" << endl;
	        cin >> num;
	        reverseInt(num);
	        
	        while(!revInt.empty())
	        {
	            reverse=reverse+(revInt.pop()*i);
	            i=i*10;
	    	}
	        cout<<"Reversed number is "<<reverse<<endl;
	        break;
	   default:
	        cout<<"invalid choice";
	}
}

///// Main function /////

int main()
{
	int c;
	cout<<"Enter your choice(1-3)";
	cin>>c;
	switch(c)
	{
	    case 1:
	            cout << "\n*** 1 - Performs addition or multiplication on diferent types of stack elements ***\n" << endl;
	            operationsList();
            	break;
       	    case 2:
	            cout << "\n*** 2 - Reverses strings and integers using linked list and recursion ***\n" << endl;
	            reverseLists();
	            break;
	   case 3:
	            cout << "\n*** 3 - Sort charecters on the stack using linked list and recursion ***\n" << endl;
	            recursiveSortList();
	            break;
	   default:
	            cout<<"Invalid entry";
	            break;
	
	}
	    return 0;
}