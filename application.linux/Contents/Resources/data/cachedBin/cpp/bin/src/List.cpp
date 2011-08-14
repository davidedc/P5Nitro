#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif

Void List_obj::__construct()
{
{
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",45)
	this->length = (int)0;
}
;
	return null();
}

List_obj::~List_obj() { }

Dynamic List_obj::__CreateEmpty() { return  new List_obj; }
hx::ObjectPtr< List_obj > List_obj::__new()
{  hx::ObjectPtr< List_obj > result = new List_obj();
	result->__construct();
	return result;}

Dynamic List_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< List_obj > result = new List_obj();
	result->__construct();
	return result;}

Void List_obj::add( Dynamic item){
{
		HX_SOURCE_PUSH("List_obj::add")
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",52)
		Dynamic x = Dynamic( Array_obj<Dynamic>::__new().Add(item));
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",53)
		if (((this->h == null()))){
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",54)
			this->h = x;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",56)
			this->q[(int)1] = x;
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",57)
		this->q = x;
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",58)
		(this->length)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,add,(void))

Void List_obj::push( Dynamic item){
{
		HX_SOURCE_PUSH("List_obj::push")
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",65)
		Array< Dynamic > x = Array_obj< Dynamic >::__new().Add(item).Add(this->h);
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",70)
		this->h = x;
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",71)
		if (((this->q == null())))
			this->q = x;
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",73)
		(this->length)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,push,(void))

Dynamic List_obj::first( ){
	HX_SOURCE_PUSH("List_obj::first")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",81)
	return (  (((this->h == null()))) ? Dynamic(null()) : Dynamic(this->h->__get((int)0)) );
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,first,return )

Dynamic List_obj::last( ){
	HX_SOURCE_PUSH("List_obj::last")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",89)
	return (  (((this->q == null()))) ? Dynamic(null()) : Dynamic(this->q->__get((int)0)) );
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,last,return )

Dynamic List_obj::pop( ){
	HX_SOURCE_PUSH("List_obj::pop")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",99)
	if (((this->h == null())))
		return null();
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",101)
	Dynamic x = this->h->__get((int)0);
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",102)
	this->h = this->h->__get((int)1);
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",103)
	if (((this->h == null())))
		this->q = null();
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",105)
	(this->length)--;
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",106)
	return x;
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,pop,return )

bool List_obj::isEmpty( ){
	HX_SOURCE_PUSH("List_obj::isEmpty")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",113)
	return (this->h == null());
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,isEmpty,return )

Void List_obj::clear( ){
{
		HX_SOURCE_PUSH("List_obj::clear")
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",120)
		this->h = null();
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",121)
		this->q = null();
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",122)
		this->length = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,clear,(void))

bool List_obj::remove( Dynamic v){
	HX_SOURCE_PUSH("List_obj::remove")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",130)
	Array< Dynamic > prev = null();
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",131)
	Array< Dynamic > l = this->h;
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",132)
	while((l != null())){
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",133)
		if (((l->__get((int)0) == v))){
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",134)
			if (((prev == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",135)
				this->h = l->__get((int)1);
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",137)
				prev[(int)1] = l->__get((int)1);
			}
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",138)
			if (((this->q == l)))
				this->q = prev;
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",140)
			(this->length)--;
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",141)
			return true;
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",143)
		prev = l;
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",144)
		l = l->__get((int)1);
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",146)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,remove,return )

Dynamic List_obj::iterator( ){
	HX_SOURCE_PUSH("List_obj::iterator")
	struct _Function_1_1{
		inline static Dynamic Block( ::List_obj *__this){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("h") , __this->h);

			HX_BEGIN_LOCAL_FUNC0(_Function_2_1)
			Dynamic run(){
{
					HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",156)
					return (__this->__Field(HX_CSTRING("h")) != null());
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("hasNext") ,  Dynamic(new _Function_2_1()));

			HX_BEGIN_LOCAL_FUNC0(_Function_2_2)
			Dynamic run(){
{
					HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",159)
					{
						HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",160)
						if (((__this->__Field(HX_CSTRING("h")) == null())))
							return null();
						HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",162)
						Dynamic x = __this->__Field(HX_CSTRING("h"))->__GetItem((int)0);
						HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",163)
						__this->__FieldRef(HX_CSTRING("h")) = __this->__Field(HX_CSTRING("h"))->__GetItem((int)1);
						HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",164)
						return x;
					}
				}
				return null();
			}
			Dynamic __this;
			void __SetThis(Dynamic inThis) { __this = inThis; }
			HX_END_LOCAL_FUNC0(return)

			__result->Add(HX_CSTRING("next") ,  Dynamic(new _Function_2_2()));
			return __result;
		}
	};
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",153)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,iterator,return )

::String List_obj::toString( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("List_obj::toString")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",174)
	::StringBuf s = ::StringBuf_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",175)
	bool first = true;
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",176)
	Array< Dynamic > l = this->h;
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",177)
	s->b[s->b->length] = HX_CSTRING("{");
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",178)
	while((l != null())){
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",179)
		if ((first)){
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",180)
			first = false;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",182)
			s->b[s->b->length] = HX_CSTRING(", ");
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",183)
		s->b[s->b->length] = ::Std_obj::string(l->__get((int)0));
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",184)
		l = l->__get((int)1);
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",186)
	s->b[s->b->length] = HX_CSTRING("}");
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",187)
	return s->b->join(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(List_obj,toString,return )

::String List_obj::join( ::String sep){
	__SAFE_POINT
	HX_SOURCE_PUSH("List_obj::join")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",194)
	::StringBuf s = ::StringBuf_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",195)
	bool first = true;
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",196)
	Array< Dynamic > l = this->h;
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",197)
	while((l != null())){
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",198)
		if ((first)){
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",199)
			first = false;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",201)
			s->b[s->b->length] = sep;
		}
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",202)
		s->b[s->b->length] = l->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",203)
		l = l->__get((int)1);
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",205)
	return s->b->join(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,join,return )

::List List_obj::filter( Dynamic f){
	__SAFE_POINT
	HX_SOURCE_PUSH("List_obj::filter")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",213)
	::List l2 = ::List_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",214)
	Array< Dynamic > l = this->h;
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",215)
	while((l != null())){
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",216)
		Dynamic v = l->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",217)
		l = l->__get((int)1);
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",218)
		if ((f(v)))
			l2->add(v);
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",221)
	return l2;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,filter,return )

::List List_obj::map( Dynamic f){
	__SAFE_POINT
	HX_SOURCE_PUSH("List_obj::map")
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",229)
	::List b = ::List_obj::__new();
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",230)
	Array< Dynamic > l = this->h;
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",231)
	while((l != null())){
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",232)
		Dynamic v = l->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",233)
		l = l->__get((int)1);
		HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",234)
		b->add(f(v));
	}
	HX_SOURCE_POS("/usr/lib/haxe/std/List.hx",236)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(List_obj,map,return )


List_obj::List_obj()
{
}

void List_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(List);
	HX_MARK_MEMBER_NAME(h,"h");
	HX_MARK_MEMBER_NAME(q,"q");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

Dynamic List_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { return h; }
		if (HX_FIELD_EQ(inName,"q") ) { return q; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"pop") ) { return pop_dyn(); }
		if (HX_FIELD_EQ(inName,"map") ) { return map_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"push") ) { return push_dyn(); }
		if (HX_FIELD_EQ(inName,"last") ) { return last_dyn(); }
		if (HX_FIELD_EQ(inName,"join") ) { return join_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"first") ) { return first_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"filter") ) { return filter_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic List_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"h") ) { h=inValue.Cast< Array< Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"q") ) { q=inValue.Cast< Array< Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void List_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("h"));
	outFields->push(HX_CSTRING("q"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("h"),
	HX_CSTRING("q"),
	HX_CSTRING("length"),
	HX_CSTRING("add"),
	HX_CSTRING("push"),
	HX_CSTRING("first"),
	HX_CSTRING("last"),
	HX_CSTRING("pop"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("clear"),
	HX_CSTRING("remove"),
	HX_CSTRING("iterator"),
	HX_CSTRING("toString"),
	HX_CSTRING("join"),
	HX_CSTRING("filter"),
	HX_CSTRING("map"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class List_obj::__mClass;

void List_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("List"), hx::TCanCast< List_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void List_obj::__boot()
{
}

