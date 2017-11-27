#ifndef SCOREREWARDS_H
#define SCOREREWARDS_H

#include <vector>
#include <cstdint>

struct GameEngine;

class ScoreRewards {
    std::vector<std::uint64_t> ScoreGoals;
    GameEngine* pEngine;

    public:
    ScoreRewards()=default;
    ScoreRewards(GameEngine* EnginePointer);
    void BindEngine(GameEngine* EnginePointer);
    void AddReward(std::uint64_t ScoreValue);
    bool CheckReward(void);
    void Clear();
};

#endif // SCOREREWARDS_H
