#include <iostream>

bool at_symbol_check(std::string str)
{
    int len = str.length();
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '@') {
            count++;
        }
    }
    if (count != 1) {
        return false;
    } else {
        return true;
    }
}

bool first_part_size_check(std::string str)
{
    int count = 0;
    for (int i = 0; i < str.find('@'); i++) {
        count++;
    }
    if (count >= 1 && count <= 64) {
        return true;
    } else {
        return false;
    }
}

bool second_part_size_check(std::string str)
{
    int len = str.length();
    int count = 0;
    for (int i = str.find('@') + 1; i < len; i++) {
        count++;
    }
    if (count >= 1 && count < 64) {
        return true;
    } else {
        return false;
    }
}

bool first_part_symbols_check(std::string str)
{
    std::string firstPartSymbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.-!#$%&'*+-/=?^_`{|}~1234567890";

    for (int i = 0; i < str.find('@'); i++) {
        if (firstPartSymbols.find(str[i]) == -1) {
            return false;
        }
    }
    return true;
}

bool second_part_symbols_check(std::string str)
{
    std::string secondPartSymbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.-1234567890";

    int len = str.length();
    for (int i = str.find('@') + 1; i < len; i++) {
        if (secondPartSymbols.find(str[i]) == -1) {
            return false;
        }
    }
    return true;
}

bool dot_check(std::string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == '.' && i == 0 || str[i] == '.' && i == len - 1 || str[i] == '.' && str[i - 1] == '.') {
            return false;
        }
    }
    return true;
}

bool second_part_dot_check(std::string str) //should be at least one dot at second part
{
    int len = str.length();
    for (int i = str.find('@') + 1; i < len; i++) {
        if (str[i] == '.') {
            return true;
        }
    }
    return false;
}

int main() {
    std::cout << "Email address validation" << std::endl;


    std::string email;
    std::cout << "Enter your Email address: ";
    std::getline(std::cin, email);


    if (!at_symbol_check(email) || !first_part_size_check(email) || !second_part_size_check(email)
            || !first_part_symbols_check(email) || !second_part_symbols_check(email) || !dot_check(email)
            || !second_part_dot_check(email)) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}
