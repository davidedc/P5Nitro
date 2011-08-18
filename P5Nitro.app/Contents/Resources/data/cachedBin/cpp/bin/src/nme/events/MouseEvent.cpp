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
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
namespace nme{
namespace events{

Void MouseEvent_obj::__construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_in_localX,Dynamic __o_in_localY,::nme::display::InteractiveObject in_relatedObject,Dynamic __o_in_ctrlKey,Dynamic __o_in_altKey,Dynamic __o_in_shiftKey,Dynamic __o_in_buttonDown,Dynamic __o_in_delta,Dynamic __o_in_commandKey,Dynamic __o_in_clickCount)
{
bool bubbles = __o_bubbles.Default(true);
bool cancelable = __o_cancelable.Default(false);
double in_localX = __o_in_localX.Default(0);
double in_localY = __o_in_localY.Default(0);
bool in_ctrlKey = __o_in_ctrlKey.Default(false);
bool in_altKey = __o_in_altKey.Default(false);
bool in_shiftKey = __o_in_shiftKey.Default(false);
bool in_buttonDown = __o_in_buttonDown.Default(false);
int in_delta = __o_in_delta.Default(0);
bool in_commandKey = __o_in_commandKey.Default(false);
int in_clickCount = __o_in_clickCount.Default(0);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",36)
	super::__construct(type,bubbles,cancelable);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",38)
	this->localX = in_localX;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",39)
	this->localY = in_localY;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",40)
	this->relatedObject = in_relatedObject;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",41)
	this->ctrlKey = in_ctrlKey;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",42)
	this->altKey = in_altKey;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",43)
	this->shiftKey = in_shiftKey;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",44)
	this->buttonDown = in_buttonDown;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",45)
	this->delta = in_delta;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",46)
	this->commandKey = in_commandKey;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",47)
	this->clickCount = in_clickCount;
}
;
	return null();
}

MouseEvent_obj::~MouseEvent_obj() { }

Dynamic MouseEvent_obj::__CreateEmpty() { return  new MouseEvent_obj; }
hx::ObjectPtr< MouseEvent_obj > MouseEvent_obj::__new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_in_localX,Dynamic __o_in_localY,::nme::display::InteractiveObject in_relatedObject,Dynamic __o_in_ctrlKey,Dynamic __o_in_altKey,Dynamic __o_in_shiftKey,Dynamic __o_in_buttonDown,Dynamic __o_in_delta,Dynamic __o_in_commandKey,Dynamic __o_in_clickCount)
{  hx::ObjectPtr< MouseEvent_obj > result = new MouseEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_in_localX,__o_in_localY,in_relatedObject,__o_in_ctrlKey,__o_in_altKey,__o_in_shiftKey,__o_in_buttonDown,__o_in_delta,__o_in_commandKey,__o_in_clickCount);
	return result;}

Dynamic MouseEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MouseEvent_obj > result = new MouseEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11],inArgs[12]);
	return result;}

