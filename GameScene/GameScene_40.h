#pragma once
#include "cocos2d.h"
#include "GameScene_8.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_40 : public CCLayer
{
public:
	GameScene_40();
	~GameScene_40();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_40);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_8(CCObject* pSender);
	void pickCard(CCObject* pSender);

	//delete tip
	void delTips(CCNode* sender);


private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

	//school card
	CCMenu* card;

};

