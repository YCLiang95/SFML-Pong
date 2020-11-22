#pragma once
#include "main.h"

class GameManager {
    GameManager() {
        height = 800;
        width = 600;
        window.create(sf::VideoMode(height, width), "Pong");
    }

public:
    int height, width;
    sf::RenderWindow window;
    bool gameOver = false;

    static GameManager* getInstance();
    void Draw();
    void Update();

private:
    static GameManager* instance;
};