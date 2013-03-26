#ifndef _AnimTest_H_
#define _AnimTest_H_

#include "../testBasic.h"
#include "cocos2d-anim.h"

using namespace std;
USING_NS_CC;


enum
{
    ANIM_MOTION_WELDER = 0,
    ANIM_LAYER_COUNT,
};


// the class inherit from TestScene
// every Scene each test used must inherit from TestScene,
// make sure the test have the menu item for back to main menu
class AnimTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

class AnimDemo : public CCLayer
{
public:
    virtual void onEnter();
    virtual void onExit();
	
    virtual string title();
    virtual string subtitle();

    void restartCallback(CCObject* pSender);
    void nextCallback(CCObject* pSender);
    void backCallback(CCObject* pSender);
};

class AnimMotionWelder : public AnimDemo
{
private:
	CCMWSprite* m_sprite1;
	CCMWSprite* m_sprite2;
	CCMWSprite* m_sprite3;
	CCMWSprite* m_sprite4;
	CCMWSprite* m_sprite5;
    
public:
    virtual void onEnter();
    virtual string subtitle();
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void update(float dt);
};

#endif
