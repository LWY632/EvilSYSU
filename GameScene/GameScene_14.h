#pragma once
#include "cocos2d.h"
#include "GameScene_13.h"
#define userDataFile CCUserDefault::sharedUserDefault()
USING_NS_CC;

class GameScene_14 : public CCLayer
{
public:
	GameScene_14();
	~GameScene_14();

	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(GameScene_14);

	//init the game scene
	void InitScene();

	//run game
	void runGame();

	//move menu
	void toScene_13(CCObject* pSender);
	void pickBook(CCObject* pSender);

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

