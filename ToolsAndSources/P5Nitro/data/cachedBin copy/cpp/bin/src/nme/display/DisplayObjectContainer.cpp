#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
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
#ifndef INCLUDED_nme_errors_Error
#include <nme/errors/Error.h>
#endif
#ifndef INCLUDED_nme_errors_RangeError
#include <nme/errors/RangeError.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
namespace nme{
namespace display{

Void DisplayObjectContainer_obj::__construct(Dynamic inHandle,::String inType)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",19)
	super::__construct(inHandle,inType);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",20)
	this->nmeChildren = Array_obj< ::nme::display::DisplayObject >::__new();
}
;
	return null();
}

DisplayObjectContainer_obj::~DisplayObjectContainer_obj() { }

Dynamic DisplayObjectContainer_obj::__CreateEmpty() { return  new DisplayObjectContainer_obj; }
hx::ObjectPtr< DisplayObjectContainer_obj > DisplayObjectContainer_obj::__new(Dynamic inHandle,::String inType)
{  hx::ObjectPtr< DisplayObjectContainer_obj > result = new DisplayObjectContainer_obj();
	result->__construct(inHandle,inType);
	return result;}

Dynamic DisplayObjectContainer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DisplayObjectContainer_obj > result = new DisplayObjectContainer_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::nme::display::DisplayObject DisplayObjectContainer_obj::nmeFindByID( int inID){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeFindByID")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",25)
	if (((this->nmeID == inID)))
		return hx::ObjectPtr<OBJ_>(this);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",27)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",27)
		int _g = (int)0;
		Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",27)
		while((_g < _g1->length)){
			__SAFE_POINT
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",27)
			::nme::display::DisplayObject child = _g1->__get(_g);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",27)
			++(_g);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",29)
			::nme::display::DisplayObject found = child->nmeFindByID(inID);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",30)
			if (((found != null())))
				return found;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",33)
	return this->super::nmeFindByID(inID);
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeFindByID,return )

Void DisplayObjectContainer_obj::nmeBroadcast( ::nme::events::Event inEvt){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeBroadcast")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",38)
		int i = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",39)
		if (((this->nmeChildren->length > (int)0)))
			while(true){
			__SAFE_POINT
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",42)
			::nme::display::DisplayObject child = this->nmeChildren->__get(i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",43)
			child->nmeBroadcast(inEvt);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",44)
			if (((i >= this->nmeChildren->length)))
				break;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",46)
			if (((this->nmeChildren->__get(i) == child))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",48)
				(i)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",49)
				if (((i >= this->nmeChildren->length)))
					break;
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",53)
		this->dispatchEvent(inEvt);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeBroadcast,(void))

bool DisplayObjectContainer_obj::nmeGetTabChildren( ){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetTabChildren")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",57)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetTabChildren,return )

bool DisplayObjectContainer_obj::nmeSetTabChildren( bool inValue){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSetTabChildren")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",58)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeSetTabChildren,return )

int DisplayObjectContainer_obj::nmeGetNumChildren( ){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetNumChildren")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",59)
	return this->nmeChildren->length;
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetNumChildren,return )

