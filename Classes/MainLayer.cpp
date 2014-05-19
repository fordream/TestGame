//
//  MainLayer.cpp
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#include "MainLayer.h"
#include "PopLayer.h"


MainLayer::MainLayer()
{
}

MainLayer::~MainLayer()
{
}

MainLayer* MainLayer::load(CCLayer *target)
{
    MainLayer *node = (MainLayer *) CCBManage::loadCCB("MainLayer.ccbi", PopLayer::create(), "MainLayer", MainLayerLoader::loader());
    
    node->setAnimationManager((CCBAnimationManager *) node->getUserObject());
    
    node->pTarget = target;
    
    return node;
}

void MainLayer::show()
{
    //CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ccbDefaultImages.plist");
    pTarget->addChild(this);
    
    CCLOG("===show===");
    CCLOG("this->%p",this);
}

SEL_CCControlHandler MainLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)   //重写Control类按钮回调函数绑定器
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickMe", MainLayer::onClickMe);    //设定Control类按钮对应函数
    //CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClose", MainLayer::onClose);    //设定Control类按钮对应函数
    
    return NULL;
}

void MainLayer::onClickMe(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("ClickMe Btn Clicked");
    
    PopLayer::load(this)->show();
}

void MainLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    CCLOG("MainLayer OnLoad");
}