::nme::events::MouseEvent MouseEvent_obj::nmeCreateSimilar( ::String inType,::nme::display::InteractiveObject related,::nme::display::InteractiveObject targ){
	HX_SOURCE_PUSH("MouseEvent_obj::nmeCreateSimilar")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",75)
	::nme::events::MouseEvent result = ::nme::events::MouseEvent_obj::__new(inType,this->bubbles,this->cancelable,this->localX,this->localY,(  (((related == null()))) ? ::nme::display::InteractiveObject(this->relatedObject) : ::nme::display::InteractiveObject(related) ),this->ctrlKey,this->altKey,this->shiftKey,this->buttonDown,this->delta,this->commandKey,this->clickCount);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",79)
	if (((targ != null())))
		result->target = targ;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",81)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC3(MouseEvent_obj,nmeCreateSimilar,return )

Void MouseEvent_obj::updateAfterEvent( ){
{
		HX_SOURCE_PUSH("MouseEvent_obj::updateAfterEvent")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,updateAfterEvent,(void))

int MouseEvent_obj::efLeftDown;

int MouseEvent_obj::efShiftDown;

int MouseEvent_obj::efCtrlDown;

int MouseEvent_obj::efAltDown;

int MouseEvent_obj::efCommandDown;

::nme::events::MouseEvent MouseEvent_obj::nmeCreate( ::String inType,Dynamic inEvent,::nme::geom::Point inLocal,::nme::display::InteractiveObject inTarget){
	HX_SOURCE_PUSH("MouseEvent_obj::nmeCreate")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",59)
	int flags = inEvent->__Field(HX_CSTRING("flags"));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",60)
	::nme::events::MouseEvent evt = ::nme::events::MouseEvent_obj::__new(inType,true,false,inLocal->x,inLocal->y,null(),(((int(flags) & int(::nme::events::MouseEvent_obj::efCtrlDown))) != (int)0),(((int(flags) & int(::nme::events::MouseEvent_obj::efAltDown))) != (int)0),(((int(flags) & int(::nme::events::MouseEvent_obj::efShiftDown))) != (int)0),(((int(flags) & int(::nme::events::MouseEvent_obj::efLeftDown))) != (int)0),(int)0,null(),(int)0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",66)
	evt->stageX = inEvent->__Field(HX_CSTRING("x"));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",67)
	evt->stageY = inEvent->__Field(HX_CSTRING("y"));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",68)
	evt->target = inTarget;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/MouseEvent.hx",69)
	return evt;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(MouseEvent_obj,nmeCreate,return )

::String MouseEvent_obj::MOUSE_MOVE;

::String MouseEvent_obj::MOUSE_OUT;

::String MouseEvent_obj::MOUSE_OVER;

::String MouseEvent_obj::ROLL_OUT;

::String MouseEvent_obj::ROLL_OVER;

::String MouseEvent_obj::CLICK;

::String MouseEvent_obj::MOUSE_DOWN;

::String MouseEvent_obj::MOUSE_UP;

::String MouseEvent_obj::MIDDLE_CLICK;

::String MouseEvent_obj::MIDDLE_MOUSE_DOWN;

::String MouseEvent_obj::MIDDLE_MOUSE_UP;

::String MouseEvent_obj::RIGHT_CLICK;

::String MouseEvent_obj::RIGHT_MOUSE_DOWN;

::String MouseEvent_obj::RIGHT_MOUSE_UP;

::String MouseEvent_obj::MOUSE_WHEEL;

::String MouseEvent_obj::DOUBLE_CLICK;


MouseEvent_obj::MouseEvent_obj()
{
}

void MouseEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MouseEvent);
	HX_MARK_MEMBER_NAME(localX,"localX");
	HX_MARK_MEMBER_NAME(localY,"localY");
	HX_MARK_MEMBER_NAME(relatedObject,"relatedObject");
	HX_MARK_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_MARK_MEMBER_NAME(altKey,"altKey");
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	HX_MARK_MEMBER_NAME(buttonDown,"buttonDown");
	HX_MARK_MEMBER_NAME(delta,"delta");
	HX_MARK_MEMBER_NAME(commandKey,"commandKey");
	HX_MARK_MEMBER_NAME(clickCount,"clickCount");
	HX_MARK_MEMBER_NAME(stageX,"stageX");
	HX_MARK_MEMBER_NAME(stageY,"stageY");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic MouseEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CLICK") ) { return CLICK; }
		if (HX_FIELD_EQ(inName,"delta") ) { return delta; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"localX") ) { return localX; }
		if (HX_FIELD_EQ(inName,"localY") ) { return localY; }
		if (HX_FIELD_EQ(inName,"altKey") ) { return altKey; }
		if (HX_FIELD_EQ(inName,"stageX") ) { return stageX; }
		if (HX_FIELD_EQ(inName,"stageY") ) { return stageY; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return ctrlKey; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ROLL_OUT") ) { return ROLL_OUT; }
		if (HX_FIELD_EQ(inName,"MOUSE_UP") ) { return MOUSE_UP; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return shiftKey; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"efAltDown") ) { return efAltDown; }
		if (HX_FIELD_EQ(inName,"nmeCreate") ) { return nmeCreate_dyn(); }
		if (HX_FIELD_EQ(inName,"MOUSE_OUT") ) { return MOUSE_OUT; }
		if (HX_FIELD_EQ(inName,"ROLL_OVER") ) { return ROLL_OVER; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { return efLeftDown; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { return efCtrlDown; }
		if (HX_FIELD_EQ(inName,"MOUSE_MOVE") ) { return MOUSE_MOVE; }
		if (HX_FIELD_EQ(inName,"MOUSE_OVER") ) { return MOUSE_OVER; }
		if (HX_FIELD_EQ(inName,"MOUSE_DOWN") ) { return MOUSE_DOWN; }
		if (HX_FIELD_EQ(inName,"buttonDown") ) { return buttonDown; }
		if (HX_FIELD_EQ(inName,"commandKey") ) { return commandKey; }
		if (HX_FIELD_EQ(inName,"clickCount") ) { return clickCount; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { return efShiftDown; }
		if (HX_FIELD_EQ(inName,"RIGHT_CLICK") ) { return RIGHT_CLICK; }
		if (HX_FIELD_EQ(inName,"MOUSE_WHEEL") ) { return MOUSE_WHEEL; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"MIDDLE_CLICK") ) { return MIDDLE_CLICK; }
		if (HX_FIELD_EQ(inName,"DOUBLE_CLICK") ) { return DOUBLE_CLICK; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { return efCommandDown; }
		if (HX_FIELD_EQ(inName,"relatedObject") ) { return relatedObject; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"RIGHT_MOUSE_UP") ) { return RIGHT_MOUSE_UP; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"MIDDLE_MOUSE_UP") ) { return MIDDLE_MOUSE_UP; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"RIGHT_MOUSE_DOWN") ) { return RIGHT_MOUSE_DOWN; }
		if (HX_FIELD_EQ(inName,"nmeCreateSimilar") ) { return nmeCreateSimilar_dyn(); }
		if (HX_FIELD_EQ(inName,"updateAfterEvent") ) { return updateAfterEvent_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"MIDDLE_MOUSE_DOWN") ) { return MIDDLE_MOUSE_DOWN; }
	}
	return super::__Field(inName);
}

