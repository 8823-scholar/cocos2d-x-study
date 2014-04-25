#include "HelloWorldScene.h"
#include "HelloWorldLayer.h"
#include "PuzzleController.h"
#include "PuzzleView.h"

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

    auto view = View::PuzzleView::create(this);
    this->setView(view);

    return true;
}

void HelloWorldScene::tap(Node* target)
{
    CCLOG("HelloWorldScene::tap");
    this->controller->tap(target);
}

void HelloWorldScene::longTap(Node* target)
{
    CCLOG("HelloWorldScene::longTap");
    this->controller->longTap(target);
}

void HelloWorldScene::setController(Controller::Controller* controller)
{
    this->controller = controller;
}
void HelloWorldScene::setView(View::View* view)
{
    this->view = view;
}

HelloWorldScene* HelloWorldScene::getScene()
{
    return this;
}

