#include "HelloWorldScene.h"
#include "BFSprite.h"

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

    this->setTouchMode(kCCTouchesOneByOne);
    this->setTouchEnabled(true);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    auto sprite = BFSprite::create("miku.JK.jpg");
    sprite->setScale(0.5);
    sprite->setTag(1);

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

/**
 * タップ開始時にコールされる
 *
 * @return  boolean
 */
bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
    BFSprite* sprite = (BFSprite*)this->getChildByTag(1);
    if (sprite->isTapped(touch->getLocation())) {
        log("miku tapped !! H !");
    }
    return true;
}

/**
 * タップ開始後、移動するとコールされる
 *
 * @return  void
 */
void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
    BFSprite* sprite = (BFSprite*)this->getChildByTag(1);
    if (sprite->isTapped(touch->getLocation())) {
        sprite->setPosition(touch->getLocation());
    }
}

/**
 * タップが終了するとコールされる
 *
 * @return  void
 */
void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
    BFSprite* sprite = (BFSprite*)this->getChildByTag(1);
    if (sprite->isTapped(touch->getLocation())) {
        Point point = touch->getLocation();
        sprite->setPositionY(point.y - 10);
    }
}

