#ifndef INCLUDED_nme_display_LineScaleMode
#define INCLUDED_nme_display_LineScaleMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,LineScaleMode)
namespace nme{
namespace display{


class LineScaleMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef LineScaleMode_obj OBJ_;

	public:
		LineScaleMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.LineScaleMode"); }
		::String __ToString() const { return HX_CSTRING("LineScaleMode.") + tag; }

		static ::nme::display::LineScaleMode HORIZONTAL;
		static ::nme::display::LineScaleMode NONE;
		static ::nme::display::LineScaleMode NORMAL;
		static ::nme::display::LineScaleMode VERTICAL;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_LineScaleMode */ 
