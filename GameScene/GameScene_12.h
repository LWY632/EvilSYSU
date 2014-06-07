#pragma once
#include "cocos2d.h"
#include "GameScene_11.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_12 : public CCLayer
{
public:
	GameScene_12();
	~GameScene_12();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_12);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_11(CCObject* pSender);
	void pickFace(CCObject* pSender);

	//delete tip
	void delTips(CCNode* sender);


private:
	//Size
	CCSize visibleSize;
	//Original point
	CCPoint visibleOrigin;

	//background image
	CCSprite* background;

	//face
	CCMenu* face;

};

