#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Controller.h"
#include "View.h"
#include "PuzzleBlock.h"
#include <array>

class HelloWorldScene : public cocos2d::Scene
{
public:
    Controller::Controller* controller;
    View::View* view;
    std::array<Model::PuzzleBlock*, 7> blocks;

    virtual bool init();
    CREATE_FUNC(HelloWorldScene);

    virtual HelloWorldScene* getScene();

    virtual void tap(cocos2d::Node* target);
    virtual void longTap(cocos2d::Node* target);
    virtual void setController(Controller::Controller* controller);
    virtual void setView(View::View* view);

    virtual void pushBlocks();
    virtual std::array<Model::PuzzleBlock*, 7> getBlocks();
};

#endif // __HELLOWORLD_SCENE_H__
