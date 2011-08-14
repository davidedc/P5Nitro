#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_GradientType
#include <nme/display/GradientType.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_IGraphicsData
#include <nme/display/IGraphicsData.h>
#endif
#ifndef INCLUDED_nme_display_InterpolationMethod
#include <nme/display/InterpolationMethod.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_SpreadMethod
#include <nme/display/SpreadMethod.h>
#endif
#ifndef INCLUDED_nme_display_Tilesheet
#include <nme/display/Tilesheet.h>
#endif
#ifndef INCLUDED_nme_display_TriangleCulling
#include <nme/display/TriangleCulling.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
namespace nme{
namespace display{

Void Graphics_obj::__construct(Dynamic inHandle)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",11)
	this->nmeHandle = inHandle;
}
;
	return null();
}

Graphics_obj::~Graphics_obj() { }

Dynamic Graphics_obj::__CreateEmpty() { return  new Graphics_obj; }
hx::ObjectPtr< Graphics_obj > Graphics_obj::__new(Dynamic inHandle)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inHandle);
	return result;}

Dynamic Graphics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Graphics_obj::beginFill( int color,Dynamic __o_alpha){
double alpha = __o_alpha.Default(1.0);
	HX_SOURCE_PUSH("Graphics_obj::beginFill");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",16)
		::nme::display::Graphics_obj::nme_gfx_begin_fill(this->nmeHandle,color,alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,beginFill,(void))

Void Graphics_obj::beginBitmapFill( ::nme::display::BitmapData bitmap,::nme::geom::Matrix matrix,Dynamic __o_repeat,Dynamic __o_smooth){
bool repeat = __o_repeat.Default(true);
bool smooth = __o_smooth.Default(false);
	HX_SOURCE_PUSH("Graphics_obj::beginBitmapFill");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",22)
		::nme::display::Graphics_obj::nme_gfx_begin_bitmap_fill(this->nmeHandle,bitmap->nmeHandle,matrix,repeat,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,beginBitmapFill,(void))

Void Graphics_obj::lineBitmapStyle( ::nme::display::BitmapData bitmap,::nme::geom::Matrix matrix,Dynamic __o_repeat,Dynamic __o_smooth){
bool repeat = __o_repeat.Default(true);
bool smooth = __o_smooth.Default(false);
	HX_SOURCE_PUSH("Graphics_obj::lineBitmapStyle");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",28)
		::nme::display::Graphics_obj::nme_gfx_line_bitmap_fill(this->nmeHandle,bitmap->nmeHandle,matrix,repeat,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,lineBitmapStyle,(void))

Void Graphics_obj::beginGradientFill( ::nme::display::GradientType type,Array< Dynamic > colors,Array< Dynamic > alphas,Array< Dynamic > ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic __o_focalPointRatio){
double focalPointRatio = __o_focalPointRatio.Default(0.0);
	HX_SOURCE_PUSH("Graphics_obj::beginGradientFill");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",42)
		if (((matrix == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",44)
			matrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",45)
			matrix->createGradientBox((int)200,(int)200,(int)0,(int)-100,(int)-100);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",47)
		::nme::display::Graphics_obj::nme_gfx_begin_gradient_fill(this->nmeHandle,type->__Index(),colors,alphas,ratios,matrix,(  (((spreadMethod == null()))) ? int((int)0) : int(spreadMethod->__Index()) ),(  (((interpolationMethod == null()))) ? int((int)0) : int(interpolationMethod->__Index()) ),focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,beginGradientFill,(void))

Void Graphics_obj::lineGradientStyle( ::nme::display::GradientType type,Array< Dynamic > colors,Array< Dynamic > alphas,Array< Dynamic > ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic __o_focalPointRatio){
double focalPointRatio = __o_focalPointRatio.Default(0.0);
	HX_SOURCE_PUSH("Graphics_obj::lineGradientStyle");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",63)
		if (((matrix == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",65)
			matrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",66)
			matrix->createGradientBox((int)200,(int)200,(int)0,(int)-100,(int)-100);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",68)
		::nme::display::Graphics_obj::nme_gfx_line_gradient_fill(this->nmeHandle,type->__Index(),colors,alphas,ratios,matrix,(  (((spreadMethod == null()))) ? int((int)0) : int(spreadMethod->__Index()) ),(  (((interpolationMethod == null()))) ? int((int)0) : int(interpolationMethod->__Index()) ),focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineGradientStyle,(void))

Void Graphics_obj::endFill( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::endFill")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",78)
		::nme::display::Graphics_obj::nme_gfx_end_fill(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,endFill,(void))

Void Graphics_obj::clear( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::clear")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",83)
		::nme::display::Graphics_obj::nme_gfx_clear(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,clear,(void))

Void Graphics_obj::lineStyle( Dynamic thickness,Dynamic __o_color,Dynamic __o_alpha,Dynamic __o_pixelHinting,::nme::display::LineScaleMode scaleMode,::nme::display::CapsStyle caps,::nme::display::JointStyle joints,Dynamic __o_miterLimit){
int color = __o_color.Default(0);
double alpha = __o_alpha.Default(1.0);
bool pixelHinting = __o_pixelHinting.Default(false);
double miterLimit = __o_miterLimit.Default(3);
	HX_SOURCE_PUSH("Graphics_obj::lineStyle");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",90)
		::nme::display::Graphics_obj::nme_gfx_line_style(this->nmeHandle,thickness,color,alpha,pixelHinting,(  (((scaleMode == null()))) ? int((int)0) : int(scaleMode->__Index()) ),(  (((caps == null()))) ? int((int)0) : int(caps->__Index()) ),(  (((joints == null()))) ? int((int)0) : int(joints->__Index()) ),miterLimit);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineStyle,(void))

Void Graphics_obj::moveTo( double inX,double inY){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::moveTo")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",102)
		::nme::display::Graphics_obj::nme_gfx_move_to(this->nmeHandle,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,moveTo,(void))

Void Graphics_obj::lineTo( double inX,double inY){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::lineTo")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",107)
		::nme::display::Graphics_obj::nme_gfx_line_to(this->nmeHandle,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,lineTo,(void))

Void Graphics_obj::curveTo( double inCX,double inCY,double inX,double inY){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::curveTo")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",112)
		::nme::display::Graphics_obj::nme_gfx_curve_to(this->nmeHandle,inCX,inCY,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,curveTo,(void))

Void Graphics_obj::arcTo( double inCX,double inCY,double inX,double inY){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::arcTo")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",117)
		::nme::display::Graphics_obj::nme_gfx_arc_to(this->nmeHandle,inCX,inCY,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,arcTo,(void))

Void Graphics_obj::drawEllipse( double inX,double inY,double inWidth,double inHeight){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::drawEllipse")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",122)
		::nme::display::Graphics_obj::nme_gfx_draw_ellipse(this->nmeHandle,inX,inY,inWidth,inHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawEllipse,(void))

Void Graphics_obj::drawCircle( double inX,double inY,double inRadius){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::drawCircle")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",127)
		::nme::display::Graphics_obj::nme_gfx_draw_ellipse(this->nmeHandle,inX,inY,inRadius,inRadius);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Graphics_obj,drawCircle,(void))

Void Graphics_obj::drawRect( double inX,double inY,double inWidth,double inHeight){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::drawRect")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",132)
		::nme::display::Graphics_obj::nme_gfx_draw_rect(this->nmeHandle,inX,inY,inWidth,inHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawRect,(void))

Void Graphics_obj::drawRoundRect( double inX,double inY,double inWidth,double inHeight,double inRadX,Dynamic inRadY){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::drawRoundRect")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",138)
		::nme::display::Graphics_obj::nme_gfx_draw_round_rect(this->nmeHandle,inX,inY,inWidth,inHeight,inRadX,(  (((inRadY == null()))) ? Dynamic(inRadX) : Dynamic(inRadY) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Graphics_obj,drawRoundRect,(void))

Void Graphics_obj::drawTriangles( Array< double > vertices,Array< int > indices,Array< double > uvtData,::nme::display::TriangleCulling culling){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::drawTriangles")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",147)
		int cull = (  (((culling == null()))) ? int((int)0) : int((culling->__Index() - (int)1)) );
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",149)
		::nme::display::Graphics_obj::nme_gfx_draw_triangles(this->nmeHandle,vertices,indices,uvtData,cull);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawTriangles,(void))

Void Graphics_obj::drawGraphicsData( Array< ::nme::display::IGraphicsData > graphicsData){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::drawGraphicsData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",155)
		Array< Dynamic > handles = Array_obj< Dynamic >::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",156)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",156)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",156)
			while((_g < graphicsData->length)){
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",156)
				::nme::display::IGraphicsData datum = graphicsData->__get(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",156)
				++(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",157)
				handles->push(datum->nmeHandle);
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",158)
		::nme::display::Graphics_obj::nme_gfx_draw_data(this->nmeHandle,handles);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,drawGraphicsData,(void))

Void Graphics_obj::drawGraphicsDatum( ::nme::display::IGraphicsData graphicsDatum){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Graphics_obj::drawGraphicsDatum")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",163)
		::nme::display::Graphics_obj::nme_gfx_draw_datum(this->nmeHandle,graphicsDatum->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,drawGraphicsDatum,(void))

Void Graphics_obj::drawTiles( ::nme::display::Tilesheet sheet,Array< double > inXYID,Dynamic __o_inSmooth){
bool inSmooth = __o_inSmooth.Default(false);
	HX_SOURCE_PUSH("Graphics_obj::drawTiles");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",168)
		this->beginBitmapFill(sheet->nmeBitmap,null(),false,inSmooth);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",169)
		::nme::display::Graphics_obj::nme_gfx_draw_tiles(this->nmeHandle,sheet->nmeHandle,inXYID);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Graphics_obj,drawTiles,(void))

Void Graphics_obj::drawPoints( Array< double > inXY,Array< int > inPointRGBA,Dynamic __o_inDefaultRGBA,Dynamic __o_inSize){
int inDefaultRGBA = __o_inDefaultRGBA.Default(-1);
double inSize = __o_inSize.Default(-1.0);
	HX_SOURCE_PUSH("Graphics_obj::drawPoints");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",183)
		::nme::display::Graphics_obj::nme_gfx_draw_points(this->nmeHandle,inXY,inPointRGBA,inDefaultRGBA,false,inSize);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawPoints,(void))

int Graphics_obj::RGBA( int inRGB,Dynamic __o_inA){
int inA = __o_inA.Default(255);
	HX_SOURCE_PUSH("Graphics_obj::RGBA");
{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Graphics.hx",177)
		return (int(inRGB) | int((int(inA) << int((int)24))));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,RGBA,return )

Dynamic Graphics_obj::nme_gfx_clear;

Dynamic Graphics_obj::nme_gfx_begin_fill;

Dynamic Graphics_obj::nme_gfx_begin_bitmap_fill;

Dynamic Graphics_obj::nme_gfx_line_bitmap_fill;

Dynamic Graphics_obj::nme_gfx_begin_gradient_fill;

Dynamic Graphics_obj::nme_gfx_line_gradient_fill;

Dynamic Graphics_obj::nme_gfx_end_fill;

Dynamic Graphics_obj::nme_gfx_line_style;

Dynamic Graphics_obj::nme_gfx_move_to;

Dynamic Graphics_obj::nme_gfx_line_to;

Dynamic Graphics_obj::nme_gfx_curve_to;

Dynamic Graphics_obj::nme_gfx_arc_to;

Dynamic Graphics_obj::nme_gfx_draw_ellipse;

Dynamic Graphics_obj::nme_gfx_draw_data;

Dynamic Graphics_obj::nme_gfx_draw_datum;

Dynamic Graphics_obj::nme_gfx_draw_rect;

Dynamic Graphics_obj::nme_gfx_draw_tiles;

Dynamic Graphics_obj::nme_gfx_draw_points;

Dynamic Graphics_obj::nme_gfx_draw_round_rect;

Dynamic Graphics_obj::nme_gfx_draw_triangles;


Graphics_obj::Graphics_obj()
{
}

void Graphics_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Graphics);
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_END_CLASS();
}

Dynamic Graphics_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"RGBA") ) { return RGBA_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"arcTo") ) { return arcTo_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		if (HX_FIELD_EQ(inName,"lineTo") ) { return lineTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		if (HX_FIELD_EQ(inName,"curveTo") ) { return curveTo_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"drawRect") ) { return drawRect_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"beginFill") ) { return beginFill_dyn(); }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { return lineStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTiles") ) { return drawTiles_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPoints") ) { return drawPoints_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"drawEllipse") ) { return drawEllipse_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nme_gfx_clear") ) { return nme_gfx_clear; }
		if (HX_FIELD_EQ(inName,"drawRoundRect") ) { return drawRoundRect_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTriangles") ) { return drawTriangles_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nme_gfx_arc_to") ) { return nme_gfx_arc_to; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_gfx_move_to") ) { return nme_gfx_move_to; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_to") ) { return nme_gfx_line_to; }
		if (HX_FIELD_EQ(inName,"beginBitmapFill") ) { return beginBitmapFill_dyn(); }
		if (HX_FIELD_EQ(inName,"lineBitmapStyle") ) { return lineBitmapStyle_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_gfx_end_fill") ) { return nme_gfx_end_fill; }
		if (HX_FIELD_EQ(inName,"nme_gfx_curve_to") ) { return nme_gfx_curve_to; }
		if (HX_FIELD_EQ(inName,"drawGraphicsData") ) { return drawGraphicsData_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_data") ) { return nme_gfx_draw_data; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_rect") ) { return nme_gfx_draw_rect; }
		if (HX_FIELD_EQ(inName,"beginGradientFill") ) { return beginGradientFill_dyn(); }
		if (HX_FIELD_EQ(inName,"lineGradientStyle") ) { return lineGradientStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"drawGraphicsDatum") ) { return drawGraphicsDatum_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_fill") ) { return nme_gfx_begin_fill; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_style") ) { return nme_gfx_line_style; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_datum") ) { return nme_gfx_draw_datum; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_tiles") ) { return nme_gfx_draw_tiles; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_points") ) { return nme_gfx_draw_points; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_ellipse") ) { return nme_gfx_draw_ellipse; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_triangles") ) { return nme_gfx_draw_triangles; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_round_rect") ) { return nme_gfx_draw_round_rect; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_bitmap_fill") ) { return nme_gfx_line_bitmap_fill; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_bitmap_fill") ) { return nme_gfx_begin_bitmap_fill; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_gradient_fill") ) { return nme_gfx_line_gradient_fill; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_gradient_fill") ) { return nme_gfx_begin_gradient_fill; }
	}
	return super::__Field(inName);
}

