# 🔐 Générateur de mots de passe - C++ / SFML

Ce projet est un **générateur de mots de passe** développé en **C++**, avec deux interfaces disponibles :

- 🖥️ Une version **console**
- 🖼️ Une version **graphique** construite avec **SFML**

Il permet de générer des mots de passe sécurisés, personnalisables selon la longueur et le type de caractères souhaités (lettres, chiffres, symboles).

---

## ✨ Fonctionnalités

✅ Génération de mots de passe aléatoires  
✅ Choix de la **longueur** du mot de passe  
✅ Sélection des **caractères à inclure** (lettres, chiffres, symboles)  
✅ Interface graphique simple et moderne (avec SFML)  
✅ Version console disponible pour un usage rapide

---

## 🗂 Structure du projet

```
Password_Generator/
├── console-version/
│   ├── src/
│   │   └── main.cpp
│   ├── build/                 # (généré automatiquement)
│   └── Makefile
│
├── front-version/
│   ├── src/
│   │   └── main.cpp
│   ├── build/                 # (généré automatiquement)
│   └── Makefile
│
├── shared/
│   ├── password_generator.cpp
│   └── password_generator.hpp
│
├── docs/
│   └── screenshot.png         # Capture d'écran de l'interface (optionnel)
│
├── .gitignore
├── README.md
└── LICENSE                    # (optionnel)
```


---

## 🚀 Lancement

### 🔧 Pré-requis

- Linux (testé sur Ubuntu/Debian)
- [SFML](https://www.sfml-dev.org/) installé (`libsfml-dev`)
- Un compilateur C++ (`g++` recommandé)

### 📦 Installation des dépendances (Ubuntu)

```bash
sudo apt update
sudo apt install g++ libsfml-dev

---

### Version console

cd console-version
make
./build/password_console

### Version graphique

cd front-version
make
./build/password_front

