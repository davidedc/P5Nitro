#ifndef INCLUDED_nme_utils_ByteArray
#define INCLUDED_nme_utils_ByteArray

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
namespace nme{
namespace utils{


class ByteArray_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef ByteArray_obj OBJ_;
		ByteArray_obj();
		Void __construct(Dynamic __o_inLen);

	public:
		static hx::ObjectPtr< ByteArray_obj > __new(Dynamic __o_inLen);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ByteArray_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ByteArray"); }

		typedef int __array_access;
		int position; /* REM */ 
		::String endian; /* REM */ 
		Dynamic nmeData; /* REM */ 
		int length; /* REM */ 
		virtual Dynamic nmeGetData( );
		Dynamic nmeGetData_dyn();

		virtual ::nme::utils::ByteArray getData( );
		Dynamic getData_dyn();

		virtual ::String asString( );
		Dynamic asString_dyn();

		virtual int nmeGetLength( );
		Dynamic nmeGetLength_dyn();

		virtual int __get( int pos);
		Dynamic __get_dyn();

		virtual Void __set( int pos,int v);
		Dynamic __set_dyn();

		virtual ::haxe::io::Bytes getBytes( );
		Dynamic getBytes_dyn();

		virtual Void writeFile( ::String inString);
		Dynamic writeFile_dyn();

		virtual int readByte( );
		Dynamic readByte_dyn();

		virtual int readInt( );
		Dynamic readInt_dyn();

		virtual int readShort( );
		Dynamic readShort_dyn();

		virtual int readUnsignedByte( );
		Dynamic readUnsignedByte_dyn();

		virtual int readUnsignedShort( );
		Dynamic readUnsignedShort_dyn();

		virtual ::String readUTFBytes( int inLen);
		Dynamic readUTFBytes_dyn();

		virtual ::String nmeGetEndian( );
		Dynamic nmeGetEndian_dyn();

		virtual ::String nmeSetEndian( ::String s);
		Dynamic nmeSetEndian_dyn();

		virtual Void writeUTFBytesToBuffer( ::String str);
		Dynamic writeUTFBytesToBuffer_dyn();

		static ::nme::utils::ByteArray fromHandle( Dynamic inHandle);
		static Dynamic fromHandle_dyn();

		static ::nme::utils::ByteArray readFile( ::String inString);
		static Dynamic readFile_dyn();

		static Dynamic nme_byte_array_create; /* REM */ 
	Dynamic &nme_byte_array_create_dyn() { return nme_byte_array_create;}
		static Dynamic nme_byte_array_as_string; /* REM */ 
	Dynamic &nme_byte_array_as_string_dyn() { return nme_byte_array_as_string;}
		static Dynamic nme_byte_array_get_bytes; /* REM */ 
	Dynamic &nme_byte_array_get_bytes_dyn() { return nme_byte_array_get_bytes;}
		static Dynamic nme_byte_array_read_file; /* REM */ 
	Dynamic &nme_byte_array_read_file_dyn() { return nme_byte_array_read_file;}
		static Dynamic nme_byte_array_overwrite_file; /* REM */ 
	Dynamic &nme_byte_array_overwrite_file_dyn() { return nme_byte_array_overwrite_file;}
		static Dynamic nme_byte_array_get_length; /* REM */ 
	Dynamic &nme_byte_array_get_length_dyn() { return nme_byte_array_get_length;}
		static Dynamic nme_byte_array_get; /* REM */ 
	Dynamic &nme_byte_array_get_dyn() { return nme_byte_array_get;}
		static Dynamic nme_byte_array_set; /* REM */ 
	Dynamic &nme_byte_array_set_dyn() { return nme_byte_array_set;}
};

} // end namespace nme
} // end namespace utils

#endif /* INCLUDED_nme_utils_ByteArray */ 
