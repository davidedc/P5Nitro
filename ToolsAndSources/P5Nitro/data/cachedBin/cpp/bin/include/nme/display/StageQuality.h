#ifndef INCLUDED_nme_display_StageQuality
#define INCLUDED_nme_display_StageQuality

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,StageQuality)
namespace nme{
namespace display{


class StageQuality_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef StageQuality_obj OBJ_;

	public:
		StageQuality_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("nme.display.StageQuality"); }
		::String __ToString() const { return HX_CSTRING("StageQuality.") + tag; }

		static ::nme::display::StageQuality BEST;
		static ::nme::display::StageQuality HIGH;
		static ::nme::display::StageQuality LOW;
		static ::nme::display::StageQuality MEDIUM;
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_StageQuality */ 
