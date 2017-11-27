#include "ScoreRewards.h"
#include "GameEngine.h"

ScoreRewards::ScoreRewards(GameEngine* EnginePointer) : pEngine(EnginePointer) {}

void ScoreRewards::AddReward(std::uint64_t ScoreValue) {
    if (ScoreGoals.size()>0) {
        if (ScoreValue<ScoreGoals.back())
            return;
        else
            ScoreGoals.push_back(ScoreValue);
    }
    else {
        ScoreGoals.push_back(ScoreValue);
    }
}

void ScoreRewards::BindEngine(GameEngine* EnginePointer) {
    pEngine=EnginePointer;
}

bool ScoreRewards::CheckReward(void) {
    if (ScoreGoals.size()>0) {
        if (ScoreGoals.front()<=pEngine->Score) {
            ScoreGoals.erase(ScoreGoals.begin());
            return true;
        }
    }
    return false;
}

void ScoreRewards::Clear(void) {
    ScoreGoals.clear();
}
