#include "GameScene_4.h"
USING_NS_CC;

GameScene_4::GameScene_4()
{
}


GameScene_4::~GameScene_4()
{
}


CCScene* GameScene_4::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_4 *layer = GameScene_4::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_4::init()
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
void GameScene_4::InitScene()
{
	background = CCSprite::create("4_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 4);

	runGame();
}

//run game
void GameScene_4::runGame()
{
	CCMenuItemImage *ts2 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_4::toScene_2));
	ts2->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts7 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_4::toScene_7));
	ts7->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.58, visibleOrigin.y + visibleSize.height * 0.3));

	CCMenu* moveMgr = CCMenu::create(ts2, ts7, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_4.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_4::toScene_2(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_2::scene()));
}
void GameScene_4::toScene_7(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_7::scene()));
}

