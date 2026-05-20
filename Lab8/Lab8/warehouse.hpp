#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include <string>

struct Product {
    std::string name;
    std::string unit;
    float price;
    int quantity;
    std::string date;
};

void SearchMissingProducts(Product* products, int totalCount, Product** missingProducts, int* resultCount);

#endif