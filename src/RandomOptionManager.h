#include <Arduino.h>

typedef struct s_option {
    int id;
    int weight;
} OPTION;

class RandomOptionManager {
    private:
        int currentOptionIndex;
        OPTION* options;
        int amtOptions;
        int totalWeightSum;
        bool isThisOption(int currentWeightSum, int i, int randomWeight);
    public:
        RandomOptionManager(OPTION* options, int amtOptions);
        void randomizeOption();
        int getCurrentOptionId();
};
