#pragma once
#include "cocos2d.h"
#include "GameScene_11.h"
#include "GameScene_14.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_13 : public CCLayer
{
public:
	GameScene_13();
	~GameScene_13();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_13);

	//init the game scene
	void InitScene();

	void showTip_1();

	//run game
	void runGame(CCNode* sender);

	//move menu
	void toScene_11(CCObject* pSender);
	void toScene_14(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

