#pragma once
#include "cocos2d.h"
#include "GameScene_7.h"
#include "GameScene_10.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_9 : public CCLayer
{
public:
	GameScene_9();
	~GameScene_9();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_9);

	//init the game scene
	void InitScene();

	void showTip_1();

	//run game
	void runGame(CCNode* sender);

	//move menu
	void toScene_7(CCObject* pSender);
	void toScene_10(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

