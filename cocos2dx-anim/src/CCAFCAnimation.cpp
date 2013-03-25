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
#include "CCAFCAnimation.h"

NS_CC_BEGIN

CCAFCAnimation::CCAFCAnimation() {
}

CCAFCAnimation::~CCAFCAnimation() {
	for(AFCFramePtrList::iterator iter = m_frameList.begin(); iter != m_frameList.end(); iter++) {
		(*iter)->release();
	}
}

CCAFCAnimation* CCAFCAnimation::create() {
	CCAFCAnimation* a = new CCAFCAnimation();
	return (CCAFCAnimation*)a->autorelease();
}

void CCAFCAnimation::addFrame(CCAFCFrame* f) {
	if(f) {
		m_frameList.push_back(f);
		f->retain();
	}
}

NS_CC_END