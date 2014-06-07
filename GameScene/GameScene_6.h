#pragma once
#include "cocos2d.h"
#include "GameScene_2.h"
#include "GameScene_15.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_6 : public CCLayer
{
public:
	GameScene_6();
	~GameScene_6();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_6);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_2(CCObject* pSender);
	void toScene_15(CCObject* pSender);

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

