#include <hxcpp.h>

#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_FocusEvent
#include <nme/events/FocusEvent.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace nme{
namespace events{

Void FocusEvent_obj::__construct(::String inType,Dynamic __o_bubbles,Dynamic __o_cancelable,::nme::display::InteractiveObject inRelatedObject,Dynamic __o_inShiftKey,Dynamic __o_inKeyCode,Dynamic __o_inDirection)
{
bool bubbles = __o_bubbles.Default(true);
bool cancelable = __o_cancelable.Default(false);
bool inShiftKey = __o_inShiftKey.Default(false);
int inKeyCode = __o_inKeyCode.Default(0);
::String inDirection = __o_inDirection.Default(HX_CSTRING("none"));
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/FocusEvent.hx",20)
	super::__construct(inType,bubbles,cancelable);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/FocusEvent.hx",21)
	this->relatedObject = inRelatedObject;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/FocusEvent.hx",22)
	this->keyCode = inKeyCode;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/FocusEvent.hx",23)
	this->shiftKey = inShiftKey;
}
;
	return null();
}

FocusEvent_obj::~FocusEvent_obj() { }

Dynamic FocusEvent_obj::__CreateEmpty() { return  new FocusEvent_obj; }
hx::ObjectPtr< FocusEvent_obj > FocusEvent_obj::__new(::String inType,Dynamic __o_bubbles,Dynamic __o_cancelable,::nme::display::InteractiveObject inRelatedObject,Dynamic __o_inShiftKey,Dynamic __o_inKeyCode,Dynamic __o_inDirection)
{  hx::ObjectPtr< FocusEvent_obj > result = new FocusEvent_obj();
	result->__construct(inType,__o_bubbles,__o_cancelable,inRelatedObject,__o_inShiftKey,__o_inKeyCode,__o_inDirection);
	return result;}

Dynamic FocusEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FocusEvent_obj > result = new FocusEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

::String FocusEvent_obj::FOCUS_IN;

::String FocusEvent_obj::FOCUS_OUT;

::String FocusEvent_obj::KEY_FOCUS_CHANGE;

::String FocusEvent_obj::MOUSE_FOCUS_CHANGE;


FocusEvent_obj::FocusEvent_obj()
{
}

void FocusEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FocusEvent);
	HX_MARK_MEMBER_NAME(keyCode,"keyCode");
	HX_MARK_MEMBER_NAME(relatedObject,"relatedObject");
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic FocusEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"keyCode") ) { return keyCode; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"FOCUS_IN") ) { return FOCUS_IN; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return shiftKey; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FOCUS_OUT") ) { return FOCUS_OUT; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"relatedObject") ) { return relatedObject; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"KEY_FOCUS_CHANGE") ) { return KEY_FOCUS_CHANGE; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"MOUSE_FOCUS_CHANGE") ) { return MOUSE_FOCUS_CHANGE; }
	}
	return super::__Field(inName);
}

Dynamic FocusEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"keyCode") ) { keyCode=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"FOCUS_IN") ) { FOCUS_IN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FOCUS_OUT") ) { FOCUS_OUT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"relatedObject") ) { relatedObject=inValue.Cast< ::nme::display::InteractiveObject >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"KEY_FOCUS_CHANGE") ) { KEY_FOCUS_CHANGE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"MOUSE_FOCUS_CHANGE") ) { MOUSE_FOCUS_CHANGE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FocusEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("keyCode"));
	outFields->push(HX_CSTRING("relatedObject"));
	outFields->push(HX_CSTRING("shiftKey"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FOCUS_IN"),
	HX_CSTRING("FOCUS_OUT"),
	HX_CSTRING("KEY_FOCUS_CHANGE"),
	HX_CSTRING("MOUSE_FOCUS_CHANGE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("keyCode"),
	HX_CSTRING("relatedObject"),
	HX_CSTRING("shiftKey"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FocusEvent_obj::FOCUS_IN,"FOCUS_IN");
	HX_MARK_MEMBER_NAME(FocusEvent_obj::FOCUS_OUT,"FOCUS_OUT");
	HX_MARK_MEMBER_NAME(FocusEvent_obj::KEY_FOCUS_CHANGE,"KEY_FOCUS_CHANGE");
	HX_MARK_MEMBER_NAME(FocusEvent_obj::MOUSE_FOCUS_CHANGE,"MOUSE_FOCUS_CHANGE");
};

Class FocusEvent_obj::__mClass;

void FocusEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.FocusEvent"), hx::TCanCast< FocusEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FocusEvent_obj::__boot()
{
	hx::Static(FOCUS_IN) = HX_CSTRING("focusIn");
	hx::Static(FOCUS_OUT) = HX_CSTRING("focusOut");
	hx::Static(KEY_FOCUS_CHANGE) = HX_CSTRING("keyFocusChange");
	hx::Static(MOUSE_FOCUS_CHANGE) = HX_CSTRING("mouseFocusChange");
}

} // end namespace nme
} // end namespace events
