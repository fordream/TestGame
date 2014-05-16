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
        pMainLayer = MainLayer::load();
        CC_BREAK_IF(!pMainLayer);
        this->addChild(pMainLayer);
        
        bRet = true;
    } while (0);
    
    return bRet;
}