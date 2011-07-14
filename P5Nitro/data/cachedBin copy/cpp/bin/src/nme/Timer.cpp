#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Timer
#include <nme/Timer.h>
#endif
namespace nme{

Void Timer_obj::__construct(double time)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",16)
	this->mTime = time;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",17)
	::nme::Timer_obj::sRunningTimers->push(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",18)
	this->mFireAt = (::nme::Timer_obj::GetMS() + this->mTime);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",19)
	this->mRunning = true;
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hx::ObjectPtr< Timer_obj > Timer_obj::__new(double time)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(time);
	return result;}

Dynamic Timer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Timer_obj > result = new Timer_obj();
	result->__construct(inArgs[0]);
	return result;}

HX_BEGIN_DEFAULT_FUNC(__default_run,Timer_obj)
Void run(){
{
		HX_SOURCE_PUSH("Timer_obj::run")
	}
return null();
}
HX_END_LOCAL_FUNC0((void))
HX_END_DEFAULT_FUNC

Void Timer_obj::stop( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Timer_obj::stop")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",27)
		if ((this->mRunning)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",29)
			this->mRunning = false;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",30)
			::nme::Timer_obj::sRunningTimers->remove(hx::ObjectPtr<OBJ_>(this));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stop,(void))

Void Timer_obj::nmeCheck( double inTime){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Timer_obj::nmeCheck")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",52)
		if (((inTime >= this->mFireAt))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",54)
			hx::AddEq(this->mFireAt,this->mTime);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",55)
			this->run();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Timer_obj,nmeCheck,(void))

Array< ::nme::Timer > Timer_obj::sRunningTimers;

double Timer_obj::nmeNextWake( double limit){
	__SAFE_POINT
	HX_SOURCE_PUSH("Timer_obj::nmeNextWake")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",36)
	double now = (::nme::Timer_obj::nme_time_stamp() * 1000.0);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",37)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",37)
		int _g = (int)0;
		Array< ::nme::Timer > _g1 = ::nme::Timer_obj::sRunningTimers;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",37)
		while((_g < _g1->length)){
			__SAFE_POINT
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",37)
			::nme::Timer timer = _g1->__get(_g);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",37)
			++(_g);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",39)
			double sleep = (timer->mFireAt - now);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",40)
			if (((sleep < limit))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",42)
				limit = sleep;
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",43)
				if (((limit < (int)0)))
					return (int)0;
			}
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",47)
	return limit;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Timer_obj,nmeNextWake,return )

Void Timer_obj::nmeCheckTimers( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Timer_obj::nmeCheckTimers")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",61)
		double now = ::nme::Timer_obj::GetMS();
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",62)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",62)
			int _g = (int)0;
			Array< ::nme::Timer > _g1 = ::nme::Timer_obj::sRunningTimers;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",62)
			while((_g < _g1->length)){
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",62)
				::nme::Timer timer = _g1->__get(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",62)
				++(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",63)
				timer->nmeCheck(now);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,nmeCheckTimers,(void))

double Timer_obj::GetMS( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Timer_obj::GetMS")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",68)
	return (::nme::Timer_obj::stamp() * 1000.0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,GetMS,return )

::nme::Timer Timer_obj::delay( Dynamic $t1,int time){
	__SAFE_POINT
	HX_SOURCE_PUSH("Timer_obj::delay")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",73)
	Array< Dynamic > f = Array_obj< Dynamic >::__new().Add($t1);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",74)
	Array< ::nme::Timer > t = Array_obj< ::nme::Timer >::__new().Add(::nme::Timer_obj::__new(time));

	HX_BEGIN_LOCAL_FUNC2(_Function_1_1,Array< ::nme::Timer >,t,Array< Dynamic >,f)
	Void run(){
{
			__SAFE_POINT
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",76)
			t->__get((int)0)->stop();
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",77)
			f->__get((int)0)();
		}
		return null();
	}
	HX_END_LOCAL_FUNC0((void))

	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",75)
	t->__get((int)0)->run =  Dynamic(new _Function_1_1(t,f));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",79)
	return t->__get((int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Timer_obj,delay,return )

double Timer_obj::stamp( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Timer_obj::stamp")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Timer.hx",85)
	return ::nme::Timer_obj::nme_time_stamp();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Timer_obj,stamp,return )

Dynamic Timer_obj::nme_time_stamp;


Timer_obj::Timer_obj()
{
	run = new __default_run(this);
}

void Timer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Timer);
	HX_MARK_MEMBER_NAME(mTime,"mTime");
	HX_MARK_MEMBER_NAME(mFireAt,"mFireAt");
	HX_MARK_MEMBER_NAME(mRunning,"mRunning");
	HX_MARK_MEMBER_NAME(run,"run");
	HX_MARK_END_CLASS();
}

Dynamic Timer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { return run; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"GetMS") ) { return GetMS_dyn(); }
		if (HX_FIELD_EQ(inName,"delay") ) { return delay_dyn(); }
		if (HX_FIELD_EQ(inName,"stamp") ) { return stamp_dyn(); }
		if (HX_FIELD_EQ(inName,"mTime") ) { return mTime; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mFireAt") ) { return mFireAt; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mRunning") ) { return mRunning; }
		if (HX_FIELD_EQ(inName,"nmeCheck") ) { return nmeCheck_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nmeNextWake") ) { return nmeNextWake_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sRunningTimers") ) { return sRunningTimers; }
		if (HX_FIELD_EQ(inName,"nmeCheckTimers") ) { return nmeCheckTimers_dyn(); }
		if (HX_FIELD_EQ(inName,"nme_time_stamp") ) { return nme_time_stamp; }
	}
	return super::__Field(inName);
}

Dynamic Timer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"run") ) { run=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mTime") ) { mTime=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mFireAt") ) { mFireAt=inValue.Cast< double >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"mRunning") ) { mRunning=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"sRunningTimers") ) { sRunningTimers=inValue.Cast< Array< ::nme::Timer > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_time_stamp") ) { nme_time_stamp=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Timer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mTime"));
	outFields->push(HX_CSTRING("mFireAt"));
	outFields->push(HX_CSTRING("mRunning"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("sRunningTimers"),
	HX_CSTRING("nmeNextWake"),
	HX_CSTRING("nmeCheckTimers"),
	HX_CSTRING("GetMS"),
	HX_CSTRING("delay"),
	HX_CSTRING("stamp"),
	HX_CSTRING("nme_time_stamp"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mTime"),
	HX_CSTRING("mFireAt"),
	HX_CSTRING("mRunning"),
	HX_CSTRING("run"),
	HX_CSTRING("stop"),
	HX_CSTRING("nmeCheck"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Timer_obj::sRunningTimers,"sRunningTimers");
	HX_MARK_MEMBER_NAME(Timer_obj::nme_time_stamp,"nme_time_stamp");
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.Timer"), hx::TCanCast< Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Timer_obj::__boot()
{
	hx::Static(sRunningTimers) = Array_obj< ::nme::Timer >::__new();
	hx::Static(nme_time_stamp) = ::nme::Loader_obj::load(HX_CSTRING("nme_time_stamp"),(int)0);
}

} // end namespace nme
