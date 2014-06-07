#pragma once
#include "cocos2d.h"
#include "GameScene_2.h"
#include "GameScene_3.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_1 : public CCLayer
{
public:
	GameScene_1();
	~GameScene_1();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_1);

	//init the game scene
	void InitScene();

	//tips animation
	void showTip_1();
	void showTip_2(CCNode* sender);
	//run game
	void runGame(CCNode* sender);

	//move menu
	void toScene_2(CCObject* pSender);
	void toScene_3(CCObject* pSender);

private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

};

