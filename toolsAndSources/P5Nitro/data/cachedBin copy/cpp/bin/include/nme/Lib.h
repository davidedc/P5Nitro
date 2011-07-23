#ifndef INCLUDED_nme_Lib
#define INCLUDED_nme_Lib

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(nme,Lib)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,MovieClip)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,display,Stage)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
namespace nme{


class Lib_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Lib_obj OBJ_;
		Lib_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Lib_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Lib_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Lib"); }

		static int FULLSCREEN; /* REM */ 
		static int BORDERLESS; /* REM */ 
		static int RESIZABLE; /* REM */ 
		static int HARDWARE; /* REM */ 
		static int VSYNC; /* REM */ 
		static Dynamic nmeMainFrame; /* REM */ 
		static ::nme::display::MovieClip nmeCurrent; /* REM */ 
		static ::nme::display::Stage nmeStage; /* REM */ 
		static int initWidth; /* REM */ 
		static int initHeight; /* REM */ 
		static ::nme::display::Stage stage; /* REM */ 
		static ::nme::display::MovieClip current; /* REM */ 
		static bool sIsInit; /* REM */ 
		static Void create( Dynamic $t1,int $t2,int $t3,Dynamic $t4,Dynamic $t5,Dynamic inFlags,Dynamic inTitle,Dynamic inIcon);
		static Dynamic create_dyn();

		static ::nme::display::Stage createManagedStage( int inWidth,int inHeight);
		static Dynamic createManagedStage_dyn();

		static ::nme::display::Stage nmeGetStage( );
		static Dynamic nmeGetStage_dyn();

		static int getTimer( );
		static Dynamic getTimer_dyn();

		static Void close( );
		static Dynamic close_dyn();

		static Void setAssetBase( ::String inBase);
		static Dynamic setAssetBase_dyn();

		static ::nme::display::MovieClip nmeGetCurrent( );
		static Dynamic nmeGetCurrent_dyn();

		static Dynamic nme_get_frame_stage; /* REM */ 
	Dynamic &nme_get_frame_stage_dyn() { return nme_get_frame_stage;}
		static Dynamic nme_set_asset_base; /* REM */ 
	Dynamic &nme_set_asset_base_dyn() { return nme_set_asset_base;}
};

} // end namespace nme

#endif /* INCLUDED_nme_Lib */ 
