// copyright Juan Fernando Ruiz 2024

#ifndef PTREE_HPP
#define PTREE_HPP

class PTree
{
    public:
        PTree(double L, int N); //default constructor

        void pTree(double L, int N, sf::Vector2f vect, sf::Vector2f origin, float rotation); //main tree function

        //get two functions to draw and branch the tree out to the sides
        void drawTree(sf::RenderTarget& target, const int N, const sf::RectangleShape& parent);
        void drawTree(sf::RenderTarget& target, const float L, const int N);

    private:
        float height;
        float width;
        int x_origin;
        int y_origin;
        float rotation = 0;
        int angle1 = 0;
        int angle2 = 0;

};

#endif
