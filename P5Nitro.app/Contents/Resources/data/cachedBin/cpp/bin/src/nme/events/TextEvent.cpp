#include <hxcpp.h>

#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_TextEvent
#include <nme/events/TextEvent.h>
#endif
namespace nme{
namespace events{

Void TextEvent_obj::__construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_inText)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
::String inText = __o_inText.Default(HX_CSTRING(""));
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/TextEvent.hx",10)
	super::__construct(type,bubbles,cancelable);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/events/TextEvent.hx",11)
	this->text = inText;
}
;
	return null();
}

TextEvent_obj::~TextEvent_obj() { }

Dynamic TextEvent_obj::__CreateEmpty() { return  new TextEvent_obj; }
hx::ObjectPtr< TextEvent_obj > TextEvent_obj::__new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_inText)
{  hx::ObjectPtr< TextEvent_obj > result = new TextEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_inText);
	return result;}

Dynamic TextEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextEvent_obj > result = new TextEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


TextEvent_obj::TextEvent_obj()
{
}

void TextEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextEvent);
	HX_MARK_MEMBER_NAME(text,"text");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TextEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return text; }
	}
	return super::__Field(inName);
}

Dynamic TextEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { text=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TextEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("text"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("text"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class TextEvent_obj::__mClass;

void TextEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.TextEvent"), hx::TCanCast< TextEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TextEvent_obj::__boot()
{
}

} // end namespace nme
} // end namespace events
