#pragma once
#include "cocos2d.h"
#include "GameScene_1.h"
#include "GameScene_39.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_3 : public CCLayer
{
public:
	GameScene_3();
	~GameScene_3();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_3);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_1(CCObject* pSender);
	void toScene_39(CCObject* pSender);

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

