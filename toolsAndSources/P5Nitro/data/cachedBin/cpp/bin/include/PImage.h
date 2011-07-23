#ifndef INCLUDED_PImage
#define INCLUDED_PImage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Bitmap.h>
HX_DECLARE_CLASS0(PImage)
HX_DECLARE_CLASS2(nme,display,Bitmap)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)


class PImage_obj : public ::nme::display::Bitmap_obj{
	public:
		typedef ::nme::display::Bitmap_obj super;
		typedef PImage_obj OBJ_;
		PImage_obj();
		Void __construct(int x,int y);

	public:
		static hx::ObjectPtr< PImage_obj > __new(int x,int y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PImage_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PImage"); }

		Array< int > pixels; /* REM */ 
		virtual Void loadPixelsArgCount0( );
		Dynamic loadPixelsArgCount0_dyn();

		virtual Void updatePixelsArgCount0( );
		Dynamic updatePixelsArgCount0_dyn();

		virtual int getArgCount2( int x,int y);
		Dynamic getArgCount2_dyn();

		virtual Void setArgCount3( int x,int y,int color);
		Dynamic setArgCount3_dyn();

};


#endif /* INCLUDED_PImage */ 
