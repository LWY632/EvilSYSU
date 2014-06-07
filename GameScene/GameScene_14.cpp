#include "GameScene_14.h"
USING_NS_CC;

GameScene_14::GameScene_14()
{
}


GameScene_14::~GameScene_14()
{
}


CCScene* GameScene_14::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_14 *layer = GameScene_14::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_14::init()
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
void GameScene_14::InitScene()
{
	background = CCSprite::create("14_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 14);

	runGame();
}

//run game
void GameScene_14::runGame()
{
	CCMenuItemImage *ts13 = CCMenuItemImage::create(
		"sign_8.png",
		"sign_8.png",
		this,
		menu_selector(GameScene_14::toScene_13));
	ts13->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.95, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *tb = CCMenuItemImage::create(
		"sysubook.png",
		"sysubook.png",
		this,
		menu_selector(GameScene_14::pickBook));
	tb->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.23594, visibleOrigin.y + visibleSize.height * 0.38611));

	CCMenu* moveMgr = CCMenu::create(ts13, tb, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_14.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_14::toScene_13(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_13::scene()));
}

void GameScene_14::pickBook(CCObject* pSender)
{
	CCSprite* tip = CCSprite::create("tip_12.png");
	tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(tip, 3);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_14::delTips));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	tip->runAction(my_1);

	if (!userDataFile->getBoolForKey("GameScene12_Open", false))
	{
		userDataFile->setBoolForKey("GameScene12_Open", true);
	}
}

//delete tip
void GameScene_14::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


