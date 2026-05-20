#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "auxiliary.hpp"

using namespace std;

int main(int argc, char** argv) {
    Product products[100];
    int count = 0;
    int choice;

    if (argc < 2) {
        cout << "Ошибка: не указан файл для загрузки!" << endl;
        cout << "Использование: " << argv[0] << " <имя_файла>" << endl;
        return 1;
    }

    ifstream f(argv[1]);
    if (f.is_open()) {
        f >> count;

        for (int i = 0; i < count; i++) {
            f >> products[i].name;
            f >> products[i].unit;
            f >> products[i].price;
            f >> products[i].quantity;
            f >> products[i].date;
        }
        f.close();
        cout << "Загружено " << count << " товаров из " << argv[1] << endl;
    }
    else {
        cout << "Файл " << argv[1] << " не найден. Склад пуст." << endl;
    }

    do {
        cout << "\n1. Показать все товары" << endl;
        cout << "2. Найти отсутствующие товары" << endl;
        cout << "3. Сохранить в файл" << endl;
        cout << "4. Загрузить из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 1) {
            if (count == 0) {
                cout << "Склад пуст. Загрузите данные из файла." << endl;
            }
            else {
                cout << left << setw(20) << "Название"
                    << left << setw(10) << "Ед.изм"
                    << right << setw(8) << "Цена"
                    << right << setw(8) << "Кол-во"
                    << left << setw(12) << "Дата" << endl;
                for (int i = 0; i < count; i++) {
                    printProduct(products[i]);
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "Склад пуст. Загрузите данные из файла." << endl;
            }
            else {
                Product* missingProducts[100];
                int resultCount = 0;

                SearchMissingProducts(products, count, missingProducts, &resultCount);

                if (resultCount == 0) {
                    cout << "Все товары есть в наличии" << endl;
                }
                else {
                    cout << "\n=== Отсутствующие товары ===" << endl;
                    for (int i = 0; i < resultCount; i++) {
                        cout << "- " << missingProducts[i]->name << endl;
                    }
                }
            }
        }
        else if (choice == 3) {
            ofstream fout(argv[1]);
            if (fout.is_open()) {
                fout << count << endl;
                for (int i = 0; i < count; i++) {
                    fout << products[i].name << endl;
                    fout << products[i].unit << endl;
                    fout << products[i].price << endl;
                    fout << products[i].quantity << endl;
                    fout << products[i].date << endl;
                }
                fout.close();
                cout << "Сохранено в " << argv[1] << endl;
            }
            else {
                cout << "Ошибка сохранения в " << argv[1] << endl;
            }
        }
        else if (choice == 4) {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;

            ifstream fin(filename);
            if (fin.is_open()) {
                fin >> count;

                for (int i = 0; i < count; i++) {
                    fin >> products[i].name;
                    fin >> products[i].unit;
                    fin >> products[i].price;
                    fin >> products[i].quantity;
                    fin >> products[i].date;
                }
                fin.close();
                cout << "Загружено из " << filename << endl;
            }
            else {
                cout << "Ошибка загрузки из " << filename << endl;
            }
        }
    } while (choice != 0);

    return 0;
}