#include "GameManager.h"
#include <iostream>

GameManager* GameManager::instance;

void GameManager::Update() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
            gameOver = true;
        }
    }
    ball.Update();
    Draw();
}

void GameManager::Draw() {
    window.clear();
    ball.Draw();
    window.display();
}

GameManager* GameManager::getInstance(){
    if (!instance)
        instance = new GameManager;
    return instance;
}