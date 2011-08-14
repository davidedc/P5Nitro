#ifndef INCLUDED_cpp_io_FileSeek
#define INCLUDED_cpp_io_FileSeek

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(cpp,io,FileSeek)
namespace cpp{
namespace io{


class FileSeek_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef FileSeek_obj OBJ_;

	public:
		FileSeek_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("cpp.io.FileSeek"); }
		::String __ToString() const { return HX_CSTRING("FileSeek.") + tag; }

		static ::cpp::io::FileSeek SeekBegin;
		static ::cpp::io::FileSeek SeekCur;
		static ::cpp::io::FileSeek SeekEnd;
};

} // end namespace cpp
} // end namespace io

#endif /* INCLUDED_cpp_io_FileSeek */ 
