// copyright Juan Fernando Ruiz 2024

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PTree.hpp"

int main() {
    double L = 0.0; // length of sides
    int N = 0; // number of recursions

    std::cin >> L >> N;
    sf::Vector2f vect;
    vect.x = 0;
    vect.y = 0;

    PTree tree(L, N);

    return 0;
}
