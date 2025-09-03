#include<iostream>
using namespace std;

class StackBase {
    public:
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual void topElement() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual ~StackBase() {}
};

class Stack : public StackBase
{
    int *arr, size, top;

    public:
    Stack(int capacity)
    {
        size = capacity;
        arr = new int[size];
        top = -1;
    }

    void push(int ele) override
    {
        if(isFull())
        {
            cout << "Stack is Full. " << endl;
        }
        else{
            top++;
            arr[top] = ele;
            cout << ele << " added element in the stack. " << endl;
        }
    }

    void pop() override
    {
        if(isEmpty())
        {
            cout << "Stack is Empty. " << endl;
        }
        else{
            cout << "Removed element :- " << arr[top] << endl;
            top--;
        }
    }

    void topElement() override
    {
        if(isEmpty())
        {
            cout << "Stack is Empty. " << endl;
        }
        else{
            cout << "Top element :- " << arr[top] << endl;
        }
    }

    bool isEmpty() override
    {
        return top == -1;
    } 

    bool isFull() override
    {
        return top == size - 1;
    }

    ~Stack()
    {
        delete[] arr;
    }

};


int main()
{
    int n;
    cout << "Enter the size of the Stack :- "; 
    cin >> n;

    StackBase* s = new Stack(n);

    int choice, ele;

    do{
        cout << "----Stack Class Program-----" << endl;
        cout << "1. Add in the stack " << endl;
        cout << "2. Delete from stack " << endl;
        cout << "3. Display Top Element " << endl;
        cout << "4. Check Stack is Empty or not " << endl;
        cout << "5. Check Stack is Full or not " << endl;
        cout << "0. Exit..... " << endl;
        cout << " Enter your choice :- ";
        cin >> choice;

        switch(choice)
        {
            case 1: 
                cout << "Enter the element to add :- ";
                cin >> ele;
                s->push(ele);
                break;

            case 2:
                s->pop();
                break;

            case 3:
                s->topElement();
                break;

            case 4:
                if(s->isEmpty()){
                    cout << "The Stack is Empty.." << endl;
                }
                else{
                    cout << "Stack is not Empty.." << endl;
                }
                break;

            case 5:
                if(s->isFull()){
                    cout << "The Stack is Full.." << endl;
                }
                else{
                    cout << "Stack is not Full.." << endl;
                }
                break;

            case 0:
                cout << "Thank you! " << endl;
                break;

            default:
                cout << "Invalid choice. " << endl;
   
        }

    } while (choice != 0);

    delete s;
    return 0;
}
