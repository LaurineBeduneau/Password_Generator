#include <iostream>
#include "../shared/password_generator.hpp"

int main() {
    int length;
    bool useLetters, useNumbers, useSymbols;

    std::cout << "Entrez la longueur du mot de passe: ";
    std::cin >> length;

    std::cout << "Inclure des lettres ? (1 = oui / 0 = non): ";
    std::cin >> useLetters;

    std::cout << "Inclure des chiffres ? (1 = oui / 0 = non): ";
    std::cin >> useNumbers;

    std::cout << "Inclure des symboles ? (1 = oui / 0 = non): ";
    std::cin >> useSymbols;

    std::string password = generatePassword(length, useLetters, useNumbers, useSymbols);
    std::cout << "Mot de passe généré : " << password << std::endl;

    return 0;
}