cocos2dx-anim
=============
cocos2d-x is lack of frame animation support, so I will migrate some code of WiEngine. 

Known-Issue
=============
I think there is a bug in CCTextureAtlas, so animation with multiple textures doesn't work. Here is issue I submit to 
cocos2d-x: https://github.com/cocos2d/cocos2d-x/issues/2264. In demos, only Arctic demo uses multiple textures, so it 
looks weird.

Tools Supported
=============
 * Frame Animation Tools
  * Motion Welder, please download it from http://www.motionwelder.com
  * SpriteX 3.9.4, download: http://wiengine.wiyun.com/tools/spx3.rar
  * SpriteX 2011, trail download: http://wiengine.wiyun.com/tools/SpriteX_2011_free_version.rar, full version is not free
  * Arctic, download: http://wiengine.wiyun.com/tools/Arctic_0.2.5.zip
  * AuroraGT 0.7.3, search it in internet, I don't provide download link here.
 * Skeletal Animation Tools
  * Spine, download it from http://esotericsoftware.com. It is not free, but there is trail version with full functions except exporting.

Requirement
===========
cocos2dx-anim project refers cocos2d-x project. You must clone cocos2d-x repository to a folder named "cocos2d-x", 
and then clone cocos2dx-anim in the same parent folder. 

I put some common code to https://github.com/stubma/cocos2dx-common, so also clone it in the same parent folder.
The cocos2dx-common is referred by all my cocos2d-x extensions.

Demo
===========
There is a test project in test folder, it supports iOS and android. If you want other platform, do it yourself.

How to use
===========
For iOS, just drag cocos2dx-anim project into your project. For Android, just import cocos2dx-anim module. If not clear, 
refer to demo code.
