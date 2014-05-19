//
//  LoadingLayer.cpp
//  TestGame
//
//  Created by Jerry on 14-5-19.
//
//

#include "LoadingLayer.h"
#include "MainLayer.h"
#include "unistd.h"


LoadingLayer::LoadingLayer()
: mLoadingBar(NULL)
, mLoadingPercent(NULL)
, iCurrentNum(0)
{
    iTotalNum = 5;
}

LoadingLayer::~LoadingLayer()
{
    CC_SAFE_RELEASE(mLoadingBar);
    CC_SAFE_RELEASE(mLoadingPercent);
}

LoadingLayer* LoadingLayer::load(CCLayer *target)
{
    LoadingLayer *node = (LoadingLayer *) CCBManage::loadCCB("LoadingLayer.ccbi", LoadingLayer::create(), "LoadingLayer", LoadingLayerLoader::loader());
    
    node->setAnimationManager((CCBAnimationManager *) node->getUserObject());
    
    node->pTarget = target;
    
    return node;
}

void LoadingLayer::show()
{
    pTarget->addChild(this);
    
    CCLOG("===show===");
    CCLOG("this->%p",this);
}

void LoadingLayer::loadingCallBack(CCObject *obj)
{
    //currentNum初始值为0，每加载一张纹理值自加1
    ++iCurrentNum;
    //求得百分比
    char cTmp[10];
    int iTmp = (int)(((float)iCurrentNum / iTotalNum) * 100);
    sprintf(cTmp, "%d%%", iTmp);
    
    //设置标签显示的内容
    mLoadingPercent->setString(cTmp);
    mLoadingBar->setPreferredSize(ccp(900 * iTmp / 100, 32));
    //sleep(1);
    //sleep(100);
    //如果当前加载的张数跟总数相等则进行场景跳转
    if (iCurrentNum == iTotalNum)
    {
        //场景跳转
//        ccColor3B transitionColor;
//        transitionColor.r = 0;
//        transitionColor.g = 0;
//        transitionColor.b = 0;
        
        pTarget->removeChild(this);
        
        MainLayer *layer = MainLayer::load(pTarget);
        //CCScene * scene = CCScene::create();
        pTarget->addChild(layer);
        
        CCLOG("===loaded===");
        
        //CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene, transitionColor));
    }
    CCLOG("===loadingCallBack===");
    CCLOG("%d",iTmp);
}

void LoadingLayer::onNodeLoaded(CCNode *pNode, CCNodeLoader *pNodeLoader)
{
    CCLOG("LoadingLayer OnLoad");
    
    mLoadingPercent->setString("0%");
    mLoadingBar->setPreferredSize(ccp(10, 32));
    
    //for (int i = 0; i < 5000; i++)
    //{
    CCTextureCache::sharedTextureCache()->addImageAsync("test1.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("test2.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("test3.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("test4.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));
    CCTextureCache::sharedTextureCache()->addImageAsync("test5.png", this, callfuncO_selector(LoadingLayer::loadingCallBack));

    //}

    CCLOG("===onNodeLoaded===");
    CCLOG("this->%p",this);
    
}

bool LoadingLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)   //重写ccbi文件成员对象绑定器
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mLoadingBar", CCScale9Sprite*, this->mLoadingBar);        //设定成员对象对应变量
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mLoadingPercent", CCLabelTTF*, this->mLoadingPercent);        //设定成员对象对应变量
    
    CCLOG("===onAssignCCBMemberVariable===");
    CCLOG("this->%p",this);
    
    return true;
}

