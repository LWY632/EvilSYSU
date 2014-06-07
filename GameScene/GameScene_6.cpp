#include "GameScene_6.h"
USING_NS_CC;

GameScene_6::GameScene_6()
{
}


GameScene_6::~GameScene_6()
{
}


CCScene* GameScene_6::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_6 *layer = GameScene_6::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_6::init()
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
void GameScene_6::InitScene()
{
	background = CCSprite::create("6_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 6);

	runGame();
}

//run game
void GameScene_6::runGame()
{
	CCMenuItemImage *ts2 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_6::toScene_2));
	ts2->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.53, visibleOrigin.y + visibleSize.height * 0.08));

	CCMenuItemImage *ts15 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_6::toScene_15));
	ts15->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.3));

	CCMenu* moveMgr = CCMenu::create(ts2, ts15, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_6.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);


	if (!userDataFile->getBoolForKey("GameScene6_Open", false))
	{
		CCSprite* tip = CCSprite::create("tip_5.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 1);
	}
}

//move menu
void GameScene_6::toScene_2(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_2::scene()));
}
void GameScene_6::toScene_15(CCObject* pSender)
{
	if (!userDataFile->getBoolForKey("GameScene6_Open", false))
	{
		CCSprite* tip = CCSprite::create("tip_6.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 3);

		CCFadeOut* fo = CCFadeOut::create(3.0f);
		CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_6::delTips));
		CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

		tip->runAction(my_1);
	}
	else
	{
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_15::scene()));
	}
}

//delete tip
void GameScene_6::delTips(CCNode* sender)
{
	this->removeChild(sender);
}

