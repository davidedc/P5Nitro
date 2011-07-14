#include <hxcpp.h>

#ifndef INCLUDED_ProcessingHaxeBitmapPool
#include <ProcessingHaxeBitmapPool.h>
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
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Transform
#include <nme/geom/Transform.h>
#endif

Void ProcessingHaxeBitmapPool_obj::__construct()
{
{
}
;
	return null();
}

ProcessingHaxeBitmapPool_obj::~ProcessingHaxeBitmapPool_obj() { }

Dynamic ProcessingHaxeBitmapPool_obj::__CreateEmpty() { return  new ProcessingHaxeBitmapPool_obj; }
hx::ObjectPtr< ProcessingHaxeBitmapPool_obj > ProcessingHaxeBitmapPool_obj::__new()
{  hx::ObjectPtr< ProcessingHaxeBitmapPool_obj > result = new ProcessingHaxeBitmapPool_obj();
	result->__construct();
	return result;}

Dynamic ProcessingHaxeBitmapPool_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ProcessingHaxeBitmapPool_obj > result = new ProcessingHaxeBitmapPool_obj();
	result->__construct();
	return result;}

Void ProcessingHaxeBitmapPool_obj::initialize( int maxPoolSize,int growthValue){
{
		HX_SOURCE_PUSH("ProcessingHaxeBitmapPool_obj::initialize")
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",19)
		this->MAX_VALUE = maxPoolSize;
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",20)
		this->GROWTH_VALUE = growthValue;
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",21)
		this->counter = maxPoolSize;
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",23)
		int i = maxPoolSize;
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",25)
		this->pool = Array_obj< ::nme::display::Bitmap >::__new();
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",26)
		while((--(i) > (int)-1)){
			__SAFE_POINT
			HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",27)
			this->pool[i] = ::nme::display::Bitmap_obj::__new(null(),::nme::display::PixelSnapping_obj::AUTO,true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ProcessingHaxeBitmapPool_obj,initialize,(void))

::nme::display::Bitmap ProcessingHaxeBitmapPool_obj::getBitmap( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ProcessingHaxeBitmapPool_obj::getBitmap")
	HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",33)
	if (((this->counter > (int)0))){
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",34)
		this->currentBitmap = this->pool->__get(--(this->counter));
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",39)
		this->currentBitmap->nmeGetTransform()->nmeSetColorTransform(null());
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",40)
		return this->currentBitmap;
	}
	HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",43)
	int i = this->GROWTH_VALUE;
	HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",44)
	while((--(i) > (int)-1)){
		__SAFE_POINT
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",45)
		this->pool->unshift(::nme::display::Bitmap_obj::__new(null(),::nme::display::PixelSnapping_obj::AUTO,true));
	}
	HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",46)
	this->counter = this->GROWTH_VALUE;
	HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",48)
	return this->getBitmap();
}


HX_DEFINE_DYNAMIC_FUNC0(ProcessingHaxeBitmapPool_obj,getBitmap,return )

Void ProcessingHaxeBitmapPool_obj::disposeBitmap( ::nme::display::Bitmap disposedBitmap){
{
		HX_SOURCE_PUSH("ProcessingHaxeBitmapPool_obj::disposeBitmap")
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",52)
		this->pool[(this->counter)++] = disposedBitmap;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ProcessingHaxeBitmapPool_obj,disposeBitmap,(void))

Void ProcessingHaxeBitmapPool_obj::disposeAllBitmaps( ){
{
		HX_SOURCE_PUSH("ProcessingHaxeBitmapPool_obj::disposeAllBitmaps")
		HX_SOURCE_POS("./ProcessingHaxeBitmapPool.hx",56)
		this->counter = this->pool->length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ProcessingHaxeBitmapPool_obj,disposeAllBitmaps,(void))


ProcessingHaxeBitmapPool_obj::ProcessingHaxeBitmapPool_obj()
{
}

void ProcessingHaxeBitmapPool_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ProcessingHaxeBitmapPool);
	HX_MARK_MEMBER_NAME(MAX_VALUE,"MAX_VALUE");
	HX_MARK_MEMBER_NAME(GROWTH_VALUE,"GROWTH_VALUE");
	HX_MARK_MEMBER_NAME(counter,"counter");
	HX_MARK_MEMBER_NAME(pool,"pool");
	HX_MARK_MEMBER_NAME(currentBitmap,"currentBitmap");
	HX_MARK_END_CLASS();
}

Dynamic ProcessingHaxeBitmapPool_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { return pool; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"counter") ) { return counter; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"MAX_VALUE") ) { return MAX_VALUE; }
		if (HX_FIELD_EQ(inName,"getBitmap") ) { return getBitmap_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"GROWTH_VALUE") ) { return GROWTH_VALUE; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentBitmap") ) { return currentBitmap; }
		if (HX_FIELD_EQ(inName,"disposeBitmap") ) { return disposeBitmap_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"disposeAllBitmaps") ) { return disposeAllBitmaps_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic ProcessingHaxeBitmapPool_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { pool=inValue.Cast< Array< ::nme::display::Bitmap > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"counter") ) { counter=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"MAX_VALUE") ) { MAX_VALUE=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"GROWTH_VALUE") ) { GROWTH_VALUE=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"currentBitmap") ) { currentBitmap=inValue.Cast< ::nme::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ProcessingHaxeBitmapPool_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("MAX_VALUE"));
	outFields->push(HX_CSTRING("GROWTH_VALUE"));
	outFields->push(HX_CSTRING("counter"));
	outFields->push(HX_CSTRING("pool"));
	outFields->push(HX_CSTRING("currentBitmap"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("MAX_VALUE"),
	HX_CSTRING("GROWTH_VALUE"),
	HX_CSTRING("counter"),
	HX_CSTRING("pool"),
	HX_CSTRING("currentBitmap"),
	HX_CSTRING("initialize"),
	HX_CSTRING("getBitmap"),
	HX_CSTRING("disposeBitmap"),
	HX_CSTRING("disposeAllBitmaps"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class ProcessingHaxeBitmapPool_obj::__mClass;

void ProcessingHaxeBitmapPool_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("ProcessingHaxeBitmapPool"), hx::TCanCast< ProcessingHaxeBitmapPool_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ProcessingHaxeBitmapPool_obj::__boot()
{
}

