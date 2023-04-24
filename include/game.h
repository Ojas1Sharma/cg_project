#ifndef GAME_H
#define GAME_H

#include <game_level.h>

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

typedef std::tuple<bool, Direction, glm::vec2> Collision;

class Game {
   public:
    GameState State;
    bool Keys[1024];
    bool KeysProcessed[1024];
    unsigned int Width, Height;
    std::vector<GameLevel> Levels;
    unsigned int Level;
    unsigned int Lives;
    Game(unsigned int width, unsigned int height);
    ~Game();
    void Init();
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
    void DoCollisions();
    void ResetLevel();
    void ResetPlayer();
};

#endif
