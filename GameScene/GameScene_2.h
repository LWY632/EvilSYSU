#pragma once
#include "cocos2d.h"
#include "GameScene_1.h"
#include "GameScene_4.h"
#include "GameScene_5.h"
#include "GameScene_6.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_2 : public CCLayer
{
public:
	GameScene_2();
	~GameScene_2();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_2);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_1(CCObject* pSender);
	void toScene_4(CCObject* pSender);
	void toScene_5(CCObject* pSender);
	void toScene_6(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

