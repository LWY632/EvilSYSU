#include "GameScene_8.h"
USING_NS_CC;

GameScene_8::GameScene_8()
{
}


GameScene_8::~GameScene_8()
{
}


CCScene* GameScene_8::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_8 *layer = GameScene_8::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_8::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();

	InitScene();

	return true;
}

//init the game scene
void GameScene_8::InitScene()
{
	background = CCSprite::create("8_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 8);

	runGame();
}

//run game
void GameScene_8::runGame()
{
	CCMenuItemImage *ts7 = CCMenuItemImage::create(
		"sign_6.png",
		"sign_6.png",
		this,
		menu_selector(GameScene_8::toScene_7));
	ts7->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.7, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts40 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_8::toScene_40));
	ts40->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.7, visibleOrigin.y + visibleSize.height * 0.55));

	CCMenu* moveMgr = CCMenu::create(ts7, ts40, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_8.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_8::toScene_7(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_7::scene()));
}
void GameScene_8::toScene_40(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_40::scene()));
}

