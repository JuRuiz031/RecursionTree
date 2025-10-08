// copyright Juan Fernando Ruiz 2024

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include "PTree.hpp"

PTree::PTree(double L, int N) {
    width = (6 * L);
    height = (4 * L);
// ready window to show tree
    sf::RenderWindow window(sf::VideoMode(width, height), "Pythagoras Tree");

    while(window.isOpen()) {
        for(sf::Event event; window.pollEvent(event);) {
            if(event.type == sf::Event::Closed)
                window.close();
            }
        window.clear();
        PTree::drawTree(window, L, N);
        window.display();
    }
}

void PTree::drawTree(sf::RenderTarget& target, const int N, const sf::RectangleShape& parent) {
    static const float halfSqrt2 = sqrt(2.f) / 2;

    if(N < 1) return; // end the recursion once N is done counting down
    target.draw(parent);
    auto const& size = parent.getSize();
    auto const& transform = parent.getTransform();

    // recursion on the left side
    auto left = parent;
    left.setSize(size * halfSqrt2);
    left.setOrigin(0, left.getSize().y);
    left.setPosition(transform.transformPoint({0, 0}));
    left.rotate(-45);
    PTree::drawTree(target, N - 1, left);

    // recursion on the right side
    auto right = parent;
    right.setSize(size * halfSqrt2);
    right.setOrigin(right.getSize());
    right.setPosition(transform.transformPoint({size.x, 0}));
    right.rotate(45);
    PTree::drawTree(target, N - 1, right);
}
// second overloaded function for drawing the tree
void PTree::drawTree(sf::RenderTarget& target, const float L, const int N) {
    sf::RectangleShape rect{{L, L}};

    rect.setOrigin(rect.getSize() / 2.f);
    rect.setPosition(target.getSize().x / 2.f, target.getSize().y - L / 2.f);
    rect.setFillColor(sf::Color::Green); // add color for extra credit
    PTree::drawTree(target, N, rect);
}
