#ifndef __BFSPRITE_H__
#define __BFSPRITE_H__

#include "cocos2d.h"

class BFSprite : public cocos2d::Sprite
{
    public:

        BFSprite();

        cocos2d::Rect getRect();
        bool isTapped(cocos2d::Point);
};

#endif // __BFSPRITE_H__
