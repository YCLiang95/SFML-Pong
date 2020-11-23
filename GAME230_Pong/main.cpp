#include "main.h"
#include <cstdlib>

int main(){
    GameManager* gm = gm->getInstance();
    gm->LoadFont();
    while (!gm->gameOver){
        gm->Update();
    }
    delete gm;
    exit(0);
    return 0;
}

