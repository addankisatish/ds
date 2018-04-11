#include<iostream>
#include<initializer_list>
#include<cassert>
using namespace std;

class IntArray
{
    int length;
    int *data;
public:
    
    IntArray() : length(0), data(nullptr) 
    {

    }

    IntArray(int len) : length(len)
    {
        data = new int[length];
    }

    IntArray(const std::initializer_list<int> &list) : 
          IntArray(list.size()) // use delegating constructor to set up initial array
    {
        int count = 0;
        for( auto &element : list)
        {
            data[count] = element;
            ++count;
        }
    }

    ~IntArray()
    {
        delete[] data;
    }

    IntArray& operator=(const std::initializer_list<int> &list)
    {
        // If the new list is a different size, reallocate it.
        if(list.size() != length)
        {
            // delete ant existing elements
            delete[] data;

            length = list.size();
            data = new int[length];
        }
        
        int count = 0;
        for(auto &element : list)
        {
            data[count] = element;
            ++count;
        }

        return *this;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < length);
        return data[index];
    }

    int getLength() { return length; }
};

int main()
{
    int array[5] { 5, 4, 3, 2 ,1}; 
    for(int elem: array)
        cout << elem << ' ' ;
    cout << endl;

    //This also works for dynamically allocated arrays.
    int *array1 = new int[5] {5,4,3,2,1};
    for(int count = 0; count < 5; count++)
        cout << array1[count] << ' ' ;
    cout << endl;
    delete[] array1;

    //
    // When c++11 compiler sees an initilizer list, it automatically converts it into an object of type
    // std::initializer_list. Therefore, if we create a constructor that takes a std::initilizer_list parameter,
    // we can create objects using the initializer list as an input.
    // There are few things to know about initializer_list. Much like std::array or std::vector, we need to tell
    // initializer_list what type of data the list holds.
    //
    IntArray array2{ 5,4,3,2,1};
    for(int count = 0; count < array2.getLength(); count++)
        cout << array2[count] << ' ';
    cout << endl;

    //
    // If we implement a constructor that takes a std::initializer_list, we should ensure at least 
    // one of the following:
    // 1. Provide an overloaded list assignment operator
    // 2. Provide a proper deep-copying copy assignment operator.
    // 3. Make the constructor explicit, so it can't be used for implicit conversions.
    // Consider, the above IntArray class which doesn't have overloaded list assignment or a copy assignment.
    // array = {1,3,5,7,9, 11};
    // First, the compiler will note that an assignment function taking std::initializer_list doesn't exist.
    // Next it will look for other assignment operator it could use and discover the implicitly provided
    // copy assignment operator. However this function can only be used if it can covert the initializer list into
    // an IntArray. Because the constructor that takes the initializer_list isn't marked as explicit, the compiler 
    // will use the list constructor to convert the initializer list into a temporary IntArray. This will call the 
    // implicit assignment operator, which will shallow copy the temporary IntArry into out array object.
    //
    // So, if you provide list construction, it's a good idea to provide a list assignment as well.
    //
    array2 = {1,3,5,7,9,11};
    for(int count = 0; count < array2.getLength(); count++)
        cout << array2[count] << ' ';
    cout << endl;
   
    return 0;
}
