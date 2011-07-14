#include <hxcpp.h>

#ifndef INCLUDED_cpp_vm_Gc
#include <cpp/vm/Gc.h>
#endif
namespace cpp{
namespace vm{

Void Gc_obj::__construct()
{
	return null();
}

Gc_obj::~Gc_obj() { }

Dynamic Gc_obj::__CreateEmpty() { return  new Gc_obj; }
hx::ObjectPtr< Gc_obj > Gc_obj::__new()
{  hx::ObjectPtr< Gc_obj > result = new Gc_obj();
	result->__construct();
	return result;}

Dynamic Gc_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Gc_obj > result = new Gc_obj();
	result->__construct();
	return result;}

Void Gc_obj::enable( bool inEnable){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Gc_obj::enable")
		HX_SOURCE_POS("/usr/lib/haxe/std/cpp/vm/Gc.hx",7)
		::__hxcpp_enable(inEnable);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Gc_obj,enable,(void))

Void Gc_obj::run( bool major){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Gc_obj::run")
		HX_SOURCE_POS("/usr/lib/haxe/std/cpp/vm/Gc.hx",12)
		::__hxcpp_collect();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Gc_obj,run,(void))

int Gc_obj::trace( ::Class sought,Dynamic __o_printInstances){
bool printInstances = __o_printInstances.Default(true);
	HX_SOURCE_PUSH("Gc_obj::trace");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/std/cpp/vm/Gc.hx",17)
		return ::__hxcpp_gc_trace(sought,printInstances);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Gc_obj,trace,return )


Gc_obj::Gc_obj()
{
}

void Gc_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Gc);
	HX_MARK_END_CLASS();
}

Dynamic Gc_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"trace") ) { return trace_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"enable") ) { return enable_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Gc_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Gc_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("enable"),
	HX_CSTRING("run"),
	HX_CSTRING("trace"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Gc_obj::__mClass;

void Gc_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.vm.Gc"), hx::TCanCast< Gc_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Gc_obj::__boot()
{
}

} // end namespace cpp
} // end namespace vm
