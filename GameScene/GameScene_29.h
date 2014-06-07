#pragma once
#include "cocos2d.h"
#include "GameScene_22.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_29 : public CCLayer
{
public:
	GameScene_29();
	~GameScene_29();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_29);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_22(CCObject* pSender);
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

	//chaosuan card
	CCMenu* card;

};

