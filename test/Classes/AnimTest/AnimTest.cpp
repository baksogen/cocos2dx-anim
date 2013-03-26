#include "AnimTest.h"
#include "../testResource.h"
#include "cocos2d.h"
#include "cocos2d-common.h"

TESTLAYER_CREATE_FUNC(AnimMotionWelder);

static NEWTESTFUNC createFunctions[] = {
    CF(AnimMotionWelder)
};

static int sceneIdx=-1;
#define MAX_LAYER (sizeof(createFunctions) / sizeof(createFunctions[0]))

static CCLayer* nextAction()
{
    sceneIdx++;
    sceneIdx = sceneIdx % MAX_LAYER;
    
    CCLayer* pLayer = (createFunctions[sceneIdx])();
    pLayer->init();
    pLayer->autorelease();
    
    return pLayer;
}

static CCLayer* backAction()
{
    sceneIdx--;
    int total = MAX_LAYER;
    if( sceneIdx < 0 )
        sceneIdx += total;
    
    CCLayer* pLayer = (createFunctions[sceneIdx])();
    pLayer->init();
    pLayer->autorelease();
    
    return pLayer;
}

static CCLayer* restartAction()
{
    CCLayer* pLayer = (createFunctions[sceneIdx])();
    pLayer->init();
    pLayer->autorelease();
    
    return pLayer;
}

void AnimTestScene::runThisTest()
{
    sceneIdx = -1;
    addChild(nextAction());

    CCDirector::sharedDirector()->replaceScene(this);
}


std::string AnimDemo::title()
{
    return "AnimTest";
}

std::string AnimDemo::subtitle()
{
    return "";
}

void AnimDemo::onEnter()
{
    CCLayer::onEnter();

    // add title and subtitle
    std::string str = title();
    const char * pTitle = str.c_str();
    CCLabelTTF* label = CCLabelTTF::create(pTitle, "Arial", 32);
    addChild(label, 1);
    label->setPosition( ccp(VisibleRect::center().x, VisibleRect::top().y - 30) );

    std::string strSubtitle = subtitle();
    if( ! strSubtitle.empty() ) 
    {
        CCLabelTTF* l = CCLabelTTF::create(strSubtitle.c_str(), "Thonburi", 16);
        addChild(l, 1);
        l->setPosition( ccp(VisibleRect::center().x, VisibleRect::top().y - 60) );
    }    

    // add menu
    CCMenuItemImage *item1 = CCMenuItemImage::create(s_pPathB1, s_pPathB2, this, menu_selector(AnimDemo::backCallback) );
    CCMenuItemImage *item2 = CCMenuItemImage::create(s_pPathR1, s_pPathR2, this, menu_selector(AnimDemo::restartCallback) );
    CCMenuItemImage *item3 = CCMenuItemImage::create(s_pPathF1, s_pPathF2, this, menu_selector(AnimDemo::nextCallback) );

    CCMenu *menu = CCMenu::create(item1, item2, item3, NULL);

    menu->setPosition(CCPointZero);
    item1->setPosition(ccp(VisibleRect::center().x - item2->getContentSize().width*2, VisibleRect::bottom().y+item2->getContentSize().height/2));
    item2->setPosition(ccp(VisibleRect::center().x, VisibleRect::bottom().y+item2->getContentSize().height/2));
    item3->setPosition(ccp(VisibleRect::center().x + item2->getContentSize().width*2, VisibleRect::bottom().y+item2->getContentSize().height/2));

    addChild(menu, 1);
}

void AnimDemo::onExit()
{
    CCLayer::onExit();
}

void AnimDemo::restartCallback(CCObject* pSender)
{
    CCScene* s = new AnimTestScene();
    s->addChild( restartAction() );
    CCDirector::sharedDirector()->replaceScene(s);
    s->release();
}

void AnimDemo::nextCallback(CCObject* pSender)
{
    CCScene* s = new AnimTestScene();
    s->addChild( nextAction() );
    CCDirector::sharedDirector()->replaceScene(s);
    s->release();
}

void AnimDemo::backCallback(CCObject* pSender)
{
    CCScene* s = new AnimTestScene();
    s->addChild( backAction() );
    CCDirector::sharedDirector()->replaceScene(s);
    s->release();
}