Dynamic MouseEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CLICK") ) { CLICK=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"delta") ) { delta=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"localX") ) { localX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localY") ) { localY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageX") ) { stageX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stageY") ) { stageY=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ROLL_OUT") ) { ROLL_OUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_UP") ) { MOUSE_UP=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"efAltDown") ) { efAltDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_OUT") ) { MOUSE_OUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ROLL_OVER") ) { ROLL_OVER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"efLeftDown") ) { efLeftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"efCtrlDown") ) { efCtrlDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_MOVE") ) { MOUSE_MOVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_OVER") ) { MOUSE_OVER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_DOWN") ) { MOUSE_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buttonDown") ) { buttonDown=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"commandKey") ) { commandKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clickCount") ) { clickCount=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"efShiftDown") ) { efShiftDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RIGHT_CLICK") ) { RIGHT_CLICK=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_WHEEL") ) { MOUSE_WHEEL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"MIDDLE_CLICK") ) { MIDDLE_CLICK=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DOUBLE_CLICK") ) { DOUBLE_CLICK=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"efCommandDown") ) { efCommandDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"relatedObject") ) { relatedObject=inValue.Cast< ::nme::display::InteractiveObject >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"RIGHT_MOUSE_UP") ) { RIGHT_MOUSE_UP=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"MIDDLE_MOUSE_UP") ) { MIDDLE_MOUSE_UP=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"RIGHT_MOUSE_DOWN") ) { RIGHT_MOUSE_DOWN=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"MIDDLE_MOUSE_DOWN") ) { MIDDLE_MOUSE_DOWN=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MouseEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localX"));
	outFields->push(HX_CSTRING("localY"));
	outFields->push(HX_CSTRING("relatedObject"));
	outFields->push(HX_CSTRING("ctrlKey"));
	outFields->push(HX_CSTRING("altKey"));
	outFields->push(HX_CSTRING("shiftKey"));
	outFields->push(HX_CSTRING("buttonDown"));
	outFields->push(HX_CSTRING("delta"));
	outFields->push(HX_CSTRING("commandKey"));
	outFields->push(HX_CSTRING("clickCount"));
	outFields->push(HX_CSTRING("stageX"));
	outFields->push(HX_CSTRING("stageY"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("efLeftDown"),
	HX_CSTRING("efShiftDown"),
	HX_CSTRING("efCtrlDown"),
	HX_CSTRING("efAltDown"),
	HX_CSTRING("efCommandDown"),
	HX_CSTRING("nmeCreate"),
	HX_CSTRING("MOUSE_MOVE"),
	HX_CSTRING("MOUSE_OUT"),
	HX_CSTRING("MOUSE_OVER"),
	HX_CSTRING("ROLL_OUT"),
	HX_CSTRING("ROLL_OVER"),
	HX_CSTRING("CLICK"),
	HX_CSTRING("MOUSE_DOWN"),
	HX_CSTRING("MOUSE_UP"),
	HX_CSTRING("MIDDLE_CLICK"),
	HX_CSTRING("MIDDLE_MOUSE_DOWN"),
	HX_CSTRING("MIDDLE_MOUSE_UP"),
	HX_CSTRING("RIGHT_CLICK"),
	HX_CSTRING("RIGHT_MOUSE_DOWN"),
	HX_CSTRING("RIGHT_MOUSE_UP"),
	HX_CSTRING("MOUSE_WHEEL"),
	HX_CSTRING("DOUBLE_CLICK"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("localX"),
	HX_CSTRING("localY"),
	HX_CSTRING("relatedObject"),
	HX_CSTRING("ctrlKey"),
	HX_CSTRING("altKey"),
	HX_CSTRING("shiftKey"),
	HX_CSTRING("buttonDown"),
	HX_CSTRING("delta"),
	HX_CSTRING("commandKey"),
	HX_CSTRING("clickCount"),
	HX_CSTRING("stageX"),
	HX_CSTRING("stageY"),
	HX_CSTRING("nmeCreateSimilar"),
	HX_CSTRING("updateAfterEvent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MouseEvent_obj::efLeftDown,"efLeftDown");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::efShiftDown,"efShiftDown");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::efCtrlDown,"efCtrlDown");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::efAltDown,"efAltDown");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::efCommandDown,"efCommandDown");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_MOVE,"MOUSE_MOVE");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_OUT,"MOUSE_OUT");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_OVER,"MOUSE_OVER");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::ROLL_OUT,"ROLL_OUT");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::ROLL_OVER,"ROLL_OVER");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::CLICK,"CLICK");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_DOWN,"MOUSE_DOWN");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_UP,"MOUSE_UP");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MIDDLE_CLICK,"MIDDLE_CLICK");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MIDDLE_MOUSE_DOWN,"MIDDLE_MOUSE_DOWN");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MIDDLE_MOUSE_UP,"MIDDLE_MOUSE_UP");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::RIGHT_CLICK,"RIGHT_CLICK");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::RIGHT_MOUSE_DOWN,"RIGHT_MOUSE_DOWN");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::RIGHT_MOUSE_UP,"RIGHT_MOUSE_UP");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_WHEEL,"MOUSE_WHEEL");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::DOUBLE_CLICK,"DOUBLE_CLICK");
};

Class MouseEvent_obj::__mClass;

void MouseEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.MouseEvent"), hx::TCanCast< MouseEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MouseEvent_obj::__boot()
{
	hx::Static(efLeftDown) = (int)1;
	hx::Static(efShiftDown) = (int)2;
	hx::Static(efCtrlDown) = (int)4;
	hx::Static(efAltDown) = (int)8;
	hx::Static(efCommandDown) = (int)16;
	hx::Static(MOUSE_MOVE) = HX_CSTRING("mouseMove");
	hx::Static(MOUSE_OUT) = HX_CSTRING("mouseOut");
	hx::Static(MOUSE_OVER) = HX_CSTRING("mouseOver");
	hx::Static(ROLL_OUT) = HX_CSTRING("rollOut");
	hx::Static(ROLL_OVER) = HX_CSTRING("rollOver");
	hx::Static(CLICK) = HX_CSTRING("click");
	hx::Static(MOUSE_DOWN) = HX_CSTRING("mouseDown");
	hx::Static(MOUSE_UP) = HX_CSTRING("mouseUp");
	hx::Static(MIDDLE_CLICK) = HX_CSTRING("middleClick");
	hx::Static(MIDDLE_MOUSE_DOWN) = HX_CSTRING("middleMouseDown");
	hx::Static(MIDDLE_MOUSE_UP) = HX_CSTRING("middleMouseUp");
	hx::Static(RIGHT_CLICK) = HX_CSTRING("rightClick");
	hx::Static(RIGHT_MOUSE_DOWN) = HX_CSTRING("rightMouseDown");
	hx::Static(RIGHT_MOUSE_UP) = HX_CSTRING("rightMouseUp");
	hx::Static(MOUSE_WHEEL) = HX_CSTRING("mouseWheel");
	hx::Static(DOUBLE_CLICK) = HX_CSTRING("doubleClick");
}

} // end namespace nme
} // end namespace events
