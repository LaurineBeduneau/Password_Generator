#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "../shared/password_generator.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 400), "Generateur de mots de passe");

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Erreur chargement police !" << std::endl;
        return 1;
    }

    // Couleurs
    sf::Color bgColor(245, 245, 250);
    sf::Color boxColor(255, 255, 255);
    sf::Color outlineColor(200, 200, 200);
    sf::Color primaryColor(70, 130, 180);      // Steel blue
    sf::Color hoverColor(90, 150, 200);
    sf::Color successColor(100, 200, 100);
    sf::Color textColor(30, 30, 30);

    // Titre
    sf::Text title("Generateur de mot de passe", font, 26);
    title.setFillColor(textColor);
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setPosition(300 - titleBounds.width / 2, 20);

    // Champ de saisie
    sf::RectangleShape inputBox(sf::Vector2f(200, 40));
    inputBox.setPosition(200, 80);
    inputBox.setFillColor(boxColor);
    inputBox.setOutlineColor(outlineColor);
    inputBox.setOutlineThickness(1);

    sf::Text inputText("", font, 20);
    inputText.setFillColor(textColor);
    inputText.setPosition(210, 85);
    std::string inputString = "";

    // Cases à cocher
    bool useLetters = true;
    bool useNumbers = true;
    bool useSymbols = true;

    auto createCheckbox = [&](float x, float y, const std::string& label, sf::RectangleShape& box, sf::Text& text) {
        box.setSize(sf::Vector2f(20, 20));
        box.setPosition(x, y);
        box.setFillColor(successColor);
        box.setOutlineColor(outlineColor);
        box.setOutlineThickness(1);

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(16);
        text.setFillColor(textColor);
        text.setPosition(x + 30, y - 2);
    };

    sf::RectangleShape lettersBox, numbersBox, symbolsBox;
    sf::Text lettersText, numbersText, symbolsText;
    createCheckbox(200, 140, "Lettres", lettersBox, lettersText);
    createCheckbox(200, 180, "Chiffres", numbersBox, numbersText);
    createCheckbox(200, 220, "Symboles", symbolsBox, symbolsText);

    // Bouton générer
    sf::RectangleShape generateButton(sf::Vector2f(160, 45));
    generateButton.setPosition(220, 270);
    generateButton.setFillColor(primaryColor);

    sf::Text buttonText("Generer", font, 20);
    buttonText.setFillColor(sf::Color::White);
    sf::FloatRect buttonBounds = buttonText.getLocalBounds();
    buttonText.setPosition(220 + (160 - buttonBounds.width) / 2, 278);

    // Mot de passe généré
    sf::Text passwordText("", font, 18);
    passwordText.setFillColor(sf::Color(50, 50, 100));
    passwordText.setPosition(100, 330);

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Clavier
            if (event.type == sf::Event::TextEntered) {
                if (isdigit(event.text.unicode) && inputString.size() < 3) {
                    inputString += static_cast<char>(event.text.unicode);
                    inputText.setString(inputString);
                } else if (event.text.unicode == 8 && !inputString.empty()) {
                    inputString.pop_back();
                    inputText.setString(inputString);
                }
            }

            // Souris
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                float x = event.mouseButton.x;
                float y = event.mouseButton.y;

                if (lettersBox.getGlobalBounds().contains(x, y)) {
                    useLetters = !useLetters;
                    lettersBox.setFillColor(useLetters ? successColor : boxColor);
                }
                if (numbersBox.getGlobalBounds().contains(x, y)) {
                    useNumbers = !useNumbers;
                    numbersBox.setFillColor(useNumbers ? successColor : boxColor);
                }
                if (symbolsBox.getGlobalBounds().contains(x, y)) {
                    useSymbols = !useSymbols;
                    symbolsBox.setFillColor(useSymbols ? successColor : boxColor);
                }

                if (generateButton.getGlobalBounds().contains(x, y)) {
                    int len = inputString.empty() ? 0 : std::stoi(inputString);
                    if (len > 0 && (useLetters || useNumbers || useSymbols)) {
                        std::string pwd = generatePassword(len, useLetters, useNumbers, useSymbols);
                        passwordText.setString("Mot de passe : " + pwd);
                        std::cout << "Mot de passe : " << pwd << std::endl;
                    } else {
                        passwordText.setString("Veuillez entrer une longueur valide et cocher au moins une option.");
                    }
                }
            }
        }

        // Hover effet sur le bouton
        if (generateButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            generateButton.setFillColor(hoverColor);
        } else {
            generateButton.setFillColor(primaryColor);
        }

        // Affichage
        window.clear(bgColor);
        window.draw(title);
        window.draw(inputBox);
        window.draw(inputText);

        window.draw(lettersBox); window.draw(lettersText);
        window.draw(numbersBox); window.draw(numbersText);
        window.draw(symbolsBox); window.draw(symbolsText);

        window.draw(generateButton);
        window.draw(buttonText);
        window.draw(passwordText);
        window.display();
    }

    return 0;
}