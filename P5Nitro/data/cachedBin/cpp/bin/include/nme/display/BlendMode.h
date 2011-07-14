#ifndef INCLUDED_nme_display_BlendMode
#define INCLUDED_nme_display_BlendMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,BlendMode)
namespace nme{
namespace display{


class BlendMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BlendMode_obj OBJ_;

	public:
		BlendMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.BlendMode"); }
		::String __ToString() const { return HX_CSTRING("BlendMode.") + tag; }

		static ::nme::display::BlendMode ADD;
		static ::nme::display::BlendMode ALPHA;
		static ::nme::display::BlendMode DARKEN;
		static ::nme::display::BlendMode DIFFERENCE;
		static ::nme::display::BlendMode ERASE;
		static ::nme::display::BlendMode HARDLIGHT;
		static ::nme::display::BlendMode INVERT;
		static ::nme::display::BlendMode LAYER;
		static ::nme::display::BlendMode LIGHTEN;
		static ::nme::display::BlendMode MULTIPLY;
		static ::nme::display::BlendMode NORMAL;
		static ::nme::display::BlendMode OVERLAY;
		static ::nme::display::BlendMode SCREEN;
		static ::nme::display::BlendMode SUBTRACT;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_BlendMode */ 
