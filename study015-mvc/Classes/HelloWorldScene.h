#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Controller.h"

class HelloWorldScene : public cocos2d::Scene
{
public:
    Controller::Controller* controller;

    virtual bool init();
    CREATE_FUNC(HelloWorldScene);

    virtual HelloWorldScene* getScene();

    virtual void tap(cocos2d::Node* target);
    virtual void longTap(cocos2d::Node* target);
    virtual void setController(Controller::Controller* controller);
};

#endif // __HELLOWORLD_SCENE_H__
