#include "GameScene_12.h"
USING_NS_CC;

GameScene_12::GameScene_12()
{
}


GameScene_12::~GameScene_12()
{
}


CCScene* GameScene_12::scene()
{
	CCScene *scene = CCScene::create();
	GameScene_12 *layer = GameScene_12::create();
	scene->addChild(layer, 1, 1000);
	return scene;
}


bool GameScene_12::init()
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
void GameScene_12::InitScene()
{
	background = CCSprite::create("12_scene.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);

	userDataFile->setIntegerForKey("CurGameScene", 12);

	if (!userDataFile->getBoolForKey("GameScene6_Open", false) && userDataFile->getBoolForKey("GameScene12_Open", false))
	{
		CCMenuItemImage *_face = CCMenuItemImage::create(
			"12_scene_ex.png",
			"12_scene_ex.png",
			this,
			menu_selector(GameScene_12::pickFace));
		_face->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.084375, visibleOrigin.y + visibleSize.height * 0.32848));

		face = CCMenu::create(_face, NULL);
		face->setPosition(CCPointZero);
		this->addChild(face, 1);
	}

	runGame();
}

//run game
void GameScene_12::runGame()
{
	CCMenuItemImage *ts11 = CCMenuItemImage::create(
		"sign_2.png",
		"sign_2.png",
		this,
		menu_selector(GameScene_12::toScene_11));
	ts11->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.05));

	CCMenu* moveMgr = CCMenu::create(ts11, NULL);
	moveMgr->setPosition(CCPointZero);
	this->addChild(moveMgr, 2);

	CCSprite* address = CCSprite::create("addr_12.png");
	address->setAnchorPoint(ccp(0, 1));
	address->setPosition(ccp(visibleOrigin.x, visibleOrigin.y + visibleSize.height));
	this->addChild(address, 2);
}

//move menu
void GameScene_12::toScene_11(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.2f, GameScene_11::scene()));
}

void GameScene_12::pickFace(CCObject* pSender)
{
	this->removeChild(face);
	userDataFile->setBoolForKey("GameScene6_Open", true);

	CCSprite* tip = CCSprite::create("tip_13.png");
	tip->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5, visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(tip, 3);

	CCFadeOut* fo = CCFadeOut::create(3.0f);
	CCCallFuncN* cfn = CCCallFuncN::create(this, callfuncN_selector(GameScene_12::delTips));
	CCAction* my_1 = CCSequence::create(fo, cfn, NULL);

	tip->runAction(my_1);
}

//delete tip
void GameScene_12::delTips(CCNode* sender)
{
	this->removeChild(sender);
}


