#include "FrameDelayManager.h"

FrameDelayManager::FrameDelayManager() {
    frameCounter = 2;
}
int FrameDelayManager::getCurrentFrameDelay() {
    if (frameCounter == 0) {
        frameCounter = 2;
        return LOW_FRAME_TIME;
    }
    else {
        frameCounter--;
        return HIGH_FRAME_TIME;
    }
}