#ifndef __BEFOOL_SIMPLEVIDEOENGINE_H__
#define __BEFOOL_SIMPLEVIDEOENGINE_H__

#include "cocos2d.h"

namespace befool
{
    using namespace cocos2d;

    class SimpleVideoEngine : public cocos2d::CCObject
    {
        public:
            void playVideo(char *path);
            static SimpleVideoEngine *getShared();
    };
}

#endif // __BEFOOL_SIMPLEVIDEOENGINE_H__
