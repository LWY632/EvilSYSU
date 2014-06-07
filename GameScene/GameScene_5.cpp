#include "GameScene_5.h"
USING_NS_CC;

GameScene_5::GameScene_5()
{
}


GameScene_5::~GameScene_5()
{
}


CCScene* GameScene_5::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_5 *layer = GameScene_5::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_5::init()
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
void GameScene_5::InitScene()
{
	background = CCSprite::create("5_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 5);

	runGame();
}

//run game
void GameScene_5::runGame()
{
	CCMenuItemImage *ts2 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_5::toScene_2));
	ts2->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts11 = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_5::toScene_11));
	ts11->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.25));

	CCMenuItemImage *ts34 = CCMenuItemImage::create(
		"sign_5.png",
		"sign_5.png",
		this,
		menu_selector(GameScene_5::toScene_34));
	ts34->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.03, visibleOrigin.y + visibleSize.height * 0.2));

	CCMenu* moveMgr = CCMenu::create(ts2, ts11, ts34, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_5.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_5::toScene_2(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_2::scene()));
}
void GameScene_5::toScene_11(CCObject* pSender)
{
	if (!userDataFile->getBoolForKey("GameScene11_Open", false))
	{
		CCSprite* tip = CCSprite::create("tip_4.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 3);

		CCFadeOut* fo = CCFadeOut::create(3.0f);
		CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_5::delTips));
		CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

		tip->runAction(my_1);
	}
	else
	{
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_11::scene()));
	}
}
void GameScene_5::toScene_34(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_34::scene()));
}

//delete tip
void GameScene_5::delTips(CCNode* sender)
{
	this->removeChild(sender);
}



