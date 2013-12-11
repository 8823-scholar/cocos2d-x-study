#include "HelloWorldScene.h"
#include "befool/SimpleVideoEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
   
    // 見出し
    auto label = LabelTTF::create("ミンカの恋愛サーキュレーション", "Arial", 24);
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    // 再生ボタン
    auto playItem = MenuItemImage::create(
                                           "miku.JK.jpg",
                                           "miku.JK.jpg",
                                           CC_CALLBACK_1(HelloWorld::playVideoCallback, this));
    
	playItem->setPosition(Point(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    return true;
}


void HelloWorld::playVideoCallback(Object *pSender)
{
    befool::SimpleVideoEngine::getShared()->playVideo("renai-circulation");
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
