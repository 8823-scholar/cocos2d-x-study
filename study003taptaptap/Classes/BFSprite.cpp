#include "BFSprite.h"

USING_NS_CC;

/**
 * タップされたかどうか
 *
 * @param   cocos2d::Point  point   座標点
 * @return  boolean
 */
bool BFSprite::isTapped(Point point)
{
    Rect rect = this->getRect();
    bool tapped = rect.containsPoint(point);
    if (tapped) {
        log("ok");
    } else {
        log("ng");
    }
    return tapped;
}

/**
 * Spriteの座標点の範囲を取得
 *
 * @return  cocos2d::Rect
 */
Rect BFSprite::getRect()
{
    Point point = this->getPosition();
    int w = this->getContentSize().width * this->getScaleX();
    int h = this->getContentSize().height * this->getScaleY();
    return CCRectMake(point.x - (w / 2), point.y - (h / 2), w, h);
}

