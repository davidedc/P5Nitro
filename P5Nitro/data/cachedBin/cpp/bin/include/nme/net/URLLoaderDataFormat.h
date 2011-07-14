#ifndef INCLUDED_nme_net_URLLoaderDataFormat
#define INCLUDED_nme_net_URLLoaderDataFormat

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,net,URLLoaderDataFormat)
namespace nme{
namespace net{


class URLLoaderDataFormat_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef URLLoaderDataFormat_obj OBJ_;

	public:
		URLLoaderDataFormat_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("nme.net.URLLoaderDataFormat"); }
		::String __ToString() const { return HX_CSTRING("URLLoaderDataFormat.") + tag; }

		static ::nme::net::URLLoaderDataFormat BINARY;
		static ::nme::net::URLLoaderDataFormat TEXT;
		static ::nme::net::URLLoaderDataFormat VARIABLES;
};

} // end namespace nme
} // end namespace net

#endif /* INCLUDED_nme_net_URLLoaderDataFormat */ 
