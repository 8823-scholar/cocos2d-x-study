#ifndef __BEFOOL_IOSWRAPPER_H__
#define __BEFOOL_IOSWRAPPER_H__

#include "cocos2d.h"

namespace befool
{
    using namespace cocos2d;

    class iOSWrapper : public cocos2d::CCObject
    {
        public:
            void playVideo(char *path);
            static iOSWrapper *getShared();
    };
}

#endif // __BEFOOL_IOSWRAPPER_H__
