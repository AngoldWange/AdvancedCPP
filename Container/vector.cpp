#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Sales_data.h"

using namespace::std;

int Vector() {
    /*
     * Points:
     * Flexible-size array. Supports fast random access.
     * Inserting or deleting elements other than at the back may be slow
     *
     * Property: 
     * Vector (also String) hold it elements in contiguous memory.
     * Because elements are contiguous, it is fast to compute the address of an element from its index.
     * However, adding or removing elements in the middle of it will cost much time .
     * Since it will move the index after the changing index
     *
     * Note: 
     * Unless you have a reason to use another container, use a vector
     */



    // 1. iterator
    cout << "1. iterator:" << endl;
    vector<string> vs1 = {"Milton", "Shakespeare", "Austen"};
    vector<string>::iterator it1 = vs1.begin();
    vector<string>::const_iterator it2 = vs1.cbegin();
    vector<string>::reverse_iterator it3 = vs1.rbegin();
    vector<string>::const_reverse_iterator it4 = vs1.crbegin();
    
    vector<string>::const_reverse_iterator it5 = vs1.crend();

    while (it4 != it5) {
	string s = *it4;
	cout << s << " ";
	++it4;
    }
    cout << endl;
    // Austen
    // Shakespeare
    // Milton



    // 2. assign and swap
    cout << "2. assign and swap:" << endl;
    list<string> ls1 = {"Milton", "Shakespeare", "Austen"};
    list<string>::iterator ils1 = ls1.begin();
    vector<const char*> vs2 = {"Austen"};
    vector<const char*>::iterator ivs2 = vs2.begin();

    // ls1 = vs2; error: container types don't match
    ls1.assign(vs2.cbegin(), vs2.cend()); // cannot use vs2.assign(ls1.cbegin(), ls2.cend())
    cout << *ils1 << endl; // Austen

    vector<const char*> vs3 = {"Shakespeare", "Milton"};
    // With the exception of arrays, swapping two containers is guaranteed to be fast (constant time)
    // Since the elements themselves are not swapped; internal data structures are swapped
    //
    // The fact that elements are not moved means that, with the exception of string, iterators, references, and pointers 
    // into the containers are not invalidated. They refer to the same elements as they did before the swap.
    swap(vs2, vs3);
    cout << *ivs2 << endl; // Austen
    for (auto c : vs2) cout << c << " "; // Shakespeare Milton
    cout << endl;


    
    // 3. insertion
    cout << "3. insertion:" << endl;
    // adding elements to a vector or a string may cause the entire object to be reallocated. 
    // Reallocating an object requires allocating new memory and moving elements from the old space to the new.
    vs1.push_back("Jackey"); // Sometimes, using push_back() to add element at the end of the vector will also cause reallocated
    cout << *it1;    // do not output anything
    cout << *(vs1.end()--) << endl;

    // Adding elements to a vector potentially invalidated all existing iterators, references and pointers into the container
    
    // warning: inserting anywhere but at the end of a vector might be slow
    vs1.insert(vs1.begin()++, "Carl");
    for (auto c : vs1) cout << c << " ";

    cout << endl;
    // insert() returns an iterator referring to the element that was added
    vector<string> vs4;
    auto iter = vs4.begin();
    string word;
    while (cin >> word && word != "Enter")
	iter = vs4.insert(iter, word); // same as calling push_front() (althought there are no push_front() in vector)

    vector<Sales_data> vsd;
    vsd.emplace_back("978-0590353403", 25, 15.99);
    vsd.push_back(Sales_data("978-0670357893", 67, 24.38));



    // 4. deleting
    auto it6 = vs2.erase(vs2.begin()++);
    cout << *it6 << endl; // Milton
    for (auto c : vs2) cout << c << " "; // Milton
    cout << endl;



    // 5. capacity and size 
    vector<int> vi1;
    cout << "vi1: size: " << vi1.size() << " capacity: " << vi1.capacity() << endl; // vi1: size: 0 capacity: 0    
    for (vector<int>::size_type ix = 0; ix != 24; ++ix) vi1.push_back(ix);
    cout << "vi1: size: " << vi1.size() << " capacity: " << vi1.capacity() << endl; // vi1: size: 24 capacity: 32     
    vi1.reserve(50);
    cout << "vi1: size: " << vi1.size() << " capacity: " << vi1.capacity() << endl; // vi1: size: 24 capacity: 50     
    while (vi1.size() != vi1.capacity()) vi1.push_back(0);
    cout << "vi1: size: " << vi1.size() << " capacity: " << vi1.capacity() << endl; // vi1: size: 50 capacity: 50     
    vi1.push_back(42);
    cout << "vi1: size: " << vi1.size() << " capacity: " << vi1.capacity() << endl; // vi1: size: 51 capacity: 100     
    vi1.shrink_to_fit();
    cout << "vi1: size: " << vi1.size() << " capacity: " << vi1.capacity() << endl; // vi1: size: 51 capacity: 51    


    return 0;
}

int main() {
    Vector();
}

