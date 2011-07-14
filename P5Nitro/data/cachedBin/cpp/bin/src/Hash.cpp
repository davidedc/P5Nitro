#include <hxcpp.h>

#ifndef INCLUDED_Hash
#include <Hash.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void Hash_obj::__construct()
{
{
	struct _Function_1_1{
		inline static Dynamic Block( ){
			hx::Anon __result = hx::Anon_obj::Create();
			return __result;
		}
	};
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",30)
	this->__Internal = _Function_1_1::Block();
}
;
	return null();
}

Hash_obj::~Hash_obj() { }

Dynamic Hash_obj::__CreateEmpty() { return  new Hash_obj; }
hx::ObjectPtr< Hash_obj > Hash_obj::__new()
{  hx::ObjectPtr< Hash_obj > result = new Hash_obj();
	result->__construct();
	return result;}

Dynamic Hash_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Hash_obj > result = new Hash_obj();
	result->__construct();
	return result;}

Void Hash_obj::set( ::String key,Dynamic value){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Hash_obj::set")
		HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",34)
		this->__Internal->__SetField(key,value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Hash_obj,set,(void))

Dynamic Hash_obj::get( ::String key){
	__SAFE_POINT
	HX_SOURCE_PUSH("Hash_obj::get")
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",38)
	return this->__Internal->__Field(key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,get,return )

bool Hash_obj::exists( ::String key){
	__SAFE_POINT
	HX_SOURCE_PUSH("Hash_obj::exists")
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",42)
	return this->__Internal->__HasField(key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,exists,return )

bool Hash_obj::remove( ::String key){
	__SAFE_POINT
	HX_SOURCE_PUSH("Hash_obj::remove")
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",46)
	return ::__hxcpp_anon_remove(this->__Internal,key);
}


HX_DEFINE_DYNAMIC_FUNC1(Hash_obj,remove,return )

Dynamic Hash_obj::keys( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Hash_obj::keys")
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",53)
	Array< ::String > a = Array_obj< ::String >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",54)
	this->__Internal->__GetFields(a);
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",55)
	return a->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,keys,return )

Dynamic Hash_obj::iterator( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Hash_obj::iterator")
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",62)
	Array< ::String > a = Array_obj< ::String >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",63)
	this->__Internal->__GetFields(a);
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",64)
	Array< Dynamic > it = Array_obj< Dynamic >::__new().Add(a->iterator());
	struct _Function_1_1{
		inline static Dynamic Block( Array< Dynamic > &it,Dynamic &__Internal){
			hx::Anon __result = hx::Anon_obj::Create();

			HX_BEGIN_LOCAL_FUNC1(_Function_2_1,Array< Dynamic >,it)
			bool run(){
{
					__SAFE_POINT
					HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",66)
					return it->__get((int)0)->__Field(HX_CSTRING("hasNext"))();
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1(it)));

			HX_BEGIN_LOCAL_FUNC2(_Function_2_2,Dynamic,__Internal,Array< Dynamic >,it)
			Dynamic run(){
{
					__SAFE_POINT
					HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",67)
					return __Internal->__Field(it->__get((int)0)->__Field(HX_CSTRING("next"))());
				}
				return null();
			}
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2(__Internal,it)));
			return __result;
		}
	};
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",65)
	return _Function_1_1::Block(it,__Internal);
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,iterator,return )

::String Hash_obj::toString( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Hash_obj::toString")
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",76)
	::StringBuf s = ::StringBuf_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",77)
	s->b[s->b->length] = HX_CSTRING("{");
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",78)
	Dynamic it = this->keys();
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",79)
	for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(it);  __it->hasNext(); ){
		::String i = __it->next();
		{
			HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",80)
			s->b[s->b->length] = i;
			HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",81)
			s->b[s->b->length] = HX_CSTRING(" => ");
			HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",82)
			s->b[s->b->length] = ::Std_obj::string(this->get(i));
			HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",83)
			if ((it->__Field(HX_CSTRING("hasNext"))()))
				s->b[s->b->length] = HX_CSTRING(", ");
		}
;
		__SAFE_POINT
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",86)
	s->b[s->b->length] = HX_CSTRING("}");
	HX_SOURCE_POS("/usr/lib/haxe/std/cpp/_std/Hash.hx",87)
	return s->b->join(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Hash_obj,toString,return )


Hash_obj::Hash_obj()
{
}

void Hash_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Hash);
	HX_MARK_MEMBER_NAME(__Internal,"__Internal");
	HX_MARK_END_CLASS();
}

Dynamic Hash_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"keys") ) { return keys_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"exists") ) { return exists_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { return __Internal; }
	}
	return super::__Field(inName);
}

Dynamic Hash_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { __Internal=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Hash_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__Internal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__Internal"),
	HX_CSTRING("set"),
	HX_CSTRING("get"),
	HX_CSTRING("exists"),
	HX_CSTRING("remove"),
	HX_CSTRING("keys"),
	HX_CSTRING("iterator"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Hash_obj::__mClass;

void Hash_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("Hash"), hx::TCanCast< Hash_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Hash_obj::__boot()
{
}

