#ifndef INCLUDED_HighDpiScreenManager
#define INCLUDED_HighDpiScreenManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(HighDpiScreenManager)


class HighDpiScreenManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HighDpiScreenManager_obj OBJ_;
		HighDpiScreenManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HighDpiScreenManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HighDpiScreenManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HighDpiScreenManager"); }

		static double dpiScaleFactor; /* REM */ 
};


#endif /* INCLUDED_HighDpiScreenManager */ 
