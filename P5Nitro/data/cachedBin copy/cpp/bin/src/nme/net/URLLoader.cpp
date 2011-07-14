#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_events_ErrorEvent
#include <nme/events/ErrorEvent.h>
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
#ifndef INCLUDED_nme_events_IOErrorEvent
#include <nme/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_nme_events_ProgressEvent
#include <nme/events/ProgressEvent.h>
#endif
#ifndef INCLUDED_nme_events_TextEvent
#include <nme/events/TextEvent.h>
#endif
#ifndef INCLUDED_nme_net_URLLoader
#include <nme/net/URLLoader.h>
#endif
#ifndef INCLUDED_nme_net_URLLoaderDataFormat
#include <nme/net/URLLoaderDataFormat.h>
#endif
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
namespace nme{
namespace net{

Void URLLoader_obj::__construct(::nme::net::URLRequest request)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",47)
	super::__construct(null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",48)
	this->nmeHandle = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",49)
	this->bytesLoaded = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",50)
	this->bytesTotal = (int)-1;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",51)
	this->state = (int)0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",52)
	this->dataFormat = ::nme::net::URLLoaderDataFormat_obj::TEXT;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",53)
	if (((request != null())))
		this->load(request);
}
;
	return null();
}

URLLoader_obj::~URLLoader_obj() { }

Dynamic URLLoader_obj::__CreateEmpty() { return  new URLLoader_obj; }
hx::ObjectPtr< URLLoader_obj > URLLoader_obj::__new(::nme::net::URLRequest request)
{  hx::ObjectPtr< URLLoader_obj > result = new URLLoader_obj();
	result->__construct(request);
	return result;}

Dynamic URLLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLLoader_obj > result = new URLLoader_obj();
	result->__construct(inArgs[0]);
	return result;}

