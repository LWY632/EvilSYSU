#pragma once
#include "cocos2d.h"
#include "GameScene_34.h"
#include "GameScene_36.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_35 : public CCLayer
{
public:
	GameScene_35();
	~GameScene_35();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_35);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_34(CCObject* pSender);
	void toScene_36(CCObject* pSender);

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

