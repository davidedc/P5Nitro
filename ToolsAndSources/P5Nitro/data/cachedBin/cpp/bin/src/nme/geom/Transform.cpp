#include <hxcpp.h>

#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_geom_Transform
#include <nme/geom/Transform.h>
#endif
namespace nme{
namespace geom{

Void Transform_obj::__construct(::nme::display::DisplayObject inParent)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",19)
	this->nmeObj = inParent;
}
;
	return null();
}

Transform_obj::~Transform_obj() { }

Dynamic Transform_obj::__CreateEmpty() { return  new Transform_obj; }
hx::ObjectPtr< Transform_obj > Transform_obj::__new(::nme::display::DisplayObject inParent)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct(inParent);
	return result;}

Dynamic Transform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct(inArgs[0]);
	return result;}

::nme::geom::Matrix Transform_obj::nmeGetMatrix( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Transform_obj::nmeGetMatrix")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",25)
	return this->nmeObj->nmeGetMatrix();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetMatrix,return )

::nme::geom::Matrix Transform_obj::nmeGetConcatenatedMatrix( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Transform_obj::nmeGetConcatenatedMatrix")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",29)
	return this->nmeObj->nmeGetConcatenatedMatrix();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetConcatenatedMatrix,return )

::nme::geom::Matrix Transform_obj::nmeSetMatrix( ::nme::geom::Matrix inMatrix){
	__SAFE_POINT
	HX_SOURCE_PUSH("Transform_obj::nmeSetMatrix")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",33)
	this->nmeObj->nmeSetMatrix(inMatrix);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",34)
	return inMatrix;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,nmeSetMatrix,return )

::nme::geom::ColorTransform Transform_obj::nmeGetColorTransform( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Transform_obj::nmeGetColorTransform")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",39)
	return this->nmeObj->nmeGetColorTransform();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetColorTransform,return )

::nme::geom::ColorTransform Transform_obj::nmeGetConcatenatedColorTransform( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Transform_obj::nmeGetConcatenatedColorTransform")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",43)
	return this->nmeObj->nmeGetConcatenatedColorTransform();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetConcatenatedColorTransform,return )

::nme::geom::ColorTransform Transform_obj::nmeSetColorTransform( ::nme::geom::ColorTransform inTrans){
	__SAFE_POINT
	HX_SOURCE_PUSH("Transform_obj::nmeSetColorTransform")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",48)
	this->nmeObj->nmeSetColorTransform(inTrans);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",49)
	return inTrans;
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,nmeSetColorTransform,return )

::nme::geom::Rectangle Transform_obj::nmeGetPixelBounds( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("Transform_obj::nmeGetPixelBounds")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Transform.hx",54)
	return this->nmeObj->nmeGetPixelBounds();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,nmeGetPixelBounds,return )


Transform_obj::Transform_obj()
{
}

void Transform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Transform);
	HX_MARK_MEMBER_NAME(colorTransform,"colorTransform");
	HX_MARK_MEMBER_NAME(concatenatedColorTransform,"concatenatedColorTransform");
	HX_MARK_MEMBER_NAME(matrix,"matrix");
	HX_MARK_MEMBER_NAME(concatenatedMatrix,"concatenatedMatrix");
	HX_MARK_MEMBER_NAME(pixelBounds,"pixelBounds");
	HX_MARK_MEMBER_NAME(nmeObj,"nmeObj");
	HX_MARK_END_CLASS();
}

Dynamic Transform_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { return nmeGetMatrix(); }
		if (HX_FIELD_EQ(inName,"nmeObj") ) { return nmeObj; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"pixelBounds") ) { return nmeGetPixelBounds(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeGetMatrix") ) { return nmeGetMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMatrix") ) { return nmeSetMatrix_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return nmeGetColorTransform(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nmeGetPixelBounds") ) { return nmeGetPixelBounds_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"concatenatedMatrix") ) { return nmeGetConcatenatedMatrix(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nmeGetColorTransform") ) { return nmeGetColorTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetColorTransform") ) { return nmeSetColorTransform_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nmeGetConcatenatedMatrix") ) { return nmeGetConcatenatedMatrix_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"concatenatedColorTransform") ) { return nmeGetConcatenatedColorTransform(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"nmeGetConcatenatedColorTransform") ) { return nmeGetConcatenatedColorTransform_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Transform_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { return nmeSetMatrix(inValue); }
		if (HX_FIELD_EQ(inName,"nmeObj") ) { nmeObj=inValue.Cast< ::nme::display::DisplayObject >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"pixelBounds") ) { pixelBounds=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return nmeSetColorTransform(inValue); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"concatenatedMatrix") ) { concatenatedMatrix=inValue.Cast< ::nme::geom::Matrix >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"concatenatedColorTransform") ) { concatenatedColorTransform=inValue.Cast< ::nme::geom::ColorTransform >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Transform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("colorTransform"));
	outFields->push(HX_CSTRING("concatenatedColorTransform"));
	outFields->push(HX_CSTRING("matrix"));
	outFields->push(HX_CSTRING("concatenatedMatrix"));
	outFields->push(HX_CSTRING("pixelBounds"));
	outFields->push(HX_CSTRING("nmeObj"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("colorTransform"),
	HX_CSTRING("concatenatedColorTransform"),
	HX_CSTRING("matrix"),
	HX_CSTRING("concatenatedMatrix"),
	HX_CSTRING("pixelBounds"),
	HX_CSTRING("nmeObj"),
	HX_CSTRING("nmeGetMatrix"),
	HX_CSTRING("nmeGetConcatenatedMatrix"),
	HX_CSTRING("nmeSetMatrix"),
	HX_CSTRING("nmeGetColorTransform"),
	HX_CSTRING("nmeGetConcatenatedColorTransform"),
	HX_CSTRING("nmeSetColorTransform"),
	HX_CSTRING("nmeGetPixelBounds"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Transform_obj::__mClass;

void Transform_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.geom.Transform"), hx::TCanCast< Transform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Transform_obj::__boot()
{
}

} // end namespace nme
} // end namespace geom
