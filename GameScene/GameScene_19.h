#pragma once
#include "cocos2d.h"
#include "GameScene_18.h"
#include "GameScene_20.h"
#include "GameScene_21.h"
#include "GameScene_22.h"
#include "GameScene_37.h"
#include "DeathLayer.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_19 : public CCLayer
{
public:
	GameScene_19();
	~GameScene_19();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_19);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_18(CCObject* pSender);
	void toScene_20(CCObject* pSender);
	void toScene_21(CCObject* pSender);
	void toScene_22(CCObject* pSender);
	void toScene_37(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};