//------------------------------------------------------------------
//
// Motion Welder
//
//------------------------------------------------------------------
void AnimMotionWelder::onEnter()
{
    AnimDemo::onEnter();
    
    // surface
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // texture
    CCTexture2D* tex1 = CCTextureCache::sharedTextureCache()->addImage("Files/mongo.png");
    
    // animation 1
    m_sprite1 = CCMWSprite::create("Files/test_motion_welder.anu", 0, tex1, NULL);
    m_sprite1->setLoopCount(-1);
    m_sprite1->setPosition(ccp(origin.x + visibleSize.width / 2,
                               origin.y + visibleSize.height * 5 / 6));
    m_sprite1->setUnitInterval(0.1f);
    m_sprite1->setDebugDrawFrameRect(true);
    m_sprite1->setDebugDrawCollisionRect(true);
    addChild(m_sprite1);
    
    // animation 2
    m_sprite2 = CCMWSprite::create("Files/test_motion_welder.anu", 1, tex1, NULL);
    m_sprite2->setLoopCount(-1);
    m_sprite2->setPosition(ccp(origin.x + visibleSize.width / 2,
                               origin.y + visibleSize.height * 4 / 6));
    m_sprite2->setUnitInterval(0.1f);
    m_sprite2->setDebugDrawFrameRect(true);
    m_sprite2->setDebugDrawCollisionRect(true);
    addChild(m_sprite2);
    
    // animation 2 but flip x
    m_sprite3 = CCMWSprite::create("Files/test_motion_welder.anu", 1, tex1, NULL);
    m_sprite3->setLoopCount(-1);
    m_sprite3->setFlipX(true);
    m_sprite3->setPosition(ccp(origin.x + visibleSize.width / 2,
                               origin.y + visibleSize.height * 3 / 6));
    m_sprite3->setUnitInterval(0.1f);
    m_sprite3->setDebugDrawFrameRect(true);
    m_sprite3->setDebugDrawCollisionRect(true);
    addChild(m_sprite3);
    
    // animation 2 but ignore frame offset
    m_sprite4 = CCMWSprite::create("Files/test_motion_welder.anu", 1, tex1, NULL);
    m_sprite4->setLoopCount(-1);
    m_sprite4->setIgnoreFrameOffset(true);
    m_sprite4->setPosition(ccp(origin.x + visibleSize.width / 2,
                               origin.y + visibleSize.height * 2 / 6));
    m_sprite4->setUnitInterval(0.1f);
    m_sprite4->setDebugDrawFrameRect(true);
    m_sprite4->setDebugDrawCollisionRect(true);
    addChild(m_sprite4);
    
    // animation 2 but ignore frame offset and flip x
    m_sprite5 = CCMWSprite::create("Files/test_motion_welder.anu", 1, tex1, NULL);
    m_sprite5->setLoopCount(-1);
    m_sprite5->setIgnoreFrameOffset(true);
    m_sprite5->setFlipX(true);
    m_sprite5->setPosition(ccp(origin.x + visibleSize.width / 2,
                               origin.y + visibleSize.height / 6));
    m_sprite5->setUnitInterval(0.1f);
    m_sprite5->setDebugDrawFrameRect(true);
    m_sprite5->setDebugDrawCollisionRect(true);
    addChild(m_sprite5);
    
    scheduleUpdate();
    
    setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);
}

bool AnimMotionWelder::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
    m_sprite1->setPaused(!m_sprite1->isPaused());
    m_sprite2->setPaused(!m_sprite2->isPaused());
    m_sprite3->setPaused(!m_sprite3->isPaused());
    m_sprite4->setPaused(!m_sprite4->isPaused());
    m_sprite5->setPaused(!m_sprite5->isPaused());
    return false;
}

void AnimMotionWelder::update(float dt) {
    m_sprite1->tick(dt);
    m_sprite2->tick(dt);
    m_sprite3->tick(dt);
    m_sprite4->tick(dt);
    m_sprite5->tick(dt);
}

std::string AnimMotionWelder::subtitle()
{
    return "Motion Welder";
}