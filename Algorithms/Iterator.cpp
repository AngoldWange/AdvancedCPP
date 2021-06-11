#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <fstream>

using namespace::std;

// print containers like vector, deque, list, etc
template<typename Sequence>
auto println(Sequence const& seq) -> std::ostream& {
    for (auto const& elem : seq) {
	cout << elem << " ";
    }
    return cout << endl;
}

void e2fct1() {
    // read int from istream
    vector<int> vi;
    istream_iterator<int> int_it(cin);
    istream_iterator<int> int_eof; // null iterator (the end itrator value)
    // An iterator bound to a stream is equal to the end iterator 
    // once its associated stream hits end-of-file(\0) or encounters an IO error(type error).
    while ( int_it != int_eof ) {
	vi.push_back(*int_it++);   // *(int_it++)
    }
    println(vi);
}

void e2fct2() {
    // same effect of e2fct1
    istream_iterator<int> int_it(cin), int_eof;
    vector<int> vi(int_it, int_eof);
    println(vi);
}

void e2fct3() {
    // use ostream_iterator
    vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    ostream_iterator<int> out_it(cout, " "); // add a " " after each output
    for (int i : vi) {
	*out_it++ = i;
    }
    cout << endl;
}

void e2fct4() {
    // same effect with e2fct3
    vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    ostream_iterator<int> out_it(cout, " "); // add a " " after each output
    copy(vi.begin(), vi.end(), out_it);
    cout << endl;
}

void e2fct5() {
    // read from file and output (10.29)
    ifstream ifs("./data/afile.txt");
    istream_iterator<string> str_in(ifs), str_eof;
    vector<string> vs;
    copy(str_in, str_eof, back_inserter(vs));
    copy(vs.cbegin(), vs.cend(), ostream_iterator<string>(cout, "\n"));
}

void e3fct1() {
    // find the last word
    string line = "FIRST,MIDDLE,LAST";
    auto rcomma = find(line.crbegin(), line.crend(), ','); // rcomma is a reverse iterator
    cout << string(rcomma.base(), line.cend()) << endl; // base() transform rcomma into a normal iterator // will output: LAST
}

int main() {

    // Example1 3 inserters:
    // An inserter is an iterator adaptor
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // uses inserter:
    // Elements are inserted ahead of the element denoted by the given iterator.
    list<int> lst1;
    copy(vec.cbegin(), vec.cend(), inserter(lst1, lst1.begin()));
    println(lst1);

    // uses back inserter:
    list<int> lst2;
    copy(vec.cbegin(), vec.cend(), back_inserter(lst2));
    println(lst2);

    // uses back inserter:
    list<int> lst3;
    copy(vec.cbegin(), vec.cend(), front_inserter(lst3));
    println(lst3);

    
    // Example2 iostream iterators
    // #1 istream iterator

    // e2fct1: example of istream
    // e2fct1();

    // e2fct2: same effect with e2fct1
    // e2fct2();


    // #2 ostream iterator

    // e2fct3: use ostream_iterator
    e2fct3(); // 1 2 3 4 5 6 7

    // e2fct4: same effect with e2fct3
    e2fct4(); // 1 2 3 4 5 6 7


    // #3 applications
    
    // e2fct5: read from file and output (10.29)
    e2fct5();

    // e2fct6: (10.33)
    // please check data/e2fct6.cpp


    // Example3 Reverse Iterators

    // find the last word
    e3fct1();
}


























