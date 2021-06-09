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

auto elimDups(vector<string> &words) -> vector<string>& {
    // this function makes every string in words unique
    sort(words.begin(), words.end());
    println(words);

    auto new_end = unique(words.begin(), words.end());
    println(words);

    words.erase(new_end, words.end());
    return words;
}
int main() {
    // Test elimDups
    vector<string> Story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    println(Story);
    println(elimDups(Story)); // fox jumps over quick red slow the turtle
}

