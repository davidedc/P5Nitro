#ifndef INCLUDED_nme_display_InteractiveObject
#define INCLUDED_nme_display_InteractiveObject

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/DisplayObject.h>
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace nme{
namespace display{


class InteractiveObject_obj : public ::nme::display::DisplayObject_obj{
	public:
		typedef ::nme::display::DisplayObject_obj super;
		typedef InteractiveObject_obj OBJ_;
		InteractiveObject_obj();
		Void __construct(Dynamic inHandle,::String inType);

	public:
		static hx::ObjectPtr< InteractiveObject_obj > __new(Dynamic inHandle,::String inType);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InteractiveObject_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InteractiveObject"); }

		bool mouseEnabled; /* REM */ 
		bool nmeMouseEnabled; /* REM */ 
		bool doubleClickEnabled; /* REM */ 
		virtual bool nmeGetMouseEnabled( );
		Dynamic nmeGetMouseEnabled_dyn();

		virtual bool nmeSetMouseEnabled( bool inVal);
		Dynamic nmeSetMouseEnabled_dyn();

		virtual ::nme::display::InteractiveObject nmeAsInteractiveObject( );
		Dynamic nmeAsInteractiveObject_dyn();

		static Dynamic nme_display_object_set_mouse_enabled; /* REM */ 
	Dynamic &nme_display_object_set_mouse_enabled_dyn() { return nme_display_object_set_mouse_enabled;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_InteractiveObject */ 