Dynamic Graphics_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nme_gfx_clear") ) { nme_gfx_clear=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nme_gfx_arc_to") ) { nme_gfx_arc_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_gfx_move_to") ) { nme_gfx_move_to=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_to") ) { nme_gfx_line_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_gfx_end_fill") ) { nme_gfx_end_fill=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_curve_to") ) { nme_gfx_curve_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_data") ) { nme_gfx_draw_data=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_rect") ) { nme_gfx_draw_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_fill") ) { nme_gfx_begin_fill=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_style") ) { nme_gfx_line_style=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_datum") ) { nme_gfx_draw_datum=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_tiles") ) { nme_gfx_draw_tiles=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_points") ) { nme_gfx_draw_points=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_ellipse") ) { nme_gfx_draw_ellipse=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_triangles") ) { nme_gfx_draw_triangles=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_round_rect") ) { nme_gfx_draw_round_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_bitmap_fill") ) { nme_gfx_line_bitmap_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_bitmap_fill") ) { nme_gfx_begin_bitmap_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_gradient_fill") ) { nme_gfx_line_gradient_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_gradient_fill") ) { nme_gfx_begin_gradient_fill=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Graphics_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeHandle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("RGBA"),
	HX_CSTRING("nme_gfx_clear"),
	HX_CSTRING("nme_gfx_begin_fill"),
	HX_CSTRING("nme_gfx_begin_bitmap_fill"),
	HX_CSTRING("nme_gfx_line_bitmap_fill"),
	HX_CSTRING("nme_gfx_begin_gradient_fill"),
	HX_CSTRING("nme_gfx_line_gradient_fill"),
	HX_CSTRING("nme_gfx_end_fill"),
	HX_CSTRING("nme_gfx_line_style"),
	HX_CSTRING("nme_gfx_move_to"),
	HX_CSTRING("nme_gfx_line_to"),
	HX_CSTRING("nme_gfx_curve_to"),
	HX_CSTRING("nme_gfx_arc_to"),
	HX_CSTRING("nme_gfx_draw_ellipse"),
	HX_CSTRING("nme_gfx_draw_data"),
	HX_CSTRING("nme_gfx_draw_datum"),
	HX_CSTRING("nme_gfx_draw_rect"),
	HX_CSTRING("nme_gfx_draw_tiles"),
	HX_CSTRING("nme_gfx_draw_points"),
	HX_CSTRING("nme_gfx_draw_round_rect"),
	HX_CSTRING("nme_gfx_draw_triangles"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("beginFill"),
	HX_CSTRING("beginBitmapFill"),
	HX_CSTRING("lineBitmapStyle"),
	HX_CSTRING("beginGradientFill"),
	HX_CSTRING("lineGradientStyle"),
	HX_CSTRING("endFill"),
	HX_CSTRING("clear"),
	HX_CSTRING("lineStyle"),
	HX_CSTRING("moveTo"),
	HX_CSTRING("lineTo"),
	HX_CSTRING("curveTo"),
	HX_CSTRING("arcTo"),
	HX_CSTRING("drawEllipse"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawRect"),
	HX_CSTRING("drawRoundRect"),
	HX_CSTRING("drawTriangles"),
	HX_CSTRING("drawGraphicsData"),
	HX_CSTRING("drawGraphicsDatum"),
	HX_CSTRING("drawTiles"),
	HX_CSTRING("drawPoints"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_clear,"nme_gfx_clear");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_fill,"nme_gfx_begin_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_bitmap_fill,"nme_gfx_begin_bitmap_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_bitmap_fill,"nme_gfx_line_bitmap_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_gradient_fill,"nme_gfx_begin_gradient_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_gradient_fill,"nme_gfx_line_gradient_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_end_fill,"nme_gfx_end_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_style,"nme_gfx_line_style");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_move_to,"nme_gfx_move_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_to,"nme_gfx_line_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_curve_to,"nme_gfx_curve_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_arc_to,"nme_gfx_arc_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_ellipse,"nme_gfx_draw_ellipse");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_data,"nme_gfx_draw_data");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_datum,"nme_gfx_draw_datum");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_rect,"nme_gfx_draw_rect");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_tiles,"nme_gfx_draw_tiles");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_points,"nme_gfx_draw_points");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_round_rect,"nme_gfx_draw_round_rect");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_triangles,"nme_gfx_draw_triangles");
};

