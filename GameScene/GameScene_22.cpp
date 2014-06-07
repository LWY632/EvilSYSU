#include "GameScene_22.h"
USING_NS_CC;

GameScene_22::GameScene_22()
{
}


GameScene_22::~GameScene_22()
{
}


CCScene* GameScene_22::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_22 *layer = GameScene_22::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_22::init()
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
void GameScene_22::InitScene()
{
	background = CCSprite::create("22_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 22);

	runGame();
}

//run game
void GameScene_22::runGame()
{
	CCMenuItemImage *ts19 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_22::toScene_19));
	ts19->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	if (userDataFile->getBoolForKey("GameScene29_Open", false))
	{
		CCSprite* tip = CCSprite::create("tip_19.png");
		tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
		this->addChild(tip, 3);

		CCFadeOut* fo = CCFadeOut::create(3.0f);
		CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_6::delTips));
		CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

		tip->runAction(my_1);


		CCMenuItemImage *ts29 = CCMenuItemImage::create(
			"sign_1.png",
			"sign_1.png",
			this,
			menu_selector(GameScene_22::toScene_29));
		ts29->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.25));

		CCMenu* moveMgr = CCMenu::create(ts19, ts29, NULL);
		moveMgr->setPosition(CCPointZero);
		this->addChild(moveMgr, 2);
	}
	else
	{
		CCMenu* moveMgr = CCMenu::create(ts19, NULL);
		moveMgr->setPosition(CCPointZero);
		this->addChild(moveMgr, 2);
	}

	CCSprite* address = CCSprite::create("addr_22.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_22::toScene_19(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_19::scene()));
}
void GameScene_22::toScene_29(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_29::scene()));
}

//delete tip
void GameScene_22::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


