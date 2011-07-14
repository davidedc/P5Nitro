#ifndef INCLUDED_nme_system_System
#define INCLUDED_nme_system_System

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,system,System)
namespace nme{
namespace system{


class System_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef System_obj OBJ_;
		System_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< System_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~System_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("System"); }

		static int totalMemory; /* REM */ 
		static int nmeGetTotalMemory( );
		static Dynamic nmeGetTotalMemory_dyn();

		static Void gc( );
		static Dynamic gc_dyn();

		static Void exit( );
		static Dynamic exit_dyn();

};

} // end namespace nme
} // end namespace system

#endif /* INCLUDED_nme_system_System */ 
