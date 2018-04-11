#include<iostream>
#include<cassert>
using namespace std;

template<class T>
class Array
{
    int m_length;
    T   *m_data;
public:
   Array(): m_length(0), m_data(nullptr)
   {

   }

   Array(int length) : m_length(length)
   {
       m_data = new T[length];
   }

   ~Array()
   {
       delete[] m_data;
   }

   T& operator[](int index)
   {
       assert(index >= 0 && index < m_length);
       return m_data[index];
   }

   int getLength();
};

template<typename T>
int Array<T>::getLength() // class name is Array<T>, not just Array
{
    return m_length;
}

template<class T, int size> // size is the expression parameter
class StaticArray
{
    T m_array[size];
public:
    T* getArray();
    
    T& operator[](int index)
    {
        return m_array[index];
    }
};

template<class T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}

//
// Function template specialization
// 
template<class T>
class Storage
{
    T m_value;
public:
    Storage(T value) : m_value(value)
    {
    }

    ~Storage()
    {
    }
  
    void print()
    {
        cout << m_value << endl;
    }
};

// Suppose we want double values to output in scientific notation.
// To do so, we can use a function template specialization.
//
template<>
void Storage<double>::print()
{
    cout << std::scientific << m_value << endl;
}

// class template specialization.
//
template<class T>
class Storage8
{
    T m_array[8];
public:
    void set(int index, const T &value)
    {
        m_array[index] = value;
    }

    const T& get(int index)
    {
        return m_array[index];
    }
};

template<>
class Storage8<bool>
{
    unsigned char m_data;
public:
    Storage8() : m_data(0)
    {
    }

    void set(int index, bool value)
    {
        unsigned char mask = 1 << index;

        if(value)
            m_data |= mask;
        else
            m_data &= ~mask;
    }
    
    bool get(int index)
    {
        unsigned char mask = 1 << index;
        return (m_data & mask) != 0;
    }
};


int main()
{
    Array<int> intArray(12);
    Array<double> doubleArray(12);

    for(int count = 0; count < intArray.getLength(); ++count)
    {
        intArray[count] = count;
        doubleArray[count] = count + 0.5;
    }

    for(int count = 0; count < intArray.getLength(); ++count)
        cout << intArray[count] << "  " << doubleArray[count] << endl;

    StaticArray<int, 12> sArray;
    for(int count = 0; count < 12; ++count)
        sArray[count] = count;

    for(int count = 0; count < 12; ++count)
        cout << sArray[count] << " ";
    cout << endl;
    
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);

    nValue.print();
    dValue.print();

    return 0;   
}
