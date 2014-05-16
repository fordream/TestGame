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
: pPopLayer(NULL)
{
    
}

MainLayer::~MainLayer()
{
    CC_SAFE_RELEASE(pPopLayer);
}

void MainLayer::show(CCLayer *target)
{
    if (target == NULL)
    {
        target = this;
    }
    
    CCNode *node = CCBManage::loadCCB("MainLayer.ccbi", this, "MainLayer", MainLayerLoader::loader());
    
    this->addChild(node);
    
    target->addChild(this);
}

SEL_CCControlHandler MainLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)   //重写Control类按钮回调函数绑定器
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickMe", MainLayer::onClickMe);    //设定Control类按钮对应函数
    return NULL;
}

void MainLayer::onClickMe(CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("ClickMe Btn Clicked");
    
    pPopLayer = PopLayer::create();
    pPopLayer->show(this);
}



void MainLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    CCLOG("MainLayer OnLoad");
}