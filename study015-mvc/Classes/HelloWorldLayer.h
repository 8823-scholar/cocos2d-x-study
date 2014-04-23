#ifndef __HELLOWORLD_LAYER_H__
#define __HELLOWORLD_LAYER_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;

class HelloWorldLayer : public Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    virtual Node* getNodeByPoint(Point point);
    virtual HelloWorldScene* getScene();

    virtual void handleEvent(float time);
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorldLayer);

protected:
    HelloWorldScene* _parent;

private:
    Touch* touch;
    Event* touchEvent;
    bool touch_began = false;
    float touch_began_time;
    float touch_ended_time;
};

#endif // __HELLOWORLD_LAYER_H__
