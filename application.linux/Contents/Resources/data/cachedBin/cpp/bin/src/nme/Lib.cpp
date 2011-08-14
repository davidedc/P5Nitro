#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_Timer
#include <nme/Timer.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_ManagedStage
#include <nme/display/ManagedStage.h>
#endif
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace nme{

Void Lib_obj::__construct()
{
	return null();
}

Lib_obj::~Lib_obj() { }

Dynamic Lib_obj::__CreateEmpty() { return  new Lib_obj; }
hx::ObjectPtr< Lib_obj > Lib_obj::__new()
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

Dynamic Lib_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Lib_obj > result = new Lib_obj();
	result->__construct();
	return result;}

int Lib_obj::FULLSCREEN;

int Lib_obj::BORDERLESS;

int Lib_obj::RESIZABLE;

int Lib_obj::HARDWARE;

int Lib_obj::VSYNC;

Dynamic Lib_obj::nmeMainFrame;

::nme::display::MovieClip Lib_obj::nmeCurrent;

::nme::display::Stage Lib_obj::nmeStage;

int Lib_obj::initWidth;

int Lib_obj::initHeight;

::nme::display::Stage Lib_obj::stage;

::nme::display::MovieClip Lib_obj::current;

bool Lib_obj::sIsInit;

Void Lib_obj::create( Dynamic $t1,int $t2,int $t3,Dynamic __o_$t4,Dynamic __o_$t5,Dynamic __o_inFlags,Dynamic __o_inTitle,Dynamic __o_inIcon){
double $t4 = __o_$t4.Default(60.0);
int $t5 = __o_$t5.Default(16777215);
int inFlags = __o_inFlags.Default(15);
::String inTitle = __o_inTitle.Default(HX_CSTRING("NME"));
::String inIcon = __o_inIcon.Default(HX_CSTRING(""));
	HX_SOURCE_PUSH("Lib_obj::create");
{
		__SAFE_POINT
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",23)
		Array< int > inColour = Array_obj< int >::__new().Add($t5);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",23)
		Array< double > inFrameRate = Array_obj< double >::__new().Add($t4);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",23)
		Array< int > inHeight = Array_obj< int >::__new().Add($t3);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",23)
		Array< int > inWidth = Array_obj< int >::__new().Add($t2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",23)
		Array< Dynamic > inOnLoaded = Array_obj< Dynamic >::__new().Add($t1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",27)
		if ((::nme::Lib_obj::sIsInit)){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",29)
			hx::Throw ((HX_CSTRING("nme.Lib.create called multiple times.  ") + HX_CSTRING("This function is automatically called by the project code.")));
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",32)
		::nme::Lib_obj::sIsInit = true;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",33)
		::nme::Lib_obj::initWidth = inWidth->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",34)
		::nme::Lib_obj::initHeight = inHeight->__get((int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",35)
		Dynamic create_main_frame = ::nme::Loader_obj::load(HX_CSTRING("nme_create_main_frame"),(int)-1);

		HX_BEGIN_LOCAL_FUNC5(_Function_1_1,Array< int >,inHeight,Array< int >,inColour,Array< int >,inWidth,Array< double >,inFrameRate,Array< Dynamic >,inOnLoaded)
		Void run(Dynamic inFrameHandle){
{
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",39)
				::nme::Lib_obj::nmeMainFrame = inFrameHandle;
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",40)
				Dynamic stage_handle = ::nme::Lib_obj::nme_get_frame_stage(::nme::Lib_obj::nmeMainFrame);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",41)
				::nme::Lib_obj::nmeStage = ::nme::display::Stage_obj::__new(stage_handle,inWidth->__get((int)0),inHeight->__get((int)0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",42)
				::nme::Lib_obj::nmeStage->nmeSetFrameRate(inFrameRate->__get((int)0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",43)
				::nme::Lib_obj::nmeStage->nmeSetBG(inColour->__get((int)0));
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",44)
				::nme::Lib_obj::nmeStage->onQuit = ::nme::Lib_obj::close_dyn();
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",45)
				if (((::nme::Lib_obj::nmeCurrent != null())))
					::nme::Lib_obj::nmeStage->addChild(::nme::Lib_obj::nmeCurrent);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",47)
				inOnLoaded->__get((int)0)();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",36)
		create_main_frame( Dynamic(new _Function_1_1(inHeight,inColour,inWidth,inFrameRate,inOnLoaded)),inWidth->__get((int)0),inHeight->__get((int)0),inFlags,inTitle,inIcon);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(Lib_obj,create,(void))

::nme::display::Stage Lib_obj::createManagedStage( int inWidth,int inHeight){
	HX_SOURCE_PUSH("Lib_obj::createManagedStage")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",56)
	::nme::Lib_obj::initWidth = inWidth;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",57)
	::nme::Lib_obj::initHeight = inHeight;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",58)
	::nme::Lib_obj::nmeStage = ::nme::display::ManagedStage_obj::__new(inWidth,inHeight);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",59)
	return ::nme::Lib_obj::nmeStage;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Lib_obj,createManagedStage,return )

::nme::display::Stage Lib_obj::nmeGetStage( ){
	HX_SOURCE_PUSH("Lib_obj::nmeGetStage")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",65)
	if (((::nme::Lib_obj::nmeStage == null())))
		hx::Throw (HX_CSTRING("Error : stage can't be accessed until init is called"));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",67)
	return ::nme::Lib_obj::nmeStage;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,nmeGetStage,return )

int Lib_obj::getTimer( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Lib_obj::getTimer")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",73)
	return ::Std_obj::_int((::nme::Timer_obj::stamp() * 1000.0));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,getTimer,return )

Void Lib_obj::close( ){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Lib_obj::close")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",79)
		Dynamic close = ::nme::Loader_obj::load(HX_CSTRING("nme_close"),(int)0);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",80)
		close();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,close,(void))

Void Lib_obj::setAssetBase( ::String inBase){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Lib_obj::setAssetBase")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",85)
		::nme::Lib_obj::nme_set_asset_base(inBase);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Lib_obj,setAssetBase,(void))

::nme::display::MovieClip Lib_obj::nmeGetCurrent( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Lib_obj::nmeGetCurrent")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",91)
	if (((::nme::Lib_obj::nmeCurrent == null()))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",93)
		::nme::Lib_obj::nmeCurrent = ::nme::display::MovieClip_obj::__new();
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",94)
		if (((::nme::Lib_obj::nmeStage != null())))
			::nme::Lib_obj::nmeStage->addChild(::nme::Lib_obj::nmeCurrent);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/Lib.hx",97)
	return ::nme::Lib_obj::nmeCurrent;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Lib_obj,nmeGetCurrent,return )

Dynamic Lib_obj::nme_get_frame_stage;

Dynamic Lib_obj::nme_set_asset_base;


Lib_obj::Lib_obj()
{
}

void Lib_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Lib);
	HX_MARK_END_CLASS();
}

Dynamic Lib_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"VSYNC") ) { return VSYNC; }
		if (HX_FIELD_EQ(inName,"stage") ) { return nmeGetStage(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { return nmeGetCurrent(); }
		if (HX_FIELD_EQ(inName,"sIsInit") ) { return sIsInit; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { return HARDWARE; }
		if (HX_FIELD_EQ(inName,"nmeStage") ) { return nmeStage; }
		if (HX_FIELD_EQ(inName,"getTimer") ) { return getTimer_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"RESIZABLE") ) { return RESIZABLE; }
		if (HX_FIELD_EQ(inName,"initWidth") ) { return initWidth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FULLSCREEN") ) { return FULLSCREEN; }
		if (HX_FIELD_EQ(inName,"BORDERLESS") ) { return BORDERLESS; }
		if (HX_FIELD_EQ(inName,"nmeCurrent") ) { return nmeCurrent; }
		if (HX_FIELD_EQ(inName,"initHeight") ) { return initHeight; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"nmeGetStage") ) { return nmeGetStage_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeMainFrame") ) { return nmeMainFrame; }
		if (HX_FIELD_EQ(inName,"setAssetBase") ) { return setAssetBase_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nmeGetCurrent") ) { return nmeGetCurrent_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"createManagedStage") ) { return createManagedStage_dyn(); }
		if (HX_FIELD_EQ(inName,"nme_set_asset_base") ) { return nme_set_asset_base; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_get_frame_stage") ) { return nme_get_frame_stage; }
	}
	return super::__Field(inName);
}

Dynamic Lib_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"VSYNC") ) { VSYNC=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stage") ) { stage=inValue.Cast< ::nme::display::Stage >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { current=inValue.Cast< ::nme::display::MovieClip >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sIsInit") ) { sIsInit=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { HARDWARE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeStage") ) { nmeStage=inValue.Cast< ::nme::display::Stage >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"RESIZABLE") ) { RESIZABLE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initWidth") ) { initWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FULLSCREEN") ) { FULLSCREEN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BORDERLESS") ) { BORDERLESS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeCurrent") ) { nmeCurrent=inValue.Cast< ::nme::display::MovieClip >(); return inValue; }
		if (HX_FIELD_EQ(inName,"initHeight") ) { initHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeMainFrame") ) { nmeMainFrame=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_set_asset_base") ) { nme_set_asset_base=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_get_frame_stage") ) { nme_get_frame_stage=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Lib_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FULLSCREEN"),
	HX_CSTRING("BORDERLESS"),
	HX_CSTRING("RESIZABLE"),
	HX_CSTRING("HARDWARE"),
	HX_CSTRING("VSYNC"),
	HX_CSTRING("nmeMainFrame"),
	HX_CSTRING("nmeCurrent"),
	HX_CSTRING("nmeStage"),
	HX_CSTRING("initWidth"),
	HX_CSTRING("initHeight"),
	HX_CSTRING("stage"),
	HX_CSTRING("current"),
	HX_CSTRING("sIsInit"),
	HX_CSTRING("create"),
	HX_CSTRING("createManagedStage"),
	HX_CSTRING("nmeGetStage"),
	HX_CSTRING("getTimer"),
	HX_CSTRING("close"),
	HX_CSTRING("setAssetBase"),
	HX_CSTRING("nmeGetCurrent"),
	HX_CSTRING("nme_get_frame_stage"),
	HX_CSTRING("nme_set_asset_base"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Lib_obj::FULLSCREEN,"FULLSCREEN");
	HX_MARK_MEMBER_NAME(Lib_obj::BORDERLESS,"BORDERLESS");
	HX_MARK_MEMBER_NAME(Lib_obj::RESIZABLE,"RESIZABLE");
	HX_MARK_MEMBER_NAME(Lib_obj::HARDWARE,"HARDWARE");
	HX_MARK_MEMBER_NAME(Lib_obj::VSYNC,"VSYNC");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeMainFrame,"nmeMainFrame");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeCurrent,"nmeCurrent");
	HX_MARK_MEMBER_NAME(Lib_obj::nmeStage,"nmeStage");
	HX_MARK_MEMBER_NAME(Lib_obj::initWidth,"initWidth");
	HX_MARK_MEMBER_NAME(Lib_obj::initHeight,"initHeight");
	HX_MARK_MEMBER_NAME(Lib_obj::stage,"stage");
	HX_MARK_MEMBER_NAME(Lib_obj::current,"current");
	HX_MARK_MEMBER_NAME(Lib_obj::sIsInit,"sIsInit");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_get_frame_stage,"nme_get_frame_stage");
	HX_MARK_MEMBER_NAME(Lib_obj::nme_set_asset_base,"nme_set_asset_base");
};

Class Lib_obj::__mClass;

void Lib_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.Lib"), hx::TCanCast< Lib_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Lib_obj::__boot()
{
	hx::Static(FULLSCREEN) = (int)1;
	hx::Static(BORDERLESS) = (int)2;
	hx::Static(RESIZABLE) = (int)4;
	hx::Static(HARDWARE) = (int)8;
	hx::Static(VSYNC) = (int)16;
	hx::Static(nmeMainFrame) = null();
	hx::Static(nmeCurrent) = null();
	hx::Static(nmeStage) = null();
	hx::Static(initWidth);
	hx::Static(initHeight);
	hx::Static(stage);
	hx::Static(current);
	hx::Static(sIsInit) = false;
	hx::Static(nme_get_frame_stage) = ::nme::Loader_obj::load(HX_CSTRING("nme_get_frame_stage"),(int)1);
	hx::Static(nme_set_asset_base) = ::nme::Loader_obj::load(HX_CSTRING("nme_set_asset_base"),(int)1);
}

} // end namespace nme
