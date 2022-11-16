#include <iostream>


std::string encrypt_caesar(std::string str, int encryptKey)
{

    std::string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";

    int n = 0;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            int pos = capital.find(str[i]) + encryptKey;
            if (pos < 0 && pos >= -26) {
                n = 26 + pos;
            } else if (pos < -26) {
                if (pos % 26 == 0) {
                    n = 0;
                } else {
                    n = 26 + (pos - (pos / 26 * 26));
                }
            } else if (pos >= 0 && pos < 26) {
                n = pos;
            } else if (pos >= 26) {
                n = pos - (pos / 26 * 26);
            }
            str[i] = capital[n];
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            int pos = lowercase.find(str[i]) + encryptKey;

            if (pos < 0 && pos >= -26) {
                n = 26 + pos;
            } else if (pos < -26) {
                if (pos % 26 == 0) {
                    n = 0;
                } else {
                    n = 26 + (pos - (pos / 26 * 26));
                }
            } else if (pos >= 0 && pos < 26) {
                n = pos;
            } else if (pos >= 26) {
                n = pos - (pos / 26 * 26);
            }
            str[i] = lowercase[n];
        }
    }

    return str;
}

int main() {
    std::cout << "Encrypt/decrypt Caesar" << std::endl;

    std::string originalText;
    std::cout << "Enter yot text below:" << std::endl;
    std::getline(std::cin, originalText);

    int encryptKey = 0;
    std::cout << "Enter your encrypt key: ";
    std::cin >> encryptKey;

    originalText = encrypt_caesar(originalText, encryptKey);
    std::cout << "Caesar encrypted: " << originalText << std::endl;

    encryptKey *= - 1;
    originalText = encrypt_caesar(originalText, encryptKey);
    std::cout << "Caesar decrypted: " << originalText << std::endl;

    return 0;
}