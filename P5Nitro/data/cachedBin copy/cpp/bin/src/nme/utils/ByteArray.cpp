#include <hxcpp.h>

#ifndef INCLUDED_cpp_CppInt32__
#include <cpp/CppInt32__.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
namespace nme{
namespace utils{

Void ByteArray_obj::__construct(Dynamic __o_inLen)
{
int inLen = __o_inLen.Default(0);
{
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",23)
	this->nmeData = ::nme::utils::ByteArray_obj::nme_byte_array_create(inLen);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",24)
	this->position = (int)0;
}
;
	return null();
}

ByteArray_obj::~ByteArray_obj() { }

Dynamic ByteArray_obj::__CreateEmpty() { return  new ByteArray_obj; }
hx::ObjectPtr< ByteArray_obj > ByteArray_obj::__new(Dynamic __o_inLen)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(__o_inLen);
	return result;}

Dynamic ByteArray_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic ByteArray_obj::nmeGetData( ){
	HX_SOURCE_PUSH("ByteArray_obj::nmeGetData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",27)
	return this->nmeData;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,nmeGetData,return )

::nme::utils::ByteArray ByteArray_obj::getData( ){
	HX_SOURCE_PUSH("ByteArray_obj::getData")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",29)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getData,return )

::String ByteArray_obj::asString( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::asString")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",33)
	return ::nme::utils::ByteArray_obj::nme_byte_array_as_string(this->nmeData);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,asString,return )

int ByteArray_obj::nmeGetLength( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::nmeGetLength")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",38)
	return ::nme::utils::ByteArray_obj::nme_byte_array_get_length(this->nmeData);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,nmeGetLength,return )

int ByteArray_obj::__get( int pos){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::__get")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",44)
	return ::nme::utils::ByteArray_obj::nme_byte_array_get(this->nmeData,pos);
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,__get,return )

Void ByteArray_obj::__set( int pos,int v){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("ByteArray_obj::__set")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",49)
		::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,pos,v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,__set,(void))

::haxe::io::Bytes ByteArray_obj::getBytes( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::getBytes")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",55)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::alloc(::nme::utils::ByteArray_obj::nme_byte_array_get_length(this->nmeData));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",56)
	::nme::utils::ByteArray_obj::nme_byte_array_get_bytes(this->nmeData,bytes->b);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",57)
	return bytes;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getBytes,return )

Void ByteArray_obj::writeFile( ::String inString){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("ByteArray_obj::writeFile")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",83)
		::nme::utils::ByteArray_obj::nme_byte_array_overwrite_file(inString,this->nmeData,::nme::utils::ByteArray_obj::nme_byte_array_get_length(this->nmeData));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeFile,(void))

int ByteArray_obj::readByte( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::readByte")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",89)
	return ::nme::utils::ByteArray_obj::nme_byte_array_get(this->nmeData,(this->position)++);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readByte,return )

int ByteArray_obj::readInt( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::readInt")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",98)
	return this->readInt32();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readInt,return )

int ByteArray_obj::readShort( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::readShort")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",102)
	return this->readInt16();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readShort,return )

int ByteArray_obj::readUnsignedByte( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::readUnsignedByte")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",106)
	return this->readByte();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedByte,return )

int ByteArray_obj::readUnsignedShort( ){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::readUnsignedShort")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",109)
	return this->readUInt16();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedShort,return )

::String ByteArray_obj::readUTFBytes( int inLen){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::readUTFBytes")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",114)
	return this->readString(inLen);
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readUTFBytes,return )

::String ByteArray_obj::nmeGetEndian( ){
	HX_SOURCE_PUSH("ByteArray_obj::nmeGetEndian")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",118)
	return (  ((this->bigEndian)) ? ::String(HX_CSTRING("bigEndian")) : ::String(HX_CSTRING("littleEndian")) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,nmeGetEndian,return )

::String ByteArray_obj::nmeSetEndian( ::String s){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::nmeSetEndian")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",122)
	this->setEndian((s == HX_CSTRING("bigEndian")));
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",123)
	return s;
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,nmeSetEndian,return )

