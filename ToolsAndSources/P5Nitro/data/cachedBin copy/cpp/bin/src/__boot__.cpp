#include <hxcpp.h>

#include <nme/display/JointStyle.h>
#include <nme/geom/Matrix.h>
#include <Date.h>
#include <nme/system/System.h>
#include <haxe/io/Bytes.h>
#include <nme/display/GradientType.h>
#include <nme/display/TriangleCulling.h>
#include <nme/media/SoundTransform.h>
#include <PGraphicsRoot.h>
#include <haxe/io/Error.h>
#include <nme/geom/Rectangle.h>
#include <ApplicationMain.h>
#include <nme/Lib.h>
#include <nme/events/KeyboardEvent.h>
#include <Main.h>
#include <nme/events/ProgressEvent.h>
#include <nme/geom/Point.h>
#include <Std.h>
#include <nme/display/StageScaleMode.h>
#include <nme/display/LineScaleMode.h>
#include <Hash.h>
#include <nme/net/URLLoaderDataFormat.h>
#include <haxe/Log.h>
#include <cpp/io/File.h>
#include <cpp/io/FileSeek.h>
#include <nme/events/Listener.h>
#include <nme/utils/ByteArray.h>
#include <nme/events/EventPhase.h>
#include <nme/events/IOErrorEvent.h>
#include <nme/display/BitmapData.h>
#include <nme/events/ErrorEvent.h>
#include <nme/events/TextEvent.h>
#include <nme/net/URLRequest.h>
#include <StringBuf.h>
#include <nme/display/PixelSnapping.h>
#include <nme/geom/Transform.h>
#include <nme/display/StageAlign.h>
#include <nme/display/ManagedStage.h>
#include <IntHash.h>
#include <nme/utils/Endian.h>
#include <nme/geom/ColorTransform.h>
#include <nme/errors/RangeError.h>
#include <nme/errors/Error.h>
#include <nme/filters/BitmapFilter.h>
#include <Type.h>
#include <ValueType.h>
#include <cpp/io/FileOutput.h>
#include <haxe/io/Output.h>
#include <HighDpiScreenManager.h>
#include <IntIter.h>
#include <nme/display/IGraphicsData.h>
#include <nme/display/StageDisplayState.h>
#include <nme/display/SpreadMethod.h>
#include <nme/display/Tilesheet.h>
#include <Reflect.h>
#include <nme/display/Shape.h>
#include <haxe/io/Eof.h>
#include <nme/media/SoundChannel.h>
#include <nme/display/Stage.h>
#include <nme/events/TouchEvent.h>
#include <nme/events/MouseEvent.h>
#include <nme/display/TouchInfo.h>
#include <nme/net/URLLoader.h>
#include <nme/display/Graphics.h>
#include <ProcessingHaxeBitmapPool.h>
#include <cpp/vm/Gc.h>
#include <nme/events/FocusEvent.h>
#include <nme/events/Event.h>
#include <nme/Timer.h>
#include <nme/display/MovieClip.h>
#include <nme/display/Sprite.h>
#include <nme/display/DisplayObjectContainer.h>
#include <nme/display/InteractiveObject.h>
#include <nme/display/StageQuality.h>
#include <nme/display/InterpolationMethod.h>
#include <cpp/io/FileInput.h>
#include <haxe/io/Input.h>
#include <List.h>
#include <cpp/FileSystem.h>
#include <cpp/FileKind.h>
#include <PGraphics.h>
#include <PImage.h>
#include <nme/display/Bitmap.h>
#include <nme/display/DisplayObject.h>
#include <cpp/Lib.h>
#include <nme/Loader.h>
#include <nme/events/EventDispatcher.h>
#include <nme/display/BlendMode.h>
#include <nme/display/CapsStyle.h>
#include <haxe/io/BytesBuffer.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::nme::display::JointStyle_obj::__register();
::nme::geom::Matrix_obj::__register();
::Date_obj::__register();
::nme::system::System_obj::__register();
::haxe::io::Bytes_obj::__register();
::nme::display::GradientType_obj::__register();
::nme::display::TriangleCulling_obj::__register();
::nme::media::SoundTransform_obj::__register();
::PGraphicsRoot_obj::__register();
::haxe::io::Error_obj::__register();
::nme::geom::Rectangle_obj::__register();
::ApplicationMain_obj::__register();
::nme::Lib_obj::__register();
::nme::events::KeyboardEvent_obj::__register();
::Main_obj::__register();
::nme::events::ProgressEvent_obj::__register();
::nme::geom::Point_obj::__register();
::Std_obj::__register();
::nme::display::StageScaleMode_obj::__register();
::nme::display::LineScaleMode_obj::__register();
::Hash_obj::__register();
::nme::net::URLLoaderDataFormat_obj::__register();
::haxe::Log_obj::__register();
::cpp::io::File_obj::__register();
::cpp::io::FileSeek_obj::__register();
::nme::events::Listener_obj::__register();
::nme::utils::ByteArray_obj::__register();
::nme::events::EventPhase_obj::__register();
::nme::events::IOErrorEvent_obj::__register();
::nme::display::BitmapData_obj::__register();
::nme::events::ErrorEvent_obj::__register();
::nme::events::TextEvent_obj::__register();
::nme::net::URLRequest_obj::__register();
::StringBuf_obj::__register();
::nme::display::PixelSnapping_obj::__register();
::nme::geom::Transform_obj::__register();
::nme::display::StageAlign_obj::__register();
::nme::display::ManagedStage_obj::__register();
::IntHash_obj::__register();
::nme::utils::Endian_obj::__register();
::nme::geom::ColorTransform_obj::__register();
::nme::errors::RangeError_obj::__register();
::nme::errors::Error_obj::__register();
::nme::filters::BitmapFilter_obj::__register();
::Type_obj::__register();
::ValueType_obj::__register();
::cpp::io::FileOutput_obj::__register();
::haxe::io::Output_obj::__register();
::HighDpiScreenManager_obj::__register();
::IntIter_obj::__register();
::nme::display::IGraphicsData_obj::__register();
::nme::display::StageDisplayState_obj::__register();
::nme::display::SpreadMethod_obj::__register();
::nme::display::Tilesheet_obj::__register();
::Reflect_obj::__register();
::nme::display::Shape_obj::__register();
::haxe::io::Eof_obj::__register();
::nme::media::SoundChannel_obj::__register();
::nme::display::Stage_obj::__register();
::nme::events::TouchEvent_obj::__register();
::nme::events::MouseEvent_obj::__register();
::nme::display::TouchInfo_obj::__register();
::nme::net::URLLoader_obj::__register();
::nme::display::Graphics_obj::__register();
::ProcessingHaxeBitmapPool_obj::__register();
::cpp::vm::Gc_obj::__register();
::nme::events::FocusEvent_obj::__register();
::nme::events::Event_obj::__register();
::nme::Timer_obj::__register();
::nme::display::MovieClip_obj::__register();
::nme::display::Sprite_obj::__register();
::nme::display::DisplayObjectContainer_obj::__register();
::nme::display::InteractiveObject_obj::__register();
::nme::display::StageQuality_obj::__register();
::nme::display::InterpolationMethod_obj::__register();
::cpp::io::FileInput_obj::__register();
::haxe::io::Input_obj::__register();
::List_obj::__register();
::cpp::FileSystem_obj::__register();
::cpp::FileKind_obj::__register();
::PGraphics_obj::__register();
::PImage_obj::__register();
::nme::display::Bitmap_obj::__register();
::nme::display::DisplayObject_obj::__register();
::cpp::Lib_obj::__register();
::nme::Loader_obj::__register();
::nme::events::EventDispatcher_obj::__register();
::nme::display::BlendMode_obj::__register();
::nme::display::CapsStyle_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::io::BytesBuffer_obj::__boot();
::nme::display::CapsStyle_obj::__boot();
::nme::display::BlendMode_obj::__boot();
::nme::events::EventDispatcher_obj::__boot();
::nme::Loader_obj::__boot();
::cpp::Lib_obj::__boot();
::nme::display::DisplayObject_obj::__boot();
::nme::display::Bitmap_obj::__boot();
::PImage_obj::__boot();
::PGraphics_obj::__boot();
::cpp::FileKind_obj::__boot();
::cpp::FileSystem_obj::__boot();
::List_obj::__boot();
::haxe::io::Input_obj::__boot();
::cpp::io::FileInput_obj::__boot();
::nme::display::InterpolationMethod_obj::__boot();
::nme::display::StageQuality_obj::__boot();
::nme::display::InteractiveObject_obj::__boot();
::nme::display::DisplayObjectContainer_obj::__boot();
::nme::display::Sprite_obj::__boot();
::nme::display::MovieClip_obj::__boot();
::nme::Timer_obj::__boot();
::nme::events::Event_obj::__boot();
::nme::events::FocusEvent_obj::__boot();
::cpp::vm::Gc_obj::__boot();
::ProcessingHaxeBitmapPool_obj::__boot();
::nme::display::Graphics_obj::__boot();
::nme::net::URLLoader_obj::__boot();
::nme::display::TouchInfo_obj::__boot();
::nme::events::MouseEvent_obj::__boot();
::nme::events::TouchEvent_obj::__boot();
::nme::display::Stage_obj::__boot();
::nme::media::SoundChannel_obj::__boot();
::haxe::io::Eof_obj::__boot();
::nme::display::Shape_obj::__boot();
::Reflect_obj::__boot();
::nme::display::Tilesheet_obj::__boot();
::nme::display::SpreadMethod_obj::__boot();
::nme::display::StageDisplayState_obj::__boot();
::nme::display::IGraphicsData_obj::__boot();
::IntIter_obj::__boot();
::HighDpiScreenManager_obj::__boot();
::haxe::io::Output_obj::__boot();
::cpp::io::FileOutput_obj::__boot();
::ValueType_obj::__boot();
::Type_obj::__boot();
::nme::filters::BitmapFilter_obj::__boot();
::nme::errors::Error_obj::__boot();
::nme::errors::RangeError_obj::__boot();
::nme::geom::ColorTransform_obj::__boot();
::nme::utils::Endian_obj::__boot();
::IntHash_obj::__boot();
::nme::display::ManagedStage_obj::__boot();
::nme::display::StageAlign_obj::__boot();
::nme::geom::Transform_obj::__boot();
::nme::display::PixelSnapping_obj::__boot();
::StringBuf_obj::__boot();
::nme::net::URLRequest_obj::__boot();
::nme::events::TextEvent_obj::__boot();
::nme::events::ErrorEvent_obj::__boot();
::nme::display::BitmapData_obj::__boot();
::nme::events::IOErrorEvent_obj::__boot();
::nme::events::EventPhase_obj::__boot();
::nme::utils::ByteArray_obj::__boot();
::nme::events::Listener_obj::__boot();
::cpp::io::FileSeek_obj::__boot();
::cpp::io::File_obj::__boot();
::haxe::Log_obj::__boot();
::nme::net::URLLoaderDataFormat_obj::__boot();
::Hash_obj::__boot();
::nme::display::LineScaleMode_obj::__boot();
::nme::display::StageScaleMode_obj::__boot();
::Std_obj::__boot();
::nme::geom::Point_obj::__boot();
::nme::events::ProgressEvent_obj::__boot();
::Main_obj::__boot();
::nme::events::KeyboardEvent_obj::__boot();
::nme::Lib_obj::__boot();
::ApplicationMain_obj::__boot();
::nme::geom::Rectangle_obj::__boot();
::haxe::io::Error_obj::__boot();
::PGraphicsRoot_obj::__boot();
::nme::media::SoundTransform_obj::__boot();
::nme::display::TriangleCulling_obj::__boot();
::nme::display::GradientType_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::nme::system::System_obj::__boot();
::Date_obj::__boot();
::nme::geom::Matrix_obj::__boot();
::nme::display::JointStyle_obj::__boot();
}

