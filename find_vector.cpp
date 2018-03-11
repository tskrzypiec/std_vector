#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <array>
#include <list>
#include <algorithm> // to do tej funkcji find

struct BigData {
    BigData() : v(100) {}
    std::vector<int> v;
};

int rand(int) { return std::rand();}
float rand(float) { return static_cast<float>(std::rand());}
BigData rand(BigData v) { return v;}

template<typename T>
void insertVector()
{
    auto start = std::chrono::system_clock::now();
    std::vector<T> data;
    data.reserve(1000000);
    for (int i = 0; i < 1000000; ++i) {
        data.push_back(rand(T()));
    }
    auto  end = std::chrono::system_clock::now();

    auto diff = end - start;
    std::cout << diff.count() << std::endl;
}
template<typename T>
void insertList()
{
    auto start = std::chrono::system_clock::now();
    std::list<T> data;
    for (int i = 0; i < 1000000; ++i) {
        data.push_back(T());
    }
    auto  end = std::chrono::system_clock::now();

    auto diff = end - start;
    std::cout << diff.count() << std::endl;
}

/*
template<typename T>
void findVector()
{
    auto start = std::chrono::system_clock::now();
    std::vector<T> data;
    data.reserve(1000000);

  /*  typedef vector<int> IntContainer;                 // to find z stackoverflow
    typedef IntContainer::iterator IntIterator;

    IntContainer vw;

    //...

    // find 5
    IntIterator i = find(vw.begin(), vw.end(), 5);

    if (i != vw.end()) {
        cout <<"Jest"<<endl; // found it
    } else {
        cout<<"nie ma"<<endl;// doesn't exist
    }
  


    auto  end = std::chrono::system_clock::now();

    auto diff = end - start;
    std::cout << diff.count() << std::endl;
}

*/









int main()
{
    std::cout << "ints = " << std::endl;
    insertVector<int>();
    insertList<int>();
    std::cout << "floats = " << std::endl;
    insertVector<float>();
    insertList<float>();
    std::cout << "bd = " << std::endl;
    insertVector<BigData>();
    insertList<BigData>();
}