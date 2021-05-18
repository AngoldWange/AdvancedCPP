#include <string>
#include <iostream>
struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p) :
	bookNo(s), units_sold(n), revenue(p) { }
    Sales_data(std::istream);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};
