#include <iostream>
using namespace std;

class List
{
protected:
    int  *arr;
    int maxSize;
    int currentSize;

public:
    List()
    {
    }
    List(int maxSize)
    {
        currentSize = 0;
        this->maxSize = maxSize;
        arr = new int[maxSize];
    }
    virtual void addElement() = 0;
    virtual void removeElement() = 0;
    virtual void searchElemen() = 0;
};

class ListFunction : public List
{
public:
    ListFunction()
    {
    }
    ListFunction(int maxSize) : List(maxSize)
    {
    }
    void addElement()
    {
        if (currentSize == 0)
        {
            cout << "enter a number";
            cin >> arr[0];
            currentSize++;
            cout << "current size is zero : ";
            print();
        }
        else
        {
            // cout << "else";
            int *temp = new int[currentSize + 1];
            for (int i = 0; i < currentSize; i++)
            {
                temp[i] = arr[i];
            }
            currentSize++;
            for (int i = currentSize - 1; i >= 0; --i)
            {

                temp[i] = temp[i - 1];
            }
            cout << "enter a  number";
            cin >> temp[0];
            arr = temp;
            if (currentSize >= maxSize)
            {
                cout << "current size equal to max size \n";
                maxSize = currentSize;
            }

            print();
        }
    }
    void removeElement()
    {

        for (int i = 0; i < currentSize - 1; i++)
        {
            arr[i] = arr[i];
        }
        currentSize--;
        print();
    }
    void searchElemen()
    {
        // bool found=0;
        int min = arr[0];
        for (int i = 1; i < currentSize; i++)
        {
            /* code */
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        cout << "minimum values into array is this : " << min << endl;
    }

    void print()
    {
        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[i] << "   ";
        }
        cout << endl;
    }
};
int main()
{

    ListFunction l(5);
    l.addElement();
    l.addElement();
    l.addElement();
    l.addElement();
    l.addElement();
    l.addElement();
    l.removeElement();
    l.removeElement();
    l.removeElement();
    l.searchElemen();

    return 0;
}