Class Graphics_obj::__mClass;

void Graphics_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.Graphics"), hx::TCanCast< Graphics_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Graphics_obj::__boot()
{
	hx::Static(nme_gfx_clear) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_clear"),(int)1);
	hx::Static(nme_gfx_begin_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_begin_fill"),(int)3);
	hx::Static(nme_gfx_begin_bitmap_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_begin_bitmap_fill"),(int)5);
	hx::Static(nme_gfx_line_bitmap_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_line_bitmap_fill"),(int)5);
	hx::Static(nme_gfx_begin_gradient_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_begin_gradient_fill"),(int)-1);
	hx::Static(nme_gfx_line_gradient_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_line_gradient_fill"),(int)-1);
	hx::Static(nme_gfx_end_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_end_fill"),(int)1);
	hx::Static(nme_gfx_line_style) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_line_style"),(int)-1);
	hx::Static(nme_gfx_move_to) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_move_to"),(int)3);
	hx::Static(nme_gfx_line_to) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_line_to"),(int)3);
	hx::Static(nme_gfx_curve_to) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_curve_to"),(int)5);
	hx::Static(nme_gfx_arc_to) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_arc_to"),(int)5);
	hx::Static(nme_gfx_draw_ellipse) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_ellipse"),(int)5);
	hx::Static(nme_gfx_draw_data) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_data"),(int)2);
	hx::Static(nme_gfx_draw_datum) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_datum"),(int)2);
	hx::Static(nme_gfx_draw_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_rect"),(int)5);
	hx::Static(nme_gfx_draw_tiles) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_tiles"),(int)3);
	hx::Static(nme_gfx_draw_points) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_points"),(int)-1);
	hx::Static(nme_gfx_draw_round_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_round_rect"),(int)-1);
	hx::Static(nme_gfx_draw_triangles) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_triangles"),(int)5);
}

} // end namespace nme
} // end namespace display
