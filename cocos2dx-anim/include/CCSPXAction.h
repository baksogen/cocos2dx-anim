/****************************************************************************
 Author: Luma (stubma@gmail.com)
 
 https://github.com/stubma/cocos2dx-anim
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef __CCSPXAction_h__
#define __CCSPXAction_h__

#include "cocos2d.h"
#include "CCSPXConstants.h"

NS_CC_BEGIN

class CCSPXLoader;

/**
 * @typedef CCSPXActionFrame
 *
 * frame info in animation
 */
typedef struct CCSPXActionFrame {
	/**
	 * frame index
	 */
	int index;

	/**
	 * duration of frame
	 */
	float duration;
} CCSPXActionFrame;

/**
 * @class CCSPXAction
 *
 * Info bean for one SpriteX animation
 */
class CC_DLL CCSPXAction : public CCObject {
	friend class CCSPXLoader;

public:
	/**
	 * transform of anmation
	 */
	CCSPXTransform m_transform;

	/**
	 * frame count in this animation
	 */
	int m_frameCount;

	/**
	 * max tile count of frame
	 */
	int m_maxFrameTile;

	/**
	 * frame info
	 */
	CCSPXActionFrame* m_frames;

private:
	CCSPXAction();

public:
	virtual ~CCSPXAction();
};

NS_CC_END

#endif // __CCSPXAction_h__