Void URLLoader_obj::close( ){
{
		HX_SOURCE_PUSH("URLLoader_obj::close")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,close,(void))

Void URLLoader_obj::load( ::nme::net::URLRequest request){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("URLLoader_obj::load")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",61)
		this->state = (int)1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",62)
		if (((request->url.substr((int)0,(int)7) != HX_CSTRING("http://")))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",64)
			try{
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",65)
				::nme::utils::ByteArray bytes = ::nme::utils::ByteArray_obj::readFile(request->url);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",66)
				{
::nme::net::URLLoaderDataFormat _switch_1 = this->dataFormat;
					switch((_switch_1)->GetIndex()){
						case 1: case 2: {
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",69)
							this->data = bytes->asString();
						}
						;break;
						default: {
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",71)
							this->data = bytes;
						}
					}
				}
			}
			catch(Dynamic __e){
				{
					Dynamic e = __e;{
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",74)
						this->onError(e);
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",75)
						return null();
					}
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",77)
			this->dispatchEvent(::nme::events::Event_obj::__new(::nme::events::Event_obj::COMPLETE,null(),null()));
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",81)
			this->nmeHandle = ::nme::net::URLLoader_obj::nme_curl_create(request->url,request->authType,request->userPassword,request->cookieString,request->verbose);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",83)
			if (((this->nmeHandle == null()))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",85)
				this->onError(HX_CSTRING("Could not open URL"));
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",88)
				::nme::net::URLLoader_obj::activeLoaders->push(hx::ObjectPtr<OBJ_>(this));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,load,(void))

Void URLLoader_obj::update( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("URLLoader_obj::update")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",96)
		if (((this->nmeHandle != null()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",98)
			int old_state = this->state;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",99)
			int old_loaded = this->bytesLoaded;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",100)
			int old_total = this->bytesTotal;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",101)
			::nme::net::URLLoader_obj::nme_curl_update_loader(this->nmeHandle,hx::ObjectPtr<OBJ_>(this));
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",102)
			if (((bool((old_total < (int)0)) && bool((this->bytesTotal > (int)0))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",104)
				this->dispatchEvent(::nme::events::Event_obj::__new(::nme::events::Event_obj::OPEN,null(),null()));
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",107)
			if (((bool((this->bytesTotal > (int)0)) && bool((this->bytesLoaded != old_loaded))))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",110)
				this->dispatchEvent(::nme::events::ProgressEvent_obj::__new(HX_CSTRING("progress"),false,false,this->bytesLoaded,this->bytesTotal));
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",113)
			if (((this->state == (int)3))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",116)
				::nme::utils::ByteArray bytes = ::nme::utils::ByteArray_obj::fromHandle(::nme::net::URLLoader_obj::nme_curl_get_data(this->nmeHandle));
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",117)
				{
::nme::net::URLLoaderDataFormat _switch_2 = this->dataFormat;
					switch((_switch_2)->GetIndex()){
						case 1: case 2: {
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",120)
							this->data = bytes->asString();
						}
						;break;
						default: {
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",122)
							this->data = bytes;
						}
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",124)
				this->nmeHandle = null();
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",125)
				this->dispatchEvent(::nme::events::Event_obj::__new(::nme::events::Event_obj::COMPLETE,null(),null()));
			}
			else{
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",127)
				if (((this->state == (int)4))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",129)
					::nme::events::IOErrorEvent evt = ::nme::events::IOErrorEvent_obj::__new(::nme::events::IOErrorEvent_obj::IO_ERROR,true,false,::nme::net::URLLoader_obj::nme_curl_get_error_message(this->nmeHandle),::nme::net::URLLoader_obj::nme_curl_get_code(this->nmeHandle));
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",131)
					this->nmeHandle = null();
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",132)
					this->dispatchEvent(evt);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,update,(void))

Void URLLoader_obj::onError( ::String msg){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("URLLoader_obj::onError")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",155)
		this->dispatchEvent(::nme::events::IOErrorEvent_obj::__new(::nme::events::IOErrorEvent_obj::IO_ERROR,true,false,msg,null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,onError,(void))

Array< ::String > URLLoader_obj::getCookies( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("URLLoader_obj::getCookies")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",160)
	return ::nme::net::URLLoader_obj::nme_curl_get_cookies(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,getCookies,return )

int URLLoader_obj::urlInvalid;

int URLLoader_obj::urlInit;

int URLLoader_obj::urlLoading;

int URLLoader_obj::urlComplete;

int URLLoader_obj::urlError;

::List URLLoader_obj::activeLoaders;

bool URLLoader_obj::hasActive( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("URLLoader_obj::hasActive")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",92)
	return !(::nme::net::URLLoader_obj::activeLoaders->isEmpty());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,hasActive,return )

Void URLLoader_obj::nmePollData( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("URLLoader_obj::nmePollData")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",139)
		if ((!(::nme::net::URLLoader_obj::activeLoaders->isEmpty()))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",141)
			::nme::net::URLLoader_obj::nme_curl_process_loaders();
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",142)
			::List oldLoaders = ::nme::net::URLLoader_obj::activeLoaders;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",143)
			::nme::net::URLLoader_obj::activeLoaders = ::List_obj::__new();
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",144)
			for(::cpp::FastIterator_obj< ::nme::net::URLLoader > *__it = ::cpp::CreateFastIterator< ::nme::net::URLLoader >(oldLoaders->iterator());  __it->hasNext(); ){
				::nme::net::URLLoader loader = __it->next();
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",146)
					loader->update();
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",147)
					if (((loader->state == (int)2)))
						::nme::net::URLLoader_obj::activeLoaders->push(loader);
				}
;
				__SAFE_POINT
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,nmePollData,(void))

bool URLLoader_obj::nmeLoadPending( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("URLLoader_obj::nmeLoadPending")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLLoader.hx",163)
	return !(::nme::net::URLLoader_obj::activeLoaders->isEmpty());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,nmeLoadPending,return )

Dynamic URLLoader_obj::nme_curl_create;

Dynamic URLLoader_obj::nme_curl_process_loaders;

Dynamic URLLoader_obj::nme_curl_update_loader;

Dynamic URLLoader_obj::nme_curl_get_code;

Dynamic URLLoader_obj::nme_curl_get_error_message;

Dynamic URLLoader_obj::nme_curl_get_data;

Dynamic URLLoader_obj::nme_curl_get_cookies;


URLLoader_obj::URLLoader_obj()
{
}

void URLLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLLoader);
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(dataFormat,"dataFormat");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_MEMBER_NAME(state,"state");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic URLLoader_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"urlInit") ) { return urlInit; }
		if (HX_FIELD_EQ(inName,"onError") ) { return onError_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"urlError") ) { return urlError; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hasActive") ) { return hasActive_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"urlInvalid") ) { return urlInvalid; }
		if (HX_FIELD_EQ(inName,"urlLoading") ) { return urlLoading; }
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return bytesTotal; }
		if (HX_FIELD_EQ(inName,"dataFormat") ) { return dataFormat; }
		if (HX_FIELD_EQ(inName,"getCookies") ) { return getCookies_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"urlComplete") ) { return urlComplete; }
		if (HX_FIELD_EQ(inName,"nmePollData") ) { return nmePollData_dyn(); }
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return bytesLoaded; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeLoaders") ) { return activeLoaders; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nmeLoadPending") ) { return nmeLoadPending_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_curl_create") ) { return nme_curl_create; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_curl_get_code") ) { return nme_curl_get_code; }
		if (HX_FIELD_EQ(inName,"nme_curl_get_data") ) { return nme_curl_get_data; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_curl_get_cookies") ) { return nme_curl_get_cookies; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_curl_update_loader") ) { return nme_curl_update_loader; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_curl_process_loaders") ) { return nme_curl_process_loaders; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_curl_get_error_message") ) { return nme_curl_get_error_message; }
	}
	return super::__Field(inName);
}

Dynamic URLLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"urlInit") ) { urlInit=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"urlError") ) { urlError=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"urlInvalid") ) { urlInvalid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"urlLoading") ) { urlLoading=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dataFormat") ) { dataFormat=inValue.Cast< ::nme::net::URLLoaderDataFormat >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"urlComplete") ) { urlComplete=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeLoaders") ) { activeLoaders=inValue.Cast< ::List >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_curl_create") ) { nme_curl_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_curl_get_code") ) { nme_curl_get_code=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_curl_get_data") ) { nme_curl_get_data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_curl_get_cookies") ) { nme_curl_get_cookies=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_curl_update_loader") ) { nme_curl_update_loader=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_curl_process_loaders") ) { nme_curl_process_loaders=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_curl_get_error_message") ) { nme_curl_get_error_message=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void URLLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bytesLoaded"));
	outFields->push(HX_CSTRING("bytesTotal"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("dataFormat"));
	outFields->push(HX_CSTRING("nmeHandle"));
	outFields->push(HX_CSTRING("state"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("urlInvalid"),
	HX_CSTRING("urlInit"),
	HX_CSTRING("urlLoading"),
	HX_CSTRING("urlComplete"),
	HX_CSTRING("urlError"),
	HX_CSTRING("activeLoaders"),
	HX_CSTRING("hasActive"),
	HX_CSTRING("nmePollData"),
	HX_CSTRING("nmeLoadPending"),
	HX_CSTRING("nme_curl_create"),
	HX_CSTRING("nme_curl_process_loaders"),
	HX_CSTRING("nme_curl_update_loader"),
	HX_CSTRING("nme_curl_get_code"),
	HX_CSTRING("nme_curl_get_error_message"),
	HX_CSTRING("nme_curl_get_data"),
	HX_CSTRING("nme_curl_get_cookies"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("bytesLoaded"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("data"),
	HX_CSTRING("dataFormat"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("state"),
	HX_CSTRING("close"),
	HX_CSTRING("load"),
	HX_CSTRING("update"),
	HX_CSTRING("onError"),
	HX_CSTRING("getCookies"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlInvalid,"urlInvalid");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlInit,"urlInit");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlLoading,"urlLoading");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlComplete,"urlComplete");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlError,"urlError");
	HX_MARK_MEMBER_NAME(URLLoader_obj::activeLoaders,"activeLoaders");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_create,"nme_curl_create");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_process_loaders,"nme_curl_process_loaders");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_update_loader,"nme_curl_update_loader");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_get_code,"nme_curl_get_code");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_get_error_message,"nme_curl_get_error_message");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_get_data,"nme_curl_get_data");
	HX_MARK_MEMBER_NAME(URLLoader_obj::nme_curl_get_cookies,"nme_curl_get_cookies");
};

Class URLLoader_obj::__mClass;

void URLLoader_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.net.URLLoader"), hx::TCanCast< URLLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void URLLoader_obj::__boot()
{
	hx::Static(urlInvalid) = (int)0;
	hx::Static(urlInit) = (int)1;
	hx::Static(urlLoading) = (int)2;
	hx::Static(urlComplete) = (int)3;
	hx::Static(urlError) = (int)4;
	hx::Static(activeLoaders) = ::List_obj::__new();
	hx::Static(nme_curl_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_create"),(int)5);
	hx::Static(nme_curl_process_loaders) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_process_loaders"),(int)0);
	hx::Static(nme_curl_update_loader) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_update_loader"),(int)2);
	hx::Static(nme_curl_get_code) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_get_code"),(int)1);
	hx::Static(nme_curl_get_error_message) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_get_error_message"),(int)1);
	hx::Static(nme_curl_get_data) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_get_data"),(int)1);
	hx::Static(nme_curl_get_cookies) = ::nme::Loader_obj::load(HX_CSTRING("nme_curl_get_cookies"),(int)1);
}

} // end namespace nme
} // end namespace net