Void ByteArray_obj::writeUTFBytesToBuffer( ::String str){
{
		__SAFE_POINT
		HX_SOURCE_PUSH("ByteArray_obj::writeUTFBytesToBuffer")
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",144)
		int requiredSpaceForString = (int)0;
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",146)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",146)
			int _g1 = (int)0;
			int _g = str.length;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",146)
			while((_g1 < _g)){
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",146)
				int i = (_g1)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",147)
				int charValue = str.charCodeAt(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",148)
				if (((bool((charValue > (int)0)) && bool((charValue <= (int)127))))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",149)
					(requiredSpaceForString)++;
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",150)
					if (((charValue <= (int)2047))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",151)
						hx::AddEq(requiredSpaceForString,(int)2);
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",152)
						if (((charValue <= (int)65535))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",153)
							hx::AddEq(requiredSpaceForString,(int)3);
						}
						else{
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",156)
							hx::AddEq(requiredSpaceForString,(int)4);
						}
					}
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",168)
		if ((((this->position + requiredSpaceForString) <= ::nme::utils::ByteArray_obj::nme_byte_array_get_length(this->nmeData)))){
		}
		else{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",176)
			int requiredSizeForNewBuffer = (this->position + requiredSpaceForString);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",178)
			Dynamic originalNmeData = this->nmeData;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",181)
			this->nmeData = ::nme::utils::ByteArray_obj::nme_byte_array_create(requiredSizeForNewBuffer);
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",184)
			{
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",184)
				int _g1 = (int)0;
				int _g = this->position;
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",184)
				while((_g1 < _g)){
					__SAFE_POINT
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",184)
					int i = (_g1)++;
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",185)
					::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,i,::nme::utils::ByteArray_obj::nme_byte_array_get(originalNmeData,i));
				}
			}
		}
		HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",192)
		{
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",192)
			int _g = (int)0;
			HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",192)
			while((_g < requiredSpaceForString)){
				__SAFE_POINT
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",192)
				int i = (_g)++;
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",193)
				int charValue = str.charCodeAt(i);
				HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",194)
				if (((charValue <= (int)127))){
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",195)
					::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,charValue);
				}
				else{
					HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",196)
					if (((charValue <= (int)2047))){
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",197)
						::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)192) | int((int(charValue) >> int((int)6)))));
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",198)
						::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)128) | int((int(charValue) & int((int)63)))));
					}
					else{
						HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",199)
						if (((charValue <= (int)65535))){
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",200)
							::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)224) | int((int(charValue) >> int((int)12)))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",201)
							::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)128) | int((int((int(charValue) >> int((int)6))) & int((int)63)))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",202)
							::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)128) | int((int(charValue) & int((int)63)))));
						}
						else{
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",205)
							::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)240) | int((int(charValue) >> int((int)18)))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",206)
							::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)128) | int((int((int(charValue) >> int((int)12))) & int((int)63)))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",207)
							::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)128) | int((int((int(charValue) >> int((int)6))) & int((int)63)))));
							HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",208)
							::nme::utils::ByteArray_obj::nme_byte_array_set(this->nmeData,(this->position)++,(int((int)128) | int((int(charValue) & int((int)63)))));
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUTFBytesToBuffer,(void))

::nme::utils::ByteArray ByteArray_obj::fromHandle( Dynamic inHandle){
	HX_SOURCE_PUSH("ByteArray_obj::fromHandle")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",67)
	::nme::utils::ByteArray result = ::nme::utils::ByteArray_obj::__new(null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",68)
	result->nmeData = inHandle;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",69)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,fromHandle,return )

::nme::utils::ByteArray ByteArray_obj::readFile( ::String inString){
	__SAFE_POINT
	HX_SOURCE_PUSH("ByteArray_obj::readFile")
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",74)
	Dynamic handle = ::nme::utils::ByteArray_obj::nme_byte_array_read_file(inString);
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",75)
	::nme::utils::ByteArray result = ::nme::utils::ByteArray_obj::__new(null());
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",76)
	result->nmeData = handle;
	HX_SOURCE_POS("/usr/lib/haxe/lib/nme/trunk/nme/utils/ByteArray.hx",77)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readFile,return )

Dynamic ByteArray_obj::nme_byte_array_create;

Dynamic ByteArray_obj::nme_byte_array_as_string;

Dynamic ByteArray_obj::nme_byte_array_get_bytes;

Dynamic ByteArray_obj::nme_byte_array_read_file;

Dynamic ByteArray_obj::nme_byte_array_overwrite_file;

Dynamic ByteArray_obj::nme_byte_array_get_length;

Dynamic ByteArray_obj::nme_byte_array_get;

Dynamic ByteArray_obj::nme_byte_array_set;


ByteArray_obj::ByteArray_obj()
{
}

void ByteArray_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ByteArray);
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(endian,"endian");
	HX_MARK_MEMBER_NAME(nmeData,"nmeData");
	HX_MARK_MEMBER_NAME(length,"length");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic ByteArray_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"__get") ) { return __get_dyn(); }
		if (HX_FIELD_EQ(inName,"__set") ) { return __set_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"endian") ) { return nmeGetEndian(); }
		if (HX_FIELD_EQ(inName,"length") ) { return nmeGetLength(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"nmeData") ) { return nmeData; }
		if (HX_FIELD_EQ(inName,"getData") ) { return getData_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt") ) { return readInt_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readFile") ) { return readFile_dyn(); }
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"asString") ) { return asString_dyn(); }
		if (HX_FIELD_EQ(inName,"getBytes") ) { return getBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeFile") ) { return writeFile_dyn(); }
		if (HX_FIELD_EQ(inName,"readShort") ) { return readShort_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fromHandle") ) { return fromHandle_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetData") ) { return nmeGetData_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"nmeGetLength") ) { return nmeGetLength_dyn(); }
		if (HX_FIELD_EQ(inName,"readUTFBytes") ) { return readUTFBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetEndian") ) { return nmeGetEndian_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetEndian") ) { return nmeSetEndian_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"readUnsignedByte") ) { return readUnsignedByte_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"readUnsignedShort") ) { return readUnsignedShort_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_byte_array_get") ) { return nme_byte_array_get; }
		if (HX_FIELD_EQ(inName,"nme_byte_array_set") ) { return nme_byte_array_set; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_byte_array_create") ) { return nme_byte_array_create; }
		if (HX_FIELD_EQ(inName,"writeUTFBytesToBuffer") ) { return writeUTFBytesToBuffer_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_byte_array_as_string") ) { return nme_byte_array_as_string; }
		if (HX_FIELD_EQ(inName,"nme_byte_array_get_bytes") ) { return nme_byte_array_get_bytes; }
		if (HX_FIELD_EQ(inName,"nme_byte_array_read_file") ) { return nme_byte_array_read_file; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_byte_array_get_length") ) { return nme_byte_array_get_length; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_byte_array_overwrite_file") ) { return nme_byte_array_overwrite_file; }
	}
	return super::__Field(inName);
}

