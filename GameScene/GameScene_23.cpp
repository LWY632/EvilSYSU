#include "GameScene_23.h"
USING_NS_CC;

GameScene_23::GameScene_23()
{
}


GameScene_23::~GameScene_23()
{
}


CCScene* GameScene_23::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_23 *layer = GameScene_23::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_23::init()
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
void GameScene_23::InitScene()
{
	background = CCSprite::create("23_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 23);

	runGame();
}

//run game
void GameScene_23::runGame()
{
	CCMenuItemImage *ts20 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_23::toScene_20));
	ts20->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts24 = CCMenuItemImage::create(
		"sign_8.png",
		"sign_8.png",
		this,
		menu_selector(GameScene_23::toScene_24));
	ts24->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.95, visibleOrigin.y + visibleSize.height * 0.55));


	CCMenu* moveMgr = CCMenu::create(ts20, ts24, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_23.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_23::toScene_20(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_20::scene()));
}
void GameScene_23::toScene_24(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_24::scene()));
}


