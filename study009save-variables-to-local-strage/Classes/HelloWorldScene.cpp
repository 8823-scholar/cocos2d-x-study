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
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    /*
    // プリファレンスデータ
    UserDefault* user = UserDefault::sharedUserDefault();
    std::string stringValue = user->getStringForKey("stringKey", "default");
    int intValue = user->getIntegerForKey("intKey", 2);
    float floatValue = user->getFloatForKey("floatKey", 0.1f);
    bool boolValue = user->getBoolForKey("boolKey", false);
    log("%s", stringValue.c_str());
    log("%d", intValue);
    log("%f", floatValue);
    log("%s", boolValue ? "true" : "false");
    user->setStringForKey("stringKey", "bar");
    user->setIntegerForKey("intKey", 10);
    user->setFloatForKey("floatKey", 10.2f);
    user->setBoolForKey("boolKey", true);
    user->flush();
    */

    // Dictionary
    FileUtils* fileUtils = FileUtils::sharedFileUtils();
    std::string filepath = fileUtils->getWritablePath() + "foo.plist";
    Dictionary* dictionary = NULL;
    if (fileUtils->isFileExist(filepath)) {
        dictionary = Dictionary::createWithContentsOfFile(filepath.c_str());
    } else {
        dictionary = Dictionary::create();
    }

    String* stringValue = (String*)dictionary->objectForKey("stringKey");
    Array* arrayValues = (Array*)dictionary->objectForKey("arrayKey");
    Dictionary* dictionaryValues = (Dictionary*)dictionary->objectForKey("dictionaryKey");
    if (! dictionaryValues) {
        dictionaryValues = Dictionary::create();
    }
    Object* arrayValue = NULL;
    log("%s", stringValue->getCString());
    CCARRAY_FOREACH(arrayValues, arrayValue) {
        String* value = (String*)arrayValue;
        log("%s", value->getCString());
    }
    String* dicValue1 = (String*)dictionaryValues->objectForKey("dictionary_key1");
    String* dicValue2 = (String*)dictionaryValues->objectForKey("dictionary_key2");
    if (dicValue1) {
        log("%s", dicValue1->getCString());
    }
    if (dicValue2) {
        log("%s", dicValue2->getCString());
    }

    dictionary->setObject(ccs("value"), "stringKey");
    dictionary->setObject(Array::create(ccs("array_value1"), ccs("array_value2"), NULL), "arrayKey");
    dictionaryValues->setObject(ccs("dictionary_value1"), "dictionary_key1");
    dictionaryValues->setObject(ccs("dictionary_value2"), "dictionary_key2");
    dictionary->setObject(dictionaryValues, "dictionaryKey");
    //dictionary->setObject(Integer(10), "intKey");
    dictionary->writeToFile(filepath.c_str());

    return true;
}


void HelloWorld::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
