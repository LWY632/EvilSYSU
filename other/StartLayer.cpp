#include "StartLayer.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

StartLayer::StartLayer()
{
}


StartLayer::~StartLayer()
{
}


CCScene* StartLayer::scene()
{
	CCScene *scene = CCScene::create();
	StartLayer *layer = StartLayer::create();
	scene->addChild(layer);
	return scene;
}


bool StartLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	visibleOrigin = CCDirector::sharedDirector()->getVisibleOrigin();

	if (!userDataFile->getBoolForKey("isExisted", false))
	{
		userDataFile->setBoolForKey("isExisted", true);
		userDataFile->setBoolForKey("MusicOn", true);
		userDataFile->setBoolForKey("isNewGame", true);
		userDataFile->setIntegerForKey("CurGameScene", 1);
		userDataFile->setBoolForKey("GameScene39_Open", false);
		userDataFile->setBoolForKey("GameScene11_Open", false);
		userDataFile->setBoolForKey("GameScene6_Open", false);
		userDataFile->setBoolForKey("GameScene12_Open", false);
		userDataFile->setBoolForKey("GameScene17_Open", false);
		userDataFile->setBoolForKey("GameScene29_Open", false);
		userDataFile->setBoolForKey("GameScene27_In", false);
	}
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("GameSceneMusic.mp3");
	InitScene();

	return true;
}


//init the game scene
void StartLayer::InitScene()
{
	background = CCSprite::create("StartBackground.png");
	background->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.5,
		visibleOrigin.y + visibleSize.height * 0.5));
	this->addChild(background, 0);


	CCMenuItemImage *_start = CCMenuItemImage::create(
		"StartMenu.png",
		"StartMenu.png",
		this,
		menu_selector(StartLayer::StartGame));
	_start->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.83125,
		visibleOrigin.y + visibleSize.height * 0.425));

	CCMenuItemImage *_cg = CCMenuItemImage::create(
		"StartMenu.png",
		"StartMenu.png",
		this,
		menu_selector(StartLayer::ScanCG));
	_cg->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.83125,
		visibleOrigin.y + visibleSize.height * 0.3125));

	CCMenuItemImage *_music = CCMenuItemImage::create(
		"StartMenu.png",
		"StartMenu.png",
		this,
		menu_selector(StartLayer::MusicSet));
	_music->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.83125,
		visibleOrigin.y + visibleSize.height * 0.1972));

	CCMenuItemImage *_exit = CCMenuItemImage::create(
		"StartMenu.png",
		"StartMenu.png",
		this,
		menu_selector(StartLayer::ExitGame));
	_exit->setPosition(ccp(visibleOrigin.x + visibleSize.width * 0.83125,
		visibleOrigin.y + visibleSize.height * 0.0875));


	StartMenu = CCMenu::create(_start, _cg, _music, _exit, NULL);
	StartMenu->setPosition(CCPointZero);
	this->addChild(StartMenu, 1);


	if (userDataFile->getBoolForKey("MusicOn", true))
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("GameSceneMusic.mp3", true);
	}

}

//start game
void StartLayer::StartGame(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2.0f, GameScene_1::scene()));
}

//scan CG
void StartLayer::ScanCG(CCObject* pSender)
{

}

//music menu
void StartLayer::MusicSet(CCObject* pSender)
{

}

//exit
void StartLayer::ExitGame(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}



