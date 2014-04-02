#include "HelloWorldScene.h"
#include "HelloWorldLayer.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool HelloWorldScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto layer = HelloWorldLayer::create();
    this->addChild(layer);
    
    return true;
}

