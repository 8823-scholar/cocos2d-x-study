#include "SimpleVideoEngine.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "iOSWrapper.h"
#endif

namespace befool {
    static SimpleVideoEngine* instance = NULL;

    /**
     * インスタンスの取得
     *
     * @return  befool::SimpleVideoEngine
     */
    SimpleVideoEngine *SimpleVideoEngine::getShared()
    {
        if (! instance) {
            instance = new SimpleVideoEngine();
        }
        return instance;
    }


    /**
     * 動画の再生
     *
     * @return  void
     */
    void SimpleVideoEngine::playVideo(char *path)
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        iOSWrapper::getShared()->playVideo(path);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
    }
}

