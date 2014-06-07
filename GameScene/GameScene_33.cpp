#include "GameScene_33.h"
USING_NS_CC;

GameScene_33::GameScene_33()
{
}


GameScene_33::~GameScene_33()
{
}


CCScene* GameScene_33::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_33 *layer = GameScene_33::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_33::init()
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
void GameScene_33::InitScene()
{
	background = CCSprite::create("33_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 33);

	runGame();
}


//run game
void GameScene_33::runGame()
{

	CCMenuItemImage *ts17 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_33::toScene_17));
	ts17->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenu* moveMgr = CCMenu::create(ts17, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_33.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);

	if (!userDataFile->getBoolForKey("GameScene29_Open", false))
	{
		CCSprite* tip = CCSprite::create("tip_30.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 3);

		CCFadeOut* fo = CCFadeOut::create(15.0f);
		CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_33::delTips));
		CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

		tip->runAction(my_1);
		userDataFile->setBoolForKey("GameScene29_Open", true);
	}
}

//move menu
void GameScene_33::toScene_17(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_17::scene()));
}

//delete tip
void GameScene_33::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


