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

    for (int i = 0; i < height; i++) {
        left[i] = false;
        right[i] = false;
    }

    for (int i = 0; i < 4; i++)
        peddles[i]->Update();
    ball->Update();
    Draw();
}

void GameManager::Draw() {
    window.clear();
    ball->Draw();

    for (int i = 0; i < 4; i++)
        peddles[i]->Draw();

    window.display();
}

GameManager* GameManager::getInstance(){
    if (!instance)
        instance = new GameManager;
    return instance;
}