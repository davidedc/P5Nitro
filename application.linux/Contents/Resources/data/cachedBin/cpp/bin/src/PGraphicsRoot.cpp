#include <hxcpp.h>

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
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_Bitmap
#include <nme/display/Bitmap.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
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
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_geom_Transform
#include <nme/geom/Transform.h>
#endif

Void PGraphicsRoot_obj::__construct(Dynamic x,Dynamic y)
{
{
	HX_SOURCE_POS("./PGraphicsRoot.hx",325)
	super::__construct();
	HX_SOURCE_POS("./PGraphicsRoot.hx",332)
	this->bitmapPool = ::ProcessingHaxeBitmapPool_obj::__new();
	HX_SOURCE_POS("./PGraphicsRoot.hx",333)
	this->bitmapPool->initialize((int)1,(int)1);
	HX_SOURCE_POS("./PGraphicsRoot.hx",336)
	this->newShapeNeeded = true;
	HX_SOURCE_POS("./PGraphicsRoot.hx",340)
	this->pGraphicsAlpha = (int)0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",342)
	this->PI = 3.141592;
	HX_SOURCE_POS("./PGraphicsRoot.hx",343)
	this->TWO_PI = ((int)2 * this->PI);
	HX_SOURCE_POS("./PGraphicsRoot.hx",344)
	this->HALF_PI = (double(this->PI) / double(2.0));
	HX_SOURCE_POS("./PGraphicsRoot.hx",345)
	this->P2D = (int)2;
	HX_SOURCE_POS("./PGraphicsRoot.hx",346)
	this->P3D = (int)3;
	HX_SOURCE_POS("./PGraphicsRoot.hx",347)
	this->CORNER = (int)0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",348)
	this->RADIUS = (int)1;
	HX_SOURCE_POS("./PGraphicsRoot.hx",349)
	this->CENTER_RADIUS = (int)1;
	HX_SOURCE_POS("./PGraphicsRoot.hx",350)
	this->CENTER = (int)2;
	HX_SOURCE_POS("./PGraphicsRoot.hx",351)
	this->POLYGON = (int)2;
	HX_SOURCE_POS("./PGraphicsRoot.hx",352)
	this->QUADS = (int)5;
	HX_SOURCE_POS("./PGraphicsRoot.hx",353)
	this->TRIANGLES = (int)6;
	HX_SOURCE_POS("./PGraphicsRoot.hx",354)
	this->POINTS = (int)7;
	HX_SOURCE_POS("./PGraphicsRoot.hx",355)
	this->LINES = (int)8;
	HX_SOURCE_POS("./PGraphicsRoot.hx",356)
	this->TRIANGLE_STRIP = (int)9;
	HX_SOURCE_POS("./PGraphicsRoot.hx",357)
	this->TRIANGLE_FAN = (int)4;
	HX_SOURCE_POS("./PGraphicsRoot.hx",358)
	this->QUAD_STRIP = (int)3;
	HX_SOURCE_POS("./PGraphicsRoot.hx",359)
	this->CORNERS = (int)10;
	HX_SOURCE_POS("./PGraphicsRoot.hx",360)
	this->CLOSE = true;
	HX_SOURCE_POS("./PGraphicsRoot.hx",361)
	this->RGB = (int)1;
	HX_SOURCE_POS("./PGraphicsRoot.hx",362)
	this->HSB = (int)2;
	HX_SOURCE_POS("./PGraphicsRoot.hx",365)
	this->hasBackground = false;
	HX_SOURCE_POS("./PGraphicsRoot.hx",366)
	this->curRectMode = this->CORNER;
	HX_SOURCE_POS("./PGraphicsRoot.hx",367)
	this->curEllipseMode = this->CENTER;
	HX_SOURCE_POS("./PGraphicsRoot.hx",368)
	this->curShape = this->POLYGON;
	HX_SOURCE_POS("./PGraphicsRoot.hx",369)
	this->curShapeCount = (int)0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",370)
	this->opacityRange = (int)255;
	HX_SOURCE_POS("./PGraphicsRoot.hx",371)
	this->redRange = (int)255;
	HX_SOURCE_POS("./PGraphicsRoot.hx",372)
	this->greenRange = (int)255;
	HX_SOURCE_POS("./PGraphicsRoot.hx",373)
	this->blueRange = (int)255;
	HX_SOURCE_POS("./PGraphicsRoot.hx",374)
	this->pathOpen = false;
	HX_SOURCE_POS("./PGraphicsRoot.hx",375)
	this->mousePressed = false;
	HX_SOURCE_POS("./PGraphicsRoot.hx",376)
	this->keyPressed = false;
	HX_SOURCE_POS("./PGraphicsRoot.hx",377)
	this->firstX = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",378)
	this->firstY = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",379)
	this->secondX = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",380)
	this->secondY = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",381)
	this->prevX = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",382)
	this->prevY = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",383)
	this->curColorMode = this->RGB;
	HX_SOURCE_POS("./PGraphicsRoot.hx",384)
	this->tintColor = (int)-1;
	HX_SOURCE_POS("./PGraphicsRoot.hx",385)
	this->curTextSize = (int)12;
	HX_SOURCE_POS("./PGraphicsRoot.hx",386)
	this->curTextFont = HX_CSTRING("Arial");
	HX_SOURCE_POS("./PGraphicsRoot.hx",390)
	this->doStroke = true;
	HX_SOURCE_POS("./PGraphicsRoot.hx",391)
	this->curStrokeWeight = (int)1;
	HX_SOURCE_POS("./PGraphicsRoot.hx",392)
	this->curStrokeColor = (int)-16777216;
	HX_SOURCE_POS("./PGraphicsRoot.hx",397)
	this->tint = false;
	HX_SOURCE_POS("./PGraphicsRoot.hx",400)
	this->doFill = true;
	HX_SOURCE_POS("./PGraphicsRoot.hx",401)
	this->curFillColor = (int)-1;
	HX_SOURCE_POS("./PGraphicsRoot.hx",411)
	this->shapeMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_SOURCE_POS("./PGraphicsRoot.hx",412)
	this->doSmooth = false;
	HX_SOURCE_POS("./PGraphicsRoot.hx",417)
	this->trackingScaleX = 1.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",418)
	this->trackingScaleY = 1.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",419)
	this->trackingRotation = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",420)
	this->trackingTranslationX = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",421)
	this->trackingTranslationY = 0.0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",423)
	this->matrixStack = Array_obj< ::nme::geom::Matrix >::__new();
	HX_SOURCE_POS("./PGraphicsRoot.hx",424)
	this->trackingScaleXStack = Array_obj< double >::__new();
	HX_SOURCE_POS("./PGraphicsRoot.hx",425)
	this->trackingScaleYStack = Array_obj< double >::__new();
	HX_SOURCE_POS("./PGraphicsRoot.hx",426)
	this->trackingRotationStack = Array_obj< double >::__new();
	HX_SOURCE_POS("./PGraphicsRoot.hx",427)
	this->trackingTranslationXStack = Array_obj< double >::__new();
	HX_SOURCE_POS("./PGraphicsRoot.hx",428)
	this->trackingTranslationYStack = Array_obj< double >::__new();
	HX_SOURCE_POS("./PGraphicsRoot.hx",430)
	this->curTightness = (int)0;
	HX_SOURCE_POS("./PGraphicsRoot.hx",431)
	this->curvePoints = Array_obj< ::nme::geom::Point >::__new();
	HX_SOURCE_POS("./PGraphicsRoot.hx",434)
	this->curBackground = this->colorArgCount1((int)214);
	HX_SOURCE_POS("./PGraphicsRoot.hx",437)
	this->backgroundArgCount0();
}
;
	return null();
}

PGraphicsRoot_obj::~PGraphicsRoot_obj() { }

Dynamic PGraphicsRoot_obj::__CreateEmpty() { return  new PGraphicsRoot_obj; }
hx::ObjectPtr< PGraphicsRoot_obj > PGraphicsRoot_obj::__new(Dynamic x,Dynamic y)
{  hx::ObjectPtr< PGraphicsRoot_obj > result = new PGraphicsRoot_obj();
	result->__construct(x,y);
	return result;}

Dynamic PGraphicsRoot_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PGraphicsRoot_obj > result = new PGraphicsRoot_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int PGraphicsRoot_obj::getArgCount2( int x,int y){
	HX_SOURCE_PUSH("PGraphicsRoot_obj::getArgCount2")
	HX_SOURCE_POS("./PGraphicsRoot.hx",139)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,getArgCount2,return )

