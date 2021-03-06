#include <hxcpp.h>

#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace nme{
namespace display{

Void MovieClip_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/MovieClip.hx",7)
	super::__construct();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/MovieClip.hx",8)
	this->mCurrentFrame = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/MovieClip.hx",9)
	this->mTotalFrames = (int)0;
}
;
	return null();
}

MovieClip_obj::~MovieClip_obj() { }

Dynamic MovieClip_obj::__CreateEmpty() { return  new MovieClip_obj; }
hx::ObjectPtr< MovieClip_obj > MovieClip_obj::__new()
{  hx::ObjectPtr< MovieClip_obj > result = new MovieClip_obj();
	result->__construct();
	return result;}

Dynamic MovieClip_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MovieClip_obj > result = new MovieClip_obj();
	result->__construct();
	return result;}

::String MovieClip_obj::nmeGetType( ){
	HX_SOURCE_PUSH("MovieClip_obj::nmeGetType")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/MovieClip.hx",12)
	return HX_CSTRING("MoveiClip");
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,nmeGetType,return )

int MovieClip_obj::GetTotalFrames( ){
	HX_SOURCE_PUSH("MovieClip_obj::GetTotalFrames")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/MovieClip.hx",23)
	return this->mTotalFrames;
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,GetTotalFrames,return )

int MovieClip_obj::GetCurrentFrame( ){
	HX_SOURCE_PUSH("MovieClip_obj::GetCurrentFrame")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/MovieClip.hx",24)
	return this->mCurrentFrame;
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,GetCurrentFrame,return )

Void MovieClip_obj::gotoAndPlay( Dynamic frame,::String scene){
{
		HX_SOURCE_PUSH("MovieClip_obj::gotoAndPlay")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MovieClip_obj,gotoAndPlay,(void))

Void MovieClip_obj::gotoAndStop( Dynamic frame,::String scene){
{
		HX_SOURCE_PUSH("MovieClip_obj::gotoAndStop")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MovieClip_obj,gotoAndStop,(void))

Void MovieClip_obj::play( ){
{
		HX_SOURCE_PUSH("MovieClip_obj::play")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,play,(void))

Void MovieClip_obj::stop( ){
{
		HX_SOURCE_PUSH("MovieClip_obj::stop")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MovieClip_obj,stop,(void))


MovieClip_obj::MovieClip_obj()
{
}

void MovieClip_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MovieClip);
	HX_MARK_MEMBER_NAME(enabled,"enabled");
	HX_MARK_MEMBER_NAME(currentFrame,"currentFrame");
	HX_MARK_MEMBER_NAME(framesLoaded,"framesLoaded");
	HX_MARK_MEMBER_NAME(totalFrames,"totalFrames");
	HX_MARK_MEMBER_NAME(mCurrentFrame,"mCurrentFrame");
	HX_MARK_MEMBER_NAME(mTotalFrames,"mTotalFrames");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic MovieClip_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return enabled; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeGetType") ) { return nmeGetType_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"totalFrames") ) { return GetTotalFrames(); }
		if (HX_FIELD_EQ(inName,"gotoAndPlay") ) { return gotoAndPlay_dyn(); }
		if (HX_FIELD_EQ(inName,"gotoAndStop") ) { return gotoAndStop_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentFrame") ) { return GetCurrentFrame(); }
		if (HX_FIELD_EQ(inName,"framesLoaded") ) { return GetTotalFrames(); }
		if (HX_FIELD_EQ(inName,"mTotalFrames") ) { return mTotalFrames; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mCurrentFrame") ) { return mCurrentFrame; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"GetTotalFrames") ) { return GetTotalFrames_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"GetCurrentFrame") ) { return GetCurrentFrame_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MovieClip_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"totalFrames") ) { totalFrames=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentFrame") ) { currentFrame=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"framesLoaded") ) { framesLoaded=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mTotalFrames") ) { mTotalFrames=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mCurrentFrame") ) { mCurrentFrame=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MovieClip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("currentFrame"));
	outFields->push(HX_CSTRING("framesLoaded"));
	outFields->push(HX_CSTRING("totalFrames"));
	outFields->push(HX_CSTRING("mCurrentFrame"));
	outFields->push(HX_CSTRING("mTotalFrames"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeGetType"),
	HX_CSTRING("enabled"),
	HX_CSTRING("currentFrame"),
	HX_CSTRING("framesLoaded"),
	HX_CSTRING("totalFrames"),
	HX_CSTRING("mCurrentFrame"),
	HX_CSTRING("mTotalFrames"),
	HX_CSTRING("GetTotalFrames"),
	HX_CSTRING("GetCurrentFrame"),
	HX_CSTRING("gotoAndPlay"),
	HX_CSTRING("gotoAndStop"),
	HX_CSTRING("play"),
	HX_CSTRING("stop"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class MovieClip_obj::__mClass;

void MovieClip_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.MovieClip"), hx::TCanCast< MovieClip_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MovieClip_obj::__boot()
{
}

} // end namespace nme
} // end namespace display
