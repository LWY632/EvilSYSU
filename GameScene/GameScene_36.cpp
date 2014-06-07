#include "GameScene_36.h"
USING_NS_CC;

GameScene_36::GameScene_36()
{
}


GameScene_36::~GameScene_36()
{
}


CCScene* GameScene_36::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_36 *layer = GameScene_36::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_36::init()
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
void GameScene_36::InitScene()
{
	background = CCSprite::create("36_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 36);

	runGame();
}

//run game
void GameScene_36::runGame()
{
	CCMenuItemImage *ts35 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_36::toScene_35));
	ts35->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.53, visibleOrigin.y + visibleSize.height * 0.08));

	CCMenuItemImage *ts37 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_36::toScene_37));
	ts37->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.3));

	CCMenu* moveMgr = CCMenu::create(ts35, ts37, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_36.png");
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
void GameScene_36::toScene_35(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_35::scene()));
}
void GameScene_36::toScene_37(CCObject* pSender)
{
	if (!userDataFile->getBoolForKey("GameScene6_Open", false))
	{
		CCSprite* tip = CCSprite::create("tip_6.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 3);

		CCFadeOut* fo = CCFadeOut::create(3.0f);
		CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_36::delTips));
		CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

		tip->runAction(my_1);
	}
	else
	{
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_37::scene()));
	}
}

//delete tip
void GameScene_36::delTips(CCNode* sender)
{
	this->removeChild(sender);
}

