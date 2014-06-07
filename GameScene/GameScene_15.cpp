#include "GameScene_15.h"
USING_NS_CC;

GameScene_15::GameScene_15()
{
}


GameScene_15::~GameScene_15()
{
}


CCScene* GameScene_15::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_15 *layer = GameScene_15::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_15::init()
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
void GameScene_15::InitScene()
{
	background = CCSprite::create("15_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 15);

	runGame();
}

//run game
void GameScene_15::runGame()
{
	CCMenuItemImage *ts6 = CCMenuItemImage::create(
		"sign_8.png",
		"sign_8.png",
		this,
		menu_selector(GameScene_15::toScene_6));
	ts6->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.95, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *ts16 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_15::toScene_16));
	ts16->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.3, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts17 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_15::toScene_17));
	ts17->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.3, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenu* moveMgr = CCMenu::create(ts6, ts16, ts17, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_15.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_15::toScene_6(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_6::scene()));
}
void GameScene_15::toScene_16(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_16::scene()));
}
void GameScene_15::toScene_17(CCObject* pSender)
{
	if (!userDataFile->getBoolForKey("GameScene17_Open", false))
	{
		CCSprite* tip = CCSprite::create("tip_14.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 3);

		CCFadeOut* fo = CCFadeOut::create(3.0f);
		CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_15::delTips));
		CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

		tip->runAction(my_1);
	}
	else
	{
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_17::scene()));
	}
}

//delete tip
void GameScene_15::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


