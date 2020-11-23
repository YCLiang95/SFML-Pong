#include "GameManager.h"
#include <iostream>

GameManager* GameManager::instance;

void GameManager::Update() {

    deltaTime = (float)(clock() - lastTime) / CLOCKS_PER_SEC * GameManager::getInstance()->timeScale;
    lastTime = clock();

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
    ball2->Update();

    ps->Update();

    Draw();
}

void GameManager::Draw() {
    window.clear();
    ball->Draw();
    ball2->Draw();

    scoreTextLeft.setString(std::to_string(leftScore));
    scoreTextRight.setString(std::to_string(rightScore));
    window.draw(scoreTextLeft);
    window.draw(scoreTextRight);

    for (int i = 0; i < 4; i++)
        peddles[i]->Draw();

    ps->Draw();

    window.display();
}

GameManager* GameManager::getInstance(){
    if (!instance)
        instance = new GameManager;
    return instance;
}

void GameManager::LoadFont() {
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Failed to load Font" << std::endl;
        return;
    }
    scoreTextLeft.setFont(font);
    scoreTextRight.setFont(font);
    scoreTextLeft.setCharacterSize(24);
    scoreTextRight.setCharacterSize(24);
    scoreTextLeft.setFillColor(sf::Color::White);
    scoreTextRight.setFillColor(sf::Color::White);
    scoreTextRight.setPosition(width - 100, 0);
}