#pragma once
#include "cocos2d.h"
#include "GameScene_17.h"

#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_33 : public CCLayer
{
public:
	GameScene_33();
	~GameScene_33();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_33);

	//init the game scene
	void InitScene();


	//run game
	void runGame();

	//move menu
	void toScene_17(CCObject* pSender);

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


