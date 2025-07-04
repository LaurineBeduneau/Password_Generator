#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "../shared/password_generator.hpp"

// Fonction de génération (simplifiée ici pour tester)
std::string generatePassword(int length) {
    std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string password = "";
    std::srand(std::time(nullptr));

    for (int i = 0; i < length; ++i) {
        password += chars[rand() % chars.length()];
    }

    return password;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 300), "Generateur de mots de passe");
    sf::Font font;

    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Erreur de chargement de la police !" << std::endl;
        return 1;
    }

    // Titre
    sf::Text title("Generateur de mots de passe", font, 24);
    title.setFillColor(sf::Color::Black);
    title.setPosition(100, 20);

    // Champ de saisie (affichage visuel)
    sf::RectangleShape inputBox(sf::Vector2f(200, 40));
    inputBox.setPosition(200, 80);
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);

    sf::Text inputText("", font, 20);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(210, 85);
    std::string inputString = "";

    // Bouton
    sf::RectangleShape generateButton(sf::Vector2f(150, 40));
    generateButton.setPosition(225, 140);
    generateButton.setFillColor(sf::Color(100, 150, 250));

    sf::Text buttonText("Generer", font, 20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(250, 145);

    // Texte du mot de passe généré
    sf::Text passwordText("", font, 20);
    passwordText.setFillColor(sf::Color::Blue);
    passwordText.setPosition(100, 200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Fermer la fenêtre
            if (event.type == sf::Event::Closed)
                window.close();

            // Gérer la saisie de texte
            if (event.type == sf::Event::TextEntered) {
                if (isdigit(event.text.unicode) && inputString.size() < 3) {
                    inputString += static_cast<char>(event.text.unicode);
                    inputText.setString(inputString);
                } else if (event.text.unicode == 8 && !inputString.empty()) {
                    inputString.pop_back();
                    inputText.setString(inputString);
                }
            }

            // Gérer le clic sur le bouton
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto mouseX = event.mouseButton.x;
                    auto mouseY = event.mouseButton.y;

                    if (generateButton.getGlobalBounds().contains(mouseX, mouseY)) {
                        int len = inputString.empty() ? 0 : std::stoi(inputString);
                        if (len > 0) {
                            std::string pwd = generatePassword(len);
                            passwordText.setString("Mot de passe : " + pwd);
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(title);
        window.draw(inputBox);
        window.draw(inputText);
        window.draw(generateButton);
        window.draw(buttonText);
        window.draw(passwordText);
        window.display();
    }

    return 0;
}