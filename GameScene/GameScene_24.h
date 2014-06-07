#pragma once
#include "cocos2d.h"
#include "GameScene_23.h"
#include "GameScene_26.h"

#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_24 : public CCLayer
{
public:
	GameScene_24();
	~GameScene_24();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_24);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_23(CCObject* pSender);
	void toScene_26(CCObject* pSender);

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


