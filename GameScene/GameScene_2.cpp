#include "GameScene_2.h"
USING_NS_CC;

GameScene_2::GameScene_2()
{
}


GameScene_2::~GameScene_2()
{
}


CCScene* GameScene_2::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_2 *layer = GameScene_2::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_2::init()
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
void GameScene_2::InitScene()
{
	background = CCSprite::create("2_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 2);

	runGame();
}

//run game
void GameScene_2::runGame()
{
	CCMenuItemImage *ts1 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_2::toScene_1));
	ts1->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts4 = CCMenuItemImage::create(
		"sign_3.png",
		"sign_3.png",
		this,
		menu_selector(GameScene_2::toScene_4));
	ts4->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.05, visibleOrigin.y + visibleSize.height * 0.2));

	CCMenuItemImage *ts5 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_2::toScene_5));
	ts5->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.28));

	CCMenuItemImage *ts6 = CCMenuItemImage::create(
		"sign_4.png",
		"sign_4.png",
		this,
		menu_selector(GameScene_2::toScene_6));
	ts6->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.95, visibleOrigin.y + visibleSize.height * 0.2));

	CCMenu* moveMgr = CCMenu::create(ts1, ts4, ts5, ts6, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_2.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_2::toScene_1(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_1::scene()));
}
void GameScene_2::toScene_4(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_4::scene()));
}
void GameScene_2::toScene_5(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_5::scene()));
}
void GameScene_2::toScene_6(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_6::scene()));
}
