#include <hxcpp.h>

#ifndef INCLUDED_PImage
#include <PImage.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_nme_display_Bitmap
#include <nme/display/Bitmap.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
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
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif

Void PImage_obj::__construct(int x,int y)
{
{
	HX_SOURCE_POS("./PImage.hx",21)
	super::__construct(null(),::nme::display::PixelSnapping_obj::AUTO,true);
	HX_SOURCE_POS("./PImage.hx",23)
	this->nmeSetBitmapData(::nme::display::BitmapData_obj::__new(x,y,null(),null()));
}
;
	return null();
}

PImage_obj::~PImage_obj() { }

Dynamic PImage_obj::__CreateEmpty() { return  new PImage_obj; }
hx::ObjectPtr< PImage_obj > PImage_obj::__new(int x,int y)
{  hx::ObjectPtr< PImage_obj > result = new PImage_obj();
	result->__construct(x,y);
	return result;}

Dynamic PImage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PImage_obj > result = new PImage_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void PImage_obj::loadPixelsArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PImage_obj::loadPixelsArgCount0")
		HX_SOURCE_POS("./PImage.hx",27)
		this->pixels = Array_obj< int >::__new();
		HX_SOURCE_POS("./PImage.hx",28)
		this->bitmapData->lock();
		HX_SOURCE_POS("./PImage.hx",29)
		int theHeight = ::Std_obj::_int(this->nmeGetHeight());
		HX_SOURCE_POS("./PImage.hx",30)
		int theWidth = ::Std_obj::_int(this->nmeGetWidth());
		HX_SOURCE_POS("./PImage.hx",33)
		{
			HX_SOURCE_POS("./PImage.hx",33)
			int _g = (int)0;
			HX_SOURCE_POS("./PImage.hx",33)
			while((_g < theHeight)){
				__SAFE_POINT
				HX_SOURCE_POS("./PImage.hx",33)
				int y = (_g)++;
				HX_SOURCE_POS("./PImage.hx",34)
				int _g1 = (int)0;
				HX_SOURCE_POS("./PImage.hx",34)
				while((_g1 < theWidth)){
					__SAFE_POINT
					HX_SOURCE_POS("./PImage.hx",34)
					int x = (_g1)++;
					HX_SOURCE_POS("./PImage.hx",35)
					this->pixels->push(this->bitmapData->getPixel32(x,y));
				}
			}
		}
		HX_SOURCE_POS("./PImage.hx",37)
		this->bitmapData->unlock(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PImage_obj,loadPixelsArgCount0,(void))

Void PImage_obj::updatePixelsArgCount0( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PImage_obj::updatePixelsArgCount0")
		HX_SOURCE_POS("./PImage.hx",47)
		this->bitmapData->lock();
		HX_SOURCE_POS("./PImage.hx",48)
		int index = (int)0;
		HX_SOURCE_POS("./PImage.hx",50)
		int theHeight = ::Std_obj::_int(this->nmeGetHeight());
		HX_SOURCE_POS("./PImage.hx",51)
		int theWidth = ::Std_obj::_int(this->nmeGetWidth());
		HX_SOURCE_POS("./PImage.hx",56)
		if (((this->pixels != null()))){
			HX_SOURCE_POS("./PImage.hx",57)
			{
				HX_SOURCE_POS("./PImage.hx",57)
				int _g = (int)0;
				HX_SOURCE_POS("./PImage.hx",57)
				while((_g < theHeight)){
					__SAFE_POINT
					HX_SOURCE_POS("./PImage.hx",57)
					int y = (_g)++;
					HX_SOURCE_POS("./PImage.hx",58)
					int _g1 = (int)0;
					HX_SOURCE_POS("./PImage.hx",58)
					while((_g1 < theWidth)){
						__SAFE_POINT
						HX_SOURCE_POS("./PImage.hx",58)
						int x = (_g1)++;
						HX_SOURCE_POS("./PImage.hx",60)
						this->bitmapData->setPixel32(x,y,this->pixels->__get((index)++));
					}
				}
			}
		}
		HX_SOURCE_POS("./PImage.hx",70)
		this->bitmapData->unlock(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PImage_obj,updatePixelsArgCount0,(void))

int PImage_obj::getArgCount2( int x,int y){
	__SAFE_POINT
	HX_SOURCE_PUSH("PImage_obj::getArgCount2")
	HX_SOURCE_POS("./PImage.hx",76)
	return this->bitmapData->getPixel32(x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(PImage_obj,getArgCount2,return )

Void PImage_obj::setArgCount3( int x,int y,int color){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("PImage_obj::setArgCount3")
		HX_SOURCE_POS("./PImage.hx",81)
		this->bitmapData->setPixel32(x,y,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(PImage_obj,setArgCount3,(void))


PImage_obj::PImage_obj()
{
}

void PImage_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PImage);
	HX_MARK_MEMBER_NAME(pixels,"pixels");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic PImage_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pixels") ) { return pixels; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getArgCount2") ) { return getArgCount2_dyn(); }
		if (HX_FIELD_EQ(inName,"setArgCount3") ) { return setArgCount3_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"loadPixelsArgCount0") ) { return loadPixelsArgCount0_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"updatePixelsArgCount0") ) { return updatePixelsArgCount0_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PImage_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pixels") ) { pixels=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void PImage_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pixels"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("pixels"),
	HX_CSTRING("loadPixelsArgCount0"),
	HX_CSTRING("updatePixelsArgCount0"),
	HX_CSTRING("getArgCount2"),
	HX_CSTRING("setArgCount3"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PImage_obj::__mClass;

void PImage_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("PImage"), hx::TCanCast< PImage_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PImage_obj::__boot()
{
}

