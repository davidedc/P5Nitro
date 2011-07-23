#include <hxcpp.h>

#ifndef INCLUDED_cpp_vm_Gc
#include <cpp/vm/Gc.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_system_System
#include <nme/system/System.h>
#endif
namespace nme{
namespace system{

Void System_obj::__construct()
{
	return null();
}

System_obj::~System_obj() { }

Dynamic System_obj::__CreateEmpty() { return  new System_obj; }
hx::ObjectPtr< System_obj > System_obj::__new()
{  hx::ObjectPtr< System_obj > result = new System_obj();
	result->__construct();
	return result;}

Dynamic System_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< System_obj > result = new System_obj();
	result->__construct();
	return result;}

int System_obj::totalMemory;

int System_obj::nmeGetTotalMemory( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("System_obj::nmeGetTotalMemory")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/system/System.hx",13)
	return ::__hxcpp_gc_used_bytes();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(System_obj,nmeGetTotalMemory,return )

Void System_obj::gc( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("System_obj::gc")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/system/System.hx",26)
		return ::cpp::vm::Gc_obj::run(true);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(System_obj,gc,(void))

Void System_obj::exit( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("System_obj::exit")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/system/System.hx",36)
		::nme::Lib_obj::close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(System_obj,exit,(void))


System_obj::System_obj()
{
}

void System_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(System);
	HX_MARK_END_CLASS();
}

Dynamic System_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"gc") ) { return gc_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"exit") ) { return exit_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"totalMemory") ) { return nmeGetTotalMemory(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeGetTotalMemory") ) { return nmeGetTotalMemory_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic System_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"totalMemory") ) { totalMemory=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void System_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("totalMemory"),
	HX_CSTRING("nmeGetTotalMemory"),
	HX_CSTRING("gc"),
	HX_CSTRING("exit"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(System_obj::totalMemory,"totalMemory");
};

Class System_obj::__mClass;

void System_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.system.System"), hx::TCanCast< System_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void System_obj::__boot()
{
	hx::Static(totalMemory);
}

} // end namespace nme
} // end namespace system
