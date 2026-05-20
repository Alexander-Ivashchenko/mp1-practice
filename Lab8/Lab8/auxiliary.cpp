#include <iostream>
#include <iomanip>
#include "auxiliary.hpp"

using namespace std;

void inputProduct(Product& p) {
    cout << "Название: ";
    cin >> p.name;
    cout << "Единица измерения: ";
    cin >> p.unit;
    cout << "Цена: ";
    cin >> p.price;
    cout << "Количество: ";
    cin >> p.quantity;
    cout << "Дата (ДД.ММ.ГГГГ): ";
    cin >> p.date;
}

void printProduct(const Product& p) {
    cout << left << setw(20) << p.name
        << left << setw(10) << p.unit
        << right << setw(8) << fixed << setprecision(2) << p.price
        << right << setw(8) << p.quantity
        << left << setw(12) << p.date << endl;
}