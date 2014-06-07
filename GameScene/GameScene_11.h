#pragma once
#include "cocos2d.h"
#include "GameScene_5.h"
#include "GameScene_12.h"
#include "GameScene_13.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_11 : public CCLayer
{
public:
	GameScene_11();
	~GameScene_11();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_11);

	//init the game scene
	void InitScene();

	void showTip_1();

	//run game
	void runGame(CCNode* sender);

	//move menu
	void toScene_5(CCObject* pSender);
	void toScene_12(CCObject* pSender);
	void toScene_13(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

