#include <iostream>

std::string consolidation(std::string strOne, std::string strTwo, std::string strThree)
{
    std::string str = strOne + strTwo + strThree;
    return str;
}

bool symbols_check(std::string str)
{
    int len = str.length();
    if (len != 9) {
        return false;
    } else {
        for (int i = 0; i < len; i++) {
            if (str[i] != 'X' && str[i] != 'O' && str[i] != '.') {
                return false;
            }
        }
    }
    return true;
}

int symbols_ratio(std::string str)
{
    int len = str.length();
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'X') {
            count++;
        } else if (str[i] == 'O') {
            count--;
        }
    }
    if (count == 0) {
        return 0;
    } else if (count == 1) {
        return 1;
    } else {
        return -1;
    }
}

std::string row_winner_check(std::string str)
{
    std::string result;
    int len = str.length();
    for (int n = 0; n < len; n += 3) {
        int count = 0;
        for (int i = n; i < n + 3; i++) {
            if (str[i] == 'X') {
                count++;
            } else if (str[i] == 'O') {
                count--;
            }
        }
        if (count == 3) {
            result += 'X';
        } else if (count == -3) {
            result += 'O';
        } else {
            result += '.';
        }
    }

    return result;
}

std::string column_winner_check(std::string str)
{
    std::string result;
    int len = str.length();
    for (int n = 1; n <= 3; n++) {
        int count = 0;
        for (int i = n - 1; i < len; i += 3) {
            if (str[i] == 'X') {
                count++;
            } else if (str[i] == 'O') {
                count--;
            }
        }
        if (count == 3) {
            result += 'X';
        } else if (count == -3) {
            result += 'O';
        } else {
            result += '.';
        }
    }
    return result;
}

std::string diagonal_winner_check(std::string str)
{
    std::string result;
    int len = str.length();
    int count = 0;
    for (int i = 0; i < len; i += 4) {
        if (str[i] == 'X') {
            count++;
        } else if (str[i] == 'O') {
            count--;
        }
    }
    if (count == 3) {
        result += 'X';
    } else if (count == -3) {
        result += 'O';
    } else {
        result += '.';
    }

    count = 0;

    for (int i = 2; i < len - 2; i += 2) {
        if (str[i] == 'X') {
            count++;
        } else if (str[i] == 'O') {
            count--;
        }
    }
    if (count == 3) {
        result += 'X';
    } else if (count == -3) {
        result += 'O';
    } else {
        result += '.';
    }

    return result;
}

char winner_check (std::string str)
{
    std::string grandCons = consolidation(row_winner_check(str), column_winner_check(str), diagonal_winner_check(str));
    int len = grandCons.length();
    int countX = 0;
    int countO = 0;
    for (int i = 0; i < len; i++) {
        if (countX > 1 || countO > 1 || (countX == 1 && countO == 1)) {
            return '.';
        } else {
            if (grandCons[i] == 'X') {
                countX++;
            } else if (grandCons[i] == 'O') {
                countO++;
            }
        }
    }
    if (countX == 1) {
        return 'X';
    } else if (countO == 1) {
        return 'O';
    }
}

int main() {
    std::cout << "Tic tac toe results" << std::endl;

    std::string first, second, third;
    std::cout << "Enter game disposition line by line:" << std::endl;
    std::cin >> first >> second >> third;

    std::string cons = consolidation(first, second, third);

    if (!symbols_check(cons)) {
        std::cout << "Incorrect" << std::endl;
    } else if (symbols_ratio(cons) < 0 || symbols_ratio(cons) > 1) {
        std::cout << "Incorrect" << std::endl;
    } else if (winner_check(cons) == 'X' && symbols_ratio(cons) == 1) {
        std::cout << "Petya won" << std::endl;
    } else if (winner_check(cons) == 'X' && symbols_ratio(cons) == 0) {
        std::cout << "Incorrect" << std::endl;
    } else if (winner_check(cons) == 'O' && symbols_ratio(cons) == 0) {
        std::cout << "Vanya won" << std::endl;
    } else if (winner_check(cons) == 'O' && symbols_ratio(cons) == 1) {
        std::cout << "Incorrect" << std::endl;
    } else {
        std::cout << "Nobody" << std::endl;
    }

    return 0;
}