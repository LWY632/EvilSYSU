#pragma once
#include "cocos2d.h"
#include "GameScene_35.h"
#include "GameScene_37.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_36 : public CCLayer
{
public:
	GameScene_36();
	~GameScene_36();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_36);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_35(CCObject* pSender);
	void toScene_37(CCObject* pSender);

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

