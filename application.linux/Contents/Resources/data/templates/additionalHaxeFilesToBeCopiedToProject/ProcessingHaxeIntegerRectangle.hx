// by [ddc] needed something to translate java.awt.Rectangle, which
// can only contain Ints, using the normal float-based Rectangle
// causes endless conversion problems so I'm making an IntRectangle here

/*
 * Copyright (c) 2008, Hugh Sanderson, http://gamehaxe.com/
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED BY THE HAXE PROJECT CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE HAXE PROJECT CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 *
 */


class ProcessingHaxeIntegerRectangle
{
   public var x : Int;
   public var y : Int;
   public var width : Int;
   public var height : Int;

   public function new(?inX : Int, ?inY : Int,
                ?inWidth : Int, ?inHeight : Int) : Void
   {
   	  // small hack cause of the way the java.awt.Rectangle constructor works
   	  // see http://download.oracle.com/javase/6/docs/api/java/awt/Rectangle.html
   	  if (inWidth==null && inHeight==null) {
		  width = inX==null ? 0 : inX;
		  height = inY==null ? 0 : inY;  	  
   	  }
   	  
   	  else {
		  x = inX==null ? 0 : inX;
		  y = inY==null ? 0 : inY; 
		  width = inWidth==null ? 0 : inWidth;
		  height = inHeight==null ? 0 : inHeight;
      }
   }

   public var left(get_left,set_left) : Int;
   function get_left() { return x; }
   function set_left(l:Int) { x=l; return l;}

   public var right(get_right,set_right) : Int;
   function get_right() { return x+width; }
   function set_right(r:Int) { width = r-x; return r;}

   public var top(get_top,set_top) : Int;
   function get_top() { return y; }
   function set_top(t:Int) { y=t; return t;}

   public var bottom(get_bottom,set_bottom) : Int;
   function get_bottom() { return y+height; }
   function set_bottom(b:Int) { height = b-y; return b;}

   public var topLeft(get_topLeft,set_topLeft) : ProcessingHaxeIntegerPoint;
   function get_topLeft() { return new ProcessingHaxeIntegerPoint(x,y); }
   function set_topLeft(p:ProcessingHaxeIntegerPoint) { x=p.x;y=p.y; return p.clone(); }

   public var size(get_topLeft,set_topLeft) : ProcessingHaxeIntegerPoint;
   function get_size() { return new ProcessingHaxeIntegerPoint(width,height); }
   function set_size(p:ProcessingHaxeIntegerPoint) { width=p.x;height=p.y; return p.clone(); }

   public var bottomRight(get_bottomRight,set_bottomRight) : ProcessingHaxeIntegerPoint;
   function get_bottomRight() { return new ProcessingHaxeIntegerPoint(x+width,y+height); }
   function set_bottomRight(p:ProcessingHaxeIntegerPoint)
   {
      width = p.x-x;
      height = p.y-y;
      return p.clone();
   }

   public function clone() : ProcessingHaxeIntegerRectangle
   {
      return new ProcessingHaxeIntegerRectangle(x,y,width,height);
   }
   public function contains(inX : Int, inY : Int) : Bool
   {
      return inX>=x && inY>=y && inX<right && inY<bottom;
   }
   public function containsPoint(point : ProcessingHaxeIntegerPoint) : Bool
   {
      return contains(point.x,point.y);
   }
   public function containsRect(rect : ProcessingHaxeIntegerRectangle) : Bool
   {
     return contains(rect.x,rect.y) && containsPoint(rect.bottomRight);
   }
   public function equals(toCompare : ProcessingHaxeIntegerRectangle) : Bool
   {
      return x==toCompare.x && y==toCompare.y &&
             width==toCompare.width && height==toCompare.height;
   }
   public function inflate(dx : Int, dy : Int) : Void
   {
      x-=dx; width+=dx*2;
      y-=dy; height+=dy*2;
   }
   public function inflatePoint(point : ProcessingHaxeIntegerPoint) : Void
   {
      inflate(point.x,point.y);
   }
   public function intersection(toIntersect : ProcessingHaxeIntegerRectangle) : ProcessingHaxeIntegerRectangle
   {
      var x0 = x<toIntersect.x ? toIntersect.x : x;
      var x1 = right>toIntersect.right ? toIntersect.right : right;
      if (x1<=x0)
         return new ProcessingHaxeIntegerRectangle();

      var y0 = y<toIntersect.y ? toIntersect.x : y;
      var y1 = bottom>toIntersect.bottom ? toIntersect.bottom : bottom;
      if (y1<=y0)
         return new ProcessingHaxeIntegerRectangle();

      return new ProcessingHaxeIntegerRectangle(x0,y0,x1-x0,y1-y0);
   }

   public function intersects(toIntersect : ProcessingHaxeIntegerRectangle) : Bool
   {
      var x0 = x<toIntersect.x ? toIntersect.x : x;
      var x1 = right>toIntersect.right ? toIntersect.right : right;
      if (x1<=x0)
         return false;

      var y0 = y<toIntersect.y ? toIntersect.y : y;
      var y1 = bottom>toIntersect.bottom ? toIntersect.bottom : bottom;
      return y1>y0;
   }

   public function union(toUnion : ProcessingHaxeIntegerRectangle) : ProcessingHaxeIntegerRectangle
   {
      var x0 = x>toUnion.x ? toUnion.x : x;
      var x1 = right<toUnion.right ? toUnion.right : right;
      var y0 = y>toUnion.y ? toUnion.x : y;
      var y1 = bottom<toUnion.bottom ? toUnion.bottom : bottom;
      return new ProcessingHaxeIntegerRectangle(x0,y0,x1-x0,y1-y0);
   }

   public function isEmpty() : Bool { return width==0 && height==0; }
   public function offset(dx : Int, dy : Int) : Void
   {
      x+=dx;
      y+=dy;
   }

   public function offsetPoint(point : ProcessingHaxeIntegerPoint) : Void
   {
      x+=point.x;
      y+=point.y;
   }

   public function setEmpty() : Void { x = y = width = height = 0; }


   public function extendBounds(r:ProcessingHaxeIntegerRectangle)
   {
      var dx = x-r.x;
      if (dx>0)
      {
         x-=dx;
         width+=dx;
      }
      var dy = y-r.y;
      if (dy>0)
      {
         y-=dy;
         height+=dy;
      }
      if (r.right>right)
         right = r.right;
      if (r.bottom>bottom)
         bottom = r.bottom;
   }
}
