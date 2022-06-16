#include "RandomOptionManager.h"

RandomOptionManager::RandomOptionManager(OPTION* options, int amtOptions) {
    RandomOptionManager::options = options;
    RandomOptionManager::amtOptions = amtOptions;
    // {NO_DI, 1}, {DI_RIGHT, 2}, {DI_LEFT, 2}
    int totalWeightSum = 0;
    for (int i = 0; i < amtOptions; i++) {
        totalWeightSum += options[i].weight;
    }
    RandomOptionManager::totalWeightSum = totalWeightSum;
    randomizeOption();
}
bool RandomOptionManager::isThisOption(int currentWeightSum, int i, int randomWeight) {
    return (randomWeight >= currentWeightSum && randomWeight < (currentWeightSum + options[i].weight));
}
void RandomOptionManager::randomizeOption() {
    int randomWeight = random(0, totalWeightSum);
    int currentWeightSum = 0;
    for (int i = 0; i < amtOptions; i++) {
        if (isThisOption(currentWeightSum, i, randomWeight)) {
            currentOptionIndex = i;
            return;
        }
        else {
            currentWeightSum += options[i].weight;
        }
    }
}
int RandomOptionManager::getCurrentOptionId() {
    return options[currentOptionIndex].id;
}