#include "GameScene_3.h"
USING_NS_CC;

GameScene_3::GameScene_3()
{
}


GameScene_3::~GameScene_3()
{
}


CCScene* GameScene_3::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_3 *layer = GameScene_3::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_3::init()
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
void GameScene_3::InitScene()
{
	background = CCSprite::create("3_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 3);

	runGame();
}

//run game
void GameScene_3::runGame()
{
	CCMenuItemImage *ts1 = CCMenuItemImage::create(
		"sign_6.png",
		"sign_6.png",
		this,
		menu_selector(GameScene_3::toScene_1));
	ts1->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenuItemImage *ts39 = CCMenuItemImage::create(
		"sign_3.png",
		"sign_3.png",
		this,
		menu_selector(GameScene_3::toScene_39));
	ts39->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.6, visibleOrigin.y + visibleSize.height * 0.3));

	CCMenu* moveMgr = CCMenu::create(ts1, ts39, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_3.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_3::toScene_1(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_1::scene()));
}
void GameScene_3::toScene_39(CCObject* pSender)
{
	if (!userDataFile->getBoolForKey("GameScene39_Open", false))
	{
		CCSprite* tip = CCSprite::create("tip_3.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 3);

		CCFadeOut* fo = CCFadeOut::create(3.0f);
		CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_3::delTips));
		CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

		tip->runAction(my_1);
	}
	else
	{
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_39::scene()));
	}
}

//delete tip
void GameScene_3::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


