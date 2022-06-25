#define LOW_FRAME_TIME 16
#define HIGH_FRAME_TIME 17

class FrameDelayManager {
    private:
        int frameCounter;
    public:
        FrameDelayManager();
        int getCurrentFrameDelay();
};