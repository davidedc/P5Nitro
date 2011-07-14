#ifndef INCLUDED_PGraphicsRoot
#define INCLUDED_PGraphicsRoot

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/Sprite.h>
HX_DECLARE_CLASS0(PGraphics)
HX_DECLARE_CLASS0(PGraphicsRoot)
HX_DECLARE_CLASS0(PImage)
HX_DECLARE_CLASS0(ProcessingHaxeBitmapPool)
HX_DECLARE_CLASS2(nme,display,Bitmap)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Shape)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Point)


class PGraphicsRoot_obj : public ::nme::display::Sprite_obj{
	public:
		typedef ::nme::display::Sprite_obj super;
		typedef PGraphicsRoot_obj OBJ_;
		PGraphicsRoot_obj();
		Void __construct(Dynamic x,Dynamic y);

	public:
		static hx::ObjectPtr< PGraphicsRoot_obj > __new(Dynamic x,Dynamic y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PGraphicsRoot_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("PGraphicsRoot"); }

		::ProcessingHaxeBitmapPool bitmapPool; /* REM */ 
		bool newShapeNeeded; /* REM */ 
		int pGraphicsAlpha; /* REM */ 
		double PI; /* REM */ 
		double TWO_PI; /* REM */ 
		double HALF_PI; /* REM */ 
		int P2D; /* REM */ 
		int P3D; /* REM */ 
		int CORNER; /* REM */ 
		int RADIUS; /* REM */ 
		int CENTER_RADIUS; /* REM */ 
		int CENTER; /* REM */ 
		int POLYGON; /* REM */ 
		int QUADS; /* REM */ 
		int TRIANGLES; /* REM */ 
		int POINTS; /* REM */ 
		int LINES; /* REM */ 
		int TRIANGLE_STRIP; /* REM */ 
		int TRIANGLE_FAN; /* REM */ 
		int QUAD_STRIP; /* REM */ 
		int CORNERS; /* REM */ 
		bool CLOSE; /* REM */ 
		int RGB; /* REM */ 
		int HSB; /* REM */ 
		bool hasBackground; /* REM */ 
		int curRectMode; /* REM */ 
		int curEllipseMode; /* REM */ 
		int curShape; /* REM */ 
		int curShapeCount; /* REM */ 
		int opacityRange; /* REM */ 
		int redRange; /* REM */ 
		int greenRange; /* REM */ 
		int blueRange; /* REM */ 
		bool pathOpen; /* REM */ 
		bool mousePressed; /* REM */ 
		bool keyPressed; /* REM */ 
		double firstX; /* REM */ 
		double firstY; /* REM */ 
		double secondX; /* REM */ 
		double secondY; /* REM */ 
		double prevX; /* REM */ 
		double prevY; /* REM */ 
		int curColorMode; /* REM */ 
		int tintColor; /* REM */ 
		int curTextSize; /* REM */ 
		::String curTextFont; /* REM */ 
		bool doStroke; /* REM */ 
		double curStrokeWeight; /* REM */ 
		int curStrokeColor; /* REM */ 
		bool tint; /* REM */ 
		bool doFill; /* REM */ 
		int curFillColor; /* REM */ 
		::nme::display::Shape shape; /* REM */ 
		::nme::geom::Matrix shapeMatrix; /* REM */ 
		bool doSmooth; /* REM */ 
		double trackingScaleX; /* REM */ 
		double trackingScaleY; /* REM */ 
		double trackingRotation; /* REM */ 
		double trackingTranslationX; /* REM */ 
		double trackingTranslationY; /* REM */ 
		Array< ::nme::geom::Matrix > matrixStack; /* REM */ 
		Array< double > trackingScaleXStack; /* REM */ 
		Array< double > trackingScaleYStack; /* REM */ 
		Array< double > trackingRotationStack; /* REM */ 
		Array< double > trackingTranslationXStack; /* REM */ 
		Array< double > trackingTranslationYStack; /* REM */ 
		double curTightness; /* REM */ 
		Array< ::nme::geom::Point > curvePoints; /* REM */ 
		int curBackground; /* REM */ 
		virtual int getArgCount2( int x,int y);
		Dynamic getArgCount2_dyn();

