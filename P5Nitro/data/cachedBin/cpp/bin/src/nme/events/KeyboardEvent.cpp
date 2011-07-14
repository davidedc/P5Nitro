#include <hxcpp.h>

#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_KeyboardEvent
#include <nme/events/KeyboardEvent.h>
#endif
namespace nme{
namespace events{

Void KeyboardEvent_obj::__construct(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic inCharCode,Dynamic inKeyCode,Dynamic inKeyLocation,Dynamic inCtrlKey,Dynamic inAltKey,Dynamic inShiftKey)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/KeyboardEvent.hx",18)
	super::__construct(type,bubbles,cancelable);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/KeyboardEvent.hx",20)
	this->keyCode = inKeyCode;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/KeyboardEvent.hx",21)
	this->keyLocation = (  (((inKeyLocation == null()))) ? Dynamic((int)0) : Dynamic(inKeyLocation) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/KeyboardEvent.hx",22)
	this->charCode = (  (((inCharCode == null()))) ? Dynamic((int)0) : Dynamic(inCharCode) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/KeyboardEvent.hx",24)
	this->shiftKey = (  (((inShiftKey == null()))) ? Dynamic(false) : Dynamic(inShiftKey) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/KeyboardEvent.hx",25)
	this->altKey = (  (((inAltKey == null()))) ? Dynamic(false) : Dynamic(inAltKey) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/KeyboardEvent.hx",26)
	this->ctrlKey = (  (((inCtrlKey == null()))) ? Dynamic(false) : Dynamic(inCtrlKey) );
}
;
	return null();
}

KeyboardEvent_obj::~KeyboardEvent_obj() { }

Dynamic KeyboardEvent_obj::__CreateEmpty() { return  new KeyboardEvent_obj; }
hx::ObjectPtr< KeyboardEvent_obj > KeyboardEvent_obj::__new(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic inCharCode,Dynamic inKeyCode,Dynamic inKeyLocation,Dynamic inCtrlKey,Dynamic inAltKey,Dynamic inShiftKey)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct(type,bubbles,cancelable,inCharCode,inKeyCode,inKeyLocation,inCtrlKey,inAltKey,inShiftKey);
	return result;}

Dynamic KeyboardEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8]);
	return result;}

::String KeyboardEvent_obj::KEY_DOWN;

::String KeyboardEvent_obj::KEY_UP;


KeyboardEvent_obj::KeyboardEvent_obj()
{
}

void KeyboardEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(KeyboardEvent);
	HX_MARK_MEMBER_NAME(keyCode,"keyCode");
	HX_MARK_MEMBER_NAME(charCode,"charCode");
	HX_MARK_MEMBER_NAME(keyLocation,"keyLocation");
	HX_MARK_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_MARK_MEMBER_NAME(altKey,"altKey");
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic KeyboardEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"KEY_UP") ) { return KEY_UP; }
		if (HX_FIELD_EQ(inName,"altKey") ) { return altKey; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"keyCode") ) { return keyCode; }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return ctrlKey; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"KEY_DOWN") ) { return KEY_DOWN; }
		if (HX_FIELD_EQ(inName,"charCode") ) { return charCode; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return shiftKey; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"keyLocation") ) { return keyLocation; }
	}
	return super::__Field(inName);
}

Dynamic KeyboardEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"KEY_UP") ) { KEY_UP=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"keyCode") ) { keyCode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"KEY_DOWN") ) { KEY_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"charCode") ) { charCode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"keyLocation") ) { keyLocation=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void KeyboardEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("keyCode"));
	outFields->push(HX_CSTRING("charCode"));
	outFields->push(HX_CSTRING("keyLocation"));
	outFields->push(HX_CSTRING("ctrlKey"));
	outFields->push(HX_CSTRING("altKey"));
	outFields->push(HX_CSTRING("shiftKey"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("KEY_DOWN"),
	HX_CSTRING("KEY_UP"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("keyCode"),
	HX_CSTRING("charCode"),
	HX_CSTRING("keyLocation"),
	HX_CSTRING("ctrlKey"),
	HX_CSTRING("altKey"),
	HX_CSTRING("shiftKey"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::KEY_DOWN,"KEY_DOWN");
	HX_MARK_MEMBER_NAME(KeyboardEvent_obj::KEY_UP,"KEY_UP");
};

Class KeyboardEvent_obj::__mClass;

void KeyboardEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.KeyboardEvent"), hx::TCanCast< KeyboardEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void KeyboardEvent_obj::__boot()
{
	hx::Static(KEY_DOWN) = HX_CSTRING("keyDown");
	hx::Static(KEY_UP) = HX_CSTRING("keyUp");
}

} // end namespace nme
} // end namespace events
