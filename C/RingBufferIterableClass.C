#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Ring
{
    int m_size;
    T *m_values;
    int m_pos;

public:
    class iterator;
    Ring(int size) : m_size(size), m_values(nullptr), m_pos(0)
    {
        m_values = new T[size];
    }

    ~Ring()
    {
        delete[] m_values;
    }

    int size() { return m_size; }

    void add(T value)
    {
        m_values[m_pos++] = value;
        m_pos = m_pos % m_size;
    }

    T get(int index)
    {
        return m_values[index];
    }

    iterator begin()
    {
        return iterator(0, *this);
    }

    iterator end()
    {
        return iterator(m_size, *this);
    }
    
};

template<typename T>
class Ring<T>::iterator
{
    int m_pos;
    Ring &m_ring;
public:

    iterator(int pos, Ring &ring) : m_pos(pos), m_ring(ring)
    {

    }

    void operator++(int ) // Post increment
    {
        m_pos++;
    }
   
    void operator++() // Pre increment
    {
        ++m_pos;
    }

    T operator*()
    {
        return m_ring.get(m_pos);
    }

    bool operator!=(const iterator &other) const 
    {
        return m_pos != other.m_pos;
    }
};

int  main()
{
    Ring<string> ring(3);
    ring.add("one");
    ring.add("two");
    ring.add("three");
    ring.add("four");
    ring.add("five");

    cout << "The number of elements: " << ring.size() << endl;

    for(int i = 0; i < ring.size(); i++)
        cout << ring.get(i) << endl;

    cout << "Traversing through iterator ..." << endl;
    for(Ring<string>::iterator it = ring.begin(); it != ring.end(); it++)
        cout << *it << endl;

    cout << "Traversing through Range based for loop ..." << endl;
    for(auto text : ring)
        cout << text << endl;

    return 0;
}