		virtual Void setArgCount3( int x,int y,int color);
		Dynamic setArgCount3_dyn();

		virtual Void ellipseModeArgCount1( int aEllipseMode);
		Dynamic ellipseModeArgCount1_dyn();

		virtual Void smoothArgCount0( );
		Dynamic smoothArgCount0_dyn();

		virtual Void endDrawArgCount0( );
		Dynamic endDrawArgCount0_dyn();

		virtual Void beginDrawArgCount0( );
		Dynamic beginDrawArgCount0_dyn();

		virtual double sinArgCount1( double aNumber);
		Dynamic sinArgCount1_dyn();

		virtual double cosArgCount1( double aNumber);
		Dynamic cosArgCount1_dyn();

		virtual double randomArgCount2( double aMin,double aMax);
		Dynamic randomArgCount2_dyn();

		virtual Void backgroundArgCount4( int r,int g,int b,int a);
		Dynamic backgroundArgCount4_dyn();

		virtual Void backgroundArgCount3( int r,int g,int b);
		Dynamic backgroundArgCount3_dyn();

		virtual Void backgroundArgCount2( int shadeOfGray,int a);
		Dynamic backgroundArgCount2_dyn();

		virtual Void backgroundArgCount1( int shadeOfGray);
		Dynamic backgroundArgCount1_dyn();

		virtual Void backgroundArgCount0( );
		Dynamic backgroundArgCount0_dyn();

		virtual Void imageArgCount3( ::PImage img,int x,int y);
		Dynamic imageArgCount3_dyn();

		virtual Void noTintArgCount0( );
		Dynamic noTintArgCount0_dyn();

		virtual Void tintArgCount3( double rc,double gc,double bc);
		Dynamic tintArgCount3_dyn();

		virtual Void tintArgCount4( double rc,double gc,double bc,double ac);
		Dynamic tintArgCount4_dyn();

		virtual ::PGraphics createGraphicsArgCount3( int w,int h,int type);
		Dynamic createGraphicsArgCount3_dyn();

		virtual int redArgCount1( int aColor);
		Dynamic redArgCount1_dyn();

		virtual int greenArgCount1( int aColor);
		Dynamic greenArgCount1_dyn();

		virtual int blueArgCount1( int aColor);
		Dynamic blueArgCount1_dyn();

		virtual int alphaArgCount1( int aColor);
		Dynamic alphaArgCount1_dyn();

		virtual int pGraphicsAlphaMethod( int aColor);
		Dynamic pGraphicsAlphaMethod_dyn();

		virtual Void beginShapeDrawing( );
		Dynamic beginShapeDrawing_dyn();

		virtual Void endAnyOpenFills( );
		Dynamic endAnyOpenFills_dyn();

		virtual Void lineArgCount4( Dynamic x1,Dynamic y1,Dynamic x2,Dynamic y2);
		Dynamic lineArgCount4_dyn();

		virtual Void rectArgCount4( double x,double y,double width,double height);
		Dynamic rectArgCount4_dyn();

		virtual Void triangleArgCount6( double x1,double y1,double x2,double y2,double x3,double y3);
		Dynamic triangleArgCount6_dyn();

		virtual Void ellipse( double x,double y,double width,double height);
		Dynamic ellipse_dyn();

		virtual Void noStrokeArgCount0( );
		Dynamic noStrokeArgCount0_dyn();

		virtual Void strokeArgCount4( int r,int g,int b,int a);
		Dynamic strokeArgCount4_dyn();

		virtual Void strokeArgCount3( int r,int g,int b);
		Dynamic strokeArgCount3_dyn();

		virtual Void strokeArgCount2( int grayScale,int a);
		Dynamic strokeArgCount2_dyn();

		virtual Void strokeArgCount1( int grayScale);
		Dynamic strokeArgCount1_dyn();

