#include "GameScene_7.h"
USING_NS_CC;

GameScene_7::GameScene_7()
{
}


GameScene_7::~GameScene_7()
{
}


CCScene* GameScene_7::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_7 *layer = GameScene_7::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_7::init()
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
void GameScene_7::InitScene()
{
	background = CCSprite::create("7_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 7);

	runGame();
}

//run game
void GameScene_7::runGame()
{
	CCMenuItemImage *ts4 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_7::toScene_4));
	ts4->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts8 = CCMenuItemImage::create(
		"sign_8.png",
		"sign_8.png",
		this,
		menu_selector(GameScene_7::toScene_8));
	ts8->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.2, visibleOrigin.y + visibleSize.height * 0.7));

	CCMenuItemImage *ts9 = CCMenuItemImage::create(
		"sign_7.png",
		"sign_7.png",
		this,
		menu_selector(GameScene_7::toScene_9));
	ts9->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.9, visibleOrigin.y + visibleSize.height * 0.3));

	CCMenu* moveMgr = CCMenu::create(ts4, ts8, ts9, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_7.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_7::toScene_4(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_4::scene()));
}
void GameScene_7::toScene_8(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_8::scene()));
}
void GameScene_7::toScene_9(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_9::scene()));
}


