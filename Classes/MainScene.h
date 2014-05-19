//
//  MainScene.h
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#ifndef __TestGame__MainScene__
#define __TestGame__MainScene__

#include "cocos2d.h"
#include "MainLayer.h"
#include "LoadingLayer.h"

USING_NS_CC;

class MainScene
: public CCScene
{
public:
    MainScene();
    
    ~MainScene();
    
    virtual bool init();      //重写init函数
    
    CREATE_FUNC(MainScene);   //创建create函数
};


#endif /* defined(__TestGame__MainScene__) */
