#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Ovni {
public:
    Ovni(int tipo = 0) : tipo(tipo), y(0) {}
    void mover() {
        y++;
    }
    int getTipo() {
        return tipo;
    }
    int getY() {
        return y;
    }
private:
    int tipo;
    int y;
};

class Estrella {
public:
    Estrella() : x(0) {}
    void mover() {
        x++;
    }
    int getX() {
        return x;
    }
private:
    int x;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ovnis y Estrella");

    char opcion;
    std::vector<Ovni> ovnis; // Usamos un vector en lugar de un arreglo
    Estrella estrella;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Mueve y muestra los ovnis
        for (size_t i = 0; i < ovnis.size(); i++) {
            ovnis[i].mover();
        }

        // Mueve y muestra la estrella
        estrella.mover();

        // Verifica colisiones
        for (size_t i = 0; i < ovnis.size(); i++) {
            if (ovnis[i].getY() == 38 && estrella.getX() == 1) {
                if (ovnis[i].getTipo() == 1) {
                    std::cout << "Pida un deseo" << std::endl;
                    _getch();
                } else if (ovnis[i].getTipo() == 2) {
                    std::cout << "PELIGRO DE INVASION" << std::endl;
                    window.close(); // Cierra la ventana si hay peligro de invasión
                }
            }
        }

        // Verifica entrada del usuario
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            ovnis.push_back(Ovni(1));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            ovnis.push_back(Ovni(2));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            estrella = Estrella();
        }

        window.clear();
        // Dibuja ovnis y estrella aquí usando funciones de SFML
        window.display();
    }

    return 0;
}
