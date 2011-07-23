#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_HighDpiScreenManager
#include <HighDpiScreenManager.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_PGraphics
#include <PGraphics.h>
#endif
#ifndef INCLUDED_PGraphicsRoot
#include <PGraphicsRoot.h>
#endif
#ifndef INCLUDED_PImage
#include <PImage.h>
#endif
#ifndef INCLUDED_ProcessingHaxeBitmapPool
#include <ProcessingHaxeBitmapPool.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_Timer
#include <nme/Timer.h>
#endif
#ifndef INCLUDED_nme_display_Bitmap
#include <nme/display/Bitmap.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Shape
#include <nme/display/Shape.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_display_StageQuality
#include <nme/display/StageQuality.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Transform
#include <nme/geom/Transform.h>
#endif
#ifndef INCLUDED_nme_system_System
#include <nme/system/System.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif

Void Main_obj::__construct()
{
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::initialiseTopLevelVariables( ){
{
		HX_SOURCE_PUSH("Main_obj::initialiseTopLevelVariables")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,initialiseTopLevelVariables,(void))

Void Main_obj::main( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::main")
		HX_SOURCE_POS("./Main.hx",24)
		::Main_obj::g = ::PGraphicsRoot_obj::__new(null(),null());
		HX_SOURCE_POS("./Main.hx",33)
		::nme::Lib_obj::nmeGetCurrent()->addChild(::Main_obj::g);
		HX_SOURCE_POS("./Main.hx",40)
		::nme::Lib_obj::nmeGetStage()->nmeSetFrameRate((int)60);
		HX_SOURCE_POS("./Main.hx",41)
		::nme::Lib_obj::nmeGetCurrent()->addEventListener(::nme::events::Event_obj::ENTER_FRAME,::Main_obj::wholeDrawCycle_dyn(),null(),null(),null());
		HX_SOURCE_POS("./Main.hx",42)
		::nme::Lib_obj::nmeGetCurrent()->addEventListener(::nme::events::MouseEvent_obj::MOUSE_UP,::Main_obj::mouseUpCatcherFunction_dyn(),null(),null(),null());
		HX_SOURCE_POS("./Main.hx",43)
		::nme::Lib_obj::nmeGetCurrent()->addEventListener(::nme::events::MouseEvent_obj::MOUSE_DOWN,::Main_obj::mouseDownCatcherFunction_dyn(),null(),null(),null());
		HX_SOURCE_POS("./Main.hx",44)
		::nme::Lib_obj::nmeGetCurrent()->addEventListener(::nme::events::MouseEvent_obj::MOUSE_MOVE,::Main_obj::mouseMoveCatcherFunction_dyn(),null(),null(),null());
		HX_SOURCE_POS("./Main.hx",45)
		::nme::Lib_obj::nmeGetCurrent()->addEventListener(::nme::events::MouseEvent_obj::CLICK,::Main_obj::mouseClickCatcherFunction_dyn(),null(),null(),null());
		HX_SOURCE_POS("./Main.hx",47)
		::nme::Lib_obj::nmeGetStage()->nmeSetQuality(::nme::display::StageQuality_obj::LOW);
		HX_SOURCE_POS("./Main.hx",51)
		::Main_obj::millisecondsWhenSketchStarted = ::Std_obj::_int((::nme::Timer_obj::stamp() * (int)1000));
		HX_SOURCE_POS("./Main.hx",52)
		::HighDpiScreenManager_obj::dpiScaleFactor = ::nme::Lib_obj::nmeGetStage()->nmeGetDPIScale();
		HX_SOURCE_POS("./Main.hx",54)
		::Main_obj::setupArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))

Void Main_obj::wholeDrawCycle( ::nme::events::Event event){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::wholeDrawCycle")
		HX_SOURCE_POS("./Main.hx",63)
		{
			HX_SOURCE_POS("./Main.hx",63)
			double secondsSinceLastDraw;
			HX_SOURCE_POS("./Main.hx",63)
			if (((::Main_obj::timeStampOfLastDraw == (int)0))){
				HX_SOURCE_POS("./Main.hx",63)
				::Main_obj::timeStampOfLastDraw = ::nme::Timer_obj::stamp();
			}
			HX_SOURCE_POS("./Main.hx",63)
			secondsSinceLastDraw = (::nme::Timer_obj::stamp() - ::Main_obj::timeStampOfLastDraw);
			HX_SOURCE_POS("./Main.hx",63)
			if (((secondsSinceLastDraw > (int)2))){
				HX_SOURCE_POS("./Main.hx",63)
				hx::AddEq(::Main_obj::millisecondsTheAppHasSpentBackgrounded,::Std_obj::_int((((int)1000 * secondsSinceLastDraw) - (double((int)1000) / double(::Main_obj::frameCount)))));
			}
			HX_SOURCE_POS("./Main.hx",63)
			::Main_obj::timeStampOfLastDraw = ::nme::Timer_obj::stamp();
			HX_SOURCE_POS("./Main.hx",63)
			::Main_obj::g->bitmapPool->disposeAllBitmaps();
			HX_SOURCE_POS("./Main.hx",63)
			::Main_obj::g->beginDrawArgCount0();
			HX_SOURCE_POS("./Main.hx",63)
			{
				HX_SOURCE_POS("./Main.hx",63)
				::PGraphicsRoot _g1 = ::Main_obj::g;
				HX_SOURCE_POS("./Main.hx",63)
				_g1->shape = ::nme::display::Shape_obj::__new();
				HX_SOURCE_POS("./Main.hx",63)
				_g1->addChild(_g1->shape);
				HX_SOURCE_POS("./Main.hx",63)
				_g1->shape->nmeGetTransform()->nmeSetMatrix(_g1->shapeMatrix);
			}
			HX_SOURCE_POS("./Main.hx",63)
			::Main_obj::g->shape->nmeGetGraphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
			HX_SOURCE_POS("./Main.hx",63)
			::Main_obj::g->shape->nmeGetGraphics()->beginFill((int)0,(int)0);
			HX_SOURCE_POS("./Main.hx",63)
			::Main_obj::g->shape->nmeGetGraphics()->drawRect((int)0,(int)0,::Main_obj::width,::Main_obj::height);
			HX_SOURCE_POS("./Main.hx",63)
			::Main_obj::g->shape->nmeGetGraphics()->endFill();
			HX_SOURCE_POS("./Main.hx",63)
			(::Main_obj::frameCount)++;
		}
		HX_SOURCE_POS("./Main.hx",64)
		::Main_obj::drawArgCount0();
		HX_SOURCE_POS("./Main.hx",65)
		{
			HX_SOURCE_POS("./Main.hx",65)
			::PGraphicsRoot _g1 = ::Main_obj::g;
			HX_SOURCE_POS("./Main.hx",65)
			{
				HX_SOURCE_POS("./Main.hx",65)
				_g1->trackingTranslationY = _g1->trackingTranslationYStack->pop();
				HX_SOURCE_POS("./Main.hx",65)
				_g1->trackingTranslationX = _g1->trackingTranslationXStack->pop();
				HX_SOURCE_POS("./Main.hx",65)
				_g1->trackingRotation = _g1->trackingRotationStack->pop();
				HX_SOURCE_POS("./Main.hx",65)
				_g1->trackingScaleY = _g1->trackingScaleYStack->pop();
				HX_SOURCE_POS("./Main.hx",65)
				_g1->trackingScaleX = _g1->trackingScaleXStack->pop();
				HX_SOURCE_POS("./Main.hx",65)
				_g1->shapeMatrix = _g1->matrixStack->pop();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,wholeDrawCycle,(void))

Void Main_obj::startOfDrawMethod( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::startOfDrawMethod")
		HX_SOURCE_POS("./Main.hx",90)
		double secondsSinceLastDraw;
		HX_SOURCE_POS("./Main.hx",91)
		if (((::Main_obj::timeStampOfLastDraw == (int)0))){
			HX_SOURCE_POS("./Main.hx",92)
			::Main_obj::timeStampOfLastDraw = ::nme::Timer_obj::stamp();
		}
		HX_SOURCE_POS("./Main.hx",94)
		secondsSinceLastDraw = (::nme::Timer_obj::stamp() - ::Main_obj::timeStampOfLastDraw);
		HX_SOURCE_POS("./Main.hx",95)
		if (((secondsSinceLastDraw > (int)2))){
			HX_SOURCE_POS("./Main.hx",96)
			hx::AddEq(::Main_obj::millisecondsTheAppHasSpentBackgrounded,::Std_obj::_int((((int)1000 * secondsSinceLastDraw) - (double((int)1000) / double(::Main_obj::frameCount)))));
		}
		HX_SOURCE_POS("./Main.hx",99)
		::Main_obj::timeStampOfLastDraw = ::nme::Timer_obj::stamp();
		HX_SOURCE_POS("./Main.hx",117)
		::Main_obj::g->bitmapPool->disposeAllBitmaps();
		HX_SOURCE_POS("./Main.hx",120)
		::Main_obj::g->beginDrawArgCount0();
		HX_SOURCE_POS("./Main.hx",145)
		{
			HX_SOURCE_POS("./Main.hx",145)
			::PGraphicsRoot _g = ::Main_obj::g;
			HX_SOURCE_POS("./Main.hx",145)
			_g->shape = ::nme::display::Shape_obj::__new();
			HX_SOURCE_POS("./Main.hx",145)
			_g->addChild(_g->shape);
			HX_SOURCE_POS("./Main.hx",145)
			_g->shape->nmeGetTransform()->nmeSetMatrix(_g->shapeMatrix);
		}
		HX_SOURCE_POS("./Main.hx",146)
		::Main_obj::g->shape->nmeGetGraphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./Main.hx",147)
		::Main_obj::g->shape->nmeGetGraphics()->beginFill((int)0,(int)0);
		HX_SOURCE_POS("./Main.hx",148)
		::Main_obj::g->shape->nmeGetGraphics()->drawRect((int)0,(int)0,::Main_obj::width,::Main_obj::height);
		HX_SOURCE_POS("./Main.hx",149)
		::Main_obj::g->shape->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("./Main.hx",156)
		(::Main_obj::frameCount)++;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,startOfDrawMethod,(void))

Void Main_obj::endOfDrawMethod( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::endOfDrawMethod")
		HX_SOURCE_POS("./Main.hx",163)
		{
			HX_SOURCE_POS("./Main.hx",163)
			::PGraphicsRoot _g = ::Main_obj::g;
			HX_SOURCE_POS("./Main.hx",163)
			{
				HX_SOURCE_POS("./Main.hx",163)
				_g->trackingTranslationY = _g->trackingTranslationYStack->pop();
				HX_SOURCE_POS("./Main.hx",163)
				_g->trackingTranslationX = _g->trackingTranslationXStack->pop();
				HX_SOURCE_POS("./Main.hx",163)
				_g->trackingRotation = _g->trackingRotationStack->pop();
				HX_SOURCE_POS("./Main.hx",163)
				_g->trackingScaleY = _g->trackingScaleYStack->pop();
				HX_SOURCE_POS("./Main.hx",163)
				_g->trackingScaleX = _g->trackingScaleXStack->pop();
				HX_SOURCE_POS("./Main.hx",163)
				_g->shapeMatrix = _g->matrixStack->pop();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,endOfDrawMethod,(void))

::PGraphicsRoot Main_obj::g;

int Main_obj::frameCount;

int Main_obj::width;

int Main_obj::height;

int Main_obj::frameRate;

int Main_obj::millisecondsWhenSketchStarted;

double Main_obj::timeStampOfLastDraw;

int Main_obj::millisecondsTheAppHasSpentBackgrounded;

bool Main_obj::mousePressed;

bool Main_obj::keyPressed;

int Main_obj::mouseX;

int Main_obj::mouseY;

int Main_obj::pmouseX;

int Main_obj::pmouseY;

double Main_obj::PI;

double Main_obj::TWO_PI;

double Main_obj::HALF_PI;

int Main_obj::P2D;

int Main_obj::P3D;

int Main_obj::CORNER;

int Main_obj::RADIUS;

int Main_obj::CENTER_RADIUS;

int Main_obj::CENTER;

int Main_obj::POLYGON;

int Main_obj::QUADS;

int Main_obj::TRIANGLES;

int Main_obj::POINTS;

int Main_obj::LINES;

int Main_obj::TRIANGLE_STRIP;

int Main_obj::TRIANGLE_FAN;

int Main_obj::QUAD_STRIP;

int Main_obj::CORNERS;

bool Main_obj::CLOSE;

int Main_obj::RGB;

int Main_obj::HSB;

Void Main_obj::exitArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::exitArgCount0")
		HX_SOURCE_POS("./Main.hx",232)
		{
			HX_SOURCE_POS("./Main.hx",232)
			::nme::Lib_obj::nmeGetCurrent()->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,::Main_obj::wholeDrawCycle_dyn(),null());
			HX_SOURCE_POS("./Main.hx",232)
			::nme::Lib_obj::nmeGetStage()->nmeSetFrameRate(0.0000001);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,exitArgCount0,(void))

double Main_obj::powArgCount2( double v,double exp){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::powArgCount2")
	HX_SOURCE_POS("./Main.hx",236)
	return ::Math_obj::pow(v,exp);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,powArgCount2,return )

double Main_obj::absArgCount1( double v){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::absArgCount1")
	HX_SOURCE_POS("./Main.hx",240)
	return ::Math_obj::abs(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,absArgCount1,return )

double Main_obj::floorArgCount1( double v){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::floorArgCount1")
	HX_SOURCE_POS("./Main.hx",244)
	return ::Math_obj::floor(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,floorArgCount1,return )

int Main_obj::yearArgCount0( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::yearArgCount0")
	HX_SOURCE_POS("./Main.hx",248)
	return ::Date_obj::now()->getFullYear();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,yearArgCount0,return )

int Main_obj::monthArgCount0( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::monthArgCount0")
	HX_SOURCE_POS("./Main.hx",252)
	return (::Date_obj::now()->getMonth() + (int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,monthArgCount0,return )

int Main_obj::dayArgCount0( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::dayArgCount0")
	HX_SOURCE_POS("./Main.hx",256)
	return ::Date_obj::now()->getDate();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,dayArgCount0,return )

int Main_obj::hourArgCount0( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::hourArgCount0")
	HX_SOURCE_POS("./Main.hx",260)
	return ::Date_obj::now()->getHours();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,hourArgCount0,return )

int Main_obj::minuteArgCount0( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::minuteArgCount0")
	HX_SOURCE_POS("./Main.hx",264)
	return ::Date_obj::now()->getMinutes();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,minuteArgCount0,return )

int Main_obj::secondArgCount0( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::secondArgCount0")
	HX_SOURCE_POS("./Main.hx",268)
	return ::Date_obj::now()->getSeconds();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,secondArgCount0,return )

Void Main_obj::pushMatrixArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::pushMatrixArgCount0")
		HX_SOURCE_POS("./Main.hx",272)
		return ::Main_obj::g->pushMatrixArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,pushMatrixArgCount0,(void))

Void Main_obj::popMatrixArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::popMatrixArgCount0")
		HX_SOURCE_POS("./Main.hx",276)
		return ::Main_obj::g->popMatrixArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,popMatrixArgCount0,(void))

int Main_obj::millisArgCount0( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::millisArgCount0")
	HX_SOURCE_POS("./Main.hx",280)
	return ((::Std_obj::_int((::nme::Timer_obj::stamp() * (int)1000)) - ::Main_obj::millisecondsWhenSketchStarted) - ::Main_obj::millisecondsTheAppHasSpentBackgrounded);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,millisArgCount0,return )

Void Main_obj::delayArgCount1( int millisecondsToWait){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::delayArgCount1")
		HX_SOURCE_POS("./Main.hx",287)
		double starttime = (::nme::Timer_obj::stamp() * (int)1000);
		HX_SOURCE_POS("./Main.hx",291)
		::nme::Lib_obj::nmeGetStage()->nmeRender(false);
		HX_SOURCE_POS("./Main.hx",293)
		if (((millisecondsToWait > (int)200))){
			HX_SOURCE_POS("./Main.hx",294)
			while((((::nme::Timer_obj::stamp() * (int)1000) - starttime) < millisecondsToWait)){
				__SAFE_POINT
				HX_SOURCE_POS("./Main.hx",296)
				::nme::system::System_obj::gc();
			}
		}
		else{
			HX_SOURCE_POS("./Main.hx",300)
			while((((::nme::Timer_obj::stamp() * (int)1000) - starttime) < millisecondsToWait)){
				__SAFE_POINT
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,delayArgCount1,(void))

Void Main_obj::frameRateArgCount1( int theFrameRate){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::frameRateArgCount1")
		HX_SOURCE_POS("./Main.hx",305)
		::Main_obj::frameRate = theFrameRate;
		HX_SOURCE_POS("./Main.hx",306)
		::nme::Lib_obj::nmeGetStage()->nmeSetFrameRate(theFrameRate);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,frameRateArgCount1,(void))

Void Main_obj::ellipseModeArgCount1( int aEllipseMode){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::ellipseModeArgCount1")
		HX_SOURCE_POS("./Main.hx",310)
		::Main_obj::g->ellipseModeArgCount1(aEllipseMode);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,ellipseModeArgCount1,(void))

Void Main_obj::noLoopArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::noLoopArgCount0")
		HX_SOURCE_POS("./Main.hx",314)
		::nme::Lib_obj::nmeGetCurrent()->removeEventListener(::nme::events::Event_obj::ENTER_FRAME,::Main_obj::wholeDrawCycle_dyn(),null());
		HX_SOURCE_POS("./Main.hx",315)
		::nme::Lib_obj::nmeGetStage()->nmeSetFrameRate(0.0000001);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,noLoopArgCount0,(void))

int Main_obj::getArgCount2( int x,int y){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::getArgCount2")
	HX_SOURCE_POS("./Main.hx",319)
	return ::Main_obj::g->getArgCount2(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,getArgCount2,return )

Void Main_obj::setArgCount3( int x,int y,int color){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::setArgCount3")
		HX_SOURCE_POS("./Main.hx",324)
		::Main_obj::g->setArgCount3(x,y,color);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Main_obj,setArgCount3,(void))

Void Main_obj::smoothArgCount0( ){
{
		HX_SOURCE_PUSH("Main_obj::smoothArgCount0")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,smoothArgCount0,(void))

int Main_obj::colorArgCount1( int shadeOfGray){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::colorArgCount1")
	HX_SOURCE_POS("./Main.hx",335)
	return ::Main_obj::g->colorArgCount1(shadeOfGray);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,colorArgCount1,return )

int Main_obj::colorArgCount2( int shadeOfGray,int a){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::colorArgCount2")
	HX_SOURCE_POS("./Main.hx",339)
	return ::Main_obj::g->colorArgCount2(shadeOfGray,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,colorArgCount2,return )

int Main_obj::colorArgCount3( int r,int green,int b){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::colorArgCount3")
	HX_SOURCE_POS("./Main.hx",343)
	return ::Main_obj::g->colorArgCount3(r,green,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Main_obj,colorArgCount3,return )

int Main_obj::colorArgCount4( int r,int green,int b,int a){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::colorArgCount4")
	HX_SOURCE_POS("./Main.hx",347)
	return ::Main_obj::g->colorArgCount4(r,green,b,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,colorArgCount4,return )

int Main_obj::redArgCount1( int aColor){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::redArgCount1")
	HX_SOURCE_POS("./Main.hx",352)
	return ::Main_obj::g->redArgCount1(aColor);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,redArgCount1,return )

int Main_obj::greenArgCount1( int aColor){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::greenArgCount1")
	HX_SOURCE_POS("./Main.hx",357)
	return ::Main_obj::g->greenArgCount1(aColor);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,greenArgCount1,return )

int Main_obj::blueArgCount1( int aColor){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::blueArgCount1")
	HX_SOURCE_POS("./Main.hx",362)
	return ::Main_obj::g->blueArgCount1(aColor);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,blueArgCount1,return )

int Main_obj::alphaArgCount1( int aColor){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::alphaArgCount1")
	HX_SOURCE_POS("./Main.hx",367)
	return ::Main_obj::g->alphaArgCount1(aColor);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,alphaArgCount1,return )

Void Main_obj::endDrawArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::endDrawArgCount0")
		struct _Function_1_1{
			inline static Void Block( ){
				{
					HX_SOURCE_POS("./Main.hx",372)
					::PGraphicsRoot _g = ::Main_obj::g;
					HX_SOURCE_POS("./Main.hx",372)
					{
						HX_SOURCE_POS("./Main.hx",372)
						_g->trackingTranslationY = _g->trackingTranslationYStack->pop();
						HX_SOURCE_POS("./Main.hx",372)
						_g->trackingTranslationX = _g->trackingTranslationXStack->pop();
						HX_SOURCE_POS("./Main.hx",372)
						_g->trackingRotation = _g->trackingRotationStack->pop();
						HX_SOURCE_POS("./Main.hx",372)
						_g->trackingScaleY = _g->trackingScaleYStack->pop();
						HX_SOURCE_POS("./Main.hx",372)
						_g->trackingScaleX = _g->trackingScaleXStack->pop();
						HX_SOURCE_POS("./Main.hx",372)
						_g->shapeMatrix = _g->matrixStack->pop();
					}
				}
				return null();
			}
		};
		HX_SOURCE_POS("./Main.hx",372)
		return _Function_1_1::Block();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,endDrawArgCount0,(void))

Void Main_obj::beginDrawArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::beginDrawArgCount0")
		HX_SOURCE_POS("./Main.hx",376)
		return ::Main_obj::g->beginDrawArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,beginDrawArgCount0,(void))

Void Main_obj::backgroundArgCount4( int r,int green,int b,int a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::backgroundArgCount4")
		HX_SOURCE_POS("./Main.hx",380)
		return ::Main_obj::g->backgroundArgCount4(r,green,b,a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,backgroundArgCount4,(void))

Void Main_obj::backgroundArgCount3( int r,int green,int b){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::backgroundArgCount3")
		HX_SOURCE_POS("./Main.hx",384)
		return ::Main_obj::g->backgroundArgCount3(r,green,b);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Main_obj,backgroundArgCount3,(void))

Void Main_obj::backgroundArgCount2( int shadeOfGray,int a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::backgroundArgCount2")
		HX_SOURCE_POS("./Main.hx",388)
		return ::Main_obj::g->backgroundArgCount2(shadeOfGray,a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,backgroundArgCount2,(void))

Void Main_obj::backgroundArgCount1( int shadeOfGray){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::backgroundArgCount1")
		HX_SOURCE_POS("./Main.hx",392)
		return ::Main_obj::g->backgroundArgCount1(shadeOfGray);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,backgroundArgCount1,(void))

Void Main_obj::backgroundArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::backgroundArgCount0")
		HX_SOURCE_POS("./Main.hx",396)
		return ::Main_obj::g->backgroundArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,backgroundArgCount0,(void))

Void Main_obj::imageArgCount3( ::PImage img,int x,int y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::imageArgCount3")
		HX_SOURCE_POS("./Main.hx",400)
		return ::Main_obj::g->imageArgCount3(img,x,y);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Main_obj,imageArgCount3,(void))

Void Main_obj::tintArgCount3( double rc,double gc,double bc){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::tintArgCount3")
		HX_SOURCE_POS("./Main.hx",405)
		::Main_obj::g->tintArgCount3(rc,gc,bc);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Main_obj,tintArgCount3,(void))

Void Main_obj::tintArgCount4( double rc,double gc,double bc,double ac){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::tintArgCount4")
		HX_SOURCE_POS("./Main.hx",410)
		::Main_obj::g->tintArgCount4(rc,gc,bc,ac);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,tintArgCount4,(void))

Void Main_obj::noTintArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::noTintArgCount0")
		HX_SOURCE_POS("./Main.hx",415)
		::Main_obj::g->noTintArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,noTintArgCount0,(void))

::PGraphics Main_obj::createGraphicsArgCount3( int w,int h,int type){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::createGraphicsArgCount3")
	HX_SOURCE_POS("./Main.hx",419)
	return ::Main_obj::g->createGraphicsArgCount3(w,h,type);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Main_obj,createGraphicsArgCount3,return )

Void Main_obj::printlnArgCount1( ::String theString){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::printlnArgCount1")
		HX_SOURCE_POS("./Main.hx",423)
		::haxe::Log_obj::trace(theString,hx::SourceInfo(HX_CSTRING("Main.hx"),423,HX_CSTRING("Main"),HX_CSTRING("printlnArgCount1")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,printlnArgCount1,(void))

Void Main_obj::printArgCount1( ::String theString){
{
		HX_SOURCE_PUSH("Main_obj::printArgCount1")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,printArgCount1,(void))

Void Main_obj::lineArgCount4( Dynamic __o_x1,Dynamic __o_y1,Dynamic __o_x2,Dynamic __o_y2){
double x1 = __o_x1.Default(0);
double y1 = __o_y1.Default(0);
double x2 = __o_x2.Default(0);
double y2 = __o_y2.Default(0);
	HX_SOURCE_PUSH("Main_obj::lineArgCount4");
{
		__SAFE_POINT
		HX_SOURCE_POS("./Main.hx",431)
		::Main_obj::g->lineArgCount4(x1,y1,x2,y2);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,lineArgCount4,(void))

double Main_obj::mapArgCount5( double value,double istart,double istop,double ostart,double ostop){
	HX_SOURCE_PUSH("Main_obj::mapArgCount5")
	HX_SOURCE_POS("./Main.hx",435)
	return (ostart + (((ostop - ostart)) * ((double(((value - istart))) / double(((istop - istart)))))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Main_obj,mapArgCount5,return )

double Main_obj::randomArgCount2( double aMin,double aMax){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::randomArgCount2")
	HX_SOURCE_POS("./Main.hx",439)
	return ::Main_obj::g->randomArgCount2(aMin,aMax);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,randomArgCount2,return )

double Main_obj::sinArgCount1( double aNumber){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::sinArgCount1")
	HX_SOURCE_POS("./Main.hx",443)
	return ::Main_obj::g->sinArgCount1(aNumber);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,sinArgCount1,return )

double Main_obj::cosArgCount1( double aNumber){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::cosArgCount1")
	HX_SOURCE_POS("./Main.hx",447)
	return ::Main_obj::g->cosArgCount1(aNumber);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,cosArgCount1,return )

Void Main_obj::rectArgCount4( Dynamic __o_x1,Dynamic __o_y1,Dynamic __o_x2,Dynamic __o_y2){
double x1 = __o_x1.Default(0);
double y1 = __o_y1.Default(0);
double x2 = __o_x2.Default(0);
double y2 = __o_y2.Default(0);
	HX_SOURCE_PUSH("Main_obj::rectArgCount4");
{
		__SAFE_POINT
		HX_SOURCE_POS("./Main.hx",451)
		::Main_obj::g->rectArgCount4(x1,y1,x2,y2);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,rectArgCount4,(void))

Void Main_obj::triangleArgCount6( double x1,double y1,double x2,double y2,double x3,double y3){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::triangleArgCount6")
		HX_SOURCE_POS("./Main.hx",455)
		::Main_obj::g->triangleArgCount6(x1,y1,x2,y2,x3,y3);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Main_obj,triangleArgCount6,(void))

Void Main_obj::ellipseArgCount4( Dynamic __o_x1,Dynamic __o_y1,Dynamic __o_x2,Dynamic __o_y2){
double x1 = __o_x1.Default(0);
double y1 = __o_y1.Default(0);
double x2 = __o_x2.Default(0);
double y2 = __o_y2.Default(0);
	HX_SOURCE_PUSH("Main_obj::ellipseArgCount4");
{
		__SAFE_POINT
		HX_SOURCE_POS("./Main.hx",459)
		::Main_obj::g->ellipse(x1,y1,x2,y2);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,ellipseArgCount4,(void))

Void Main_obj::noStrokeArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::noStrokeArgCount0")
		HX_SOURCE_POS("./Main.hx",463)
		::Main_obj::g->noStrokeArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,noStrokeArgCount0,(void))

Void Main_obj::strokeArgCount4( double r,double green,double b,double a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::strokeArgCount4")
		HX_SOURCE_POS("./Main.hx",467)
		::Main_obj::g->strokeArgCount4(::Std_obj::_int(r),::Std_obj::_int(green),::Std_obj::_int(b),::Std_obj::_int(a));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,strokeArgCount4,(void))

Void Main_obj::strokeArgCount3( double theRed,double theGreen,double theBlue){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::strokeArgCount3")
		HX_SOURCE_POS("./Main.hx",470)
		::Main_obj::g->strokeArgCount3(::Std_obj::_int(theRed),::Std_obj::_int(theGreen),::Std_obj::_int(theBlue));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Main_obj,strokeArgCount3,(void))

Void Main_obj::strokeArgCount2( double shade,double a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::strokeArgCount2")
		HX_SOURCE_POS("./Main.hx",473)
		::Main_obj::g->strokeArgCount2(::Std_obj::_int(shade),::Std_obj::_int(a));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,strokeArgCount2,(void))

Void Main_obj::strokeArgCount1( double shade){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::strokeArgCount1")
		HX_SOURCE_POS("./Main.hx",476)
		::Main_obj::g->strokeArgCount1(::Std_obj::_int(shade));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,strokeArgCount1,(void))

Void Main_obj::noFillArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::noFillArgCount0")
		HX_SOURCE_POS("./Main.hx",480)
		::Main_obj::g->noFillArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,noFillArgCount0,(void))

Void Main_obj::fillArgCount4( double r,double green,double b,double a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::fillArgCount4")
		HX_SOURCE_POS("./Main.hx",484)
		::Main_obj::g->fillArgCount4(::Std_obj::_int(r),::Std_obj::_int(green),::Std_obj::_int(b),::Std_obj::_int(a));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,fillArgCount4,(void))

Void Main_obj::fillArgCount3( double r,double green,double b){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::fillArgCount3")
		HX_SOURCE_POS("./Main.hx",487)
		::Main_obj::g->fillArgCount3(::Std_obj::_int(r),::Std_obj::_int(green),::Std_obj::_int(b));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Main_obj,fillArgCount3,(void))

Void Main_obj::fillArgCount2( double shade,double a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::fillArgCount2")
		HX_SOURCE_POS("./Main.hx",490)
		::Main_obj::g->fillArgCount2(::Std_obj::_int(shade),::Std_obj::_int(a));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,fillArgCount2,(void))

Void Main_obj::fillArgCount1( double shade){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::fillArgCount1")
		HX_SOURCE_POS("./Main.hx",493)
		::Main_obj::g->fillArgCount1(::Std_obj::_int(shade));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,fillArgCount1,(void))

Void Main_obj::rotateArgCount1( double aAngle){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::rotateArgCount1")
		HX_SOURCE_POS("./Main.hx",497)
		::Main_obj::g->rotateArgCount1(aAngle);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,rotateArgCount1,(void))

Void Main_obj::scaleArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::scaleArgCount2")
		HX_SOURCE_POS("./Main.hx",501)
		::Main_obj::g->scaleArgCount2(x,y);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,scaleArgCount2,(void))

Void Main_obj::scaleArgCount1( double xy){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::scaleArgCount1")
		HX_SOURCE_POS("./Main.hx",505)
		::Main_obj::g->scaleArgCount1(xy);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,scaleArgCount1,(void))

Void Main_obj::translateArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::translateArgCount2")
		HX_SOURCE_POS("./Main.hx",509)
		::Main_obj::g->translateArgCount2(x,y);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,translateArgCount2,(void))

int Main_obj::intArgCount1( double x){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::intArgCount1")
	HX_SOURCE_POS("./Main.hx",513)
	return ::Std_obj::_int(x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,intArgCount1,return )

Void Main_obj::strokeWeightArgCount1( double w){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::strokeWeightArgCount1")
		HX_SOURCE_POS("./Main.hx",517)
		return ::Main_obj::g->strokeWeightArgCount1(w);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,strokeWeightArgCount1,(void))

Void Main_obj::pointArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::pointArgCount2")
		HX_SOURCE_POS("./Main.hx",521)
		return ::Main_obj::g->pointArgCount2(x,y);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,pointArgCount2,(void))

Void Main_obj::mouseUpCatcherFunction( Dynamic event){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::mouseUpCatcherFunction")
		HX_SOURCE_POS("./Main.hx",525)
		::Main_obj::mousePressed = false;
		HX_SOURCE_POS("./Main.hx",526)
		::Main_obj::pmouseX = ::Std_obj::_int(::Main_obj::mouseX);
		HX_SOURCE_POS("./Main.hx",527)
		::Main_obj::mouseX = ::Std_obj::_int(event->__Field(HX_CSTRING("localX")));
		HX_SOURCE_POS("./Main.hx",529)
		::Main_obj::pmouseY = ::Std_obj::_int(::Main_obj::mouseY);
		HX_SOURCE_POS("./Main.hx",530)
		::Main_obj::mouseY = ::Std_obj::_int(event->__Field(HX_CSTRING("localY")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mouseUpCatcherFunction,(void))

Void Main_obj::mouseDownCatcherFunction( Dynamic event){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::mouseDownCatcherFunction")
		HX_SOURCE_POS("./Main.hx",539)
		::Main_obj::mousePressed = true;
		HX_SOURCE_POS("./Main.hx",540)
		::Main_obj::pmouseX = ::Std_obj::_int(::Main_obj::mouseX);
		HX_SOURCE_POS("./Main.hx",541)
		::Main_obj::mouseX = ::Std_obj::_int(event->__Field(HX_CSTRING("localX")));
		HX_SOURCE_POS("./Main.hx",543)
		::Main_obj::pmouseY = ::Std_obj::_int(::Main_obj::mouseY);
		HX_SOURCE_POS("./Main.hx",544)
		::Main_obj::mouseY = ::Std_obj::_int(event->__Field(HX_CSTRING("localY")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mouseDownCatcherFunction,(void))

Void Main_obj::mouseMoveCatcherFunction( Dynamic event){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::mouseMoveCatcherFunction")
		HX_SOURCE_POS("./Main.hx",551)
		::Main_obj::pmouseX = ::Std_obj::_int(::Main_obj::mouseX);
		HX_SOURCE_POS("./Main.hx",552)
		::Main_obj::mouseX = ::Std_obj::_int(event->__Field(HX_CSTRING("localX")));
		HX_SOURCE_POS("./Main.hx",554)
		::Main_obj::pmouseY = ::Std_obj::_int(::Main_obj::mouseY);
		HX_SOURCE_POS("./Main.hx",555)
		::Main_obj::mouseY = ::Std_obj::_int(event->__Field(HX_CSTRING("localY")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mouseMoveCatcherFunction,(void))

Void Main_obj::mouseClickCatcherFunction( Dynamic event){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::mouseClickCatcherFunction")
		HX_SOURCE_POS("./Main.hx",566)
		::Main_obj::pmouseX = ::Std_obj::_int(::Main_obj::mouseX);
		HX_SOURCE_POS("./Main.hx",567)
		::Main_obj::mouseX = ::Std_obj::_int(event->__Field(HX_CSTRING("localX")));
		HX_SOURCE_POS("./Main.hx",569)
		::Main_obj::pmouseY = ::Std_obj::_int(::Main_obj::mouseY);
		HX_SOURCE_POS("./Main.hx",570)
		::Main_obj::mouseY = ::Std_obj::_int(event->__Field(HX_CSTRING("localY")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mouseClickCatcherFunction,(void))

Void Main_obj::beginShapeArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::beginShapeArgCount0")
		HX_SOURCE_POS("./Main.hx",578)
		::Main_obj::g->beginShapeArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,beginShapeArgCount0,(void))

Void Main_obj::beginShapeArgCount1( int x){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::beginShapeArgCount1")
		HX_SOURCE_POS("./Main.hx",582)
		::Main_obj::g->beginShapeArgCount1(x);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,beginShapeArgCount1,(void))

Void Main_obj::vertexArgCount2( double x1,double y1){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::vertexArgCount2")
		HX_SOURCE_POS("./Main.hx",586)
		::Main_obj::g->vertexArgCount2(x1,y1);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,vertexArgCount2,(void))

Void Main_obj::vertexArgCount4( double x1,double y1,double x2,double y2){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::vertexArgCount4")
		HX_SOURCE_POS("./Main.hx",589)
		::Main_obj::g->vertexArgCount4(x1,y1,x2,y2);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Main_obj,vertexArgCount4,(void))

Void Main_obj::vertexArgCount6( double x1,double y1,double x2,double y2,double x3,double y3){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::vertexArgCount6")
		HX_SOURCE_POS("./Main.hx",592)
		::Main_obj::g->vertexArgCount6(x1,y1,x2,y2,x3,y3);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Main_obj,vertexArgCount6,(void))

Void Main_obj::endShapeArgCount1( bool x){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::endShapeArgCount1")
		HX_SOURCE_POS("./Main.hx",595)
		::Main_obj::g->endShapeArgCount1(x);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,endShapeArgCount1,(void))

Void Main_obj::bezierArgCount8( double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::bezierArgCount8")
		HX_SOURCE_POS("./Main.hx",599)
		::Main_obj::g->bezierArgCount8(x1,y1,x2,y2,x3,y3,x4,y4);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(Main_obj,bezierArgCount8,(void))

Void Main_obj::curveVertexArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::curveVertexArgCount2")
		HX_SOURCE_POS("./Main.hx",603)
		::Main_obj::g->curveVertexArgCount2(x,y);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,curveVertexArgCount2,(void))

Void Main_obj::endShapeArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::endShapeArgCount0")
		HX_SOURCE_POS("./Main.hx",607)
		::Main_obj::g->endShapeArgCount0();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,endShapeArgCount0,(void))

Void Main_obj::bezierVertexArgCount6( double x,double y,double x2,double y2,double x3,double y3){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::bezierVertexArgCount6")
		HX_SOURCE_POS("./Main.hx",611)
		::Main_obj::g->bezierVertexArgCount6(x,y,x2,y2,x3,y3);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Main_obj,bezierVertexArgCount6,(void))

Void Main_obj::sizeArgCount2( double x1,double y1){
{
		HX_SOURCE_PUSH("Main_obj::sizeArgCount2")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,sizeArgCount2,(void))

Array< ::String > Main_obj::loadStringsArgCount1( ::String x1){
	__SAFE_POINT
	HX_SOURCE_PUSH("Main_obj::loadStringsArgCount1")
	HX_SOURCE_POS("./Main.hx",618)
	::nme::utils::ByteArray ba = ::nme::utils::ByteArray_obj::readFile(x1);
	HX_SOURCE_POS("./Main.hx",620)
	::String dkdkd = ba->asString();
	HX_SOURCE_POS("./Main.hx",622)
	Array< ::String > fetchedArray = dkdkd.split(HX_CSTRING("\n"));
	HX_SOURCE_POS("./Main.hx",626)
	Array< ::String > arrayToBeReturned = Array_obj< ::String >::__new();
	HX_SOURCE_POS("./Main.hx",627)
	{
		HX_SOURCE_POS("./Main.hx",627)
		int _g1 = (int)0;
		int _g = (fetchedArray->length - (int)1);
		HX_SOURCE_POS("./Main.hx",627)
		while((_g1 < _g)){
			__SAFE_POINT
			HX_SOURCE_POS("./Main.hx",627)
			int i = (_g1)++;
			HX_SOURCE_POS("./Main.hx",628)
			arrayToBeReturned[i] = fetchedArray->__get(i);
		}
	}
	HX_SOURCE_POS("./Main.hx",631)
	return arrayToBeReturned;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,loadStringsArgCount1,return )

Void Main_obj::saveStringsArgCount2( ::String fileName,Array< ::String > arrayOfStrings){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::saveStringsArgCount2")
		HX_SOURCE_POS("./Main.hx",649)
		if (((fileName.indexOf(HX_CSTRING("data/"),null()) == (int)0))){
			HX_SOURCE_POS("./Main.hx",650)
			fileName = fileName.substr((int)5,null());
			HX_SOURCE_POS("./Main.hx",651)
			::haxe::Log_obj::trace((HX_CSTRING("saving to data folder, simplifying the path to: ") + fileName),hx::SourceInfo(HX_CSTRING("Main.hx"),651,HX_CSTRING("Main"),HX_CSTRING("saveStringsArgCount2")));
		}
		HX_SOURCE_POS("./Main.hx",654)
		if (((fileName.indexOf(HX_CSTRING("./data/"),null()) == (int)0))){
			HX_SOURCE_POS("./Main.hx",655)
			fileName = fileName.substr((int)7,null());
			HX_SOURCE_POS("./Main.hx",656)
			::haxe::Log_obj::trace((HX_CSTRING("saving to data folder, simplifying the path to: ") + fileName),hx::SourceInfo(HX_CSTRING("Main.hx"),656,HX_CSTRING("Main"),HX_CSTRING("saveStringsArgCount2")));
		}
		HX_SOURCE_POS("./Main.hx",661)
		::String theFinalString = HX_CSTRING("");
		HX_SOURCE_POS("./Main.hx",664)
		{
			HX_SOURCE_POS("./Main.hx",664)
			int _g1 = (int)0;
			int _g = arrayOfStrings->length;
			HX_SOURCE_POS("./Main.hx",664)
			while((_g1 < _g)){
				__SAFE_POINT
				HX_SOURCE_POS("./Main.hx",664)
				int i = (_g1)++;
				HX_SOURCE_POS("./Main.hx",665)
				theFinalString = ((theFinalString + arrayOfStrings->__get(i)) + HX_CSTRING("\n"));
			}
		}
		HX_SOURCE_POS("./Main.hx",668)
		::nme::utils::ByteArray ba = ::nme::utils::ByteArray_obj::__new((int)0);
		HX_SOURCE_POS("./Main.hx",672)
		ba->writeFile(fileName);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Main_obj,saveStringsArgCount2,(void))

Void Main_obj::setupArgCount0( ){
{
		HX_SOURCE_PUSH("Main_obj::setupArgCount0")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,setupArgCount0,(void))

Void Main_obj::drawArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Main_obj::drawArgCount0")
		HX_SOURCE_POS("./Main.hx",683)
		Dynamic();
		HX_SOURCE_POS("./Main.hx",684)
		::Main_obj::g->fillArgCount3(::Std_obj::_int((int)0),::Std_obj::_int((int)255),::Std_obj::_int((int)0));
		HX_SOURCE_POS("./Main.hx",685)
		::Main_obj::g->rectArgCount4((int)10,(int)10,(int)50,(int)50);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,drawArgCount0,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_END_CLASS();
}

Dynamic Main_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"PI") ) { return PI; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"P2D") ) { return P2D; }
		if (HX_FIELD_EQ(inName,"P3D") ) { return P3D; }
		if (HX_FIELD_EQ(inName,"RGB") ) { return RGB; }
		if (HX_FIELD_EQ(inName,"HSB") ) { return HSB; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"QUADS") ) { return QUADS; }
		if (HX_FIELD_EQ(inName,"LINES") ) { return LINES; }
		if (HX_FIELD_EQ(inName,"CLOSE") ) { return CLOSE; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"mouseX") ) { return mouseX; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { return mouseY; }
		if (HX_FIELD_EQ(inName,"TWO_PI") ) { return TWO_PI; }
		if (HX_FIELD_EQ(inName,"CORNER") ) { return CORNER; }
		if (HX_FIELD_EQ(inName,"RADIUS") ) { return RADIUS; }
		if (HX_FIELD_EQ(inName,"CENTER") ) { return CENTER; }
		if (HX_FIELD_EQ(inName,"POINTS") ) { return POINTS; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"pmouseX") ) { return pmouseX; }
		if (HX_FIELD_EQ(inName,"pmouseY") ) { return pmouseY; }
		if (HX_FIELD_EQ(inName,"HALF_PI") ) { return HALF_PI; }
		if (HX_FIELD_EQ(inName,"POLYGON") ) { return POLYGON; }
		if (HX_FIELD_EQ(inName,"CORNERS") ) { return CORNERS; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameRate") ) { return frameRate; }
		if (HX_FIELD_EQ(inName,"TRIANGLES") ) { return TRIANGLES; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameCount") ) { return frameCount; }
		if (HX_FIELD_EQ(inName,"keyPressed") ) { return keyPressed; }
		if (HX_FIELD_EQ(inName,"QUAD_STRIP") ) { return QUAD_STRIP; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mousePressed") ) { return mousePressed; }
		if (HX_FIELD_EQ(inName,"TRIANGLE_FAN") ) { return TRIANGLE_FAN; }
		if (HX_FIELD_EQ(inName,"powArgCount2") ) { return powArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"absArgCount1") ) { return absArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"dayArgCount0") ) { return dayArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"getArgCount2") ) { return getArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"setArgCount3") ) { return setArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"redArgCount1") ) { return redArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"mapArgCount5") ) { return mapArgCount5_dyn(); }
		if (HX_FIELD_EQ(inName,"sinArgCount1") ) { return sinArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"cosArgCount1") ) { return cosArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"intArgCount1") ) { return intArgCount1_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"CENTER_RADIUS") ) { return CENTER_RADIUS; }
		if (HX_FIELD_EQ(inName,"exitArgCount0") ) { return exitArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"yearArgCount0") ) { return yearArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"hourArgCount0") ) { return hourArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"blueArgCount1") ) { return blueArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"tintArgCount3") ) { return tintArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"tintArgCount4") ) { return tintArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"lineArgCount4") ) { return lineArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"rectArgCount4") ) { return rectArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"fillArgCount4") ) { return fillArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"fillArgCount3") ) { return fillArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"fillArgCount2") ) { return fillArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"fillArgCount1") ) { return fillArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"sizeArgCount2") ) { return sizeArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"drawArgCount0") ) { return drawArgCount0_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"wholeDrawCycle") ) { return wholeDrawCycle_dyn(); }
		if (HX_FIELD_EQ(inName,"TRIANGLE_STRIP") ) { return TRIANGLE_STRIP; }
		if (HX_FIELD_EQ(inName,"floorArgCount1") ) { return floorArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"monthArgCount0") ) { return monthArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"delayArgCount1") ) { return delayArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"colorArgCount1") ) { return colorArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"colorArgCount2") ) { return colorArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"colorArgCount3") ) { return colorArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"colorArgCount4") ) { return colorArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"greenArgCount1") ) { return greenArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"alphaArgCount1") ) { return alphaArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"imageArgCount3") ) { return imageArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"printArgCount1") ) { return printArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"scaleArgCount2") ) { return scaleArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"scaleArgCount1") ) { return scaleArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"pointArgCount2") ) { return pointArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"setupArgCount0") ) { return setupArgCount0_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"endOfDrawMethod") ) { return endOfDrawMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"minuteArgCount0") ) { return minuteArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"secondArgCount0") ) { return secondArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"millisArgCount0") ) { return millisArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"noLoopArgCount0") ) { return noLoopArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"smoothArgCount0") ) { return smoothArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"noTintArgCount0") ) { return noTintArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"randomArgCount2") ) { return randomArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"strokeArgCount4") ) { return strokeArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"strokeArgCount3") ) { return strokeArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"strokeArgCount2") ) { return strokeArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"strokeArgCount1") ) { return strokeArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"noFillArgCount0") ) { return noFillArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"rotateArgCount1") ) { return rotateArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"vertexArgCount2") ) { return vertexArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"vertexArgCount4") ) { return vertexArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"vertexArgCount6") ) { return vertexArgCount6_dyn(); }
		if (HX_FIELD_EQ(inName,"bezierArgCount8") ) { return bezierArgCount8_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"endDrawArgCount0") ) { return endDrawArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"printlnArgCount1") ) { return printlnArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"ellipseArgCount4") ) { return ellipseArgCount4_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"startOfDrawMethod") ) { return startOfDrawMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"triangleArgCount6") ) { return triangleArgCount6_dyn(); }
		if (HX_FIELD_EQ(inName,"noStrokeArgCount0") ) { return noStrokeArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"endShapeArgCount1") ) { return endShapeArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"endShapeArgCount0") ) { return endShapeArgCount0_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"popMatrixArgCount0") ) { return popMatrixArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"frameRateArgCount1") ) { return frameRateArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"beginDrawArgCount0") ) { return beginDrawArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"translateArgCount2") ) { return translateArgCount2_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"timeStampOfLastDraw") ) { return timeStampOfLastDraw; }
		if (HX_FIELD_EQ(inName,"pushMatrixArgCount0") ) { return pushMatrixArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount4") ) { return backgroundArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount3") ) { return backgroundArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount2") ) { return backgroundArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount1") ) { return backgroundArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount0") ) { return backgroundArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"beginShapeArgCount0") ) { return beginShapeArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"beginShapeArgCount1") ) { return beginShapeArgCount1_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"ellipseModeArgCount1") ) { return ellipseModeArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"curveVertexArgCount2") ) { return curveVertexArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"loadStringsArgCount1") ) { return loadStringsArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"saveStringsArgCount2") ) { return saveStringsArgCount2_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"strokeWeightArgCount1") ) { return strokeWeightArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"bezierVertexArgCount6") ) { return bezierVertexArgCount6_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"mouseUpCatcherFunction") ) { return mouseUpCatcherFunction_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"createGraphicsArgCount3") ) { return createGraphicsArgCount3_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"mouseDownCatcherFunction") ) { return mouseDownCatcherFunction_dyn(); }
		if (HX_FIELD_EQ(inName,"mouseMoveCatcherFunction") ) { return mouseMoveCatcherFunction_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"mouseClickCatcherFunction") ) { return mouseClickCatcherFunction_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"initialiseTopLevelVariables") ) { return initialiseTopLevelVariables_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"millisecondsWhenSketchStarted") ) { return millisecondsWhenSketchStarted; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"millisecondsTheAppHasSpentBackgrounded") ) { return millisecondsTheAppHasSpentBackgrounded; }
	}
	return super::__Field(inName);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"g") ) { g=inValue.Cast< ::PGraphicsRoot >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"PI") ) { PI=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"P2D") ) { P2D=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"P3D") ) { P3D=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RGB") ) { RGB=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HSB") ) { HSB=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"QUADS") ) { QUADS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LINES") ) { LINES=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CLOSE") ) { CLOSE=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseX") ) { mouseX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { mouseY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TWO_PI") ) { TWO_PI=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CORNER") ) { CORNER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RADIUS") ) { RADIUS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CENTER") ) { CENTER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"POINTS") ) { POINTS=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"pmouseX") ) { pmouseX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pmouseY") ) { pmouseY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HALF_PI") ) { HALF_PI=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"POLYGON") ) { POLYGON=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CORNERS") ) { CORNERS=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"frameRate") ) { frameRate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TRIANGLES") ) { TRIANGLES=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameCount") ) { frameCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keyPressed") ) { keyPressed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"QUAD_STRIP") ) { QUAD_STRIP=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mousePressed") ) { mousePressed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TRIANGLE_FAN") ) { TRIANGLE_FAN=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"CENTER_RADIUS") ) { CENTER_RADIUS=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TRIANGLE_STRIP") ) { TRIANGLE_STRIP=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"timeStampOfLastDraw") ) { timeStampOfLastDraw=inValue.Cast< double >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"millisecondsWhenSketchStarted") ) { millisecondsWhenSketchStarted=inValue.Cast< int >(); return inValue; }
		break;
	case 38:
		if (HX_FIELD_EQ(inName,"millisecondsTheAppHasSpentBackgrounded") ) { millisecondsTheAppHasSpentBackgrounded=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	HX_CSTRING("wholeDrawCycle"),
	HX_CSTRING("startOfDrawMethod"),
	HX_CSTRING("endOfDrawMethod"),
	HX_CSTRING("g"),
	HX_CSTRING("frameCount"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("frameRate"),
	HX_CSTRING("millisecondsWhenSketchStarted"),
	HX_CSTRING("timeStampOfLastDraw"),
	HX_CSTRING("millisecondsTheAppHasSpentBackgrounded"),
	HX_CSTRING("mousePressed"),
	HX_CSTRING("keyPressed"),
	HX_CSTRING("mouseX"),
	HX_CSTRING("mouseY"),
	HX_CSTRING("pmouseX"),
	HX_CSTRING("pmouseY"),
	HX_CSTRING("PI"),
	HX_CSTRING("TWO_PI"),
	HX_CSTRING("HALF_PI"),
	HX_CSTRING("P2D"),
	HX_CSTRING("P3D"),
	HX_CSTRING("CORNER"),
	HX_CSTRING("RADIUS"),
	HX_CSTRING("CENTER_RADIUS"),
	HX_CSTRING("CENTER"),
	HX_CSTRING("POLYGON"),
	HX_CSTRING("QUADS"),
	HX_CSTRING("TRIANGLES"),
	HX_CSTRING("POINTS"),
	HX_CSTRING("LINES"),
	HX_CSTRING("TRIANGLE_STRIP"),
	HX_CSTRING("TRIANGLE_FAN"),
	HX_CSTRING("QUAD_STRIP"),
	HX_CSTRING("CORNERS"),
	HX_CSTRING("CLOSE"),
	HX_CSTRING("RGB"),
	HX_CSTRING("HSB"),
	HX_CSTRING("exitArgCount0"),
	HX_CSTRING("powArgCount2"),
	HX_CSTRING("absArgCount1"),
	HX_CSTRING("floorArgCount1"),
	HX_CSTRING("yearArgCount0"),
	HX_CSTRING("monthArgCount0"),
	HX_CSTRING("dayArgCount0"),
	HX_CSTRING("hourArgCount0"),
	HX_CSTRING("minuteArgCount0"),
	HX_CSTRING("secondArgCount0"),
	HX_CSTRING("pushMatrixArgCount0"),
	HX_CSTRING("popMatrixArgCount0"),
	HX_CSTRING("millisArgCount0"),
	HX_CSTRING("delayArgCount1"),
	HX_CSTRING("frameRateArgCount1"),
	HX_CSTRING("ellipseModeArgCount1"),
	HX_CSTRING("noLoopArgCount0"),
	HX_CSTRING("getArgCount2"),
	HX_CSTRING("setArgCount3"),
	HX_CSTRING("smoothArgCount0"),
	HX_CSTRING("colorArgCount1"),
	HX_CSTRING("colorArgCount2"),
	HX_CSTRING("colorArgCount3"),
	HX_CSTRING("colorArgCount4"),
	HX_CSTRING("redArgCount1"),
	HX_CSTRING("greenArgCount1"),
	HX_CSTRING("blueArgCount1"),
	HX_CSTRING("alphaArgCount1"),
	HX_CSTRING("endDrawArgCount0"),
	HX_CSTRING("beginDrawArgCount0"),
	HX_CSTRING("backgroundArgCount4"),
	HX_CSTRING("backgroundArgCount3"),
	HX_CSTRING("backgroundArgCount2"),
	HX_CSTRING("backgroundArgCount1"),
	HX_CSTRING("backgroundArgCount0"),
	HX_CSTRING("imageArgCount3"),
	HX_CSTRING("tintArgCount3"),
	HX_CSTRING("tintArgCount4"),
	HX_CSTRING("noTintArgCount0"),
	HX_CSTRING("createGraphicsArgCount3"),
	HX_CSTRING("printlnArgCount1"),
	HX_CSTRING("printArgCount1"),
	HX_CSTRING("lineArgCount4"),
	HX_CSTRING("mapArgCount5"),
	HX_CSTRING("randomArgCount2"),
	HX_CSTRING("sinArgCount1"),
	HX_CSTRING("cosArgCount1"),
	HX_CSTRING("rectArgCount4"),
	HX_CSTRING("triangleArgCount6"),
	HX_CSTRING("ellipseArgCount4"),
	HX_CSTRING("noStrokeArgCount0"),
	HX_CSTRING("strokeArgCount4"),
	HX_CSTRING("strokeArgCount3"),
	HX_CSTRING("strokeArgCount2"),
	HX_CSTRING("strokeArgCount1"),
	HX_CSTRING("noFillArgCount0"),
	HX_CSTRING("fillArgCount4"),
	HX_CSTRING("fillArgCount3"),
	HX_CSTRING("fillArgCount2"),
	HX_CSTRING("fillArgCount1"),
	HX_CSTRING("rotateArgCount1"),
	HX_CSTRING("scaleArgCount2"),
	HX_CSTRING("scaleArgCount1"),
	HX_CSTRING("translateArgCount2"),
	HX_CSTRING("intArgCount1"),
	HX_CSTRING("strokeWeightArgCount1"),
	HX_CSTRING("pointArgCount2"),
	HX_CSTRING("mouseUpCatcherFunction"),
	HX_CSTRING("mouseDownCatcherFunction"),
	HX_CSTRING("mouseMoveCatcherFunction"),
	HX_CSTRING("mouseClickCatcherFunction"),
	HX_CSTRING("beginShapeArgCount0"),
	HX_CSTRING("beginShapeArgCount1"),
	HX_CSTRING("vertexArgCount2"),
	HX_CSTRING("vertexArgCount4"),
	HX_CSTRING("vertexArgCount6"),
	HX_CSTRING("endShapeArgCount1"),
	HX_CSTRING("bezierArgCount8"),
	HX_CSTRING("curveVertexArgCount2"),
	HX_CSTRING("endShapeArgCount0"),
	HX_CSTRING("bezierVertexArgCount6"),
	HX_CSTRING("sizeArgCount2"),
	HX_CSTRING("loadStringsArgCount1"),
	HX_CSTRING("saveStringsArgCount2"),
	HX_CSTRING("setupArgCount0"),
	HX_CSTRING("drawArgCount0"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initialiseTopLevelVariables"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::g,"g");
	HX_MARK_MEMBER_NAME(Main_obj::frameCount,"frameCount");
	HX_MARK_MEMBER_NAME(Main_obj::width,"width");
	HX_MARK_MEMBER_NAME(Main_obj::height,"height");
	HX_MARK_MEMBER_NAME(Main_obj::frameRate,"frameRate");
	HX_MARK_MEMBER_NAME(Main_obj::millisecondsWhenSketchStarted,"millisecondsWhenSketchStarted");
	HX_MARK_MEMBER_NAME(Main_obj::timeStampOfLastDraw,"timeStampOfLastDraw");
	HX_MARK_MEMBER_NAME(Main_obj::millisecondsTheAppHasSpentBackgrounded,"millisecondsTheAppHasSpentBackgrounded");
	HX_MARK_MEMBER_NAME(Main_obj::mousePressed,"mousePressed");
	HX_MARK_MEMBER_NAME(Main_obj::keyPressed,"keyPressed");
	HX_MARK_MEMBER_NAME(Main_obj::mouseX,"mouseX");
	HX_MARK_MEMBER_NAME(Main_obj::mouseY,"mouseY");
	HX_MARK_MEMBER_NAME(Main_obj::pmouseX,"pmouseX");
	HX_MARK_MEMBER_NAME(Main_obj::pmouseY,"pmouseY");
	HX_MARK_MEMBER_NAME(Main_obj::PI,"PI");
	HX_MARK_MEMBER_NAME(Main_obj::TWO_PI,"TWO_PI");
	HX_MARK_MEMBER_NAME(Main_obj::HALF_PI,"HALF_PI");
	HX_MARK_MEMBER_NAME(Main_obj::P2D,"P2D");
	HX_MARK_MEMBER_NAME(Main_obj::P3D,"P3D");
	HX_MARK_MEMBER_NAME(Main_obj::CORNER,"CORNER");
	HX_MARK_MEMBER_NAME(Main_obj::RADIUS,"RADIUS");
	HX_MARK_MEMBER_NAME(Main_obj::CENTER_RADIUS,"CENTER_RADIUS");
	HX_MARK_MEMBER_NAME(Main_obj::CENTER,"CENTER");
	HX_MARK_MEMBER_NAME(Main_obj::POLYGON,"POLYGON");
	HX_MARK_MEMBER_NAME(Main_obj::QUADS,"QUADS");
	HX_MARK_MEMBER_NAME(Main_obj::TRIANGLES,"TRIANGLES");
	HX_MARK_MEMBER_NAME(Main_obj::POINTS,"POINTS");
	HX_MARK_MEMBER_NAME(Main_obj::LINES,"LINES");
	HX_MARK_MEMBER_NAME(Main_obj::TRIANGLE_STRIP,"TRIANGLE_STRIP");
	HX_MARK_MEMBER_NAME(Main_obj::TRIANGLE_FAN,"TRIANGLE_FAN");
	HX_MARK_MEMBER_NAME(Main_obj::QUAD_STRIP,"QUAD_STRIP");
	HX_MARK_MEMBER_NAME(Main_obj::CORNERS,"CORNERS");
	HX_MARK_MEMBER_NAME(Main_obj::CLOSE,"CLOSE");
	HX_MARK_MEMBER_NAME(Main_obj::RGB,"RGB");
	HX_MARK_MEMBER_NAME(Main_obj::HSB,"HSB");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Main_obj::__boot()
{
	hx::Static(g);
	hx::Static(frameCount) = (int)0;
	hx::Static(width) = (int)320;
	hx::Static(height) = (int)480;
	hx::Static(frameRate) = (int)60;
	hx::Static(millisecondsWhenSketchStarted);
	hx::Static(timeStampOfLastDraw);
	hx::Static(millisecondsTheAppHasSpentBackgrounded);
	hx::Static(mousePressed);
	hx::Static(keyPressed);
	hx::Static(mouseX) = (int)0;
	hx::Static(mouseY) = (int)0;
	hx::Static(pmouseX) = (int)0;
	hx::Static(pmouseY) = (int)0;
	hx::Static(PI) = 3.141592;
	hx::Static(TWO_PI) = ((int)2 * 3.141592);
	hx::Static(HALF_PI) = (double(3.141592) / double((int)2));
	hx::Static(P2D) = (int)2;
	hx::Static(P3D) = (int)3;
	hx::Static(CORNER) = (int)0;
	hx::Static(RADIUS) = (int)1;
	hx::Static(CENTER_RADIUS) = (int)1;
	hx::Static(CENTER) = (int)2;
	hx::Static(POLYGON) = (int)2;
	hx::Static(QUADS) = (int)5;
	hx::Static(TRIANGLES) = (int)6;
	hx::Static(POINTS) = (int)7;
	hx::Static(LINES) = (int)8;
	hx::Static(TRIANGLE_STRIP) = (int)9;
	hx::Static(TRIANGLE_FAN) = (int)4;
	hx::Static(QUAD_STRIP) = (int)3;
	hx::Static(CORNERS) = (int)10;
	hx::Static(CLOSE) = true;
	hx::Static(RGB) = (int)1;
	hx::Static(HSB) = (int)2;
}

