//
//  MainScene.cpp
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#include "MainScene.h"

MainScene::MainScene()
{
    
}

MainScene::~MainScene()
{
}

bool MainScene::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!CCScene::init());
        
        CCLayer *target = (CCLayer *) this;
        
        LoadingLayer::load(target)->show();
        
        bRet = true;
    } while (0);
    
    return bRet;
}