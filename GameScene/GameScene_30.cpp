#include "GameScene_30.h"
USING_NS_CC;

GameScene_30::GameScene_30()
{
}


GameScene_30::~GameScene_30()
{
}


CCScene* GameScene_30::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_30 *layer = GameScene_30::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_30::init()
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
void GameScene_30::InitScene()
{
	background = CCSprite::create("30_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 30);


	if (userDataFile->getBoolForKey("GameScene27_In", false) && !userDataFile->getBoolForKey("GameScene17_Open", false))
	{
		CCMenuItemImage *_cz = CCMenuItemImage::create(
			"30_scene_ex.png",
			"30_scene_ex.png",
			this,
			menu_selector(GameScene_30::pickCZ));
		_cz->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.64219, visibleOrigin.y + visibleSize.height * 0.32083));

		CZ = CCMenu::create(_cz, NULL);
		CZ->setPosition(CCPointZero);
		this->addChild(CZ, 1);
	}



	runGame();
}

//run game
void GameScene_30::runGame()
{
	CCMenuItemImage *ts16 = CCMenuItemImage::create(
		"sign_9.png",
		"sign_9.png",
		this,
		menu_selector(GameScene_30::toScene_16));
	ts16->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.05, visibleOrigin.y + visibleSize.height * 0.5));

	CCMenuItemImage *td = CCMenuItemImage::create(
		"sign_1.png",
		"sign_1.png",
		this,
		menu_selector(GameScene_10::toDeath));
	td->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.32));

	CCMenu* moveMgr = CCMenu::create(ts16, td, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_30.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_30::toScene_16(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_16::scene()));
}
void GameScene_30::toDeath(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, DeathLayer::scene()));
}


void GameScene_30::pickCZ(CCObject* pSender)
{
	this->removeChild(CZ);
	userDataFile->setBoolForKey("GameScene17_Open", true);

	CCSprite* tip = CCSprite::create("tip_29.png");
	tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(tip, 3);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_30::delTips));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	tip->runAction(my_1);
}

//delete tip
void GameScene_30::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


