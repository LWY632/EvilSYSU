#include "GameScene_35.h"
USING_NS_CC;

GameScene_35::GameScene_35()
{
}


GameScene_35::~GameScene_35()
{
}


CCScene* GameScene_35::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_35 *layer = GameScene_35::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_35::init()
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
void GameScene_35::InitScene()
{
	background = CCSprite::create("35_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 35);

	runGame();
}

//run game
void GameScene_35::runGame()
{
	CCMenuItemImage *ts34 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_35::toScene_34));
	ts34->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts36 = CCMenuItemImage::create(
		"sign_8.png",
		"sign_8.png",
		this,
		menu_selector(GameScene_35::toScene_36));
	ts36->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.95, visibleOrigin.y + visibleSize.height * 0.45));

	CCMenu* moveMgr = CCMenu::create(ts34, ts36, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_35.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);


	CCSprite* tip = CCSprite::create("tip_15.png");
	tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(tip, 3);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_35::delTips));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	tip->runAction(my_1);
}

//move menu
void GameScene_35::toScene_34(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_34::scene()));
}
void GameScene_35::toScene_36(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_36::scene()));
}


//delete tip
void GameScene_35::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