Dynamic ByteArray_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"endian") ) { return nmeSetEndian(inValue); }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"nmeData") ) { nmeData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_byte_array_get") ) { nme_byte_array_get=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_byte_array_set") ) { nme_byte_array_set=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_byte_array_create") ) { nme_byte_array_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_byte_array_as_string") ) { nme_byte_array_as_string=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_byte_array_get_bytes") ) { nme_byte_array_get_bytes=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_byte_array_read_file") ) { nme_byte_array_read_file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_byte_array_get_length") ) { nme_byte_array_get_length=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_byte_array_overwrite_file") ) { nme_byte_array_overwrite_file=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ByteArray_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("endian"));
	outFields->push(HX_CSTRING("nmeData"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromHandle"),
	HX_CSTRING("readFile"),
	HX_CSTRING("nme_byte_array_create"),
	HX_CSTRING("nme_byte_array_as_string"),
	HX_CSTRING("nme_byte_array_get_bytes"),
	HX_CSTRING("nme_byte_array_read_file"),
	HX_CSTRING("nme_byte_array_overwrite_file"),
	HX_CSTRING("nme_byte_array_get_length"),
	HX_CSTRING("nme_byte_array_get"),
	HX_CSTRING("nme_byte_array_set"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("position"),
	HX_CSTRING("endian"),
	HX_CSTRING("nmeData"),
	HX_CSTRING("length"),
	HX_CSTRING("nmeGetData"),
	HX_CSTRING("getData"),
	HX_CSTRING("asString"),
	HX_CSTRING("nmeGetLength"),
	HX_CSTRING("__get"),
	HX_CSTRING("__set"),
	HX_CSTRING("getBytes"),
	HX_CSTRING("writeFile"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readInt"),
	HX_CSTRING("readShort"),
	HX_CSTRING("readUnsignedByte"),
	HX_CSTRING("readUnsignedShort"),
	HX_CSTRING("readUTFBytes"),
	HX_CSTRING("nmeGetEndian"),
	HX_CSTRING("nmeSetEndian"),
	HX_CSTRING("writeUTFBytesToBuffer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_create,"nme_byte_array_create");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_as_string,"nme_byte_array_as_string");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_get_bytes,"nme_byte_array_get_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_read_file,"nme_byte_array_read_file");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_overwrite_file,"nme_byte_array_overwrite_file");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_get_length,"nme_byte_array_get_length");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_get,"nme_byte_array_get");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_set,"nme_byte_array_set");
};

Class ByteArray_obj::__mClass;

void ByteArray_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.utils.ByteArray"), hx::TCanCast< ByteArray_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ByteArray_obj::__boot()
{
	hx::Static(nme_byte_array_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_byte_array_create"),(int)1);
	hx::Static(nme_byte_array_as_string) = ::nme::Loader_obj::load(HX_CSTRING("nme_byte_array_as_string"),(int)1);
	hx::Static(nme_byte_array_get_bytes) = ::nme::Loader_obj::load(HX_CSTRING("nme_byte_array_get_bytes"),(int)2);
	hx::Static(nme_byte_array_read_file) = ::nme::Loader_obj::load(HX_CSTRING("nme_byte_array_read_file"),(int)1);
	hx::Static(nme_byte_array_overwrite_file) = ::nme::Loader_obj::load(HX_CSTRING("nme_byte_array_overwrite_file"),(int)3);
	hx::Static(nme_byte_array_get_length) = ::nme::Loader_obj::load(HX_CSTRING("nme_byte_array_get_length"),(int)1);
	hx::Static(nme_byte_array_get) = ::nme::Loader_obj::load(HX_CSTRING("nme_byte_array_get"),(int)2);
	hx::Static(nme_byte_array_set) = ::nme::Loader_obj::load(HX_CSTRING("nme_byte_array_set"),(int)3);
}

} // end namespace nme
} // end namespace utils