Void PGraphicsRoot_obj::setArgCount3( int x,int y,int color){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::setArgCount3")
		HX_SOURCE_POS("./PGraphicsRoot.hx",146)
		Array< double > xy;
		HX_SOURCE_POS("./PGraphicsRoot.hx",147)
		Array< int > cols;
		HX_SOURCE_POS("./PGraphicsRoot.hx",148)
		xy = Array_obj< double >::__new();
		HX_SOURCE_POS("./PGraphicsRoot.hx",149)
		cols = Array_obj< int >::__new();
		HX_SOURCE_POS("./PGraphicsRoot.hx",150)
		xy[(int)0] = x;
		HX_SOURCE_POS("./PGraphicsRoot.hx",151)
		xy[(int)1] = y;
		HX_SOURCE_POS("./PGraphicsRoot.hx",153)
		int a = (int((int(color) >> int((int)24))) & int((int)255));
		HX_SOURCE_POS("./PGraphicsRoot.hx",154)
		int r = (int((int(color) >> int((int)16))) & int((int)255));
		HX_SOURCE_POS("./PGraphicsRoot.hx",155)
		int g = (int((int(color) >> int((int)8))) & int((int)255));
		HX_SOURCE_POS("./PGraphicsRoot.hx",156)
		int b = (int(color) & int((int)255));
		HX_SOURCE_POS("./PGraphicsRoot.hx",162)
		cols[(int)0] = (int((int((int((int(a) << int((int)24))) | int((int(b) << int((int)16))))) | int((int(g) << int((int)8))))) | int(r));
		HX_SOURCE_POS("./PGraphicsRoot.hx",164)
		this->nmeGetGraphics()->drawPoints(xy,cols,(int)0,(int)2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PGraphicsRoot_obj,setArgCount3,(void))

Void PGraphicsRoot_obj::ellipseModeArgCount1( int aEllipseMode){
{
		HX_SOURCE_PUSH("PGraphicsRoot_obj::ellipseModeArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",169)
		this->curEllipseMode = aEllipseMode;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,ellipseModeArgCount1,(void))

Void PGraphicsRoot_obj::smoothArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::smoothArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",179)
		::nme::Lib_obj::nmeGetStage()->nmeSetQuality(::nme::display::StageQuality_obj::BEST);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,smoothArgCount0,(void))

Void PGraphicsRoot_obj::endDrawArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::endDrawArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",187)
		{
			HX_SOURCE_POS("./PGraphicsRoot.hx",187)
			this->trackingTranslationY = this->trackingTranslationYStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",187)
			this->trackingTranslationX = this->trackingTranslationXStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",187)
			this->trackingRotation = this->trackingRotationStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",187)
			this->trackingScaleY = this->trackingScaleYStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",187)
			this->trackingScaleX = this->trackingScaleXStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",187)
			this->shapeMatrix = this->matrixStack->pop();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,endDrawArgCount0,(void))

Void PGraphicsRoot_obj::beginDrawArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::beginDrawArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",200)
		if (((this->nmeGetNumChildren() != (int)0))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",201)
			int k = this->nmeGetNumChildren();
			HX_SOURCE_POS("./PGraphicsRoot.hx",202)
			do{
				__SAFE_POINT
				HX_SOURCE_POS("./PGraphicsRoot.hx",203)
				(k)--;
				HX_SOURCE_POS("./PGraphicsRoot.hx",205)
				this->removeChildAt(k);
			}
while((k != (int)0));
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",210)
		this->pushMatrixArgCount0();
		HX_SOURCE_POS("./PGraphicsRoot.hx",223)
		if ((this->hasBackground)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",225)
			this->backgroundArgCount0();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,beginDrawArgCount0,(void))

double PGraphicsRoot_obj::sinArgCount1( double aNumber){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::sinArgCount1")
	HX_SOURCE_POS("./PGraphicsRoot.hx",230)
	return ::Math_obj::sin(aNumber);
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,sinArgCount1,return )

double PGraphicsRoot_obj::cosArgCount1( double aNumber){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::cosArgCount1")
	HX_SOURCE_POS("./PGraphicsRoot.hx",234)
	return ::Math_obj::cos(aNumber);
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,cosArgCount1,return )

double PGraphicsRoot_obj::randomArgCount2( double aMin,double aMax){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::randomArgCount2")
	HX_SOURCE_POS("./PGraphicsRoot.hx",238)
	return (aMin + (::Math_obj::random() * ((aMax - aMin))));
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,randomArgCount2,return )

Void PGraphicsRoot_obj::backgroundArgCount4( int r,int g,int b,int a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::backgroundArgCount4")
		HX_SOURCE_POS("./PGraphicsRoot.hx",242)
		this->curBackground = this->colorArgCount4(r,g,b,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,backgroundArgCount4,(void))

Void PGraphicsRoot_obj::backgroundArgCount3( int r,int g,int b){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::backgroundArgCount3")
		HX_SOURCE_POS("./PGraphicsRoot.hx",253)
		this->curBackground = this->colorArgCount3(r,g,b);
		HX_SOURCE_POS("./PGraphicsRoot.hx",256)
		{
			HX_SOURCE_POS("./PGraphicsRoot.hx",256)
			this->shape = ::nme::display::Shape_obj::__new();
			HX_SOURCE_POS("./PGraphicsRoot.hx",256)
			this->addChild(this->shape);
			HX_SOURCE_POS("./PGraphicsRoot.hx",256)
			this->shape->nmeGetTransform()->nmeSetMatrix(this->shapeMatrix);
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",257)
		this->shape->nmeGetGraphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",258)
		this->shape->nmeGetGraphics()->beginFill(this->curBackground,1.0);
		HX_SOURCE_POS("./PGraphicsRoot.hx",259)
		this->shape->nmeGetGraphics()->drawRect((int)0,(int)0,(int)320,(int)480);
		HX_SOURCE_POS("./PGraphicsRoot.hx",260)
		this->shape->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("./PGraphicsRoot.hx",262)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PGraphicsRoot_obj,backgroundArgCount3,(void))

Void PGraphicsRoot_obj::backgroundArgCount2( int shadeOfGray,int a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::backgroundArgCount2")
		HX_SOURCE_POS("./PGraphicsRoot.hx",271)
		this->curBackground = this->colorArgCount2(shadeOfGray,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,backgroundArgCount2,(void))

Void PGraphicsRoot_obj::backgroundArgCount1( int shadeOfGray){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::backgroundArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",282)
		this->curBackground = this->colorArgCount1(shadeOfGray);
		HX_SOURCE_POS("./PGraphicsRoot.hx",285)
		{
			HX_SOURCE_POS("./PGraphicsRoot.hx",285)
			this->shape = ::nme::display::Shape_obj::__new();
			HX_SOURCE_POS("./PGraphicsRoot.hx",285)
			this->addChild(this->shape);
			HX_SOURCE_POS("./PGraphicsRoot.hx",285)
			this->shape->nmeGetTransform()->nmeSetMatrix(this->shapeMatrix);
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",286)
		this->shape->nmeGetGraphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",287)
		this->shape->nmeGetGraphics()->beginFill(this->curBackground,null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",288)
		this->shape->nmeGetGraphics()->drawRect((int)0,(int)0,(int)320,(int)480);
		HX_SOURCE_POS("./PGraphicsRoot.hx",289)
		this->shape->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("./PGraphicsRoot.hx",290)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,backgroundArgCount1,(void))

Void PGraphicsRoot_obj::backgroundArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::backgroundArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",302)
		{
			HX_SOURCE_POS("./PGraphicsRoot.hx",302)
			this->shape = ::nme::display::Shape_obj::__new();
			HX_SOURCE_POS("./PGraphicsRoot.hx",302)
			this->addChild(this->shape);
			HX_SOURCE_POS("./PGraphicsRoot.hx",302)
			this->shape->nmeGetTransform()->nmeSetMatrix(this->shapeMatrix);
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",303)
		this->shape->nmeGetGraphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",304)
		this->shape->nmeGetGraphics()->beginFill((int(this->curBackground) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curBackground)) / double((int)255)));
		HX_SOURCE_POS("./PGraphicsRoot.hx",305)
		this->shape->nmeGetGraphics()->drawRect((int)0,(int)0,(int)320,(int)480);
		HX_SOURCE_POS("./PGraphicsRoot.hx",306)
		this->shape->nmeGetGraphics()->endFill();
		HX_SOURCE_POS("./PGraphicsRoot.hx",307)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,backgroundArgCount0,(void))

Void PGraphicsRoot_obj::imageArgCount3( ::PImage img,int x,int y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::imageArgCount3")
		HX_SOURCE_POS("./PGraphicsRoot.hx",451)
		::nme::geom::Matrix keepingTheOriginalMatrix = this->shapeMatrix->clone();
		HX_SOURCE_POS("./PGraphicsRoot.hx",453)
		this->translateArgCount2(x,y);
		HX_SOURCE_POS("./PGraphicsRoot.hx",479)
		::nme::display::Bitmap imageCopy = this->bitmapPool->getBitmap();
		HX_SOURCE_POS("./PGraphicsRoot.hx",480)
		imageCopy->nmeSetBitmapData(img->bitmapData);
		HX_SOURCE_POS("./PGraphicsRoot.hx",483)
		if ((this->tint)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",484)
			int aa = (int((int(this->tintColor) >> int((int)24))) & int((int)255));
			HX_SOURCE_POS("./PGraphicsRoot.hx",485)
			int rr = (int((int(this->tintColor) >> int((int)16))) & int((int)255));
			HX_SOURCE_POS("./PGraphicsRoot.hx",486)
			int gg = (int((int(this->tintColor) >> int((int)8))) & int((int)255));
			HX_SOURCE_POS("./PGraphicsRoot.hx",487)
			int bb = (int(this->tintColor) & int((int)255));
			HX_SOURCE_POS("./PGraphicsRoot.hx",495)
			imageCopy->nmeGetTransform()->nmeSetColorTransform(::nme::geom::ColorTransform_obj::__new((double(rr) / double((int)255)),(double(gg) / double((int)255)),(double(bb) / double((int)255)),(double(aa) / double((int)255)),(int)0,(int)0,(int)0,(int)0));
		}
		else{
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",506)
		::nme::geom::Matrix newMatrix = this->shapeMatrix->clone();
		HX_SOURCE_POS("./PGraphicsRoot.hx",507)
		imageCopy->nmeGetTransform()->nmeSetMatrix(newMatrix);
		HX_SOURCE_POS("./PGraphicsRoot.hx",508)
		this->addChild(imageCopy);
		HX_SOURCE_POS("./PGraphicsRoot.hx",512)
		this->shapeMatrix = keepingTheOriginalMatrix;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PGraphicsRoot_obj,imageArgCount3,(void))

Void PGraphicsRoot_obj::noTintArgCount0( ){
{
		HX_SOURCE_PUSH("PGraphicsRoot_obj::noTintArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",516)
		this->tint = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,noTintArgCount0,(void))

Void PGraphicsRoot_obj::tintArgCount3( double rc,double gc,double bc){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::tintArgCount3")
		HX_SOURCE_POS("./PGraphicsRoot.hx",520)
		this->tint = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",521)
		this->tintColor = this->colorArgCount3(::Std_obj::_int(rc),::Std_obj::_int(gc),::Std_obj::_int(bc));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PGraphicsRoot_obj,tintArgCount3,(void))

Void PGraphicsRoot_obj::tintArgCount4( double rc,double gc,double bc,double ac){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::tintArgCount4")
		HX_SOURCE_POS("./PGraphicsRoot.hx",526)
		this->tint = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",527)
		this->tintColor = this->colorArgCount4(::Std_obj::_int(rc),::Std_obj::_int(gc),::Std_obj::_int(bc),::Std_obj::_int(ac));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,tintArgCount4,(void))

::PGraphics PGraphicsRoot_obj::createGraphicsArgCount3( int w,int h,int type){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::createGraphicsArgCount3")
	HX_SOURCE_POS("./PGraphicsRoot.hx",541)
	::PGraphics thepGraphics = ::PGraphics_obj::__new(w,h);
	HX_SOURCE_POS("./PGraphicsRoot.hx",542)
	thepGraphics->nmeSetCacheAsBitmap(true);
	HX_SOURCE_POS("./PGraphicsRoot.hx",545)
	::nme::geom::Rectangle rect = ::nme::geom::Rectangle_obj::__new((int)0,(int)0,w,h);
	HX_SOURCE_POS("./PGraphicsRoot.hx",546)
	thepGraphics->bitmapData->fillRect(rect,(int)-16777216);
	HX_SOURCE_POS("./PGraphicsRoot.hx",547)
	return thepGraphics;
}


HX_DEFINE_DYNAMIC_FUNC3(PGraphicsRoot_obj,createGraphicsArgCount3,return )

int PGraphicsRoot_obj::redArgCount1( int aColor){
	HX_SOURCE_PUSH("PGraphicsRoot_obj::redArgCount1")
	HX_SOURCE_POS("./PGraphicsRoot.hx",551)
	return (int((int(aColor) >> int((int)16))) & int((int)255));
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,redArgCount1,return )

int PGraphicsRoot_obj::greenArgCount1( int aColor){
	HX_SOURCE_PUSH("PGraphicsRoot_obj::greenArgCount1")
	HX_SOURCE_POS("./PGraphicsRoot.hx",555)
	return (int((int(aColor) >> int((int)8))) & int((int)255));
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,greenArgCount1,return )

int PGraphicsRoot_obj::blueArgCount1( int aColor){
	HX_SOURCE_PUSH("PGraphicsRoot_obj::blueArgCount1")
	HX_SOURCE_POS("./PGraphicsRoot.hx",559)
	return (int(aColor) & int((int)255));
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,blueArgCount1,return )

int PGraphicsRoot_obj::alphaArgCount1( int aColor){
	HX_SOURCE_PUSH("PGraphicsRoot_obj::alphaArgCount1")
	HX_SOURCE_POS("./PGraphicsRoot.hx",563)
	return (int((int(aColor) >> int((int)24))) & int((int)255));
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,alphaArgCount1,return )

int PGraphicsRoot_obj::pGraphicsAlphaMethod( int aColor){
	HX_SOURCE_PUSH("PGraphicsRoot_obj::pGraphicsAlphaMethod")
	HX_SOURCE_POS("./PGraphicsRoot.hx",567)
	return (int((int(aColor) >> int((int)24))) & int((int)255));
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,pGraphicsAlphaMethod,return )

Void PGraphicsRoot_obj::beginShapeDrawing( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::beginShapeDrawing")
		HX_SOURCE_POS("./PGraphicsRoot.hx",592)
		{
			HX_SOURCE_POS("./PGraphicsRoot.hx",592)
			this->shape = ::nme::display::Shape_obj::__new();
			HX_SOURCE_POS("./PGraphicsRoot.hx",592)
			this->addChild(this->shape);
			HX_SOURCE_POS("./PGraphicsRoot.hx",592)
			this->shape->nmeGetTransform()->nmeSetMatrix(this->shapeMatrix);
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",598)
		this->newShapeNeeded = false;
		HX_SOURCE_POS("./PGraphicsRoot.hx",605)
		if ((this->doStroke))
			this->shape->nmeGetGraphics()->lineStyle(this->curStrokeWeight,(int(this->curStrokeColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curStrokeColor)) / double((int)255)),null(),::nme::display::LineScaleMode_obj::NONE,::nme::display::CapsStyle_obj::ROUND,null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",610)
		if ((this->doFill))
			this->shape->nmeGetGraphics()->beginFill((int(this->curFillColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curFillColor)) / double((int)255)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,beginShapeDrawing,(void))

Void PGraphicsRoot_obj::endAnyOpenFills( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::endAnyOpenFills")
		HX_SOURCE_POS("./PGraphicsRoot.hx",617)
		this->shape->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,endAnyOpenFills,(void))

Void PGraphicsRoot_obj::lineArgCount4( Dynamic __o_x1,Dynamic __o_y1,Dynamic __o_x2,Dynamic __o_y2){
double x1 = __o_x1.Default(0);
double y1 = __o_y1.Default(0);
double x2 = __o_x2.Default(0);
double y2 = __o_y2.Default(0);
	HX_SOURCE_PUSH("PGraphicsRoot_obj::lineArgCount4");
{
		__SAFE_POINT
		HX_SOURCE_POS("./PGraphicsRoot.hx",623)
		if ((this->newShapeNeeded))
			this->beginShapeDrawing();
		HX_SOURCE_POS("./PGraphicsRoot.hx",624)
		this->shape->nmeGetGraphics()->moveTo(x1,y1);
		HX_SOURCE_POS("./PGraphicsRoot.hx",625)
		this->shape->nmeGetGraphics()->lineTo(x2,y2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,lineArgCount4,(void))

Void PGraphicsRoot_obj::rectArgCount4( double x,double y,double width,double height){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::rectArgCount4")
		HX_SOURCE_POS("./PGraphicsRoot.hx",639)
		if ((this->doStroke)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",640)
			hx::AddEq(x,this->curStrokeWeight);
			HX_SOURCE_POS("./PGraphicsRoot.hx",641)
			hx::AddEq(y,this->curStrokeWeight);
			HX_SOURCE_POS("./PGraphicsRoot.hx",642)
			hx::SubEq(width,this->curStrokeWeight);
			HX_SOURCE_POS("./PGraphicsRoot.hx",643)
			hx::SubEq(height,this->curStrokeWeight);
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",649)
		int _switch_1 = this->curRectMode;
		if (  ( _switch_1==this->CORNERS)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",652)
			hx::SubEq(width,x);
			HX_SOURCE_POS("./PGraphicsRoot.hx",653)
			hx::SubEq(height,y);
		}
		else if (  ( _switch_1==this->RADIUS)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",656)
			hx::MultEq(width,(int)2);
			HX_SOURCE_POS("./PGraphicsRoot.hx",657)
			hx::MultEq(height,(int)2);
		}
		else if (  ( _switch_1==this->CENTER)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",659)
			hx::SubEq(x,(double(width) / double((int)2)));
			HX_SOURCE_POS("./PGraphicsRoot.hx",660)
			hx::SubEq(y,(double(height) / double((int)2)));
		}
		else  {
		}
;
;
		HX_SOURCE_POS("./PGraphicsRoot.hx",666)
		if ((this->newShapeNeeded))
			this->beginShapeDrawing();
		HX_SOURCE_POS("./PGraphicsRoot.hx",667)
		this->shape->nmeGetGraphics()->drawRect(x,y,width,height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,rectArgCount4,(void))

Void PGraphicsRoot_obj::triangleArgCount6( double x1,double y1,double x2,double y2,double x3,double y3){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::triangleArgCount6")
		HX_SOURCE_POS("./PGraphicsRoot.hx",673)
		if ((this->newShapeNeeded))
			this->beginShapeDrawing();
		HX_SOURCE_POS("./PGraphicsRoot.hx",674)
		this->beginShapeArgCount0();
		HX_SOURCE_POS("./PGraphicsRoot.hx",675)
		this->vertexArgCount2(x1,y1);
		HX_SOURCE_POS("./PGraphicsRoot.hx",676)
		this->vertexArgCount2(x2,y2);
		HX_SOURCE_POS("./PGraphicsRoot.hx",677)
		this->vertexArgCount2(x3,y3);
		HX_SOURCE_POS("./PGraphicsRoot.hx",678)
		this->endShapeArgCount0();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(PGraphicsRoot_obj,triangleArgCount6,(void))

Void PGraphicsRoot_obj::ellipse( double x,double y,double width,double height){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::ellipse")
		HX_SOURCE_POS("./PGraphicsRoot.hx",686)
		hx::DivEq(width,(int)2);
		HX_SOURCE_POS("./PGraphicsRoot.hx",687)
		hx::DivEq(height,(int)2);
		HX_SOURCE_POS("./PGraphicsRoot.hx",689)
		int _switch_2 = this->curEllipseMode;
		if (  ( _switch_2==this->CORNER)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",694)
			hx::AddEq(x,width);
			HX_SOURCE_POS("./PGraphicsRoot.hx",695)
			hx::AddEq(y,height);
		}
		else if (  ( _switch_2==this->RADIUS)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",699)
			hx::MultEq(width,(int)2);
			HX_SOURCE_POS("./PGraphicsRoot.hx",700)
			hx::MultEq(height,(int)2);
		}
		else if (  ( _switch_2==this->CENTER)){
		}
		else if (  ( _switch_2==this->CORNERS)){
			HX_SOURCE_POS("./PGraphicsRoot.hx",707)
			hx::DivEq(width,(int)4);
			HX_SOURCE_POS("./PGraphicsRoot.hx",708)
			hx::DivEq(height,(int)4);
			HX_SOURCE_POS("./PGraphicsRoot.hx",709)
			hx::AddEq(x,width);
			HX_SOURCE_POS("./PGraphicsRoot.hx",710)
			hx::AddEq(y,height);
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",714)
		if ((this->newShapeNeeded))
			this->beginShapeDrawing();
		HX_SOURCE_POS("./PGraphicsRoot.hx",715)
		this->shape->nmeGetGraphics()->drawEllipse(x,y,width,height);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,ellipse,(void))

Void PGraphicsRoot_obj::noStrokeArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::noStrokeArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",720)
		this->doStroke = false;
		HX_SOURCE_POS("./PGraphicsRoot.hx",721)
		this->shape->nmeGetGraphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,noStrokeArgCount0,(void))

Void PGraphicsRoot_obj::strokeArgCount4( int r,int g,int b,int a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::strokeArgCount4")
		HX_SOURCE_POS("./PGraphicsRoot.hx",726)
		this->doStroke = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",727)
		this->curStrokeColor = this->colorArgCount4(r,g,b,a);
		HX_SOURCE_POS("./PGraphicsRoot.hx",728)
		this->shape->nmeGetGraphics()->lineStyle(this->curStrokeWeight,(int(this->curStrokeColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curStrokeColor)) / double((int)255)),null(),::nme::display::LineScaleMode_obj::NONE,::nme::display::CapsStyle_obj::ROUND,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,strokeArgCount4,(void))

Void PGraphicsRoot_obj::strokeArgCount3( int r,int g,int b){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::strokeArgCount3")
		HX_SOURCE_POS("./PGraphicsRoot.hx",734)
		this->doStroke = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",735)
		this->curStrokeColor = this->colorArgCount3(r,g,b);
		HX_SOURCE_POS("./PGraphicsRoot.hx",736)
		this->shape->nmeGetGraphics()->lineStyle(this->curStrokeWeight,(int(this->curStrokeColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curStrokeColor)) / double((int)255)),null(),::nme::display::LineScaleMode_obj::NONE,::nme::display::CapsStyle_obj::ROUND,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PGraphicsRoot_obj,strokeArgCount3,(void))

Void PGraphicsRoot_obj::strokeArgCount2( int grayScale,int a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::strokeArgCount2")
		HX_SOURCE_POS("./PGraphicsRoot.hx",742)
		this->doStroke = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",743)
		this->curStrokeColor = this->colorArgCount2(grayScale,a);
		HX_SOURCE_POS("./PGraphicsRoot.hx",744)
		this->shape->nmeGetGraphics()->lineStyle(this->curStrokeWeight,(int(this->curStrokeColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curStrokeColor)) / double((int)255)),null(),::nme::display::LineScaleMode_obj::NONE,::nme::display::CapsStyle_obj::ROUND,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,strokeArgCount2,(void))

Void PGraphicsRoot_obj::strokeArgCount1( int grayScale){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::strokeArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",750)
		this->doStroke = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",751)
		this->curStrokeColor = this->colorArgCount1(grayScale);
		HX_SOURCE_POS("./PGraphicsRoot.hx",752)
		this->shape->nmeGetGraphics()->lineStyle(this->curStrokeWeight,(int(this->curStrokeColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curStrokeColor)) / double((int)255)),null(),::nme::display::LineScaleMode_obj::NONE,::nme::display::CapsStyle_obj::ROUND,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,strokeArgCount1,(void))

Void PGraphicsRoot_obj::noFillArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::noFillArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",758)
		this->doFill = false;
		HX_SOURCE_POS("./PGraphicsRoot.hx",759)
		this->shape->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,noFillArgCount0,(void))

Void PGraphicsRoot_obj::fillArgCount4( int mr,int mg,int mb,int ma){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::fillArgCount4")
		HX_SOURCE_POS("./PGraphicsRoot.hx",764)
		this->doFill = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",765)
		this->curFillColor = this->colorArgCount4(mr,mg,mb,ma);
		HX_SOURCE_POS("./PGraphicsRoot.hx",766)
		this->shape->nmeGetGraphics()->beginFill((int(this->curFillColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curFillColor)) / double((int)255)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,fillArgCount4,(void))

Void PGraphicsRoot_obj::fillArgCount3( int r,int g,int b){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::fillArgCount3")
		HX_SOURCE_POS("./PGraphicsRoot.hx",771)
		this->doFill = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",772)
		this->curFillColor = this->colorArgCount3(r,g,b);
		HX_SOURCE_POS("./PGraphicsRoot.hx",773)
		this->shape->nmeGetGraphics()->beginFill((int(this->curFillColor) & int((int)16777215)),1.0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PGraphicsRoot_obj,fillArgCount3,(void))

Void PGraphicsRoot_obj::fillArgCount2( int grayScale,int a){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::fillArgCount2")
		HX_SOURCE_POS("./PGraphicsRoot.hx",778)
		this->doFill = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",779)
		this->curFillColor = this->colorArgCount2(grayScale,a);
		HX_SOURCE_POS("./PGraphicsRoot.hx",780)
		this->shape->nmeGetGraphics()->beginFill((int(this->curFillColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curFillColor)) / double((int)255)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,fillArgCount2,(void))

Void PGraphicsRoot_obj::fillArgCount1( int grayScale){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::fillArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",785)
		this->doFill = true;
		HX_SOURCE_POS("./PGraphicsRoot.hx",786)
		this->curFillColor = this->colorArgCount1(grayScale);
		HX_SOURCE_POS("./PGraphicsRoot.hx",787)
		this->shape->nmeGetGraphics()->beginFill((int(this->curFillColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curFillColor)) / double((int)255)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,fillArgCount1,(void))

int PGraphicsRoot_obj::colorArgCount1( int shadeOfGray){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::colorArgCount1")
	HX_SOURCE_POS("./PGraphicsRoot.hx",793)
	int r = ::Std_obj::_int(((int)255 * ((double(shadeOfGray) / double(this->redRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",799)
	return (((((int(this->opacityRange) << int((int)24))) + ((int(r) << int((int)16)))) + ((int(r) << int((int)8)))) + r);
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,colorArgCount1,return )

int PGraphicsRoot_obj::colorArgCount2( int shadeOfGray,int a){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::colorArgCount2")
	HX_SOURCE_POS("./PGraphicsRoot.hx",804)
	int r = ::Std_obj::_int(((int)255 * ((double(shadeOfGray) / double(this->redRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",810)
	return (((((int(a) << int((int)24))) + ((int(r) << int((int)16)))) + ((int(r) << int((int)8)))) + r);
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,colorArgCount2,return )

int PGraphicsRoot_obj::colorArgCount3( int r,int g,int b){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::colorArgCount3")
	HX_SOURCE_POS("./PGraphicsRoot.hx",815)
	int r1 = ::Std_obj::_int(((int)255 * ((double(r) / double(this->redRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",816)
	int g1 = ::Std_obj::_int(((int)255 * ((double(g) / double(this->greenRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",817)
	int b1 = ::Std_obj::_int(((int)255 * ((double(b) / double(this->blueRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",826)
	return (((((int(this->opacityRange) << int((int)24))) + ((int(r1) << int((int)16)))) + ((int(g1) << int((int)8)))) + b1);
}


HX_DEFINE_DYNAMIC_FUNC3(PGraphicsRoot_obj,colorArgCount3,return )

int PGraphicsRoot_obj::colorArgCount4( int theR,int theG,int theB,int theA){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::colorArgCount4")
	HX_SOURCE_POS("./PGraphicsRoot.hx",836)
	int r = ::Std_obj::_int(((int)255 * ((double(theR) / double(this->redRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",837)
	int g = ::Std_obj::_int(((int)255 * ((double(theG) / double(this->greenRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",838)
	int b = ::Std_obj::_int(((int)255 * ((double(theB) / double(this->blueRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",839)
	int a = ::Std_obj::_int(((int)255 * ((double(theA) / double(this->opacityRange)))));
	HX_SOURCE_POS("./PGraphicsRoot.hx",848)
	return (((((int(a) << int((int)24))) + ((int(r) << int((int)16)))) + ((int(g) << int((int)8)))) + b);
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,colorArgCount4,return )

int PGraphicsRoot_obj::getColor( int aValue,int range){
	__SAFE_POINT
	HX_SOURCE_PUSH("PGraphicsRoot_obj::getColor")
	HX_SOURCE_POS("./PGraphicsRoot.hx",857)
	return ::Std_obj::_int(((int)255 * ((double(aValue) / double(range)))));
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,getColor,return )

Void PGraphicsRoot_obj::pushMatrixWithoutCreatingNewShape( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::pushMatrixWithoutCreatingNewShape")
		HX_SOURCE_POS("./PGraphicsRoot.hx",864)
		this->matrixStack->push(this->shapeMatrix);
		HX_SOURCE_POS("./PGraphicsRoot.hx",867)
		::nme::geom::Matrix newMatrix = this->shapeMatrix->clone();
		HX_SOURCE_POS("./PGraphicsRoot.hx",868)
		this->shapeMatrix = newMatrix;
		HX_SOURCE_POS("./PGraphicsRoot.hx",874)
		this->trackingScaleXStack->push(this->trackingScaleX);
		HX_SOURCE_POS("./PGraphicsRoot.hx",875)
		this->trackingScaleYStack->push(this->trackingScaleY);
		HX_SOURCE_POS("./PGraphicsRoot.hx",876)
		this->trackingRotationStack->push(this->trackingRotation);
		HX_SOURCE_POS("./PGraphicsRoot.hx",877)
		this->trackingTranslationXStack->push(this->trackingTranslationX);
		HX_SOURCE_POS("./PGraphicsRoot.hx",878)
		this->trackingTranslationYStack->push(this->trackingTranslationY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,pushMatrixWithoutCreatingNewShape,(void))

Void PGraphicsRoot_obj::pushMatrixArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::pushMatrixArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",888)
		{
			HX_SOURCE_POS("./PGraphicsRoot.hx",888)
			this->matrixStack->push(this->shapeMatrix);
			HX_SOURCE_POS("./PGraphicsRoot.hx",888)
			::nme::geom::Matrix newMatrix = this->shapeMatrix->clone();
			HX_SOURCE_POS("./PGraphicsRoot.hx",888)
			this->shapeMatrix = newMatrix;
			HX_SOURCE_POS("./PGraphicsRoot.hx",888)
			this->trackingScaleXStack->push(this->trackingScaleX);
			HX_SOURCE_POS("./PGraphicsRoot.hx",888)
			this->trackingScaleYStack->push(this->trackingScaleY);
			HX_SOURCE_POS("./PGraphicsRoot.hx",888)
			this->trackingRotationStack->push(this->trackingRotation);
			HX_SOURCE_POS("./PGraphicsRoot.hx",888)
			this->trackingTranslationXStack->push(this->trackingTranslationX);
			HX_SOURCE_POS("./PGraphicsRoot.hx",888)
			this->trackingTranslationYStack->push(this->trackingTranslationY);
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",889)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,pushMatrixArgCount0,(void))

Void PGraphicsRoot_obj::popMatrixWithoutCreatingNewShape( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::popMatrixWithoutCreatingNewShape")
		HX_SOURCE_POS("./PGraphicsRoot.hx",902)
		this->trackingTranslationY = this->trackingTranslationYStack->pop();
		HX_SOURCE_POS("./PGraphicsRoot.hx",903)
		this->trackingTranslationX = this->trackingTranslationXStack->pop();
		HX_SOURCE_POS("./PGraphicsRoot.hx",904)
		this->trackingRotation = this->trackingRotationStack->pop();
		HX_SOURCE_POS("./PGraphicsRoot.hx",905)
		this->trackingScaleY = this->trackingScaleYStack->pop();
		HX_SOURCE_POS("./PGraphicsRoot.hx",906)
		this->trackingScaleX = this->trackingScaleXStack->pop();
		HX_SOURCE_POS("./PGraphicsRoot.hx",908)
		this->shapeMatrix = this->matrixStack->pop();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,popMatrixWithoutCreatingNewShape,(void))

Void PGraphicsRoot_obj::popMatrixArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::popMatrixArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",913)
		{
			HX_SOURCE_POS("./PGraphicsRoot.hx",913)
			this->trackingTranslationY = this->trackingTranslationYStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",913)
			this->trackingTranslationX = this->trackingTranslationXStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",913)
			this->trackingRotation = this->trackingRotationStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",913)
			this->trackingScaleY = this->trackingScaleYStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",913)
			this->trackingScaleX = this->trackingScaleXStack->pop();
			HX_SOURCE_POS("./PGraphicsRoot.hx",913)
			this->shapeMatrix = this->matrixStack->pop();
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",914)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,popMatrixArgCount0,(void))

Void PGraphicsRoot_obj::rotateArgCount1( double aAngle){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::rotateArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",927)
		::nme::geom::Matrix newMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",928)
		newMatrix->rotate(aAngle);
		HX_SOURCE_POS("./PGraphicsRoot.hx",929)
		newMatrix->concat(this->shapeMatrix);
		HX_SOURCE_POS("./PGraphicsRoot.hx",930)
		this->shapeMatrix = newMatrix;
		HX_SOURCE_POS("./PGraphicsRoot.hx",932)
		hx::AddEq(this->trackingRotation,aAngle);
		HX_SOURCE_POS("./PGraphicsRoot.hx",933)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,rotateArgCount1,(void))

Void PGraphicsRoot_obj::scaleArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::scaleArgCount2")
		HX_SOURCE_POS("./PGraphicsRoot.hx",945)
		::nme::geom::Matrix newMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",946)
		newMatrix->scale(x,y);
		HX_SOURCE_POS("./PGraphicsRoot.hx",947)
		newMatrix->concat(this->shapeMatrix);
		HX_SOURCE_POS("./PGraphicsRoot.hx",948)
		this->shapeMatrix = newMatrix;
		HX_SOURCE_POS("./PGraphicsRoot.hx",950)
		hx::MultEq(this->trackingScaleX,x);
		HX_SOURCE_POS("./PGraphicsRoot.hx",951)
		hx::MultEq(this->trackingScaleY,y);
		HX_SOURCE_POS("./PGraphicsRoot.hx",953)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,scaleArgCount2,(void))

Void PGraphicsRoot_obj::createNewShape( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::createNewShape")
		HX_SOURCE_POS("./PGraphicsRoot.hx",960)
		this->shape = ::nme::display::Shape_obj::__new();
		HX_SOURCE_POS("./PGraphicsRoot.hx",961)
		this->addChild(this->shape);
		HX_SOURCE_POS("./PGraphicsRoot.hx",962)
		this->shape->nmeGetTransform()->nmeSetMatrix(this->shapeMatrix);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,createNewShape,(void))

Void PGraphicsRoot_obj::scaleArgCount1( double xy){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::scaleArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",974)
		::nme::geom::Matrix newMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",975)
		newMatrix->scale(xy,xy);
		HX_SOURCE_POS("./PGraphicsRoot.hx",976)
		newMatrix->concat(this->shapeMatrix);
		HX_SOURCE_POS("./PGraphicsRoot.hx",977)
		this->shapeMatrix = newMatrix;
		HX_SOURCE_POS("./PGraphicsRoot.hx",979)
		hx::MultEq(this->trackingScaleX,xy);
		HX_SOURCE_POS("./PGraphicsRoot.hx",980)
		hx::MultEq(this->trackingScaleY,xy);
		HX_SOURCE_POS("./PGraphicsRoot.hx",982)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,scaleArgCount1,(void))

Void PGraphicsRoot_obj::translateArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::translateArgCount2")
		HX_SOURCE_POS("./PGraphicsRoot.hx",993)
		::nme::geom::Matrix newMatrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",994)
		newMatrix->translate(x,y);
		HX_SOURCE_POS("./PGraphicsRoot.hx",996)
		hx::AddEq(this->trackingTranslationX,x);
		HX_SOURCE_POS("./PGraphicsRoot.hx",997)
		hx::AddEq(this->trackingTranslationY,y);
		HX_SOURCE_POS("./PGraphicsRoot.hx",999)
		newMatrix->concat(this->shapeMatrix);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1000)
		this->shapeMatrix = newMatrix;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1002)
		this->newShapeNeeded = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,translateArgCount2,(void))

Void PGraphicsRoot_obj::strokeWeightArgCount1( double w){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::strokeWeightArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1007)
		this->curStrokeWeight = w;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1009)
		if ((this->doStroke))
			this->shape->nmeGetGraphics()->lineStyle(this->curStrokeWeight,(int(this->curStrokeColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curStrokeColor)) / double((int)255)),null(),::nme::display::LineScaleMode_obj::NONE,::nme::display::CapsStyle_obj::ROUND,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,strokeWeightArgCount1,(void))

Void PGraphicsRoot_obj::pointArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::pointArgCount2")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1019)
		::nme::geom::Point point = ::nme::geom::Point_obj::__new(null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",1020)
		point->x = x;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1021)
		point->y = y;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1024)
		::nme::geom::Point pointPosition;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1025)
		pointPosition = this->shapeMatrix->transformPoint(point);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1033)
		this->shape->nmeGetGraphics()->lineStyle(null(),null(),null(),null(),null(),null(),null(),null());
		HX_SOURCE_POS("./PGraphicsRoot.hx",1037)
		this->shape->nmeGetGraphics()->beginFill((int(this->curStrokeColor) & int((int)16777215)),(  (((this->pGraphicsAlphaMethod(this->curStrokeColor) == (int)255))) ? double((int)255) : double((double(this->pGraphicsAlphaMethod(this->curStrokeColor)) / double((int)312))) ));
		HX_SOURCE_POS("./PGraphicsRoot.hx",1041)
		this->shape->nmeGetGraphics()->drawEllipse((pointPosition->x - (double((this->curStrokeWeight * this->trackingScaleX)) / double((int)2))),(pointPosition->y - (double((this->curStrokeWeight * this->trackingScaleY)) / double((int)2))),((this->curStrokeWeight * this->trackingScaleX) + (int)1),((this->curStrokeWeight * this->trackingScaleY) + (int)1));
		HX_SOURCE_POS("./PGraphicsRoot.hx",1044)
		this->shape->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,pointArgCount2,(void))

Void PGraphicsRoot_obj::beginShapeArgCount0( ){
{
		HX_SOURCE_PUSH("PGraphicsRoot_obj::beginShapeArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1070)
		this->curShape = this->POLYGON;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1071)
		this->curShapeCount = (int)0;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1072)
		this->curvePoints = Array_obj< ::nme::geom::Point >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,beginShapeArgCount0,(void))

Void PGraphicsRoot_obj::beginShapeArgCount1( int type){
{
		HX_SOURCE_PUSH("PGraphicsRoot_obj::beginShapeArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1078)
		this->curShape = type;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1079)
		this->curShapeCount = (int)0;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1080)
		this->curvePoints = Array_obj< ::nme::geom::Point >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,beginShapeArgCount1,(void))

Void PGraphicsRoot_obj::endShapeArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::endShapeArgCount0")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1084)
		if (((bool((this->curShapeCount != (int)0)) || bool(this->pathOpen)))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1085)
			this->shape->nmeGetGraphics()->endFill();
			HX_SOURCE_POS("./PGraphicsRoot.hx",1086)
			this->curShapeCount = (int)0;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1087)
			this->pathOpen = false;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1101)
			if ((this->doFill))
				this->shape->nmeGetGraphics()->beginFill((int(this->curFillColor) & int((int)16777215)),(double(this->pGraphicsAlphaMethod(this->curFillColor)) / double((int)255)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PGraphicsRoot_obj,endShapeArgCount0,(void))

Void PGraphicsRoot_obj::endShapeArgCount1( bool close){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::endShapeArgCount1")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1108)
		this->shape->nmeGetGraphics()->lineTo(this->firstX,this->firstY);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1110)
		if (((bool((this->curShapeCount != (int)0)) || bool(this->pathOpen)))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1111)
			this->shape->nmeGetGraphics()->endFill();
			HX_SOURCE_POS("./PGraphicsRoot.hx",1112)
			this->curShapeCount = (int)0;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1113)
			this->pathOpen = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,endShapeArgCount1,(void))

Void PGraphicsRoot_obj::vertexArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::vertexArgCount2")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1119)
		if (((bool((this->curShapeCount == (int)0)) && bool((this->curShape != this->POINTS))))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1121)
			this->pathOpen = true;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1122)
			if ((this->newShapeNeeded))
				this->beginShapeDrawing();
			HX_SOURCE_POS("./PGraphicsRoot.hx",1123)
			this->shape->nmeGetGraphics()->moveTo(x,y);
			HX_SOURCE_POS("./PGraphicsRoot.hx",1124)
			this->firstX = x;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1125)
			this->firstY = y;
		}
		else{
			HX_SOURCE_POS("./PGraphicsRoot.hx",1129)
			if (((this->curShape == this->POINTS))){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1131)
				this->pointArgCount2(x,y);
			}
			else{
				HX_SOURCE_POS("./PGraphicsRoot.hx",1134)
				if (((bool((this->curShape != this->QUAD_STRIP)) || bool((this->curShapeCount != (int)2)))))
					this->shape->nmeGetGraphics()->lineTo(x,y);
				HX_SOURCE_POS("./PGraphicsRoot.hx",1137)
				if (((this->curShape == this->TRIANGLE_STRIP))){
					HX_SOURCE_POS("./PGraphicsRoot.hx",1138)
					if (((this->curShapeCount == (int)2))){
						HX_SOURCE_POS("./PGraphicsRoot.hx",1140)
						this->endShapeArgCount1(this->CLOSE);
						HX_SOURCE_POS("./PGraphicsRoot.hx",1141)
						this->pathOpen = true;
						HX_SOURCE_POS("./PGraphicsRoot.hx",1142)
						if ((this->newShapeNeeded))
							this->beginShapeDrawing();
						HX_SOURCE_POS("./PGraphicsRoot.hx",1145)
						this->shape->nmeGetGraphics()->moveTo(this->prevX,this->prevY);
						HX_SOURCE_POS("./PGraphicsRoot.hx",1146)
						this->shape->nmeGetGraphics()->lineTo(x,y);
						HX_SOURCE_POS("./PGraphicsRoot.hx",1147)
						this->curShapeCount = (int)1;
					}
					HX_SOURCE_POS("./PGraphicsRoot.hx",1149)
					this->firstX = this->prevX;
					HX_SOURCE_POS("./PGraphicsRoot.hx",1150)
					this->firstY = this->prevY;
				}
				HX_SOURCE_POS("./PGraphicsRoot.hx",1153)
				if (((bool((this->curShape == this->TRIANGLE_FAN)) && bool((this->curShapeCount == (int)2))))){
					HX_SOURCE_POS("./PGraphicsRoot.hx",1155)
					this->endShapeArgCount1(this->CLOSE);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1156)
					this->pathOpen = true;
					HX_SOURCE_POS("./PGraphicsRoot.hx",1157)
					if ((this->newShapeNeeded))
						this->beginShapeDrawing();
					HX_SOURCE_POS("./PGraphicsRoot.hx",1160)
					this->shape->nmeGetGraphics()->moveTo(this->firstX,this->firstY);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1161)
					this->shape->nmeGetGraphics()->lineTo(x,y);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1162)
					this->curShapeCount = (int)1;
				}
				HX_SOURCE_POS("./PGraphicsRoot.hx",1165)
				if (((bool((this->curShape == this->QUAD_STRIP)) && bool((this->curShapeCount == (int)3))))){
					HX_SOURCE_POS("./PGraphicsRoot.hx",1167)
					this->shape->nmeGetGraphics()->lineTo(this->prevX,this->prevY);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1168)
					this->endShapeArgCount1(this->CLOSE);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1169)
					this->pathOpen = true;
					HX_SOURCE_POS("./PGraphicsRoot.hx",1170)
					if ((this->newShapeNeeded))
						this->beginShapeDrawing();
					HX_SOURCE_POS("./PGraphicsRoot.hx",1173)
					this->shape->nmeGetGraphics()->moveTo(this->prevX,this->prevY);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1174)
					this->shape->nmeGetGraphics()->lineTo(x,y);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1175)
					this->curShapeCount = (int)1;
				}
				HX_SOURCE_POS("./PGraphicsRoot.hx",1178)
				if (((this->curShape == this->QUAD_STRIP))){
					HX_SOURCE_POS("./PGraphicsRoot.hx",1179)
					this->firstX = this->secondX;
					HX_SOURCE_POS("./PGraphicsRoot.hx",1180)
					this->firstY = this->secondY;
					HX_SOURCE_POS("./PGraphicsRoot.hx",1181)
					this->secondX = this->prevX;
					HX_SOURCE_POS("./PGraphicsRoot.hx",1182)
					this->secondY = this->prevY;
				}
			}
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",1201)
		this->prevX = x;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1202)
		this->prevY = y;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1203)
		(this->curShapeCount)++;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1205)
		if (((bool((bool((bool((this->curShape == this->LINES)) && bool((this->curShapeCount == (int)2)))) || bool((bool((this->curShape == this->TRIANGLES)) && bool((this->curShapeCount == (int)3)))))) || bool((bool((this->curShape == this->QUADS)) && bool((this->curShapeCount == (int)4))))))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1208)
			this->endShapeArgCount1(this->CLOSE);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,vertexArgCount2,(void))

Void PGraphicsRoot_obj::vertexArgCount4( double x,double y,double x2,double y2){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::vertexArgCount4")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1213)
		if (((bool((this->curShapeCount == (int)0)) && bool((this->curShape != this->POINTS))))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1215)
			this->pathOpen = true;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1216)
			if ((this->newShapeNeeded))
				this->beginShapeDrawing();
			HX_SOURCE_POS("./PGraphicsRoot.hx",1217)
			this->shape->nmeGetGraphics()->moveTo(x,y);
			HX_SOURCE_POS("./PGraphicsRoot.hx",1218)
			this->firstX = x;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1219)
			this->firstY = y;
		}
		else{
			HX_SOURCE_POS("./PGraphicsRoot.hx",1223)
			if (((this->curShape == this->POINTS))){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1225)
				this->pointArgCount2(x,y);
			}
			else{
				HX_SOURCE_POS("./PGraphicsRoot.hx",1228)
				if (((this->curShapeCount > (int)1))){
					HX_SOURCE_POS("./PGraphicsRoot.hx",1229)
					this->shape->nmeGetGraphics()->moveTo(this->prevX,this->prevY);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1230)
					this->shape->nmeGetGraphics()->curveTo(this->firstX,this->firstY,x,y);
					HX_SOURCE_POS("./PGraphicsRoot.hx",1231)
					this->curShapeCount = (int)1;
				}
			}
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",1236)
		this->prevX = x;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1237)
		this->prevY = y;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1238)
		(this->curShapeCount)++;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1240)
		if (((bool((bool((bool((this->curShape == this->LINES)) && bool((this->curShapeCount == (int)2)))) || bool((bool((this->curShape == this->TRIANGLES)) && bool((this->curShapeCount == (int)3)))))) || bool((bool((this->curShape == this->QUADS)) && bool((this->curShapeCount == (int)4))))))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1243)
			this->endShapeArgCount1(this->CLOSE);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,vertexArgCount4,(void))

Void PGraphicsRoot_obj::vertexArgCount6( double x,double y,double x2,double y2,double x3,double y3){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::vertexArgCount6")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1248)
		if (((bool((this->curShapeCount == (int)0)) && bool((this->curShape != this->POINTS))))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1250)
			this->pathOpen = true;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1251)
			if ((this->newShapeNeeded))
				this->beginShapeDrawing();
			HX_SOURCE_POS("./PGraphicsRoot.hx",1252)
			this->shape->nmeGetGraphics()->moveTo(x,y);
			HX_SOURCE_POS("./PGraphicsRoot.hx",1253)
			this->firstX = x;
			HX_SOURCE_POS("./PGraphicsRoot.hx",1254)
			this->firstY = y;
		}
		else{
			HX_SOURCE_POS("./PGraphicsRoot.hx",1258)
			if (((this->curShape == this->POINTS))){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1260)
				this->pointArgCount2(x,y);
			}
			else{
				HX_SOURCE_POS("./PGraphicsRoot.hx",1264)
				this->drawCubicBezier2(this->prevX,this->prevY,x,y,x2,y2,x3,y3);
				HX_SOURCE_POS("./PGraphicsRoot.hx",1267)
				x = x3;
				HX_SOURCE_POS("./PGraphicsRoot.hx",1268)
				y = y3;
			}
		}
		HX_SOURCE_POS("./PGraphicsRoot.hx",1272)
		this->prevX = x;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1273)
		this->prevY = y;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1274)
		(this->curShapeCount)++;
		HX_SOURCE_POS("./PGraphicsRoot.hx",1276)
		if (((bool((bool((bool((this->curShape == this->LINES)) && bool((this->curShapeCount == (int)2)))) || bool((bool((this->curShape == this->TRIANGLES)) && bool((this->curShapeCount == (int)3)))))) || bool((bool((this->curShape == this->QUADS)) && bool((this->curShapeCount == (int)4))))))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1279)
			this->endShapeArgCount1(this->CLOSE);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(PGraphicsRoot_obj,vertexArgCount6,(void))

Void PGraphicsRoot_obj::bezierVertexArgCount6( double x,double y,double x2,double y2,double x3,double y3){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::bezierVertexArgCount6")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1284)
		this->vertexArgCount6(x,y,x2,y2,x3,y3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(PGraphicsRoot_obj,bezierVertexArgCount6,(void))

Void PGraphicsRoot_obj::curveVertexArgCount2( double x,double y){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::curveVertexArgCount2")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1288)
		if (((this->curvePoints->length < (int)3))){
			HX_SOURCE_POS("./PGraphicsRoot.hx",1289)
			this->curvePoints->push(::nme::geom::Point_obj::__new(x,y));
		}
		else{
			HX_SOURCE_POS("./PGraphicsRoot.hx",1291)
			Array< Array< double > > b = Array_obj< Array< double > >::__new();
			HX_SOURCE_POS("./PGraphicsRoot.hx",1292)
			double s = ((int)1 - this->curTightness);
			HX_SOURCE_POS("./PGraphicsRoot.hx",1303)
			this->curvePoints->push(::nme::geom::Point_obj::__new(x,y));
			HX_SOURCE_POS("./PGraphicsRoot.hx",1305)
			b[(int)0] = Array_obj< double >::__new().Add(this->curvePoints->__get((int)1)->x).Add(this->curvePoints->__get((int)1)->y);
			HX_SOURCE_POS("./PGraphicsRoot.hx",1306)
			b[(int)1] = Array_obj< double >::__new().Add((this->curvePoints->__get((int)1)->x + (double((((s * this->curvePoints->__get((int)2)->x) - (s * this->curvePoints->__get((int)0)->x)))) / double((int)6)))).Add((this->curvePoints->__get((int)1)->y + (double((((s * this->curvePoints->__get((int)2)->y) - (s * this->curvePoints->__get((int)0)->y)))) / double((int)6))));
			HX_SOURCE_POS("./PGraphicsRoot.hx",1307)
			b[(int)2] = Array_obj< double >::__new().Add((this->curvePoints->__get((int)2)->x + (double((((s * this->curvePoints->__get((int)1)->x) - (s * this->curvePoints->__get((int)3)->x)))) / double((int)6)))).Add((this->curvePoints->__get((int)2)->y + (double((((s * this->curvePoints->__get((int)1)->y) - (s * this->curvePoints->__get((int)3)->y)))) / double((int)6))));
			HX_SOURCE_POS("./PGraphicsRoot.hx",1308)
			b[(int)3] = Array_obj< double >::__new().Add(this->curvePoints->__get((int)2)->x).Add(this->curvePoints->__get((int)2)->y);
			HX_SOURCE_POS("./PGraphicsRoot.hx",1310)
			if ((!(this->pathOpen))){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1311)
				this->vertexArgCount2(b->__get((int)0)->__get((int)0),b->__get((int)1)->__get((int)1));
			}
			else{
				HX_SOURCE_POS("./PGraphicsRoot.hx",1313)
				this->curShapeCount = (int)1;
			}
			HX_SOURCE_POS("./PGraphicsRoot.hx",1316)
			this->vertexArgCount6(b->__get((int)1)->__get((int)0),b->__get((int)1)->__get((int)1),b->__get((int)2)->__get((int)0),b->__get((int)2)->__get((int)1),b->__get((int)3)->__get((int)0),b->__get((int)3)->__get((int)1));
			HX_SOURCE_POS("./PGraphicsRoot.hx",1317)
			this->curvePoints->shift();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PGraphicsRoot_obj,curveVertexArgCount2,(void))

Void PGraphicsRoot_obj::curveTightness( double tightness){
{
		HX_SOURCE_PUSH("PGraphicsRoot_obj::curveTightness")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1322)
		this->curTightness = tightness;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PGraphicsRoot_obj,curveTightness,(void))

Void PGraphicsRoot_obj::bezierArgCount8( double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::bezierArgCount8")
		HX_SOURCE_POS("./PGraphicsRoot.hx",1328)
		if ((this->newShapeNeeded))
			this->beginShapeDrawing();
		HX_SOURCE_POS("./PGraphicsRoot.hx",1329)
		this->shape->nmeGetGraphics()->moveTo(x1,y1);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1330)
		this->drawCubicBezier2(x1,y1,x2,y2,x3,y3,x4,y4);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1331)
		this->shape->nmeGetGraphics()->endFill();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(PGraphicsRoot_obj,bezierArgCount8,(void))

Void PGraphicsRoot_obj::drawCubicBezier2( double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PGraphicsRoot_obj::drawCubicBezier2")
		struct _Function_1_1{
			inline static ::nme::geom::Point Block( double &x2,double &y1,double &x1,double &y2){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1351)
				double ratio = (double((int)3) / double((int)4));
				HX_SOURCE_POS("./PGraphicsRoot.hx",1351)
				return ::nme::geom::Point_obj::__new((x1 + (((x2 - x1)) * ratio)),(y1 + (((y2 - y1)) * ratio)));
			}
		};
		HX_SOURCE_POS("./PGraphicsRoot.hx",1351)
		::nme::geom::Point PA = _Function_1_1::Block(x2,y1,x1,y2);
		struct _Function_1_2{
			inline static ::nme::geom::Point Block( double &y4,double &x4,double &y3,double &x3){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1352)
				double ratio = (double((int)3) / double((int)4));
				HX_SOURCE_POS("./PGraphicsRoot.hx",1352)
				return ::nme::geom::Point_obj::__new((x4 + (((x3 - x4)) * ratio)),(y4 + (((y3 - y4)) * ratio)));
			}
		};
		HX_SOURCE_POS("./PGraphicsRoot.hx",1352)
		::nme::geom::Point PB = _Function_1_2::Block(y4,x4,y3,x3);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1355)
		double dx = (double(((x4 - x1))) / double((int)16));
		HX_SOURCE_POS("./PGraphicsRoot.hx",1356)
		double dy = (double(((y4 - y1))) / double((int)16));
		struct _Function_1_3{
			inline static ::nme::geom::Point Block( double &x2,double &y1,double &x1,double &y2){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1359)
				double ratio = (double((int)3) / double((int)8));
				HX_SOURCE_POS("./PGraphicsRoot.hx",1359)
				return ::nme::geom::Point_obj::__new((x1 + (((x2 - x1)) * ratio)),(y1 + (((y2 - y1)) * ratio)));
			}
		};
		HX_SOURCE_POS("./PGraphicsRoot.hx",1359)
		::nme::geom::Point Pc_1 = _Function_1_3::Block(x2,y1,x1,y2);
		struct _Function_1_4{
			inline static ::nme::geom::Point Block( ::nme::geom::Point &PA,::nme::geom::Point &PB){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1362)
				double x11 = PA->x;
				double y11 = PA->y;
				double ratio = (double((int)3) / double((int)8));
				HX_SOURCE_POS("./PGraphicsRoot.hx",1362)
				return ::nme::geom::Point_obj::__new((x11 + (((PB->x - x11)) * ratio)),(y11 + (((PB->y - y11)) * ratio)));
			}
		};
		HX_SOURCE_POS("./PGraphicsRoot.hx",1362)
		::nme::geom::Point Pc_2 = _Function_1_4::Block(PA,PB);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1363)
		hx::SubEq(Pc_2->x,dx);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1364)
		hx::SubEq(Pc_2->y,dy);
		struct _Function_1_5{
			inline static ::nme::geom::Point Block( ::nme::geom::Point &PB,::nme::geom::Point &PA){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1367)
				double x11 = PB->x;
				double y11 = PB->y;
				double ratio = (double((int)3) / double((int)8));
				HX_SOURCE_POS("./PGraphicsRoot.hx",1367)
				return ::nme::geom::Point_obj::__new((x11 + (((PA->x - x11)) * ratio)),(y11 + (((PA->y - y11)) * ratio)));
			}
		};
		HX_SOURCE_POS("./PGraphicsRoot.hx",1367)
		::nme::geom::Point Pc_3 = _Function_1_5::Block(PB,PA);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1368)
		hx::AddEq(Pc_3->x,dx);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1369)
		hx::AddEq(Pc_3->y,dy);
		struct _Function_1_6{
			inline static ::nme::geom::Point Block( double &y4,double &x4,double &y3,double &x3){
				HX_SOURCE_POS("./PGraphicsRoot.hx",1372)
				double ratio = (double((int)3) / double((int)8));
				HX_SOURCE_POS("./PGraphicsRoot.hx",1372)
				return ::nme::geom::Point_obj::__new((x4 + (((x3 - x4)) * ratio)),(y4 + (((y3 - y4)) * ratio)));
			}
		};
		HX_SOURCE_POS("./PGraphicsRoot.hx",1372)
		::nme::geom::Point Pc_4 = _Function_1_6::Block(y4,x4,y3,x3);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1375)
		::nme::geom::Point Pa_1 = ::nme::geom::Point_obj::__new((double(((Pc_1->x + Pc_2->x))) / double((int)2)),(double(((Pc_1->y + Pc_2->y))) / double((int)2)));
		HX_SOURCE_POS("./PGraphicsRoot.hx",1376)
		::nme::geom::Point Pa_2 = ::nme::geom::Point_obj::__new((double(((PA->x + PB->x))) / double((int)2)),(double(((PA->y + PB->y))) / double((int)2)));
		HX_SOURCE_POS("./PGraphicsRoot.hx",1377)
		::nme::geom::Point Pa_3 = ::nme::geom::Point_obj::__new((double(((Pc_3->x + Pc_4->x))) / double((int)2)),(double(((Pc_3->y + Pc_4->y))) / double((int)2)));
		HX_SOURCE_POS("./PGraphicsRoot.hx",1380)
		this->shape->nmeGetGraphics()->curveTo(Pc_1->x,Pc_1->y,Pa_1->x,Pa_1->y);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1381)
		this->shape->nmeGetGraphics()->curveTo(Pc_2->x,Pc_2->y,Pa_2->x,Pa_2->y);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1382)
		this->shape->nmeGetGraphics()->curveTo(Pc_3->x,Pc_3->y,Pa_3->x,Pa_3->y);
		HX_SOURCE_POS("./PGraphicsRoot.hx",1383)
		this->shape->nmeGetGraphics()->curveTo(Pc_4->x,Pc_4->y,x4,y4);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(PGraphicsRoot_obj,drawCubicBezier2,(void))

::nme::geom::Point PGraphicsRoot_obj::getMiddle( double x1,double y1,double x2,double y2){
	HX_SOURCE_PUSH("PGraphicsRoot_obj::getMiddle")
	HX_SOURCE_POS("./PGraphicsRoot.hx",1388)
	return ::nme::geom::Point_obj::__new((double(((x1 + x2))) / double((int)2)),(double(((y1 + y2))) / double((int)2)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(PGraphicsRoot_obj,getMiddle,return )

::nme::geom::Point PGraphicsRoot_obj::getPointOnSegment( double x1,double y1,double x2,double y2,double ratio){
	HX_SOURCE_PUSH("PGraphicsRoot_obj::getPointOnSegment")
	HX_SOURCE_POS("./PGraphicsRoot.hx",1394)
	return ::nme::geom::Point_obj::__new((x1 + (((x2 - x1)) * ratio)),(y1 + (((y2 - y1)) * ratio)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(PGraphicsRoot_obj,getPointOnSegment,return )


PGraphicsRoot_obj::PGraphicsRoot_obj()
{
}

void PGraphicsRoot_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PGraphicsRoot);
	HX_MARK_MEMBER_NAME(bitmapPool,"bitmapPool");
	HX_MARK_MEMBER_NAME(newShapeNeeded,"newShapeNeeded");
	HX_MARK_MEMBER_NAME(pGraphicsAlpha,"pGraphicsAlpha");
	HX_MARK_MEMBER_NAME(PI,"PI");
	HX_MARK_MEMBER_NAME(TWO_PI,"TWO_PI");
	HX_MARK_MEMBER_NAME(HALF_PI,"HALF_PI");
	HX_MARK_MEMBER_NAME(P2D,"P2D");
	HX_MARK_MEMBER_NAME(P3D,"P3D");
	HX_MARK_MEMBER_NAME(CORNER,"CORNER");
	HX_MARK_MEMBER_NAME(RADIUS,"RADIUS");
	HX_MARK_MEMBER_NAME(CENTER_RADIUS,"CENTER_RADIUS");
	HX_MARK_MEMBER_NAME(CENTER,"CENTER");
	HX_MARK_MEMBER_NAME(POLYGON,"POLYGON");
	HX_MARK_MEMBER_NAME(QUADS,"QUADS");
	HX_MARK_MEMBER_NAME(TRIANGLES,"TRIANGLES");
	HX_MARK_MEMBER_NAME(POINTS,"POINTS");
	HX_MARK_MEMBER_NAME(LINES,"LINES");
	HX_MARK_MEMBER_NAME(TRIANGLE_STRIP,"TRIANGLE_STRIP");
	HX_MARK_MEMBER_NAME(TRIANGLE_FAN,"TRIANGLE_FAN");
	HX_MARK_MEMBER_NAME(QUAD_STRIP,"QUAD_STRIP");
	HX_MARK_MEMBER_NAME(CORNERS,"CORNERS");
	HX_MARK_MEMBER_NAME(CLOSE,"CLOSE");
	HX_MARK_MEMBER_NAME(RGB,"RGB");
	HX_MARK_MEMBER_NAME(HSB,"HSB");
	HX_MARK_MEMBER_NAME(hasBackground,"hasBackground");
	HX_MARK_MEMBER_NAME(curRectMode,"curRectMode");
	HX_MARK_MEMBER_NAME(curEllipseMode,"curEllipseMode");
	HX_MARK_MEMBER_NAME(curShape,"curShape");
	HX_MARK_MEMBER_NAME(curShapeCount,"curShapeCount");
	HX_MARK_MEMBER_NAME(opacityRange,"opacityRange");
	HX_MARK_MEMBER_NAME(redRange,"redRange");
	HX_MARK_MEMBER_NAME(greenRange,"greenRange");
	HX_MARK_MEMBER_NAME(blueRange,"blueRange");
	HX_MARK_MEMBER_NAME(pathOpen,"pathOpen");
	HX_MARK_MEMBER_NAME(mousePressed,"mousePressed");
	HX_MARK_MEMBER_NAME(keyPressed,"keyPressed");
	HX_MARK_MEMBER_NAME(firstX,"firstX");
	HX_MARK_MEMBER_NAME(firstY,"firstY");
	HX_MARK_MEMBER_NAME(secondX,"secondX");
	HX_MARK_MEMBER_NAME(secondY,"secondY");
	HX_MARK_MEMBER_NAME(prevX,"prevX");
	HX_MARK_MEMBER_NAME(prevY,"prevY");
	HX_MARK_MEMBER_NAME(curColorMode,"curColorMode");
	HX_MARK_MEMBER_NAME(tintColor,"tintColor");
	HX_MARK_MEMBER_NAME(curTextSize,"curTextSize");
	HX_MARK_MEMBER_NAME(curTextFont,"curTextFont");
	HX_MARK_MEMBER_NAME(doStroke,"doStroke");
	HX_MARK_MEMBER_NAME(curStrokeWeight,"curStrokeWeight");
	HX_MARK_MEMBER_NAME(curStrokeColor,"curStrokeColor");
	HX_MARK_MEMBER_NAME(tint,"tint");
	HX_MARK_MEMBER_NAME(doFill,"doFill");
	HX_MARK_MEMBER_NAME(curFillColor,"curFillColor");
	HX_MARK_MEMBER_NAME(shape,"shape");
	HX_MARK_MEMBER_NAME(shapeMatrix,"shapeMatrix");
	HX_MARK_MEMBER_NAME(doSmooth,"doSmooth");
	HX_MARK_MEMBER_NAME(trackingScaleX,"trackingScaleX");
	HX_MARK_MEMBER_NAME(trackingScaleY,"trackingScaleY");
	HX_MARK_MEMBER_NAME(trackingRotation,"trackingRotation");
	HX_MARK_MEMBER_NAME(trackingTranslationX,"trackingTranslationX");
	HX_MARK_MEMBER_NAME(trackingTranslationY,"trackingTranslationY");
	HX_MARK_MEMBER_NAME(matrixStack,"matrixStack");
	HX_MARK_MEMBER_NAME(trackingScaleXStack,"trackingScaleXStack");
	HX_MARK_MEMBER_NAME(trackingScaleYStack,"trackingScaleYStack");
	HX_MARK_MEMBER_NAME(trackingRotationStack,"trackingRotationStack");
	HX_MARK_MEMBER_NAME(trackingTranslationXStack,"trackingTranslationXStack");
	HX_MARK_MEMBER_NAME(trackingTranslationYStack,"trackingTranslationYStack");
	HX_MARK_MEMBER_NAME(curTightness,"curTightness");
	HX_MARK_MEMBER_NAME(curvePoints,"curvePoints");
	HX_MARK_MEMBER_NAME(curBackground,"curBackground");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic PGraphicsRoot_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
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
		if (HX_FIELD_EQ(inName,"tint") ) { return tint; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"QUADS") ) { return QUADS; }
		if (HX_FIELD_EQ(inName,"LINES") ) { return LINES; }
		if (HX_FIELD_EQ(inName,"CLOSE") ) { return CLOSE; }
		if (HX_FIELD_EQ(inName,"prevX") ) { return prevX; }
		if (HX_FIELD_EQ(inName,"prevY") ) { return prevY; }
		if (HX_FIELD_EQ(inName,"shape") ) { return shape; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"TWO_PI") ) { return TWO_PI; }
		if (HX_FIELD_EQ(inName,"CORNER") ) { return CORNER; }
		if (HX_FIELD_EQ(inName,"RADIUS") ) { return RADIUS; }
		if (HX_FIELD_EQ(inName,"CENTER") ) { return CENTER; }
		if (HX_FIELD_EQ(inName,"POINTS") ) { return POINTS; }
		if (HX_FIELD_EQ(inName,"firstX") ) { return firstX; }
		if (HX_FIELD_EQ(inName,"firstY") ) { return firstY; }
		if (HX_FIELD_EQ(inName,"doFill") ) { return doFill; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"HALF_PI") ) { return HALF_PI; }
		if (HX_FIELD_EQ(inName,"POLYGON") ) { return POLYGON; }
		if (HX_FIELD_EQ(inName,"CORNERS") ) { return CORNERS; }
		if (HX_FIELD_EQ(inName,"secondX") ) { return secondX; }
		if (HX_FIELD_EQ(inName,"secondY") ) { return secondY; }
		if (HX_FIELD_EQ(inName,"ellipse") ) { return ellipse_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"curShape") ) { return curShape; }
		if (HX_FIELD_EQ(inName,"redRange") ) { return redRange; }
		if (HX_FIELD_EQ(inName,"pathOpen") ) { return pathOpen; }
		if (HX_FIELD_EQ(inName,"doStroke") ) { return doStroke; }
		if (HX_FIELD_EQ(inName,"doSmooth") ) { return doSmooth; }
		if (HX_FIELD_EQ(inName,"getColor") ) { return getColor_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getMiddle") ) { return getMiddle_dyn(); }
		if (HX_FIELD_EQ(inName,"TRIANGLES") ) { return TRIANGLES; }
		if (HX_FIELD_EQ(inName,"blueRange") ) { return blueRange; }
		if (HX_FIELD_EQ(inName,"tintColor") ) { return tintColor; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapPool") ) { return bitmapPool; }
		if (HX_FIELD_EQ(inName,"QUAD_STRIP") ) { return QUAD_STRIP; }
		if (HX_FIELD_EQ(inName,"greenRange") ) { return greenRange; }
		if (HX_FIELD_EQ(inName,"keyPressed") ) { return keyPressed; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"curRectMode") ) { return curRectMode; }
		if (HX_FIELD_EQ(inName,"curTextSize") ) { return curTextSize; }
		if (HX_FIELD_EQ(inName,"curTextFont") ) { return curTextFont; }
		if (HX_FIELD_EQ(inName,"shapeMatrix") ) { return shapeMatrix; }
		if (HX_FIELD_EQ(inName,"matrixStack") ) { return matrixStack; }
		if (HX_FIELD_EQ(inName,"curvePoints") ) { return curvePoints; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TRIANGLE_FAN") ) { return TRIANGLE_FAN; }
		if (HX_FIELD_EQ(inName,"opacityRange") ) { return opacityRange; }
		if (HX_FIELD_EQ(inName,"mousePressed") ) { return mousePressed; }
		if (HX_FIELD_EQ(inName,"curColorMode") ) { return curColorMode; }
		if (HX_FIELD_EQ(inName,"curFillColor") ) { return curFillColor; }
		if (HX_FIELD_EQ(inName,"curTightness") ) { return curTightness; }
		if (HX_FIELD_EQ(inName,"getArgCount2") ) { return getArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"setArgCount3") ) { return setArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"sinArgCount1") ) { return sinArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"cosArgCount1") ) { return cosArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"redArgCount1") ) { return redArgCount1_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"CENTER_RADIUS") ) { return CENTER_RADIUS; }
		if (HX_FIELD_EQ(inName,"hasBackground") ) { return hasBackground; }
		if (HX_FIELD_EQ(inName,"curShapeCount") ) { return curShapeCount; }
		if (HX_FIELD_EQ(inName,"curBackground") ) { return curBackground; }
		if (HX_FIELD_EQ(inName,"tintArgCount3") ) { return tintArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"tintArgCount4") ) { return tintArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"blueArgCount1") ) { return blueArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"lineArgCount4") ) { return lineArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"rectArgCount4") ) { return rectArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"fillArgCount4") ) { return fillArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"fillArgCount3") ) { return fillArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"fillArgCount2") ) { return fillArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"fillArgCount1") ) { return fillArgCount1_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"newShapeNeeded") ) { return newShapeNeeded; }
		if (HX_FIELD_EQ(inName,"pGraphicsAlpha") ) { return pGraphicsAlpha; }
		if (HX_FIELD_EQ(inName,"TRIANGLE_STRIP") ) { return TRIANGLE_STRIP; }
		if (HX_FIELD_EQ(inName,"curEllipseMode") ) { return curEllipseMode; }
		if (HX_FIELD_EQ(inName,"curStrokeColor") ) { return curStrokeColor; }
		if (HX_FIELD_EQ(inName,"trackingScaleX") ) { return trackingScaleX; }
		if (HX_FIELD_EQ(inName,"trackingScaleY") ) { return trackingScaleY; }
		if (HX_FIELD_EQ(inName,"imageArgCount3") ) { return imageArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"greenArgCount1") ) { return greenArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"alphaArgCount1") ) { return alphaArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"colorArgCount1") ) { return colorArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"colorArgCount2") ) { return colorArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"colorArgCount3") ) { return colorArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"colorArgCount4") ) { return colorArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"scaleArgCount2") ) { return scaleArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"createNewShape") ) { return createNewShape_dyn(); }
		if (HX_FIELD_EQ(inName,"scaleArgCount1") ) { return scaleArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"pointArgCount2") ) { return pointArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"curveTightness") ) { return curveTightness_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"curStrokeWeight") ) { return curStrokeWeight; }
		if (HX_FIELD_EQ(inName,"smoothArgCount0") ) { return smoothArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"randomArgCount2") ) { return randomArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"noTintArgCount0") ) { return noTintArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"endAnyOpenFills") ) { return endAnyOpenFills_dyn(); }
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
		if (HX_FIELD_EQ(inName,"trackingRotation") ) { return trackingRotation; }
		if (HX_FIELD_EQ(inName,"endDrawArgCount0") ) { return endDrawArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"drawCubicBezier2") ) { return drawCubicBezier2_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getPointOnSegment") ) { return getPointOnSegment_dyn(); }
		if (HX_FIELD_EQ(inName,"beginShapeDrawing") ) { return beginShapeDrawing_dyn(); }
		if (HX_FIELD_EQ(inName,"triangleArgCount6") ) { return triangleArgCount6_dyn(); }
		if (HX_FIELD_EQ(inName,"noStrokeArgCount0") ) { return noStrokeArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"endShapeArgCount0") ) { return endShapeArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"endShapeArgCount1") ) { return endShapeArgCount1_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"beginDrawArgCount0") ) { return beginDrawArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"popMatrixArgCount0") ) { return popMatrixArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"translateArgCount2") ) { return translateArgCount2_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"trackingScaleXStack") ) { return trackingScaleXStack; }
		if (HX_FIELD_EQ(inName,"trackingScaleYStack") ) { return trackingScaleYStack; }
		if (HX_FIELD_EQ(inName,"backgroundArgCount4") ) { return backgroundArgCount4_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount3") ) { return backgroundArgCount3_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount2") ) { return backgroundArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount1") ) { return backgroundArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundArgCount0") ) { return backgroundArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"pushMatrixArgCount0") ) { return pushMatrixArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"beginShapeArgCount0") ) { return beginShapeArgCount0_dyn(); }
		if (HX_FIELD_EQ(inName,"beginShapeArgCount1") ) { return beginShapeArgCount1_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"trackingTranslationX") ) { return trackingTranslationX; }
		if (HX_FIELD_EQ(inName,"trackingTranslationY") ) { return trackingTranslationY; }
		if (HX_FIELD_EQ(inName,"ellipseModeArgCount1") ) { return ellipseModeArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"pGraphicsAlphaMethod") ) { return pGraphicsAlphaMethod_dyn(); }
		if (HX_FIELD_EQ(inName,"curveVertexArgCount2") ) { return curveVertexArgCount2_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"trackingRotationStack") ) { return trackingRotationStack; }
		if (HX_FIELD_EQ(inName,"strokeWeightArgCount1") ) { return strokeWeightArgCount1_dyn(); }
		if (HX_FIELD_EQ(inName,"bezierVertexArgCount6") ) { return bezierVertexArgCount6_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"createGraphicsArgCount3") ) { return createGraphicsArgCount3_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"trackingTranslationXStack") ) { return trackingTranslationXStack; }
		if (HX_FIELD_EQ(inName,"trackingTranslationYStack") ) { return trackingTranslationYStack; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"popMatrixWithoutCreatingNewShape") ) { return popMatrixWithoutCreatingNewShape_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"pushMatrixWithoutCreatingNewShape") ) { return pushMatrixWithoutCreatingNewShape_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PGraphicsRoot_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"PI") ) { PI=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"P2D") ) { P2D=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"P3D") ) { P3D=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RGB") ) { RGB=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HSB") ) { HSB=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tint") ) { tint=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"QUADS") ) { QUADS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LINES") ) { LINES=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CLOSE") ) { CLOSE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"prevX") ) { prevX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"prevY") ) { prevY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shape") ) { shape=inValue.Cast< ::nme::display::Shape >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"TWO_PI") ) { TWO_PI=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CORNER") ) { CORNER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RADIUS") ) { RADIUS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CENTER") ) { CENTER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"POINTS") ) { POINTS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstX") ) { firstX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"firstY") ) { firstY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"doFill") ) { doFill=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"HALF_PI") ) { HALF_PI=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"POLYGON") ) { POLYGON=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CORNERS") ) { CORNERS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"secondX") ) { secondX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"secondY") ) { secondY=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"curShape") ) { curShape=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"redRange") ) { redRange=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pathOpen") ) { pathOpen=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"doStroke") ) { doStroke=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"doSmooth") ) { doSmooth=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"TRIANGLES") ) { TRIANGLES=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blueRange") ) { blueRange=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tintColor") ) { tintColor=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapPool") ) { bitmapPool=inValue.Cast< ::ProcessingHaxeBitmapPool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"QUAD_STRIP") ) { QUAD_STRIP=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"greenRange") ) { greenRange=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keyPressed") ) { keyPressed=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"curRectMode") ) { curRectMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curTextSize") ) { curTextSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curTextFont") ) { curTextFont=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shapeMatrix") ) { shapeMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		if (HX_FIELD_EQ(inName,"matrixStack") ) { matrixStack=inValue.Cast< Array< ::nme::geom::Matrix > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curvePoints") ) { curvePoints=inValue.Cast< Array< ::nme::geom::Point > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TRIANGLE_FAN") ) { TRIANGLE_FAN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"opacityRange") ) { opacityRange=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mousePressed") ) { mousePressed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curColorMode") ) { curColorMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curFillColor") ) { curFillColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curTightness") ) { curTightness=inValue.Cast< double >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"CENTER_RADIUS") ) { CENTER_RADIUS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hasBackground") ) { hasBackground=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curShapeCount") ) { curShapeCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curBackground") ) { curBackground=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"newShapeNeeded") ) { newShapeNeeded=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pGraphicsAlpha") ) { pGraphicsAlpha=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TRIANGLE_STRIP") ) { TRIANGLE_STRIP=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curEllipseMode") ) { curEllipseMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curStrokeColor") ) { curStrokeColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"trackingScaleX") ) { trackingScaleX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"trackingScaleY") ) { trackingScaleY=inValue.Cast< double >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"curStrokeWeight") ) { curStrokeWeight=inValue.Cast< double >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"trackingRotation") ) { trackingRotation=inValue.Cast< double >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"trackingScaleXStack") ) { trackingScaleXStack=inValue.Cast< Array< double > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"trackingScaleYStack") ) { trackingScaleYStack=inValue.Cast< Array< double > >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"trackingTranslationX") ) { trackingTranslationX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"trackingTranslationY") ) { trackingTranslationY=inValue.Cast< double >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"trackingRotationStack") ) { trackingRotationStack=inValue.Cast< Array< double > >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"trackingTranslationXStack") ) { trackingTranslationXStack=inValue.Cast< Array< double > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"trackingTranslationYStack") ) { trackingTranslationYStack=inValue.Cast< Array< double > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PGraphicsRoot_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bitmapPool"));
	outFields->push(HX_CSTRING("newShapeNeeded"));
	outFields->push(HX_CSTRING("pGraphicsAlpha"));
	outFields->push(HX_CSTRING("PI"));
	outFields->push(HX_CSTRING("TWO_PI"));
	outFields->push(HX_CSTRING("HALF_PI"));
	outFields->push(HX_CSTRING("P2D"));
	outFields->push(HX_CSTRING("P3D"));
	outFields->push(HX_CSTRING("CORNER"));
	outFields->push(HX_CSTRING("RADIUS"));
	outFields->push(HX_CSTRING("CENTER_RADIUS"));
	outFields->push(HX_CSTRING("CENTER"));
	outFields->push(HX_CSTRING("POLYGON"));
	outFields->push(HX_CSTRING("QUADS"));
	outFields->push(HX_CSTRING("TRIANGLES"));
	outFields->push(HX_CSTRING("POINTS"));
	outFields->push(HX_CSTRING("LINES"));
	outFields->push(HX_CSTRING("TRIANGLE_STRIP"));
	outFields->push(HX_CSTRING("TRIANGLE_FAN"));
	outFields->push(HX_CSTRING("QUAD_STRIP"));
	outFields->push(HX_CSTRING("CORNERS"));
	outFields->push(HX_CSTRING("CLOSE"));
	outFields->push(HX_CSTRING("RGB"));
	outFields->push(HX_CSTRING("HSB"));
	outFields->push(HX_CSTRING("hasBackground"));
	outFields->push(HX_CSTRING("curRectMode"));
	outFields->push(HX_CSTRING("curEllipseMode"));
	outFields->push(HX_CSTRING("curShape"));
	outFields->push(HX_CSTRING("curShapeCount"));
	outFields->push(HX_CSTRING("opacityRange"));
	outFields->push(HX_CSTRING("redRange"));
	outFields->push(HX_CSTRING("greenRange"));
	outFields->push(HX_CSTRING("blueRange"));
	outFields->push(HX_CSTRING("pathOpen"));
	outFields->push(HX_CSTRING("mousePressed"));
	outFields->push(HX_CSTRING("keyPressed"));
	outFields->push(HX_CSTRING("firstX"));
	outFields->push(HX_CSTRING("firstY"));
	outFields->push(HX_CSTRING("secondX"));
	outFields->push(HX_CSTRING("secondY"));
	outFields->push(HX_CSTRING("prevX"));
	outFields->push(HX_CSTRING("prevY"));
	outFields->push(HX_CSTRING("curColorMode"));
	outFields->push(HX_CSTRING("tintColor"));
	outFields->push(HX_CSTRING("curTextSize"));
	outFields->push(HX_CSTRING("curTextFont"));
	outFields->push(HX_CSTRING("doStroke"));
	outFields->push(HX_CSTRING("curStrokeWeight"));
	outFields->push(HX_CSTRING("curStrokeColor"));
	outFields->push(HX_CSTRING("tint"));
	outFields->push(HX_CSTRING("doFill"));
	outFields->push(HX_CSTRING("curFillColor"));
	outFields->push(HX_CSTRING("shape"));
	outFields->push(HX_CSTRING("shapeMatrix"));
	outFields->push(HX_CSTRING("doSmooth"));
	outFields->push(HX_CSTRING("trackingScaleX"));
	outFields->push(HX_CSTRING("trackingScaleY"));
	outFields->push(HX_CSTRING("trackingRotation"));
	outFields->push(HX_CSTRING("trackingTranslationX"));
	outFields->push(HX_CSTRING("trackingTranslationY"));
	outFields->push(HX_CSTRING("matrixStack"));
	outFields->push(HX_CSTRING("trackingScaleXStack"));
	outFields->push(HX_CSTRING("trackingScaleYStack"));
	outFields->push(HX_CSTRING("trackingRotationStack"));
	outFields->push(HX_CSTRING("trackingTranslationXStack"));
	outFields->push(HX_CSTRING("trackingTranslationYStack"));
	outFields->push(HX_CSTRING("curTightness"));
	outFields->push(HX_CSTRING("curvePoints"));
	outFields->push(HX_CSTRING("curBackground"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getMiddle"),
	HX_CSTRING("getPointOnSegment"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bitmapPool"),
	HX_CSTRING("newShapeNeeded"),
	HX_CSTRING("pGraphicsAlpha"),
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
	HX_CSTRING("hasBackground"),
	HX_CSTRING("curRectMode"),
	HX_CSTRING("curEllipseMode"),
	HX_CSTRING("curShape"),
	HX_CSTRING("curShapeCount"),
	HX_CSTRING("opacityRange"),
	HX_CSTRING("redRange"),
	HX_CSTRING("greenRange"),
	HX_CSTRING("blueRange"),
	HX_CSTRING("pathOpen"),
	HX_CSTRING("mousePressed"),
	HX_CSTRING("keyPressed"),
	HX_CSTRING("firstX"),
	HX_CSTRING("firstY"),
	HX_CSTRING("secondX"),
	HX_CSTRING("secondY"),
	HX_CSTRING("prevX"),
	HX_CSTRING("prevY"),
	HX_CSTRING("curColorMode"),
	HX_CSTRING("tintColor"),
	HX_CSTRING("curTextSize"),
	HX_CSTRING("curTextFont"),
	HX_CSTRING("doStroke"),
	HX_CSTRING("curStrokeWeight"),
	HX_CSTRING("curStrokeColor"),
	HX_CSTRING("tint"),
	HX_CSTRING("doFill"),
	HX_CSTRING("curFillColor"),
	HX_CSTRING("shape"),
	HX_CSTRING("shapeMatrix"),
	HX_CSTRING("doSmooth"),
	HX_CSTRING("trackingScaleX"),
	HX_CSTRING("trackingScaleY"),
	HX_CSTRING("trackingRotation"),
	HX_CSTRING("trackingTranslationX"),
	HX_CSTRING("trackingTranslationY"),
	HX_CSTRING("matrixStack"),
	HX_CSTRING("trackingScaleXStack"),
	HX_CSTRING("trackingScaleYStack"),
	HX_CSTRING("trackingRotationStack"),
	HX_CSTRING("trackingTranslationXStack"),
	HX_CSTRING("trackingTranslationYStack"),
	HX_CSTRING("curTightness"),
	HX_CSTRING("curvePoints"),
	HX_CSTRING("curBackground"),
	HX_CSTRING("getArgCount2"),
	HX_CSTRING("setArgCount3"),
	HX_CSTRING("ellipseModeArgCount1"),
	HX_CSTRING("smoothArgCount0"),
	HX_CSTRING("endDrawArgCount0"),
	HX_CSTRING("beginDrawArgCount0"),
	HX_CSTRING("sinArgCount1"),
	HX_CSTRING("cosArgCount1"),
	HX_CSTRING("randomArgCount2"),
	HX_CSTRING("backgroundArgCount4"),
	HX_CSTRING("backgroundArgCount3"),
	HX_CSTRING("backgroundArgCount2"),
	HX_CSTRING("backgroundArgCount1"),
	HX_CSTRING("backgroundArgCount0"),
	HX_CSTRING("imageArgCount3"),
	HX_CSTRING("noTintArgCount0"),
	HX_CSTRING("tintArgCount3"),
	HX_CSTRING("tintArgCount4"),
	HX_CSTRING("createGraphicsArgCount3"),
	HX_CSTRING("redArgCount1"),
	HX_CSTRING("greenArgCount1"),
	HX_CSTRING("blueArgCount1"),
	HX_CSTRING("alphaArgCount1"),
	HX_CSTRING("pGraphicsAlphaMethod"),
	HX_CSTRING("beginShapeDrawing"),
	HX_CSTRING("endAnyOpenFills"),
	HX_CSTRING("lineArgCount4"),
	HX_CSTRING("rectArgCount4"),
	HX_CSTRING("triangleArgCount6"),
	HX_CSTRING("ellipse"),
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
	HX_CSTRING("colorArgCount1"),
	HX_CSTRING("colorArgCount2"),
	HX_CSTRING("colorArgCount3"),
	HX_CSTRING("colorArgCount4"),
	HX_CSTRING("getColor"),
	HX_CSTRING("pushMatrixWithoutCreatingNewShape"),
	HX_CSTRING("pushMatrixArgCount0"),
	HX_CSTRING("popMatrixWithoutCreatingNewShape"),
	HX_CSTRING("popMatrixArgCount0"),
	HX_CSTRING("rotateArgCount1"),
	HX_CSTRING("scaleArgCount2"),
	HX_CSTRING("createNewShape"),
	HX_CSTRING("scaleArgCount1"),
	HX_CSTRING("translateArgCount2"),
	HX_CSTRING("strokeWeightArgCount1"),
	HX_CSTRING("pointArgCount2"),
	HX_CSTRING("beginShapeArgCount0"),
	HX_CSTRING("beginShapeArgCount1"),
	HX_CSTRING("endShapeArgCount0"),
	HX_CSTRING("endShapeArgCount1"),
	HX_CSTRING("vertexArgCount2"),
	HX_CSTRING("vertexArgCount4"),
	HX_CSTRING("vertexArgCount6"),
	HX_CSTRING("bezierVertexArgCount6"),
	HX_CSTRING("curveVertexArgCount2"),
	HX_CSTRING("curveTightness"),
	HX_CSTRING("bezierArgCount8"),
	HX_CSTRING("drawCubicBezier2"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PGraphicsRoot_obj::__mClass;

void PGraphicsRoot_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("PGraphicsRoot"), hx::TCanCast< PGraphicsRoot_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PGraphicsRoot_obj::__boot()
{
}

