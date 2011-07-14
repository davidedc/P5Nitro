#include <hxcpp.h>

#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
namespace nme{
namespace net{

Void URLRequest_obj::__construct(::String inURL)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",21)
	if (((inURL != null())))
		this->url = inURL;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",23)
	this->verbose = false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",24)
	this->userPassword = HX_CSTRING("");
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",25)
	this->cookieString = HX_CSTRING("");
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",26)
	this->authType = (int)0;
}
;
	return null();
}

URLRequest_obj::~URLRequest_obj() { }

Dynamic URLRequest_obj::__CreateEmpty() { return  new URLRequest_obj; }
hx::ObjectPtr< URLRequest_obj > URLRequest_obj::__new(::String inURL)
{  hx::ObjectPtr< URLRequest_obj > result = new URLRequest_obj();
	result->__construct(inURL);
	return result;}

Dynamic URLRequest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLRequest_obj > result = new URLRequest_obj();
	result->__construct(inArgs[0]);
	return result;}

Void URLRequest_obj::basicAuth( ::String inUser,::String inPasswd){
{
		HX_SOURCE_PUSH("URLRequest_obj::basicAuth")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",31)
		this->authType = (int)1;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",32)
		this->userPassword = ((inUser + HX_CSTRING(":")) + inPasswd);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(URLRequest_obj,basicAuth,(void))

Void URLRequest_obj::digestAuth( ::String inUser,::String inPasswd){
{
		HX_SOURCE_PUSH("URLRequest_obj::digestAuth")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",37)
		this->authType = (int)2;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/net/URLRequest.hx",38)
		this->userPassword = ((inUser + HX_CSTRING(":")) + inPasswd);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(URLRequest_obj,digestAuth,(void))

int URLRequest_obj::AUTH_BASIC;

int URLRequest_obj::AUTH_DIGEST;

int URLRequest_obj::AUTH_GSSNEGOTIATE;

int URLRequest_obj::AUTH_NTLM;

int URLRequest_obj::AUTH_DIGEST_IE;

int URLRequest_obj::AUTH_DIGEST_ANY;


URLRequest_obj::URLRequest_obj()
{
}

void URLRequest_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLRequest);
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(verbose,"verbose");
	HX_MARK_MEMBER_NAME(userPassword,"userPassword");
	HX_MARK_MEMBER_NAME(authType,"authType");
	HX_MARK_MEMBER_NAME(cookieString,"cookieString");
	HX_MARK_END_CLASS();
}

Dynamic URLRequest_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { return verbose; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"authType") ) { return authType; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"AUTH_NTLM") ) { return AUTH_NTLM; }
		if (HX_FIELD_EQ(inName,"basicAuth") ) { return basicAuth_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"AUTH_BASIC") ) { return AUTH_BASIC; }
		if (HX_FIELD_EQ(inName,"digestAuth") ) { return digestAuth_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST") ) { return AUTH_DIGEST; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"userPassword") ) { return userPassword; }
		if (HX_FIELD_EQ(inName,"cookieString") ) { return cookieString; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST_IE") ) { return AUTH_DIGEST_IE; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST_ANY") ) { return AUTH_DIGEST_ANY; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"AUTH_GSSNEGOTIATE") ) { return AUTH_GSSNEGOTIATE; }
	}
	return super::__Field(inName);
}

Dynamic URLRequest_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { verbose=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"authType") ) { authType=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"AUTH_NTLM") ) { AUTH_NTLM=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"AUTH_BASIC") ) { AUTH_BASIC=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST") ) { AUTH_DIGEST=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"userPassword") ) { userPassword=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cookieString") ) { cookieString=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST_IE") ) { AUTH_DIGEST_IE=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"AUTH_DIGEST_ANY") ) { AUTH_DIGEST_ANY=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"AUTH_GSSNEGOTIATE") ) { AUTH_GSSNEGOTIATE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void URLRequest_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("verbose"));
	outFields->push(HX_CSTRING("userPassword"));
	outFields->push(HX_CSTRING("authType"));
	outFields->push(HX_CSTRING("cookieString"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("AUTH_BASIC"),
	HX_CSTRING("AUTH_DIGEST"),
	HX_CSTRING("AUTH_GSSNEGOTIATE"),
	HX_CSTRING("AUTH_NTLM"),
	HX_CSTRING("AUTH_DIGEST_IE"),
	HX_CSTRING("AUTH_DIGEST_ANY"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("url"),
	HX_CSTRING("verbose"),
	HX_CSTRING("userPassword"),
	HX_CSTRING("authType"),
	HX_CSTRING("cookieString"),
	HX_CSTRING("basicAuth"),
	HX_CSTRING("digestAuth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_BASIC,"AUTH_BASIC");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_DIGEST,"AUTH_DIGEST");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_GSSNEGOTIATE,"AUTH_GSSNEGOTIATE");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_NTLM,"AUTH_NTLM");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_DIGEST_IE,"AUTH_DIGEST_IE");
	HX_MARK_MEMBER_NAME(URLRequest_obj::AUTH_DIGEST_ANY,"AUTH_DIGEST_ANY");
};

Class URLRequest_obj::__mClass;

void URLRequest_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.net.URLRequest"), hx::TCanCast< URLRequest_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void URLRequest_obj::__boot()
{
	hx::Static(AUTH_BASIC) = (int)1;
	hx::Static(AUTH_DIGEST) = (int)2;
	hx::Static(AUTH_GSSNEGOTIATE) = (int)4;
	hx::Static(AUTH_NTLM) = (int)8;
	hx::Static(AUTH_DIGEST_IE) = (int)16;
	hx::Static(AUTH_DIGEST_ANY) = (int)15;
}

} // end namespace nme
} // end namespace net
