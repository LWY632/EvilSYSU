#include "GameScene_29.h"
USING_NS_CC;

GameScene_29::GameScene_29()
{
}


GameScene_29::~GameScene_29()
{
}


CCScene* GameScene_29::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_29 *layer = GameScene_29::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_29::init()
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
void GameScene_29::InitScene()
{
	background = CCSprite::create("29_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 29);

	if (!userDataFile->getBoolForKey("GameScene39_Open", false))
	{
		CCMenuItemImage *_card = CCMenuItemImage::create(
			"29_scene_ex.png",
			"29_scene_ex.png",
			this,
			menu_selector(GameScene_29::pickCard));
		_card->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.2711, visibleOrigin.y + visibleSize.height * 0.5292));

		card = CCMenu::create(_card, NULL);
		card->setPosition(CCPointZero);
		this->addChild(card, 1);
	}

	runGame();
}

//run game
void GameScene_29::runGame()
{
	CCMenuItemImage *ts22 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_29::toScene_22));
	ts22->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenu* moveMgr = CCMenu::create(ts22, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_29.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_29::toScene_22(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_22::scene()));
}

void GameScene_29::pickCard(CCObject* pSender)
{
	this->removeChild(card);
	userDataFile->setBoolForKey("GameScene39_Open", true);

	CCSprite* tip = CCSprite::create("tip_20.png");
	tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(tip, 3);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_29::delTips));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	tip->runAction(my_1);
}

//delete tip
void GameScene_29::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


