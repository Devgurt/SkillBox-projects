#include <iostream>

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

std::string get_address_part(std::string str, int partNumber)
{
    int len = str.length();
    std::string part;
    int n = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != '.' && n == partNumber) {
            part += str[i];
        } else if (str[i] == '.') {
            n++;
        } else if (n > partNumber) {
            return part;
        }
    }
    return part;
}

bool values_check(std::string str)
{
    int len = str.length();
    if (len == 1) {
        if (str[0] < '0' || str[0] > '9') {
            return false;
        } return true;
    } else if (len == 2) {
        if (str[0] < '1' || str[0] > '9' || str[1] < '0' || str[1] > '9') {
            return false;
        } return true;
    } else if (len == 3) {
        int value = (str[0] - '0') * 100 + (str[1] - '0') * 10 + (str[2] - '0');
        if (str[0] < '1' || str[0] > '2' || str[1] < '0' || str[1] > '9' || str[2] < '0' || str[2] > '9' || value > 255) {
            return false;
        } return true;
    }
}

bool all_parts_check(std::string str)
{
    for (int i = 0; i < 4; i++) {
        if (!values_check(get_address_part(str, i))) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "IP-address validation" << std::endl;

    std::string ipAddress;
    std::cout << "Enter your IP-address: ";
    std::getline(std::cin, ipAddress);
    std::cout << std::endl;

    for (int i = 0; i < 4; i ++) {
        std::cout << values_check(get_address_part(ipAddress, i)) << std::endl;
    }

    if (dot_check(ipAddress) && all_parts_check(ipAddress)) {
        std::cout << "Valid" << std::endl;
    } else {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}
