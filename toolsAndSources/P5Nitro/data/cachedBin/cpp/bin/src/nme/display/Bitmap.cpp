#include <hxcpp.h>

#ifndef INCLUDED_nme_display_Bitmap
#include <nme/display/Bitmap.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_PixelSnapping
#include <nme/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
namespace nme{
namespace display{

Void Bitmap_obj::__construct(::nme::display::BitmapData inBitmapData,::nme::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",14)
	super::__construct(::nme::display::DisplayObject_obj::nme_create_display_object(),HX_CSTRING("Bitmap"));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",15)
	this->pixelSnapping = inPixelSnapping;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",16)
	this->smoothing = inSmoothing;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",17)
	this->nmeSetBitmapData(inBitmapData);
}
;
	return null();
}

Bitmap_obj::~Bitmap_obj() { }

Dynamic Bitmap_obj::__CreateEmpty() { return  new Bitmap_obj; }
hx::ObjectPtr< Bitmap_obj > Bitmap_obj::__new(::nme::display::BitmapData inBitmapData,::nme::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inBitmapData,inPixelSnapping,inSmoothing);
	return result;}

Dynamic Bitmap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::nme::display::BitmapData Bitmap_obj::nmeSetBitmapData( ::nme::display::BitmapData inBitmapData){
	__SAFE_POINT
	HX_SOURCE_PUSH("Bitmap_obj::nmeSetBitmapData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",22)
	::nme::display::Graphics gfx = this->nmeGetGraphics();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",23)
	gfx->clear();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",24)
	this->bitmapData = inBitmapData;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",25)
	if (((inBitmapData != null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",27)
		gfx->beginBitmapFill(inBitmapData,null(),false,this->smoothing);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",28)
		gfx->drawRect((int)0,(int)0,inBitmapData->nmeGetWidth(),inBitmapData->nmeGetHeight());
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",29)
		gfx->endFill();
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/Bitmap.hx",31)
	return inBitmapData;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,nmeSetBitmapData,return )


Bitmap_obj::Bitmap_obj()
{
}

void Bitmap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bitmap);
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_MEMBER_NAME(pixelSnapping,"pixelSnapping");
	HX_MARK_MEMBER_NAME(smoothing,"smoothing");
	HX_MARK_MEMBER_NAME(mGraphics,"mGraphics");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Bitmap_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"smoothing") ) { return smoothing; }
		if (HX_FIELD_EQ(inName,"mGraphics") ) { return mGraphics; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { return pixelSnapping; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeSetBitmapData") ) { return nmeSetBitmapData_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Bitmap_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"smoothing") ) { smoothing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mGraphics") ) { mGraphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return nmeSetBitmapData(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pixelSnapping") ) { pixelSnapping=inValue.Cast< ::nme::display::PixelSnapping >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Bitmap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bitmapData"));
	outFields->push(HX_CSTRING("pixelSnapping"));
	outFields->push(HX_CSTRING("smoothing"));
	outFields->push(HX_CSTRING("mGraphics"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bitmapData"),
	HX_CSTRING("pixelSnapping"),
	HX_CSTRING("smoothing"),
	HX_CSTRING("mGraphics"),
	HX_CSTRING("nmeSetBitmapData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Bitmap_obj::__mClass;

void Bitmap_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.Bitmap"), hx::TCanCast< Bitmap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Bitmap_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
