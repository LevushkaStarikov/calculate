#include <iostream>

#include "tasks.hpp"

bool wrong = false;

int main() {
    init();
    std::cout << "Введите выражение:\n";
    std::cin >> calculation;
    numbers_symbols = separate(calculation);
    std::string replace_value;
    for (int i = 0; i < numbers_symbols.size(); i++) {
        std::cout << std::endl << numbers_symbols[i];
        if (numbers_symbols[i] == "x") {
            std::cout << "\nВведите x: ";
            std::cin >> replace_value;
            std::replace_if(numbers_symbols.begin(), numbers_symbols.end(), [](std::string a) { return a == "x"; },
                            replace_value); // замена x на значение пользователя
            break;
        }

    }
    check_equation(numbers_symbols);
    int i = 0;
    while (i < numbers_symbols.size() and wrong != true) {
        if (operations.find(numbers_symbols[i]) == operations.end()) {   // если не операция
            numbers.push_back(numbers_symbols[i]);
            i += 1;
        } else {

            if (symbols.empty()) {       // если ещё не было операций, то добавить
                //cout<<"\nok2";
                symbols.push_back(numbers_symbols[i]);
                i += 1;
            } else if (operations.find(numbers_symbols[i])->second <= operations.find(symbols.back())->second and
                       (symbols.back() != "(" or numbers_symbols[i] ==
                                                 ")")) {
                counting();
                if (operindex.find(numbers_symbols[i])->second == 41) {   // если нашлась закрывающая скобка
                    while (symbols.back() != "(" and wrong != true) {

                        counting();
                        check_numbers(numbers);
                    }
                    symbols.pop_back();
                    i += 1;

                }
            } else {


                symbols.push_back(numbers_symbols[i]);
                i += 1;

            }
        }
        check_numbers(numbers);
    }
    std::cout << std::endl;
    while (!symbols.empty() and wrong != true) {
        counting();
        check_numbers(numbers);
    }
    if (wrong != true) {
        std::cout << "\nРезультат " << numbers[0] << std::endl;
    } else {
        std::cout << "\nВ выражении ошибка";
    }
    return 0;
}
