//
//  MainLayer.cpp
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#include "MainLayer.h"
#include "MaskLayer.h"


MainLayer::MainLayer()
: pPopLayer(NULL)
{
    
}

MainLayer::~MainLayer()
{
    CC_SAFE_RELEASE(pPopLayer);
}

MainLayer* MainLayer::load()
{
    MainLayer *layer = MainLayer::create();
    
    CCNode *node = CCBLoader::loadCCB("MainLayer.ccbi", layer, "MainLayer", MainLayerLoader::loader());
    
    layer->addChild(node);
    
    //CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("shoot_background.plist");
    //CCTextureCache::sharedTextureCache()->add
    
    //CCSprite::createWithSpriteFrameName("Btn.png");
    
    //CCSpriteFrameCache::

    return layer;
}

SEL_CCControlHandler MainLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)   //重写Control类按钮回调函数绑定器
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickMe", MainLayer::onClickMe);    //设定Control类按钮对应函数
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClose", MainLayer::onClose);        //设定Control类按钮对应函数
    return NULL;
}

void MainLayer::onClickMe(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("ClickMe Btn Clicked");
    
    //CCLayer *pMaskLayer = MaskLayer::create();
    //this->addChild(pMaskLayer);
    
    pPopLayer = CCBLoader::loadCCB("PopLayer.ccbi", this, "PopLayer", PopLayerLoader::loader());
    
    this->addChild(pPopLayer);
}

void MainLayer::onClose(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCBAnimationManager *mAnimationManager = (CCBAnimationManager *) pPopLayer->getUserObject();
    
    mAnimationManager->runAnimationsForSequenceNamed("Display");
    mAnimationManager->setAnimationCompletedCallback(this, callfunc_selector(MainLayer::callBackAnimationCompleted));
    
    //this->removeChild(pPopLayer);
    CCLOG("Close Btn Clicked");
}

void MainLayer::callBackAnimationCompleted()
{
    CCBAnimationManager *mAnimationManager = (CCBAnimationManager *) pPopLayer->getUserObject();
    
    std::string lastSeqName = mAnimationManager->getLastCompletedSequenceName();
    
    if (lastSeqName == "Display")
    {
        this->removeChild(pPopLayer);
        CCLOG("pPopLayer remove");
    }
}

void MainLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    CCLOG("MainLayer OnLoad");
}