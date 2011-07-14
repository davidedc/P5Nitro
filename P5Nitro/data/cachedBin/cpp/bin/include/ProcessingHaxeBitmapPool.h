#ifndef INCLUDED_ProcessingHaxeBitmapPool
#define INCLUDED_ProcessingHaxeBitmapPool

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(ProcessingHaxeBitmapPool)
HX_DECLARE_CLASS2(nme,display,Bitmap)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)


class ProcessingHaxeBitmapPool_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ProcessingHaxeBitmapPool_obj OBJ_;
		ProcessingHaxeBitmapPool_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ProcessingHaxeBitmapPool_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ProcessingHaxeBitmapPool_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ProcessingHaxeBitmapPool"); }

		int MAX_VALUE; /* REM */ 
		int GROWTH_VALUE; /* REM */ 
		int counter; /* REM */ 
		Array< ::nme::display::Bitmap > pool; /* REM */ 
		::nme::display::Bitmap currentBitmap; /* REM */ 
		virtual Void initialize( int maxPoolSize,int growthValue);
		Dynamic initialize_dyn();

		virtual ::nme::display::Bitmap getBitmap( );
		Dynamic getBitmap_dyn();

		virtual Void disposeBitmap( ::nme::display::Bitmap disposedBitmap);
		Dynamic disposeBitmap_dyn();

		virtual Void disposeAllBitmaps( );
		Dynamic disposeAllBitmaps_dyn();

};


#endif /* INCLUDED_ProcessingHaxeBitmapPool */ 
