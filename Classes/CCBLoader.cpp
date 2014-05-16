//
//  CCBLoader.cpp
//  TestGame
//
//  Created by Jerry on 14-5-13.
//
//

#include "CCBLoader.h"

CCNode *CCBLoader::loadCCB(const char * pCCBFileName, CCLayer * pCCLayer, const char * pCCNodeName, CCNodeLoader * pCCNodeLoader)
{
    /* Create an autorelease CCNodeLoaderLibrary. */
    CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    if(pCCNodeName != NULL && pCCNodeLoader != NULL) {
        ccNodeLoaderLibrary->registerCCNodeLoader(pCCNodeName, pCCNodeLoader);
    }
    
    /* Create an autorelease CCBReader. */
    CCBReader *ccbReader = new CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    /* Read a ccbi file. */
    // Load the scene from the ccbi-file, setting this class as
    // the owner will cause lblTestTitle to be set by the CCBReader.
    // lblTestTitle is in the TestHeader.ccbi, which is referenced
    // from each of the test scenes.
    return ccbReader->readNodeGraphFromFile(pCCBFileName, pCCLayer);
}