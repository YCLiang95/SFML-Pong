#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

class GameManager {
    GameManager() {
        width = 800;
        height = 600;
        window.create(sf::VideoMode(width, height), "Pong");
    }

public:
    int height, width;
    sf::RenderWindow window;
    bool gameOver = false;

    static GameManager* getInstance();
    void Draw();
    void Update();

    Ball ball;

private:
    static GameManager* instance;
};