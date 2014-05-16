//
//  CCBLoader.h
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#ifndef __TestGame__CCBLoader__
#define __TestGame__CCBLoader__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CCBManage
: public CCLayer
{
public:
    static CCNode *loadCCB(const char * pCCBFileName, CCLayer *pCCLayer, const char * pCCNodeName = NULL, CCNodeLoader * pCCNodeLoader = NULL);
};

#endif /* defined(__TestGame__CCBLoader__) */