		virtual Void noFillArgCount0( );
		Dynamic noFillArgCount0_dyn();

		virtual Void fillArgCount4( int mr,int mg,int mb,int ma);
		Dynamic fillArgCount4_dyn();

		virtual Void fillArgCount3( int r,int g,int b);
		Dynamic fillArgCount3_dyn();

		virtual Void fillArgCount2( int grayScale,int a);
		Dynamic fillArgCount2_dyn();

		virtual Void fillArgCount1( int grayScale);
		Dynamic fillArgCount1_dyn();

		virtual int colorArgCount1( int shadeOfGray);
		Dynamic colorArgCount1_dyn();

		virtual int colorArgCount2( int shadeOfGray,int a);
		Dynamic colorArgCount2_dyn();

		virtual int colorArgCount3( int r,int g,int b);
		Dynamic colorArgCount3_dyn();

		virtual int colorArgCount4( int theR,int theG,int theB,int theA);
		Dynamic colorArgCount4_dyn();

		virtual int getColor( int aValue,int range);
		Dynamic getColor_dyn();

		virtual Void pushMatrixWithoutCreatingNewShape( );
		Dynamic pushMatrixWithoutCreatingNewShape_dyn();

		virtual Void pushMatrixArgCount0( );
		Dynamic pushMatrixArgCount0_dyn();

		virtual Void popMatrixWithoutCreatingNewShape( );
		Dynamic popMatrixWithoutCreatingNewShape_dyn();

		virtual Void popMatrixArgCount0( );
		Dynamic popMatrixArgCount0_dyn();

		virtual Void rotateArgCount1( double aAngle);
		Dynamic rotateArgCount1_dyn();

		virtual Void scaleArgCount2( double x,double y);
		Dynamic scaleArgCount2_dyn();

		virtual Void createNewShape( );
		Dynamic createNewShape_dyn();

		virtual Void scaleArgCount1( double xy);
		Dynamic scaleArgCount1_dyn();

		virtual Void translateArgCount2( double x,double y);
		Dynamic translateArgCount2_dyn();

		virtual Void strokeWeightArgCount1( double w);
		Dynamic strokeWeightArgCount1_dyn();

		virtual Void pointArgCount2( double x,double y);
		Dynamic pointArgCount2_dyn();

		virtual Void beginShapeArgCount0( );
		Dynamic beginShapeArgCount0_dyn();

		virtual Void beginShapeArgCount1( int type);
		Dynamic beginShapeArgCount1_dyn();

		virtual Void endShapeArgCount0( );
		Dynamic endShapeArgCount0_dyn();

		virtual Void endShapeArgCount1( bool close);
		Dynamic endShapeArgCount1_dyn();

		virtual Void vertexArgCount2( double x,double y);
		Dynamic vertexArgCount2_dyn();

		virtual Void vertexArgCount4( double x,double y,double x2,double y2);
		Dynamic vertexArgCount4_dyn();

		virtual Void vertexArgCount6( double x,double y,double x2,double y2,double x3,double y3);
		Dynamic vertexArgCount6_dyn();

		virtual Void bezierVertexArgCount6( double x,double y,double x2,double y2,double x3,double y3);
		Dynamic bezierVertexArgCount6_dyn();

		virtual Void curveVertexArgCount2( double x,double y);
		Dynamic curveVertexArgCount2_dyn();

		virtual Void curveTightness( double tightness);
		Dynamic curveTightness_dyn();

		virtual Void bezierArgCount8( double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4);
		Dynamic bezierArgCount8_dyn();

		virtual Void drawCubicBezier2( double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4);
		Dynamic drawCubicBezier2_dyn();

		static ::nme::geom::Point getMiddle( double x1,double y1,double x2,double y2);
		static Dynamic getMiddle_dyn();

		static ::nme::geom::Point getPointOnSegment( double x1,double y1,double x2,double y2,double ratio);
		static Dynamic getPointOnSegment_dyn();

};


#endif /* INCLUDED_PGraphicsRoot */ 
