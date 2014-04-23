#include "HelloWorldScene.h"
#include "HelloWorldLayer.h"
#include "PuzzleController.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool HelloWorldScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto controller = Controller::PuzzleController::create(this);
    this->setController(controller);
    
    auto layer = HelloWorldLayer::create();
    layer->setTag(5);
    this->addChild(layer);

    return true;
}

void HelloWorldScene::tap(Node* target)
{
    CCLOG("HelloWorldScene::tap");
}

void HelloWorldScene::longTap(Node* target)
{
    CCLOG("HelloWorldScene::longTap");
}

void HelloWorldScene::setController(Controller::Controller* controller)
{
    this->controller = controller;
}

HelloWorldScene* HelloWorldScene::getScene()
{
    return this;
}

