#pragma once
#include "cocos2d.h"
#include "GameScene_1.h"

#define userDataFile CCUserDefault::sharedUserDefault()

USING_NS_CC;

class StartLayer : public CCLayer
{
public:
	StartLayer();
	~StartLayer();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(StartLayer);

	//init the game scene
	void InitScene();

	//start game
	void StartGame(CCObject* pSender);
	//scan CG
	void ScanCG(CCObject* pSender);
	//music menu
	void MusicSet(CCObject* pSender);
	//exit
	void ExitGame(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

	//menu
	CCMenu* StartMenu;

};

