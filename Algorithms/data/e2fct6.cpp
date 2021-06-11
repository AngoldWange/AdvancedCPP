#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

//  Write a program that takes the names of an input file and two output files.
//  The input file should hold integers. Using an istream_iterator read the input file.
//  Using ostream_iterators, write the odd numbers into the first output file.
//  Each value should be followed by a space.Write the even numbers into the second file.
//  Each of these values should be placed on a separate line.
//
//  Run: ./a.out "./input.txt" "./odd.txt" "./even.txt"

using namespace::std;

int main(int argc, char **argv) {
    if (argc != 4) return -1;

    ifstream ifs(argv[1]);
    ofstream ofs_even(argv[2]), ofs_odd(argv[3]);

    istream_iterator<int> int_it(ifs), int_eof;
    ostream_iterator<int> out_even(ofs_even, " "), out_odd(ofs_odd, " ");

    for_each(int_it, int_eof, [&out_odd, &out_even](const int ci) {
	    *(ci & 0x1 ? out_odd : out_even)++ = ci;
    });

    return 0;

}
