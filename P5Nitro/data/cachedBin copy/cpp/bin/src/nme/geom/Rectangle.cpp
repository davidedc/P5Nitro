#include <hxcpp.h>

#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace nme{
namespace geom{

Void Rectangle_obj::__construct(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",41)
	this->x = (  (((inX == null()))) ? Dynamic((int)0) : Dynamic(inX) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",42)
	this->y = (  (((inY == null()))) ? Dynamic((int)0) : Dynamic(inY) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",43)
	this->width = (  (((inWidth == null()))) ? Dynamic((int)0) : Dynamic(inWidth) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",44)
	this->height = (  (((inHeight == null()))) ? Dynamic((int)0) : Dynamic(inHeight) );
}
;
	return null();
}

Rectangle_obj::~Rectangle_obj() { }

Dynamic Rectangle_obj::__CreateEmpty() { return  new Rectangle_obj; }
hx::ObjectPtr< Rectangle_obj > Rectangle_obj::__new(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inX,inY,inWidth,inHeight);
	return result;}

Dynamic Rectangle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

double Rectangle_obj::get_left( ){
	HX_SOURCE_PUSH("Rectangle_obj::get_left")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",48)
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_left,return )

double Rectangle_obj::set_left( double l){
	HX_SOURCE_PUSH("Rectangle_obj::set_left")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",49)
	hx::SubEq(this->width,(l - this->x));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",49)
	this->x = l;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",49)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_left,return )

double Rectangle_obj::get_right( ){
	HX_SOURCE_PUSH("Rectangle_obj::get_right")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",52)
	return (this->x + this->width);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_right,return )

double Rectangle_obj::set_right( double r){
	HX_SOURCE_PUSH("Rectangle_obj::set_right")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",53)
	this->width = (r - this->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",53)
	return r;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_right,return )

double Rectangle_obj::get_top( ){
	HX_SOURCE_PUSH("Rectangle_obj::get_top")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",56)
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_top,return )

double Rectangle_obj::set_top( double t){
	HX_SOURCE_PUSH("Rectangle_obj::set_top")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",57)
	hx::SubEq(this->height,(t - this->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",57)
	this->y = t;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",57)
	return t;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_top,return )

double Rectangle_obj::get_bottom( ){
	HX_SOURCE_PUSH("Rectangle_obj::get_bottom")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",60)
	return (this->y + this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottom,return )

double Rectangle_obj::set_bottom( double b){
	HX_SOURCE_PUSH("Rectangle_obj::set_bottom")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",61)
	this->height = (b - this->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",61)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottom,return )

::nme::geom::Point Rectangle_obj::get_topLeft( ){
	HX_SOURCE_PUSH("Rectangle_obj::get_topLeft")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",64)
	return ::nme::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_topLeft,return )

::nme::geom::Point Rectangle_obj::set_topLeft( ::nme::geom::Point p){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::set_topLeft")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",65)
	this->x = p->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",65)
	this->y = p->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",65)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_topLeft,return )

::nme::geom::Point Rectangle_obj::get_size( ){
	HX_SOURCE_PUSH("Rectangle_obj::get_size")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",68)
	return ::nme::geom::Point_obj::__new(this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_size,return )

::nme::geom::Point Rectangle_obj::set_size( ::nme::geom::Point p){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::set_size")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",69)
	this->width = p->x;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",69)
	this->height = p->y;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",69)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_size,return )

::nme::geom::Point Rectangle_obj::get_bottomRight( ){
	HX_SOURCE_PUSH("Rectangle_obj::get_bottomRight")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",72)
	return ::nme::geom::Point_obj::__new((this->x + this->width),(this->y + this->height));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottomRight,return )

::nme::geom::Point Rectangle_obj::set_bottomRight( ::nme::geom::Point p){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::set_bottomRight")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",75)
	this->width = (p->x - this->x);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",76)
	this->height = (p->y - this->y);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",77)
	return p->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottomRight,return )

::nme::geom::Rectangle Rectangle_obj::clone( ){
	HX_SOURCE_PUSH("Rectangle_obj::clone")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",82)
	return ::nme::geom::Rectangle_obj::__new(this->x,this->y,this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,clone,return )

bool Rectangle_obj::contains( double inX,double inY){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::contains")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",86)
	return (bool((bool((bool((inX >= this->x)) && bool((inY >= this->y)))) && bool((inX < this->get_right())))) && bool((inY < this->get_bottom())));
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,contains,return )

bool Rectangle_obj::containsPoint( ::nme::geom::Point point){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::containsPoint")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",90)
	return this->contains(point->x,point->y);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsPoint,return )

bool Rectangle_obj::containsRect( ::nme::geom::Rectangle rect){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::containsRect")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",94)
	return (bool(this->contains(rect->x,rect->y)) && bool(this->containsPoint(rect->get_bottomRight())));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsRect,return )

bool Rectangle_obj::equals( ::nme::geom::Rectangle toCompare){
	HX_SOURCE_PUSH("Rectangle_obj::equals")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",98)
	return (bool((bool((bool((this->x == toCompare->x)) && bool((this->y == toCompare->y)))) && bool((this->width == toCompare->width)))) && bool((this->height == toCompare->height)));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,equals,return )

Void Rectangle_obj::inflate( double dx,double dy){
{
		HX_SOURCE_PUSH("Rectangle_obj::inflate")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",103)
		hx::SubEq(this->x,dx);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",103)
		hx::AddEq(this->width,(dx * (int)2));
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",104)
		hx::SubEq(this->y,dy);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",104)
		hx::AddEq(this->height,(dy * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,inflate,(void))

Void Rectangle_obj::inflatePoint( ::nme::geom::Point point){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Rectangle_obj::inflatePoint")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",108)
		this->inflate(point->x,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,inflatePoint,(void))

::nme::geom::Rectangle Rectangle_obj::intersection( ::nme::geom::Rectangle toIntersect){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::intersection")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",112)
	double x0 = (  (((this->x < toIntersect->x))) ? double(toIntersect->x) : double(this->x) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",113)
	double x1 = (  (((this->get_right() > toIntersect->get_right()))) ? double(toIntersect->get_right()) : double(this->get_right()) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",114)
	if (((x1 <= x0)))
		return ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",117)
	double y0 = (  (((this->y < toIntersect->y))) ? double(toIntersect->x) : double(this->y) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",118)
	double y1 = (  (((this->get_bottom() > toIntersect->get_bottom()))) ? double(toIntersect->get_bottom()) : double(this->get_bottom()) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",119)
	if (((y1 <= y0)))
		return ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",122)
	return ::nme::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersection,return )

bool Rectangle_obj::intersects( ::nme::geom::Rectangle toIntersect){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::intersects")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",127)
	double x0 = (  (((this->x < toIntersect->x))) ? double(toIntersect->x) : double(this->x) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",128)
	double x1 = (  (((this->get_right() > toIntersect->get_right()))) ? double(toIntersect->get_right()) : double(this->get_right()) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",129)
	if (((x1 <= x0)))
		return false;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",132)
	double y0 = (  (((this->y < toIntersect->y))) ? double(toIntersect->y) : double(this->y) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",133)
	double y1 = (  (((this->get_bottom() > toIntersect->get_bottom()))) ? double(toIntersect->get_bottom()) : double(this->get_bottom()) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",134)
	return (y1 > y0);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersects,return )

::nme::geom::Rectangle Rectangle_obj::_union( ::nme::geom::Rectangle toUnion){
	__SAFE_POINT
	HX_SOURCE_PUSH("Rectangle_obj::union")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",139)
	double x0 = (  (((this->x > toUnion->x))) ? double(toUnion->x) : double(this->x) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",140)
	double x1 = (  (((this->get_right() < toUnion->get_right()))) ? double(toUnion->get_right()) : double(this->get_right()) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",141)
	double y0 = (  (((this->y > toUnion->y))) ? double(toUnion->x) : double(this->y) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",142)
	double y1 = (  (((this->get_bottom() < toUnion->get_bottom()))) ? double(toUnion->get_bottom()) : double(this->get_bottom()) );
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",143)
	return ::nme::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,_union,return )

bool Rectangle_obj::isEmpty( ){
	HX_SOURCE_PUSH("Rectangle_obj::isEmpty")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",146)
	return (bool((this->width == (int)0)) && bool((this->height == (int)0)));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,isEmpty,return )

Void Rectangle_obj::offset( double dx,double dy){
{
		HX_SOURCE_PUSH("Rectangle_obj::offset")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",149)
		hx::AddEq(this->x,dx);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",150)
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,offset,(void))

Void Rectangle_obj::offsetPoint( ::nme::geom::Point point){
{
		HX_SOURCE_PUSH("Rectangle_obj::offsetPoint")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",155)
		hx::AddEq(this->x,point->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",156)
		hx::AddEq(this->y,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,offsetPoint,(void))

Void Rectangle_obj::setEmpty( ){
{
		HX_SOURCE_PUSH("Rectangle_obj::setEmpty")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",159)
		this->x = this->y = this->width = this->height = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,setEmpty,(void))

::nme::geom::Rectangle Rectangle_obj::transform( ::nme::geom::Matrix m){
	HX_SOURCE_PUSH("Rectangle_obj::transform")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",163)
	double tx0 = ((m->a * this->x) + (m->c * this->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",164)
	double tx1 = tx0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",165)
	double ty0 = ((m->b * this->x) + (m->d * this->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",166)
	double ty1 = tx0;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",168)
	double tx = ((m->a * ((this->x + this->width))) + (m->c * this->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",169)
	double ty = ((m->b * ((this->x + this->width))) + (m->d * this->y));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",170)
	if (((tx < tx0)))
		tx0 = tx;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",171)
	if (((ty < ty0)))
		ty0 = ty;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",172)
	if (((tx > tx1)))
		tx1 = tx;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",173)
	if (((ty > ty1)))
		ty1 = ty;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",175)
	tx = ((m->a * ((this->x + this->width))) + (m->c * ((this->y + this->height))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",176)
	ty = ((m->b * ((this->x + this->width))) + (m->d * ((this->y + this->height))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",177)
	if (((tx < tx0)))
		tx0 = tx;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",178)
	if (((ty < ty0)))
		ty0 = ty;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",179)
	if (((tx > tx1)))
		tx1 = tx;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",180)
	if (((ty > ty1)))
		ty1 = ty;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",182)
	tx = ((m->a * this->x) + (m->c * ((this->y + this->height))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",183)
	ty = ((m->b * this->x) + (m->d * ((this->y + this->height))));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",184)
	if (((tx < tx0)))
		tx0 = tx;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",185)
	if (((ty < ty0)))
		ty0 = ty;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",186)
	if (((tx > tx1)))
		tx1 = tx;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",187)
	if (((ty > ty1)))
		ty1 = ty;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",189)
	return ::nme::geom::Rectangle_obj::__new((tx0 + m->tx),(ty0 + m->ty),(tx1 - tx0),(ty1 - ty0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,transform,return )

Void Rectangle_obj::extendBounds( ::nme::geom::Rectangle r){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("Rectangle_obj::extendBounds")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",194)
		double dx = (this->x - r->x);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",195)
		if (((dx > (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",197)
			hx::SubEq(this->x,dx);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",198)
			hx::AddEq(this->width,dx);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",200)
		double dy = (this->y - r->y);
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",201)
		if (((dy > (int)0))){
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",203)
			hx::SubEq(this->y,dy);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",204)
			hx::AddEq(this->height,dy);
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",206)
		if (((r->get_right() > this->get_right())))
			this->set_right(r->get_right());
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/geom/Rectangle.hx",208)
		if (((r->get_bottom() > this->get_bottom())))
			this->set_bottom(r->get_bottom());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,extendBounds,(void))


Rectangle_obj::Rectangle_obj()
{
}

void Rectangle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Rectangle);
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(bottom,"bottom");
	HX_MARK_MEMBER_NAME(topLeft,"topLeft");
	HX_MARK_MEMBER_NAME(size,"size");
	HX_MARK_MEMBER_NAME(bottomRight,"bottomRight");
	HX_MARK_END_CLASS();
}

Dynamic Rectangle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return get_top(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return get_left(); }
		if (HX_FIELD_EQ(inName,"size") ) { return get_topLeft(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"right") ) { return get_right(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"union") ) { return _union_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return get_bottom(); }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_top") ) { return get_top_dyn(); }
		if (HX_FIELD_EQ(inName,"set_top") ) { return set_top_dyn(); }
		if (HX_FIELD_EQ(inName,"topLeft") ) { return get_topLeft(); }
		if (HX_FIELD_EQ(inName,"inflate") ) { return inflate_dyn(); }
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_left") ) { return get_left_dyn(); }
		if (HX_FIELD_EQ(inName,"set_left") ) { return set_left_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"set_size") ) { return set_size_dyn(); }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		if (HX_FIELD_EQ(inName,"setEmpty") ) { return setEmpty_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"set_right") ) { return set_right_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_bottom") ) { return get_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bottom") ) { return set_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"intersects") ) { return intersects_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_topLeft") ) { return get_topLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_topLeft") ) { return set_topLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return get_bottomRight(); }
		if (HX_FIELD_EQ(inName,"offsetPoint") ) { return offsetPoint_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"containsRect") ) { return containsRect_dyn(); }
		if (HX_FIELD_EQ(inName,"inflatePoint") ) { return inflatePoint_dyn(); }
		if (HX_FIELD_EQ(inName,"intersection") ) { return intersection_dyn(); }
		if (HX_FIELD_EQ(inName,"extendBounds") ) { return extendBounds_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"containsPoint") ) { return containsPoint_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_bottomRight") ) { return get_bottomRight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bottomRight") ) { return set_bottomRight_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Rectangle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< double >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return set_top(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return set_left(inValue); }
		if (HX_FIELD_EQ(inName,"size") ) { return set_topLeft(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { return set_right(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return set_bottom(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"topLeft") ) { return set_topLeft(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return set_bottomRight(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void Rectangle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("bottom"));
	outFields->push(HX_CSTRING("topLeft"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("bottomRight"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("left"),
	HX_CSTRING("get_left"),
	HX_CSTRING("set_left"),
	HX_CSTRING("right"),
	HX_CSTRING("get_right"),
	HX_CSTRING("set_right"),
	HX_CSTRING("top"),
	HX_CSTRING("get_top"),
	HX_CSTRING("set_top"),
	HX_CSTRING("bottom"),
	HX_CSTRING("get_bottom"),
	HX_CSTRING("set_bottom"),
	HX_CSTRING("topLeft"),
	HX_CSTRING("get_topLeft"),
	HX_CSTRING("set_topLeft"),
	HX_CSTRING("size"),
	HX_CSTRING("get_size"),
	HX_CSTRING("set_size"),
	HX_CSTRING("bottomRight"),
	HX_CSTRING("get_bottomRight"),
	HX_CSTRING("set_bottomRight"),
	HX_CSTRING("clone"),
	HX_CSTRING("contains"),
	HX_CSTRING("containsPoint"),
	HX_CSTRING("containsRect"),
	HX_CSTRING("equals"),
	HX_CSTRING("inflate"),
	HX_CSTRING("inflatePoint"),
	HX_CSTRING("intersection"),
	HX_CSTRING("intersects"),
	HX_CSTRING("union"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("offset"),
	HX_CSTRING("offsetPoint"),
	HX_CSTRING("setEmpty"),
	HX_CSTRING("transform"),
	HX_CSTRING("extendBounds"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Rectangle_obj::__mClass;

void Rectangle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.geom.Rectangle"), hx::TCanCast< Rectangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Rectangle_obj::__boot()
{
}

} // end namespace nme
} // end namespace geom
