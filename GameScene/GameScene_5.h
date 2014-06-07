#pragma once
#include "cocos2d.h"
#include "GameScene_2.h"
#include "GameScene_11.h"
#include "GameScene_34.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_5 : public CCLayer
{
public:
	GameScene_5();
	~GameScene_5();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_5);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_2(CCObject* pSender);
	void toScene_11(CCObject* pSender);
	void toScene_34(CCObject* pSender);

	//delete tip
	void delTips(CCNode* sender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

