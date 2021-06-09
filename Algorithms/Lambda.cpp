#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace::std;

// print containers like vector, deque, list, etc
template<typename Sequence>
auto println(Sequence const& seq) -> std::ostream& {
    for (auto const& elem : seq) {
	cout << elem << " ";
    }
    return cout << endl;
}

auto elimDups(vector<string> &words) -> vector<string>& {
    // this function makes every string in words unique
    sort(words.begin(), words.end());
    auto new_end = unique(words.begin(), words.end());
    words.erase(new_end, words.end());
    return words;
}

void biggies(vector<string> &vs, size_t sz, ostream &os = cout, char c = ' ') {
    elimDups(vs);
    // sort by size, but maintain alphabetical order for same size.
    stable_sort(vs.begin(), vs.end(), [](string const& lhs, string const& rhs) { return lhs.size() < rhs.size(); } );

    // get an iterator to the first one whose size() is >= sz
    auto wc = find_if(vs.begin(), vs.end(), [sz](const string& a) { return a.size() > sz; });

    // print the biggies
    for_each(wc, vs.end(), [&, c](const string &s) { os << s << c; });   // must use capture by reference to capture os

}

void e2fct1() {
    // capture by value
    size_t v1 = 42;
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();  // j == 42
    cout << "Example2 function1 j: "<< j << endl;
}
void e2fct2() {
    // capture by reference
    size_t v1 = 42;
    auto f = [&v1] { return v1; };
    v1 = 0;
    auto j = f();  // j == 0
    cout << "Example2 function2 j: "<< j << endl;
}

bool check_size(const string &s, string::size_type sz) {
    return s.size() > sz;
}
void biggies3(vector<string> &vs, size_t sz, ostream &os = cout, char c = ' ') {
    // same logic with biggies()
    elimDups(vs);
    // sort by size, but maintain alphabetical order for same size.
    stable_sort(vs.begin(), vs.end(), [](string const& lhs, string const& rhs) { return lhs.size() < rhs.size(); } );

    // get an iterator to the first one whose size() is >= sz
    auto wc = find_if(vs.begin(), vs.end(), bind(check_size, placeholders::_1, sz)); // check_size() replace lambda expression 
    // notice that: bind() return a callable: (e.g. bindreturn()) and this callable will call: bindreturn(s) in find_if

    // print the biggies
    for_each(wc, vs.end(), [&, c](const string &s) { os << s << c; });  // must use capture by reference to capture os 
//  for_each(wc, vs.end(), [=, &os](const string &s) { os << s << c; });  // or in this way
//  for_each(wc, vs.end(), [&os, c])(const string &s) { os << s << c; }); // or in this way

}



int main() {
    // Lambda expressions are most useful for simple operations that we do not need to use in more than one or two places. 
    // Similarly, if an operation requires many statements or multiple times, it is ordinarily better to use a function.

    // Example1 test biggies:
    vector<string> Story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    println(Story);
    biggies(Story, 3); // over slow jumps quick turtle  
    cout << endl;


    // Example2 test lambda capture:
    // If possible, avoid capturing pointers or references.
    e2fct1(); e2fct2(); // 42 0
    cout << endl;
    

    // Example 3 test bind()

    //  It takes a callable object and generates a new callable that “adapts” the parameter list of the original object.

    // #1 bind()
    string s = "hello";
    auto check31 = bind(check_size, placeholders::_1, 6);
    bool b31 = check31(s);



    // #2 using bind() to replace lambda
    vector<string> Story3 = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies3(Story3, 3); // over slow jumps quick turtle
    cout << endl;

    
    // #3 multiple parameters
    // assume: f is a callable function
    // auto g = bind(f, a, b, _2, c, _1);
    // Then when we call:
    // g(X, Y);
    // it will be: 
    // f(a, b, Y, c, X);

    

    return 0;
}
