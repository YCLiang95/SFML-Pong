#include "GameManager.h"

GameManager* GameManager::instance;

void GameManager::Update() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    Draw();
}

void GameManager::Draw() {
    window.clear();
    window.display();
}

GameManager* GameManager::getInstance(){
    if (!instance)
        instance = new GameManager;
    return instance;
}