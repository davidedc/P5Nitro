#ifndef INCLUDED_nme_events_MouseEvent
#define INCLUDED_nme_events_MouseEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/events/Event.h>
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,events,MouseEvent)
HX_DECLARE_CLASS2(nme,geom,Point)
namespace nme{
namespace events{


class MouseEvent_obj : public ::nme::events::Event_obj{
	public:
		typedef ::nme::events::Event_obj super;
		typedef MouseEvent_obj OBJ_;
		MouseEvent_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_in_localX,Dynamic __o_in_localY,::nme::display::InteractiveObject in_relatedObject,Dynamic __o_in_ctrlKey,Dynamic __o_in_altKey,Dynamic __o_in_shiftKey,Dynamic __o_in_buttonDown,Dynamic __o_in_delta,Dynamic __o_in_commandKey,Dynamic __o_in_clickCount);

	public:
		static hx::ObjectPtr< MouseEvent_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_in_localX,Dynamic __o_in_localY,::nme::display::InteractiveObject in_relatedObject,Dynamic __o_in_ctrlKey,Dynamic __o_in_altKey,Dynamic __o_in_shiftKey,Dynamic __o_in_buttonDown,Dynamic __o_in_delta,Dynamic __o_in_commandKey,Dynamic __o_in_clickCount);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MouseEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MouseEvent"); }

		double localX; /* REM */ 
		double localY; /* REM */ 
		::nme::display::InteractiveObject relatedObject; /* REM */ 
		bool ctrlKey; /* REM */ 
		bool altKey; /* REM */ 
		bool shiftKey; /* REM */ 
		bool buttonDown; /* REM */ 
		int delta; /* REM */ 
		bool commandKey; /* REM */ 
		int clickCount; /* REM */ 
		double stageX; /* REM */ 
		double stageY; /* REM */ 
		virtual ::nme::events::MouseEvent nmeCreateSimilar( ::String inType,::nme::display::InteractiveObject related,::nme::display::InteractiveObject targ);
		Dynamic nmeCreateSimilar_dyn();

		virtual Void updateAfterEvent( );
		Dynamic updateAfterEvent_dyn();

		static int efLeftDown; /* REM */ 
		static int efShiftDown; /* REM */ 
		static int efCtrlDown; /* REM */ 
		static int efAltDown; /* REM */ 
		static int efCommandDown; /* REM */ 
		static ::nme::events::MouseEvent nmeCreate( ::String inType,Dynamic inEvent,::nme::geom::Point inLocal,::nme::display::InteractiveObject inTarget);
		static Dynamic nmeCreate_dyn();

		static ::String MOUSE_MOVE; /* REM */ 
		static ::String MOUSE_OUT; /* REM */ 
		static ::String MOUSE_OVER; /* REM */ 
		static ::String ROLL_OUT; /* REM */ 
		static ::String ROLL_OVER; /* REM */ 
		static ::String CLICK; /* REM */ 
		static ::String MOUSE_DOWN; /* REM */ 
		static ::String MOUSE_UP; /* REM */ 
		static ::String MIDDLE_CLICK; /* REM */ 
		static ::String MIDDLE_MOUSE_DOWN; /* REM */ 
		static ::String MIDDLE_MOUSE_UP; /* REM */ 
		static ::String RIGHT_CLICK; /* REM */ 
		static ::String RIGHT_MOUSE_DOWN; /* REM */ 
		static ::String RIGHT_MOUSE_UP; /* REM */ 
		static ::String MOUSE_WHEEL; /* REM */ 
		static ::String DOUBLE_CLICK; /* REM */ 
};

} // end namespace nme
} // end namespace events

#endif /* INCLUDED_nme_events_MouseEvent */ 
