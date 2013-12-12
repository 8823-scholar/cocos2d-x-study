#include "HelloWorldScene.h"

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
    
    /*
    Sprite *miku = Sprite::create("miku-notanimated-0.png");
    miku->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(miku);

    // 続くパラパラアニメを登録
    Animation *animation = Animation::create();
    animation->addSpriteFrameWithFileName("miku-notanimated-1.png");
    animation->addSpriteFrameWithFileName("miku-notanimated-2.png");
    animation->addSpriteFrameWithFileName("miku-notanimated-3.png");
    animation->setRestoreOriginalFrame(true);   // 最初の画像に戻すかどうか
    animation->setDelayPerUnit(0.5f / 4.0f);

    // パラパラアニメを動かす
    Animate *animate = Animate::create(animation);
    RepeatForever *animated = RepeatForever::create(animate);
    miku->runAction(animated);
    */
    
    Sprite *miku = Sprite::create();
    miku->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(miku);
    
    // パラパラアニメを登録
    const int IMAGE_SIZE = 200;
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(0.5f / 4.0f);
    for (int i = 0; i < 4; i++ ) {
        animation->addSpriteFrame(SpriteFrame::create("miku-tiled.png", Rect(IMAGE_SIZE * i, 0, IMAGE_SIZE, IMAGE_SIZE)));
    }
    
    // パラパラアニメを動かす
    Animate *animate = Animate::create(animation);
    RepeatForever *animated = RepeatForever::create(animate);
    miku->runAction(animated);

    
    return true;
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
