#include "GameScene_24.h"
USING_NS_CC;

GameScene_24::GameScene_24()
{
}


GameScene_24::~GameScene_24()
{
}


CCScene* GameScene_24::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_24 *layer = GameScene_24::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_24::init()
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
void GameScene_24::InitScene()
{
	background = CCSprite::create("24_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 24);

	runGame();
}

//run game
void GameScene_24::runGame()
{
	CCMenuItemImage *ts23 = CCMenuItemImage::create(
		"sign_6.png",
		"sign_6.png",
		this,
		menu_selector(GameScene_24::toScene_23));
	ts23->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.1, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts26 = CCMenuItemImage::create(
		"sign_4.png",
		"sign_4.png",
		this,
		menu_selector(GameScene_24::toScene_26));
	ts26->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.15));


	CCMenu* moveMgr = CCMenu::create(ts23, ts26, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_24.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);



	if (!userDataFile->getBoolForKey("GameScene27_In", false))
	{
		CCSprite* tip = CCSprite::create("tip_21.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 3);

		CCFadeOut* fo = CCFadeOut::create(3.0f);
		CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_24::delTips));
		CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

		tip->runAction(my_1);
	}
}

//move menu
void GameScene_24::toScene_23(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_23::scene()));
}
void GameScene_24::toScene_26(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_26::scene()));
}

//delete tip
void GameScene_24::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


