//
//  MainScene.cpp
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#include "MainScene.h"

MainScene::MainScene()
: pMainLayer(NULL)
{
    
}

MainScene::~MainScene()
{
    CC_SAFE_RELEASE(pMainLayer);
}

bool MainScene::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!CCScene::init());
        
        MainLayer::create()->show((CCLayer *) this);
        
        bRet = true;
    } while (0);
    
    return bRet;
}