Void DisplayObjectContainer_obj::nmeRemoveChildFromArray( ::nme::display::DisplayObject child){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeRemoveChildFromArray")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",63)
		int i = this->getChildIndex(child);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",64)
		if (((i >= (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",66)
			::nme::display::DisplayObjectContainer_obj::nme_doc_remove_child(this->nmeHandle,i);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",67)
			this->nmeChildren->splice(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeRemoveChildFromArray,(void))

Void DisplayObjectContainer_obj::nmeOnAdded( ::nme::display::DisplayObject inObj,bool inIsOnStage){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeOnAdded")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",73)
		this->super::nmeOnAdded(inObj,inIsOnStage);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",74)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",74)
			int _g = (int)0;
			Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",74)
			while((_g < _g1->length)){
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",74)
				::nme::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",74)
				++(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",75)
				child->nmeOnAdded(inObj,inIsOnStage);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeOnAdded,(void))

Void DisplayObjectContainer_obj::nmeOnRemoved( ::nme::display::DisplayObject inObj,bool inWasOnStage){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeOnRemoved")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",80)
		this->super::nmeOnRemoved(inObj,inWasOnStage);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",81)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",81)
			int _g = (int)0;
			Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",81)
			while((_g < _g1->length)){
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",81)
				::nme::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",81)
				++(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",82)
				child->nmeOnRemoved(inObj,inWasOnStage);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeOnRemoved,(void))

::nme::display::DisplayObject DisplayObjectContainer_obj::addChild( ::nme::display::DisplayObject child){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::addChild")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",87)
	if (((child == hx::ObjectPtr<OBJ_>(this)))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",88)
		hx::Throw (HX_CSTRING("Adding to self"));
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",90)
	if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",92)
		this->setChildIndex(child,(this->nmeChildren->length - (int)1));
	}
	else{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",96)
		child->nmeSetParent(hx::ObjectPtr<OBJ_>(this));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",97)
		this->nmeChildren->push(child);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",98)
		::nme::display::DisplayObjectContainer_obj::nme_doc_add_child(this->nmeHandle,child->nmeHandle);
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",100)
	return child;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,addChild,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::addChildAt( ::nme::display::DisplayObject child,int index){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::addChildAt")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",105)
	this->addChild(child);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",106)
	this->setChildIndex(child,index);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",107)
	return child;
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,addChildAt,return )

bool DisplayObjectContainer_obj::areInaccessibleObjectsUnderPoint( ::nme::geom::Point point){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::areInaccessibleObjectsUnderPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",109)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,areInaccessibleObjectsUnderPoint,return )

bool DisplayObjectContainer_obj::contains( ::nme::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::contains")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",112)
	if (((child == null())))
		return false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",114)
	if (((hx::ObjectPtr<OBJ_>(this) == child)))
		return true;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",116)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",116)
		int _g = (int)0;
		Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",116)
		while((_g < _g1->length)){
			__SAFE_POINT
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",116)
			::nme::display::DisplayObject c = _g1->__get(_g);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",116)
			++(_g);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",117)
			if (((c == child)))
				return true;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",119)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,contains,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::getChildByName( ::String name){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildByName")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",123)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",123)
		int _g = (int)0;
		Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",123)
		while((_g < _g1->length)){
			__SAFE_POINT
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",123)
			::nme::display::DisplayObject c = _g1->__get(_g);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",123)
			++(_g);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",124)
			if (((name == c->nmeGetName())))
				return c;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",126)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildByName,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::getChildAt( int index){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildAt")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",131)
	if (((bool((index >= (int)0)) && bool((index < this->nmeChildren->length)))))
		return this->nmeChildren->__get(index);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",134)
	hx::Throw (::nme::errors::RangeError_obj::__new((((HX_CSTRING("getChildAt : index out of bounds ") + index) + HX_CSTRING("/")) + this->nmeChildren->length)));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",135)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildAt,return )

int DisplayObjectContainer_obj::getChildIndex( ::nme::display::DisplayObject child){
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getChildIndex")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",140)
	{
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",140)
		int _g1 = (int)0;
		int _g = this->nmeChildren->length;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",140)
		while((_g1 < _g)){
			__SAFE_POINT
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",140)
			int i = (_g1)++;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",141)
			if (((this->nmeChildren->__get(i) == child)))
				return i;
		}
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",143)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getChildIndex,return )

Void DisplayObjectContainer_obj::nmeGetObjectsUnderPoint( ::nme::geom::Point point,Array< ::nme::display::DisplayObject > result){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetObjectsUnderPoint")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",148)
		this->super::nmeGetObjectsUnderPoint(point,result);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",149)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",149)
			int _g = (int)0;
			Array< ::nme::display::DisplayObject > _g1 = this->nmeChildren;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",149)
			while((_g < _g1->length)){
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",149)
				::nme::display::DisplayObject child = _g1->__get(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",149)
				++(_g);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",150)
				this->nmeGetObjectsUnderPoint(point,result);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,nmeGetObjectsUnderPoint,(void))

Array< ::nme::display::DisplayObject > DisplayObjectContainer_obj::getObjectsUnderPoint( ::nme::geom::Point point){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::getObjectsUnderPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",155)
	Array< ::nme::display::DisplayObject > result = Array_obj< ::nme::display::DisplayObject >::__new();
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",156)
	this->nmeGetObjectsUnderPoint(point,result);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",157)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,getObjectsUnderPoint,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::removeChild( ::nme::display::DisplayObject child){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::removeChild")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",161)
	int c = this->getChildIndex(child);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",162)
	if (((c >= (int)0))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",164)
		child->nmeSetParent(null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",165)
		return child;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",167)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChild,return )

::nme::display::DisplayObject DisplayObjectContainer_obj::removeChildAt( int index){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::removeChildAt")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",172)
	if (((bool((index >= (int)0)) && bool((index < this->nmeChildren->length))))){
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",174)
		::nme::display::DisplayObject result = this->nmeChildren->__get(index);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",175)
		result->nmeSetParent(null());
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",176)
		return result;
	}
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",178)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,removeChildAt,return )

Void DisplayObjectContainer_obj::setChildIndex( ::nme::display::DisplayObject child,int index){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::setChildIndex")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",183)
		if (((index > this->nmeChildren->length)))
			hx::Throw ((HX_CSTRING("Invalid index position ") + index));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",186)
		::nme::display::DisplayObject s = null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",187)
		int orig = this->getChildIndex(child);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",189)
		if (((orig < (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",190)
			::String msg = ((HX_CSTRING("setChildIndex : object ") + child->toString()) + HX_CSTRING(" not found."));
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",191)
			if (((child->nmeParent == hx::ObjectPtr<OBJ_>(this)))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",192)
				int realindex = (int)-1;
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",193)
				{
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",193)
					int _g1 = (int)0;
					int _g = this->nmeChildren->length;
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",193)
					while((_g1 < _g)){
						__SAFE_POINT
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",193)
						int i = (_g1)++;
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",194)
						if (((this->nmeChildren->__get(i) == child))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",195)
							realindex = i;
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",196)
							break;
						}
					}
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",199)
				if (((realindex != (int)-1))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",200)
					hx::AddEq(msg,(HX_CSTRING("Internal error: Real child index was ") + ::Std_obj::string(realindex)));
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",202)
					hx::AddEq(msg,HX_CSTRING("Internal error: Child was not in nmeChildren array!"));
				}
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",204)
			hx::Throw (msg);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",207)
		::nme::display::DisplayObjectContainer_obj::nme_doc_set_child_index(this->nmeHandle,child->nmeHandle,index);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",210)
		if (((index < orig))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",212)
			int i = orig;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",213)
			while((i > index)){
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",214)
				this->nmeChildren[i] = this->nmeChildren->__get((i - (int)1));
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",215)
				(i)--;
			}
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",217)
			this->nmeChildren[index] = child;
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",220)
			if (((orig < index))){
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",222)
				int i = orig;
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",223)
				while((i < index)){
					__SAFE_POINT
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",224)
					this->nmeChildren[i] = this->nmeChildren->__get((i + (int)1));
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",225)
					(i)++;
				}
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",227)
				this->nmeChildren[index] = child;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,setChildIndex,(void))

Void DisplayObjectContainer_obj::swapChildren( ::nme::display::DisplayObject child1,::nme::display::DisplayObject child2){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::swapChildren")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",233)
		int idx1 = this->getChildIndex(child1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",234)
		int idx2 = this->getChildIndex(child2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",235)
		if (((bool((idx1 < (int)0)) || bool((idx2 < (int)0)))))
			hx::Throw (HX_CSTRING("swapChildren:Could not find children"));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",237)
		this->swapChildrenAt(idx1,idx2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildren,(void))

Void DisplayObjectContainer_obj::swapChildrenAt( int index1,int index2){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("DisplayObjectContainer_obj::swapChildrenAt")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",242)
		if (((bool((bool((bool((index1 < (int)0)) || bool((index2 < (int)0)))) || bool((index1 > this->nmeChildren->length)))) || bool((index2 > this->nmeChildren->length)))))
			hx::Throw (::nme::errors::RangeError_obj::__new(HX_CSTRING("swapChildrenAt : index out of bounds")));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",244)
		if (((index1 == index2)))
			return null();
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",246)
		::nme::display::DisplayObject tmp = this->nmeChildren->__get(index1);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",247)
		this->nmeChildren[index1] = this->nmeChildren->__get(index2);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",248)
		this->nmeChildren[index2] = tmp;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",249)
		::nme::display::DisplayObjectContainer_obj::nme_doc_swap_children(this->nmeHandle,index1,index2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(DisplayObjectContainer_obj,swapChildrenAt,(void))

bool DisplayObjectContainer_obj::nmeGetMouseChildren( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeGetMouseChildren")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",252)
	return ::nme::display::DisplayObjectContainer_obj::nme_doc_get_mouse_children(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(DisplayObjectContainer_obj,nmeGetMouseChildren,return )

bool DisplayObjectContainer_obj::nmeSetMouseChildren( bool inVal){
	__SAFE_POINT
	HX_SOURCE_PUSH("DisplayObjectContainer_obj::nmeSetMouseChildren")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",255)
	::nme::display::DisplayObjectContainer_obj::nme_doc_set_mouse_children(this->nmeHandle,inVal);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/display/DisplayObjectContainer.hx",256)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(DisplayObjectContainer_obj,nmeSetMouseChildren,return )

Dynamic DisplayObjectContainer_obj::nme_create_display_object_container;

Dynamic DisplayObjectContainer_obj::nme_doc_add_child;

Dynamic DisplayObjectContainer_obj::nme_doc_remove_child;

Dynamic DisplayObjectContainer_obj::nme_doc_set_child_index;

Dynamic DisplayObjectContainer_obj::nme_doc_get_mouse_children;

Dynamic DisplayObjectContainer_obj::nme_doc_set_mouse_children;

Dynamic DisplayObjectContainer_obj::nme_doc_swap_children;


DisplayObjectContainer_obj::DisplayObjectContainer_obj()
{
}

void DisplayObjectContainer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DisplayObjectContainer);
	HX_MARK_MEMBER_NAME(mouseChildren,"mouseChildren");
	HX_MARK_MEMBER_NAME(numChildren,"numChildren");
	HX_MARK_MEMBER_NAME(tabChildren,"tabChildren");
	HX_MARK_MEMBER_NAME(nmeChildren,"nmeChildren");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic DisplayObjectContainer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"addChild") ) { return addChild_dyn(); }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"nmeOnAdded") ) { return nmeOnAdded_dyn(); }
		if (HX_FIELD_EQ(inName,"addChildAt") ) { return addChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"getChildAt") ) { return getChildAt_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"numChildren") ) { return nmeGetNumChildren(); }
		if (HX_FIELD_EQ(inName,"tabChildren") ) { return nmeGetTabChildren(); }
		if (HX_FIELD_EQ(inName,"nmeChildren") ) { return nmeChildren; }
		if (HX_FIELD_EQ(inName,"nmeFindByID") ) { return nmeFindByID_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeBroadcast") ) { return nmeBroadcast_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeOnRemoved") ) { return nmeOnRemoved_dyn(); }
		if (HX_FIELD_EQ(inName,"swapChildren") ) { return swapChildren_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mouseChildren") ) { return nmeGetMouseChildren(); }
		if (HX_FIELD_EQ(inName,"getChildIndex") ) { return getChildIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChildAt") ) { return removeChildAt_dyn(); }
		if (HX_FIELD_EQ(inName,"setChildIndex") ) { return setChildIndex_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getChildByName") ) { return getChildByName_dyn(); }
		if (HX_FIELD_EQ(inName,"swapChildrenAt") ) { return swapChildrenAt_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_doc_add_child") ) { return nme_doc_add_child; }
		if (HX_FIELD_EQ(inName,"nmeGetTabChildren") ) { return nmeGetTabChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetTabChildren") ) { return nmeSetTabChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetNumChildren") ) { return nmeGetNumChildren_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nmeGetMouseChildren") ) { return nmeGetMouseChildren_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMouseChildren") ) { return nmeSetMouseChildren_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_doc_remove_child") ) { return nme_doc_remove_child; }
		if (HX_FIELD_EQ(inName,"getObjectsUnderPoint") ) { return getObjectsUnderPoint_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_doc_swap_children") ) { return nme_doc_swap_children; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_doc_set_child_index") ) { return nme_doc_set_child_index; }
		if (HX_FIELD_EQ(inName,"nmeRemoveChildFromArray") ) { return nmeRemoveChildFromArray_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetObjectsUnderPoint") ) { return nmeGetObjectsUnderPoint_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_doc_get_mouse_children") ) { return nme_doc_get_mouse_children; }
		if (HX_FIELD_EQ(inName,"nme_doc_set_mouse_children") ) { return nme_doc_set_mouse_children; }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"areInaccessibleObjectsUnderPoint") ) { return areInaccessibleObjectsUnderPoint_dyn(); }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_create_display_object_container") ) { return nme_create_display_object_container; }
	}
	return super::__Field(inName);
}

Dynamic DisplayObjectContainer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"numChildren") ) { numChildren=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tabChildren") ) { return nmeSetTabChildren(inValue); }
		if (HX_FIELD_EQ(inName,"nmeChildren") ) { nmeChildren=inValue.Cast< Array< ::nme::display::DisplayObject > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mouseChildren") ) { return nmeSetMouseChildren(inValue); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"nme_doc_add_child") ) { nme_doc_add_child=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_doc_remove_child") ) { nme_doc_remove_child=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_doc_swap_children") ) { nme_doc_swap_children=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_doc_set_child_index") ) { nme_doc_set_child_index=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_doc_get_mouse_children") ) { nme_doc_get_mouse_children=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_doc_set_mouse_children") ) { nme_doc_set_mouse_children=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"nme_create_display_object_container") ) { nme_create_display_object_container=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void DisplayObjectContainer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mouseChildren"));
	outFields->push(HX_CSTRING("numChildren"));
	outFields->push(HX_CSTRING("tabChildren"));
	outFields->push(HX_CSTRING("nmeChildren"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_create_display_object_container"),
	HX_CSTRING("nme_doc_add_child"),
	HX_CSTRING("nme_doc_remove_child"),
	HX_CSTRING("nme_doc_set_child_index"),
	HX_CSTRING("nme_doc_get_mouse_children"),
	HX_CSTRING("nme_doc_set_mouse_children"),
	HX_CSTRING("nme_doc_swap_children"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mouseChildren"),
	HX_CSTRING("numChildren"),
	HX_CSTRING("tabChildren"),
	HX_CSTRING("nmeChildren"),
	HX_CSTRING("nmeFindByID"),
	HX_CSTRING("nmeBroadcast"),
	HX_CSTRING("nmeGetTabChildren"),
	HX_CSTRING("nmeSetTabChildren"),
	HX_CSTRING("nmeGetNumChildren"),
	HX_CSTRING("nmeRemoveChildFromArray"),
	HX_CSTRING("nmeOnAdded"),
	HX_CSTRING("nmeOnRemoved"),
	HX_CSTRING("addChild"),
	HX_CSTRING("addChildAt"),
	HX_CSTRING("areInaccessibleObjectsUnderPoint"),
	HX_CSTRING("contains"),
	HX_CSTRING("getChildByName"),
	HX_CSTRING("getChildAt"),
	HX_CSTRING("getChildIndex"),
	HX_CSTRING("nmeGetObjectsUnderPoint"),
	HX_CSTRING("getObjectsUnderPoint"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("removeChildAt"),
	HX_CSTRING("setChildIndex"),
	HX_CSTRING("swapChildren"),
	HX_CSTRING("swapChildrenAt"),
	HX_CSTRING("nmeGetMouseChildren"),
	HX_CSTRING("nmeSetMouseChildren"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_create_display_object_container,"nme_create_display_object_container");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_add_child,"nme_doc_add_child");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_remove_child,"nme_doc_remove_child");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_child_index,"nme_doc_set_child_index");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_get_mouse_children,"nme_doc_get_mouse_children");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_set_mouse_children,"nme_doc_set_mouse_children");
	HX_MARK_MEMBER_NAME(DisplayObjectContainer_obj::nme_doc_swap_children,"nme_doc_swap_children");
};

Class DisplayObjectContainer_obj::__mClass;

void DisplayObjectContainer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.DisplayObjectContainer"), hx::TCanCast< DisplayObjectContainer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void DisplayObjectContainer_obj::__boot()
{
	hx::Static(nme_create_display_object_container) = ::nme::Loader_obj::load(HX_CSTRING("nme_create_display_object_container"),(int)0);
	hx::Static(nme_doc_add_child) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_add_child"),(int)2);
	hx::Static(nme_doc_remove_child) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_remove_child"),(int)2);
	hx::Static(nme_doc_set_child_index) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_set_child_index"),(int)3);
	hx::Static(nme_doc_get_mouse_children) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_get_mouse_children"),(int)1);
	hx::Static(nme_doc_set_mouse_children) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_set_mouse_children"),(int)2);
	hx::Static(nme_doc_swap_children) = ::nme::Loader_obj::load(HX_CSTRING("nme_doc_swap_children"),(int)3);
}

} // end namespace nme
} // end namespace display
