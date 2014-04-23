#include "HelloWorldLayer.h"
#include "HelloWorldScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool HelloWorldLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setTag(3);
    this->addChild(sprite, 0);

    // touch
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorldLayer::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(HelloWorldLayer::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    // handling event
    this->schedule(schedule_selector(HelloWorldLayer::handleEvent));
    
    return true;
}



Node* HelloWorldLayer::getNodeByPoint(Point point)
{
    auto children = this->getChildren();
    for (auto child : children) {
        CCLOG("%f, %f", child->getPositionX(), child->getPositionY());

        if (child->getBoundingBox().containsPoint(point)) {
            return child;
        }
    }
    return NULL;
}



/**
 * handle event.
 */
void HelloWorldLayer::handleEvent(float time)
{
    if (this->touch_began) {
        this->touch_ended_time ++;
        //CCLOG("%f", this->touch_ended_time);
    } else if (this->touch_began_time != this->touch_ended_time) {
        auto scene = this->getScene();
        auto node = this->getNodeByPoint(this->touch->getLocation());
        if (node) {
            CCLOG("node tag: %d", node->getTag());
            // single tap
            if (this->touch_ended_time < 20) {
                CCLOG("tapped !");
                scene->tap(node);

            } else {
                CCLOG("long tapped !");
                scene->longTap(node);
            }
        }
        this->touch_began_time = 0;
        this->touch_ended_time = 0;
    }
}



/**
 * start touch.
 */
bool HelloWorldLayer::onTouchBegan(Touch* touch, Event* event)
{
    CCLOG("began");
    this->touch = touch;
    this->touchEvent = event;
    this->touch_began = true;
    this->touch_began_time = 0;
    this->touch_ended_time = 0;
    return true;
}

/**
 * end touch.
 */
void HelloWorldLayer::onTouchEnded(Touch* touch, Event* event)
{
    CCLOG("ended");
    this->touch = touch;
    this->touchEvent = event;
    this->touch_began = false;
}


HelloWorldScene* HelloWorldLayer::getScene()
{
    if(!_parent) return nullptr;
    
    return _parent->getScene();
}

