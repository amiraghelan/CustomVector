#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class CustomVector
{

private:

    T *arr = nullptr;
    int mSize = 0;

public:

    CustomVector() {}
    CustomVector(int size)
    {
        resize(size);
    }
    CustomVector(int size, T defaultValue)
    {
        resize(size, defaultValue);
    }

    int size()
    {
        return mSize;
    }

    void resize(int newSize, T fillValue)
    {
        if (newSize < 0)
        {

            throw invalid_argument("new size msut be greater than 0");
        }
        else if (newSize > mSize)
        {

            T *newArr = new T[newSize];

            for (int i = 0; i < mSize; i++)
            {
                newArr[i] = arr[i];
            }

            for (int i = mSize; i < newSize; i++)
            {
                newArr[i] = fillValue;
            }

            delete[] arr;
            arr = newArr;
            mSize = newSize;
        }
        else if (newSize < mSize)
        {

            T *newArr = new T[newSize];

            for (int i = 0; i < newSize; i++)
            {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
            mSize = newSize;
        }
    }

    void resize(int newSize)
    {
        T h;
        resize(newSize, h);
    }

    void pushBack(T el)
    {
        resize(mSize + 1, el);
    }

    T &get(int index)
    {
        if (index >= mSize)
            throw invalid_argument("index out of range");
        else if (index < 0)
            throw invalid_argument("index must be greater than 0");
        else
            return arr[index];
    }

    T &operator[](int index)
    {
        return get(index);
    }

    void print()
    {   
        if(mSize==0){
            cout<<"[]"<<endl;
            return;
        }
        cout << "[";

        for (int i = 0; i < mSize - 1; i++)
            cout << arr[i] << ", ";

        cout << arr[mSize - 1] << "]" << endl;
    }

    ~CustomVector(){
        delete[] arr;
    }
};

int main()
{

    CustomVector<int> c1;

    CustomVector<float> c2{5,2.1f};
    CustomVector<float> c3{2};

    cout<<"c1: ";
    c1.print();

    cout<<"c2: ";
    c2.print();

    cout<<"c3: ";
    c3.print();

    c1.pushBack(1);
    c1.pushBack(2);
    c1.pushBack(3);
    c1.print();

    c1.resize(6,7);
    cout<<"c1: ";
    c1.print();

    cout << "c1: " << c1[1] <<endl;
    c1[1] = 17;
    cout << "c1: " << c1[1] <<endl;
    
    c1.resize(2);
    cout<<"c1: ";
    c1.print();

    return 0;
}