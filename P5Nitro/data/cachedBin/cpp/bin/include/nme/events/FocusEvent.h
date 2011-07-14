#ifndef INCLUDED_nme_events_FocusEvent
#define INCLUDED_nme_events_FocusEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,FocusEvent)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace nme{
namespace events{


class FocusEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef FocusEvent_obj OBJ_;
		FocusEvent_obj();
		Void __construct(::String inType,Dynamic __o_bubbles,Dynamic __o_cancelable,::nme::display::InteractiveObject inRelatedObject,Dynamic __o_inShiftKey,Dynamic __o_inKeyCode,Dynamic __o_inDirection);

	public:
		static hx::ObjectPtr< FocusEvent_obj > __new(::String inType,Dynamic __o_bubbles,Dynamic __o_cancelable,::nme::display::InteractiveObject inRelatedObject,Dynamic __o_inShiftKey,Dynamic __o_inKeyCode,Dynamic __o_inDirection);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FocusEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FocusEvent"); }

		int keyCode; /* REM */ 
		::nme::display::InteractiveObject relatedObject; /* REM */ 
		bool shiftKey; /* REM */ 
		static ::String FOCUS_IN; /* REM */ 
		static ::String FOCUS_OUT; /* REM */ 
		static ::String KEY_FOCUS_CHANGE; /* REM */ 
		static ::String MOUSE_FOCUS_CHANGE; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_FocusEvent */ 
