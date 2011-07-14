#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace nme{
namespace display{

Void InteractiveObject_obj::__construct(Dynamic inHandle,::String inType)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/InteractiveObject.hx",12)
	this->doubleClickEnabled = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/InteractiveObject.hx",13)
	this->nmeMouseEnabled = true;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/InteractiveObject.hx",14)
	super::__construct(inHandle,inType);
}
;
	return null();
}

InteractiveObject_obj::~InteractiveObject_obj() { }

Dynamic InteractiveObject_obj::__CreateEmpty() { return  new InteractiveObject_obj; }
hx::ObjectPtr< InteractiveObject_obj > InteractiveObject_obj::__new(Dynamic inHandle,::String inType)
{  hx::ObjectPtr< InteractiveObject_obj > result = new InteractiveObject_obj();
	result->__construct(inHandle,inType);
	return result;}

Dynamic InteractiveObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InteractiveObject_obj > result = new InteractiveObject_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool InteractiveObject_obj::nmeGetMouseEnabled( ){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeGetMouseEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/InteractiveObject.hx",17)
	return this->nmeMouseEnabled;
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeGetMouseEnabled,return )

bool InteractiveObject_obj::nmeSetMouseEnabled( bool inVal){
	__SAFE_POINT
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeSetMouseEnabled")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/InteractiveObject.hx",20)
	this->nmeMouseEnabled = inVal;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/InteractiveObject.hx",21)
	::nme::display::InteractiveObject_obj::nme_display_object_set_mouse_enabled(this->nmeHandle,inVal);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/InteractiveObject.hx",22)
	return this->nmeMouseEnabled;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,nmeSetMouseEnabled,return )

::nme::display::InteractiveObject InteractiveObject_obj::nmeAsInteractiveObject( ){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeAsInteractiveObject")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/InteractiveObject.hx",25)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeAsInteractiveObject,return )

Dynamic InteractiveObject_obj::nme_display_object_set_mouse_enabled;


InteractiveObject_obj::InteractiveObject_obj()
{
}

void InteractiveObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InteractiveObject);
	HX_MARK_MEMBER_NAME(mouseEnabled,"mouseEnabled");
	HX_MARK_MEMBER_NAME(nmeMouseEnabled,"nmeMouseEnabled");
	HX_MARK_MEMBER_NAME(doubleClickEnabled,"doubleClickEnabled");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InteractiveObject_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { return nmeGetMouseEnabled(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeMouseEnabled") ) { return nmeMouseEnabled; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"doubleClickEnabled") ) { return doubleClickEnabled; }
		if (HX_FIELD_EQ(inName,"nmeGetMouseEnabled") ) { return nmeGetMouseEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMouseEnabled") ) { return nmeSetMouseEnabled_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nmeAsInteractiveObject") ) { return nmeAsInteractiveObject_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"nme_display_object_set_mouse_enabled") ) { return nme_display_object_set_mouse_enabled; }
	}
	return super::__Field(inName);
}

Dynamic InteractiveObject_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { return nmeSetMouseEnabled(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeMouseEnabled") ) { nmeMouseEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"doubleClickEnabled") ) { doubleClickEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"nme_display_object_set_mouse_enabled") ) { nme_display_object_set_mouse_enabled=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void InteractiveObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mouseEnabled"));
	outFields->push(HX_CSTRING("nmeMouseEnabled"));
	outFields->push(HX_CSTRING("doubleClickEnabled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_display_object_set_mouse_enabled"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mouseEnabled"),
	HX_CSTRING("nmeMouseEnabled"),
	HX_CSTRING("doubleClickEnabled"),
	HX_CSTRING("nmeGetMouseEnabled"),
	HX_CSTRING("nmeSetMouseEnabled"),
	HX_CSTRING("nmeAsInteractiveObject"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_mouse_enabled,"nme_display_object_set_mouse_enabled");
};

Class InteractiveObject_obj::__mClass;

void InteractiveObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.InteractiveObject"), hx::TCanCast< InteractiveObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InteractiveObject_obj::__boot()
{
	hx::Static(nme_display_object_set_mouse_enabled) = ::nme::Loader_obj::load(HX_CSTRING("nme_display_object_set_mouse_enabled"),(int)2);
}

} // end namespace nme
} // end namespace display
