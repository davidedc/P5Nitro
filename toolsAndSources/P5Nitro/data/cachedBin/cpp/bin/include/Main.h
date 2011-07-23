#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS0(PGraphics)
HX_DECLARE_CLASS0(PGraphicsRoot)
HX_DECLARE_CLASS0(PImage)
HX_DECLARE_CLASS2(nme,display,Bitmap)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,Event)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)


class Main_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual Void initialiseTopLevelVariables( );
		Dynamic initialiseTopLevelVariables_dyn();

		static Void main( );
		static Dynamic main_dyn();

		static Void wholeDrawCycle( ::nme::events::Event event);
		static Dynamic wholeDrawCycle_dyn();

		static Void startOfDrawMethod( );
		static Dynamic startOfDrawMethod_dyn();

		static Void endOfDrawMethod( );
		static Dynamic endOfDrawMethod_dyn();

		static ::PGraphicsRoot g; /* REM */ 
		static int frameCount; /* REM */ 
		static int width; /* REM */ 
		static int height; /* REM */ 
		static int frameRate; /* REM */ 
		static int millisecondsWhenSketchStarted; /* REM */ 
		static double timeStampOfLastDraw; /* REM */ 
		static int millisecondsTheAppHasSpentBackgrounded; /* REM */ 
		static bool mousePressed; /* REM */ 
		static bool keyPressed; /* REM */ 
		static int mouseX; /* REM */ 
		static int mouseY; /* REM */ 
		static int pmouseX; /* REM */ 
		static int pmouseY; /* REM */ 
		static double PI; /* REM */ 
		static double TWO_PI; /* REM */ 
		static double HALF_PI; /* REM */ 
		static int P2D; /* REM */ 
		static int P3D; /* REM */ 
		static int CORNER; /* REM */ 
		static int RADIUS; /* REM */ 
		static int CENTER_RADIUS; /* REM */ 
		static int CENTER; /* REM */ 
		static int POLYGON; /* REM */ 
		static int QUADS; /* REM */ 
		static int TRIANGLES; /* REM */ 
		static int POINTS; /* REM */ 
		static int LINES; /* REM */ 
		static int TRIANGLE_STRIP; /* REM */ 
		static int TRIANGLE_FAN; /* REM */ 
		static int QUAD_STRIP; /* REM */ 
		static int CORNERS; /* REM */ 
		static bool CLOSE; /* REM */ 
		static int RGB; /* REM */ 
		static int HSB; /* REM */ 
		static Void exitArgCount0( );
		static Dynamic exitArgCount0_dyn();

		static double powArgCount2( double v,double exp);
		static Dynamic powArgCount2_dyn();

		static double absArgCount1( double v);
		static Dynamic absArgCount1_dyn();

		static double floorArgCount1( double v);
		static Dynamic floorArgCount1_dyn();

		static int yearArgCount0( );
		static Dynamic yearArgCount0_dyn();

		static int monthArgCount0( );
		static Dynamic monthArgCount0_dyn();

		static int dayArgCount0( );
		static Dynamic dayArgCount0_dyn();

		static int hourArgCount0( );
		static Dynamic hourArgCount0_dyn();

		static int minuteArgCount0( );
		static Dynamic minuteArgCount0_dyn();

		static int secondArgCount0( );
		static Dynamic secondArgCount0_dyn();

		static Void pushMatrixArgCount0( );
		static Dynamic pushMatrixArgCount0_dyn();

		static Void popMatrixArgCount0( );
		static Dynamic popMatrixArgCount0_dyn();

		static int millisArgCount0( );
		static Dynamic millisArgCount0_dyn();

		static Void delayArgCount1( int millisecondsToWait);
		static Dynamic delayArgCount1_dyn();

		static Void frameRateArgCount1( int theFrameRate);
		static Dynamic frameRateArgCount1_dyn();

		static Void ellipseModeArgCount1( int aEllipseMode);
		static Dynamic ellipseModeArgCount1_dyn();

		static Void noLoopArgCount0( );
		static Dynamic noLoopArgCount0_dyn();

		static int getArgCount2( int x,int y);
		static Dynamic getArgCount2_dyn();

		static Void setArgCount3( int x,int y,int color);
		static Dynamic setArgCount3_dyn();

		static Void smoothArgCount0( );
		static Dynamic smoothArgCount0_dyn();

		static int colorArgCount1( int shadeOfGray);
		static Dynamic colorArgCount1_dyn();

		static int colorArgCount2( int shadeOfGray,int a);
		static Dynamic colorArgCount2_dyn();

		static int colorArgCount3( int r,int green,int b);
		static Dynamic colorArgCount3_dyn();

		static int colorArgCount4( int r,int green,int b,int a);
		static Dynamic colorArgCount4_dyn();

		static int redArgCount1( int aColor);
		static Dynamic redArgCount1_dyn();

		static int greenArgCount1( int aColor);
		static Dynamic greenArgCount1_dyn();

		static int blueArgCount1( int aColor);
		static Dynamic blueArgCount1_dyn();

		static int alphaArgCount1( int aColor);
		static Dynamic alphaArgCount1_dyn();

		static Void endDrawArgCount0( );
		static Dynamic endDrawArgCount0_dyn();

		static Void beginDrawArgCount0( );
		static Dynamic beginDrawArgCount0_dyn();

		static Void backgroundArgCount4( int r,int green,int b,int a);
		static Dynamic backgroundArgCount4_dyn();

		static Void backgroundArgCount3( int r,int green,int b);
		static Dynamic backgroundArgCount3_dyn();

		static Void backgroundArgCount2( int shadeOfGray,int a);
		static Dynamic backgroundArgCount2_dyn();

		static Void backgroundArgCount1( int shadeOfGray);
		static Dynamic backgroundArgCount1_dyn();

		static Void backgroundArgCount0( );
		static Dynamic backgroundArgCount0_dyn();

		static Void imageArgCount3( ::PImage img,int x,int y);
		static Dynamic imageArgCount3_dyn();

		static Void tintArgCount3( double rc,double gc,double bc);
		static Dynamic tintArgCount3_dyn();

		static Void tintArgCount4( double rc,double gc,double bc,double ac);
		static Dynamic tintArgCount4_dyn();

		static Void noTintArgCount0( );
		static Dynamic noTintArgCount0_dyn();

		static ::PGraphics createGraphicsArgCount3( int w,int h,int type);
		static Dynamic createGraphicsArgCount3_dyn();

		static Void printlnArgCount1( ::String theString);
		static Dynamic printlnArgCount1_dyn();

		static Void printArgCount1( ::String theString);
		static Dynamic printArgCount1_dyn();

		static Void lineArgCount4( Dynamic x1,Dynamic y1,Dynamic x2,Dynamic y2);
		static Dynamic lineArgCount4_dyn();

		static double mapArgCount5( double value,double istart,double istop,double ostart,double ostop);
		static Dynamic mapArgCount5_dyn();

		static double randomArgCount2( double aMin,double aMax);
		static Dynamic randomArgCount2_dyn();

		static double sinArgCount1( double aNumber);
		static Dynamic sinArgCount1_dyn();

		static double cosArgCount1( double aNumber);
		static Dynamic cosArgCount1_dyn();

		static Void rectArgCount4( Dynamic x1,Dynamic y1,Dynamic x2,Dynamic y2);
		static Dynamic rectArgCount4_dyn();

		static Void triangleArgCount6( double x1,double y1,double x2,double y2,double x3,double y3);
		static Dynamic triangleArgCount6_dyn();

		static Void ellipseArgCount4( Dynamic x1,Dynamic y1,Dynamic x2,Dynamic y2);
		static Dynamic ellipseArgCount4_dyn();

		static Void noStrokeArgCount0( );
		static Dynamic noStrokeArgCount0_dyn();

		static Void strokeArgCount4( double r,double green,double b,double a);
		static Dynamic strokeArgCount4_dyn();

		static Void strokeArgCount3( double theRed,double theGreen,double theBlue);
		static Dynamic strokeArgCount3_dyn();

		static Void strokeArgCount2( double shade,double a);
		static Dynamic strokeArgCount2_dyn();

		static Void strokeArgCount1( double shade);
		static Dynamic strokeArgCount1_dyn();

		static Void noFillArgCount0( );
		static Dynamic noFillArgCount0_dyn();

		static Void fillArgCount4( double r,double green,double b,double a);
		static Dynamic fillArgCount4_dyn();

		static Void fillArgCount3( double r,double green,double b);
		static Dynamic fillArgCount3_dyn();

		static Void fillArgCount2( double shade,double a);
		static Dynamic fillArgCount2_dyn();

		static Void fillArgCount1( double shade);
		static Dynamic fillArgCount1_dyn();

		static Void rotateArgCount1( double aAngle);
		static Dynamic rotateArgCount1_dyn();

		static Void scaleArgCount2( double x,double y);
		static Dynamic scaleArgCount2_dyn();

		static Void scaleArgCount1( double xy);
		static Dynamic scaleArgCount1_dyn();

		static Void translateArgCount2( double x,double y);
		static Dynamic translateArgCount2_dyn();

		static int intArgCount1( double x);
		static Dynamic intArgCount1_dyn();

		static Void strokeWeightArgCount1( double w);
		static Dynamic strokeWeightArgCount1_dyn();

		static Void pointArgCount2( double x,double y);
		static Dynamic pointArgCount2_dyn();

		static Void mouseUpCatcherFunction( Dynamic event);
		static Dynamic mouseUpCatcherFunction_dyn();

		static Void mouseDownCatcherFunction( Dynamic event);
		static Dynamic mouseDownCatcherFunction_dyn();

		static Void mouseMoveCatcherFunction( Dynamic event);
		static Dynamic mouseMoveCatcherFunction_dyn();

		static Void mouseClickCatcherFunction( Dynamic event);
		static Dynamic mouseClickCatcherFunction_dyn();

		static Void beginShapeArgCount0( );
		static Dynamic beginShapeArgCount0_dyn();

		static Void beginShapeArgCount1( int x);
		static Dynamic beginShapeArgCount1_dyn();

		static Void vertexArgCount2( double x1,double y1);
		static Dynamic vertexArgCount2_dyn();

		static Void vertexArgCount4( double x1,double y1,double x2,double y2);
		static Dynamic vertexArgCount4_dyn();

		static Void vertexArgCount6( double x1,double y1,double x2,double y2,double x3,double y3);
		static Dynamic vertexArgCount6_dyn();

		static Void endShapeArgCount1( bool x);
		static Dynamic endShapeArgCount1_dyn();

		static Void bezierArgCount8( double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4);
		static Dynamic bezierArgCount8_dyn();

		static Void curveVertexArgCount2( double x,double y);
		static Dynamic curveVertexArgCount2_dyn();

		static Void endShapeArgCount0( );
		static Dynamic endShapeArgCount0_dyn();

		static Void bezierVertexArgCount6( double x,double y,double x2,double y2,double x3,double y3);
		static Dynamic bezierVertexArgCount6_dyn();

		static Void sizeArgCount2( double x1,double y1);
		static Dynamic sizeArgCount2_dyn();

		static Array< ::String > loadStringsArgCount1( ::String x1);
		static Dynamic loadStringsArgCount1_dyn();

		static Void saveStringsArgCount2( ::String fileName,Array< ::String > arrayOfStrings);
		static Dynamic saveStringsArgCount2_dyn();

		static Void setupArgCount0( );
		static Dynamic setupArgCount0_dyn();

		static Void drawArgCount0( );
		static Dynamic drawArgCount0_dyn();

};


#endif /* INCLUDED_Main */ 
