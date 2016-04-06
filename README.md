# LYCategories
==============

[![License MIT](https://img.shields.io/badge/license-MIT-green.svg?style=flat)](https://raw.githubusercontent.com/CoderYLiu/LYCategories/master/LICENSE)&nbsp;
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)&nbsp;
[![CocoaPods](http://img.shields.io/cocoapods/v/LYCategories.svg?style=flat)](http://cocoapods.org/?q=LYCategories)&nbsp;
[![CocoaPods](http://img.shields.io/cocoapods/p/LYCategories.svg?style=flat)](http://cocoapods.org/?q=LYCategories)&nbsp;
[![Support](https://img.shields.io/badge/support-iOS%206%2B%20-blue.svg?style=flat)](https://www.apple.com/nl/ios/)&nbsp;
[![Build Status](https://img.shields.io/teamcity/codebetter/bt428.svg)](https://travis-ci.org/CoderYLiu/LYCategories)

收集整理的一套Foundation和UIKit下的 Category 类型工具库

安装
==============

### CocoaPods

1. 在 Podfile 中添加  `pod "LYCategories"`。
2. 执行 `pod install` 或 `pod update`。
3. 导入 \<LYCategories/LYCategories.h\>。


### 手动安装

1. 下载 LYCategories 文件夹内的所有内容。
2. 将 LYCategories 内的源文件添加(拖放)到你的工程。
3. 为`GTMBase64.m` 添加编译参数 `-fno-objc-arc`。
4. 链接以下 frameworks:
	* UIKit
	* CoreGraphics
	* QuartzCore
	* Accelerate
	* ImageIO
	* CoreText
	* CoreFoundation
5. 导入 `LYCategories.h`。

文档
==============
你可以在 [CocoaDocs](http://cocoadocs.org/docsets/LYCategories) 查看在线 API 文档，也可以用 [appledoc](https://github.com/tomaz/appledoc) 本地生成文档。

系统要求
==============
该项目最低支持 iOS 6.0。

关于
==============
该工程是一个静态库工程，所有头文件已经暴露出去了，所以使用的时候可以直接编译成静态库后，拖入项目中使用。如果你只需要其中少量代码，那最好将那段代码取出来，而不是导入整个库。

许可证
==============
LYCategories 使用 MIT 许可证，详情见 LICENSE 文件。
