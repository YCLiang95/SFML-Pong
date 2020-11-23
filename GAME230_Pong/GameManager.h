#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Peddle.h"

class GameManager {
    GameManager() {
        width = 800;
        height = 600;
        window.create(sf::VideoMode(width, height), "Pong");

        ball = new Ball();
        peddles[0] = new Peddle(0, 0, false, true);
        peddles[1] = new Peddle(790, 0, false, false);

        peddles[2] = new Peddle(0, 0, true, false);
        peddles[3] = new Peddle(790, 0, true, false);

        left = new bool[height];
        right = new bool[height];

        leftScore = 0.0f;
        rightScore = 0.0f;

        timeScale = 1.0f;
    }



public:
    int height, width;
    sf::RenderWindow window;
    bool gameOver = false;

    static GameManager* getInstance();
    void Draw();
    void Update();

    Ball* ball;
    Peddle* peddles[4];

    bool* left;
    bool* right;

    int leftScore;
    int rightScore;

    float timeScale;

    ~GameManager() {
        delete(ball);
        //for (int i = 0; i < 4; i++)
            //delete (peddles[i]);
        delete(peddles);
    }

private:
    static GameManager* instance;
};