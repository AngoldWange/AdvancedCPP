#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace::std;

// print containers like vector, deque, list, etc
template<typename Sequence>
auto println(Sequence const& seq) -> std::ostream& {
    for (auto const& elem : seq) {
	cout << elem << " ";
    }
    return cout << endl;
}

inline bool isShorter(const string &s1, const string &s2) {return s1.size() < s2.size();}

auto elimDups(vector<string> &words) -> vector<string>& {
    // this function makes every string in words unique
    sort(words.begin(), words.end());
    auto new_end = unique(words.begin(), words.end());
    words.erase(new_end, words.end());
    return words;
}

int main() {
    vector<string> Story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    // Test pred
    elimDups(Story);
    stable_sort(Story.begin(), Story.end(), isShorter);
  //stable_sort(Story. begin(), Story.end(), [](const string &a, const string &b) { return a.size() < b.size(); })
    println(Story); // fox red the over slow jumps quick turtle 
}
