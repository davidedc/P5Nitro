#include <hxcpp.h>

#ifndef INCLUDED_HighDpiScreenManager
#include <HighDpiScreenManager.h>
#endif

Void HighDpiScreenManager_obj::__construct()
{
	return null();
}

HighDpiScreenManager_obj::~HighDpiScreenManager_obj() { }

Dynamic HighDpiScreenManager_obj::__CreateEmpty() { return  new HighDpiScreenManager_obj; }
hx::ObjectPtr< HighDpiScreenManager_obj > HighDpiScreenManager_obj::__new()
{  hx::ObjectPtr< HighDpiScreenManager_obj > result = new HighDpiScreenManager_obj();
	result->__construct();
	return result;}

Dynamic HighDpiScreenManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HighDpiScreenManager_obj > result = new HighDpiScreenManager_obj();
	result->__construct();
	return result;}

double HighDpiScreenManager_obj::dpiScaleFactor;


HighDpiScreenManager_obj::HighDpiScreenManager_obj()
{
}

void HighDpiScreenManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HighDpiScreenManager);
	HX_MARK_END_CLASS();
}

Dynamic HighDpiScreenManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"dpiScaleFactor") ) { return dpiScaleFactor; }
	}
	return super::__Field(inName);
}

Dynamic HighDpiScreenManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"dpiScaleFactor") ) { dpiScaleFactor=inValue.Cast< double >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void HighDpiScreenManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("dpiScaleFactor"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HighDpiScreenManager_obj::dpiScaleFactor,"dpiScaleFactor");
};

Class HighDpiScreenManager_obj::__mClass;

void HighDpiScreenManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("HighDpiScreenManager"), hx::TCanCast< HighDpiScreenManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HighDpiScreenManager_obj::__boot()
{
	hx::Static(dpiScaleFactor);
}

